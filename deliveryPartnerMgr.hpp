#pragma once

#include "deliveryPartner.hpp"
#include "mutex"
#include "unordered_map"
#include "common.hpp"

class DeliveryPartnerMgr {
	DeliveryPartnerMgr() {}
	static DeliveryPartnerMgr* deliveryPartnerMgrInstance;
	static mutex mtx;
	unordered_map<string, DeliveryPartner*> deliveryPartnersMap;
public:
	static DeliveryPartnerMgr* getDeliveryPartnerMgr();
	void addDeliveryPartner(string pDeliveryPartnerName, DeliveryPartner* pDeliveryPartner);
	DeliveryPartner* getDeliveryPartner(string pDeliveryPartnerName);

	//This getter is added so that delivery partner matching strategy can access the map and 
	//select nearest delivery partners
	unordered_map<string, DeliveryPartner*> getDeliveryPartnersMap() {
		return deliveryPartnersMap;
	}
};
