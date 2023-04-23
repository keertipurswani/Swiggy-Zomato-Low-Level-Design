#include "restaurantMgr.hpp"

RestaurantMgr* RestaurantMgr::restaurantMgrInstance = nullptr;
mutex RestaurantMgr::mtx;


RestaurantMgr* RestaurantMgr::getRestaurantMgr() {
	if (restaurantMgrInstance == nullptr) {
		mtx.lock();
		if (restaurantMgrInstance == nullptr) {
			restaurantMgrInstance = new RestaurantMgr();
		}
		mtx.unlock();
	}
	return restaurantMgrInstance;
}

void RestaurantMgr::addRestaurant(string pRestaurantName, Restaurant* pRestaurant) {
	restaurantsMap[pRestaurantName] = pRestaurant;
}

Restaurant* RestaurantMgr::getRestaurant(string pRestaurantName) {
	return restaurantsMap[pRestaurantName];
}