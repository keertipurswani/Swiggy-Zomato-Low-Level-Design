#include "foodMgr.hpp"
#include "pushNotificationSender.hpp"

FoodMgr* FoodMgr::foodMgrInstance = nullptr;
mutex FoodMgr::mtx;

FoodMgr* FoodMgr::getFoodMgr() {
	if (foodMgrInstance == nullptr) {
		mtx.lock();
		if (foodMgrInstance == nullptr) {
			foodMgrInstance = new FoodMgr();
		}
		mtx.unlock();
	}
	return foodMgrInstance;
}


void FoodMgr::addRestaurantForNotificationUpdates(string pOrderId, string pRestaurantId) {
	NotificationMgr* notificationMgr = NotificationMgr::getNotificationMgr();
	//we can add push or whatsapp notifications in same way. Basically, we are keeping all notifications customisable
	notificationMgr->addNotificationSender(pOrderId, pRestaurantId, new PushNotificationSender());
}


void FoodMgr::prepareFood(string pOrderId, string pRestaurantId, unordered_map<Dish*, int> pDishes) {
	RestaurantMgr* restaurantMgr = RestaurantMgr::getRestaurantMgr();
	Restaurant* restaurant = restaurantMgr->getRestaurant(pRestaurantId);
	restaurant->prepareFood(pOrderId, pDishes);

	//Restaurant should receive the delivery partner's notifications. 
	//The order in which the restaurant, user & delivery partner are added to the notification mgr
	//will decide which notifications they receive
	//For interviews, This is too much detailing though, we can just mention to interviewer and move forward
	addRestaurantForNotificationUpdates(pOrderId, pRestaurantId);
}