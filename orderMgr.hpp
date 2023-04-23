#pragma once

#include "order.hpp"
#include "mutex"
#include "unordered_map"
#include "common.hpp"
#include "deliveryMetaData.hpp"
#include "deliveryMgr.hpp"
#include "foodMgr.hpp"
#include "notificationMgr.hpp"

class OrderMgr {
	OrderMgr() {
		deliveryMgr = DeliveryMgr::getDeliveryMgr();
		foodMgr = FoodMgr::getFoodMgr();
	}
	static OrderMgr* orderMgrInstance;
	static mutex mtx;
	unordered_map<string, Order*> ordersMap;

	DeliveryMgr* deliveryMgr;
	FoodMgr* foodMgr;

	//3 stages of order creation
	void addUserForNotificationUpdates(string pOrderId, Order* pOrder);
	void manageDelivery(string pOrderId, Order* pOrder);
	void manageFood(string pOrderId, Order* pOrder);
public:
	static OrderMgr* getOrderMgr();
	void createOrder(string pOrderName, Order* pOrder); // the name should ideally not be passed
														//id should be generated. using name as id here

	Order* getOrder(string pOrderId); //this id should be returned while creating order
										//and can be used to fetch order details
};
