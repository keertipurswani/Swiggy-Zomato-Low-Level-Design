#pragma once

#include "restaurant.hpp"
#include "mutex"
#include "unordered_map"
#include "common.hpp"

class RestaurantMgr {
	RestaurantMgr() {}
	static RestaurantMgr* restaurantMgrInstance;
	static mutex mtx;
	unordered_map<string, Restaurant*> restaurantsMap;
public:
	static RestaurantMgr* getRestaurantMgr();
	void addRestaurant(string pRestaurantName, Restaurant* pRestaurant);
	Restaurant* getRestaurant(string pRestaurantName);
};
