#pragma once
#include "common.hpp"
//This class basically has all the info that will be used by strategy 
//Even if more data is needed, only this class needs to be updated
//Suppose strategy is different for premium customer then only one bool can be added here
//The bool here can determine if customer is premium ot not, all customer info need not be passed

class DeliveryMetaData {
	Location* userLoc;
	Location* restaurantLoc;
	string orderId;
	//weather conditions
public:
	DeliveryMetaData(string pOrderId, Location* pUserLoc, Location* pRestaurantLoc) : 
		orderId(pOrderId), userLoc(pUserLoc), restaurantLoc(pRestaurantLoc) {}

	Location* getUserLoc() {
		return userLoc;
	}
	Location* getRestaurantLoc() {
		return restaurantLoc;
	}
};
