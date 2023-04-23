#pragma once
#include "mutex"
#include "restaurantMgr.hpp"
#include "notificationMgr.hpp"

class FoodMgr {
	FoodMgr() {}
	static FoodMgr* foodMgrInstance;
	static mutex mtx;
public:
	static FoodMgr* getFoodMgr();
	void prepareFood(string pOrderId, string pRestaurantId, unordered_map<Dish*, int> pDishes);
	void addRestaurantForNotificationUpdates(string pOrderId, string pRestaurantId);
};
