#pragma once

#include "thread"
#include "chrono"
#include "string"
#include "ipartner.hpp"
#include "notificationMgr.hpp"
#include "deliveryMetaData.hpp"



class DeliveryPartner : public IPartner {
public:
	DeliveryPartner(string pName) : IPartner(pName) {}

	//Order Status also needs to be updated while these steps are happening
	//We have black-boxed that
	void performDelivery(string pOrderId, DeliveryMetaData* pDeliveryMetaData) {
		NotificationMgr* notificationMgr = NotificationMgr::getNotificationMgr();

		double restaurantLocLatitude = pDeliveryMetaData->getRestaurantLoc()->getLatitude();
		double restaurantLocLongitude = pDeliveryMetaData->getRestaurantLoc()->getLongitude();
		notificationMgr->notify(pOrderId, name + " going to pick up delivery from location " 
						+ to_string(restaurantLocLatitude) + "," + to_string(restaurantLocLongitude));

		this_thread::sleep_for(chrono::seconds(5));

		notificationMgr->notify(pOrderId, name + " picked up delivery!");

		this_thread::sleep_for(chrono::seconds(5));

		notificationMgr->notify(pOrderId, name + " on the way to deliver!");

		this_thread::sleep_for(chrono::seconds(5));

		double userLocLatitude = pDeliveryMetaData->getUserLoc()->getLatitude();
		double userLocLongitude = pDeliveryMetaData->getUserLoc()->getLongitude();
		notificationMgr->notify(pOrderId, name + " reached the location " + to_string(userLocLatitude) + "," + to_string(userLocLongitude));
		
		this_thread::sleep_for(chrono::seconds(5));

		notificationMgr->notify(pOrderId, name + " delivered the order. CONGRATULATIONS!!");

	}
};

