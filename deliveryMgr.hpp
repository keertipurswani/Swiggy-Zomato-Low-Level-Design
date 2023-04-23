#pragma once
#include "deliveryMetaData.hpp"
#include "strategyMgr.hpp"
#include "deliveryPartnerMgr.hpp"
#include "notificationMgr.hpp"
#include "pushNotificationSender.hpp"

class DeliveryMgr {
	DeliveryMgr() {}
	static DeliveryMgr* deliveryMgrInstance;
	static mutex mtx;
public:
	static DeliveryMgr* getDeliveryMgr();
	void manageDelivery(string pOrderId, DeliveryMetaData* pDeliveryMetaData);
};