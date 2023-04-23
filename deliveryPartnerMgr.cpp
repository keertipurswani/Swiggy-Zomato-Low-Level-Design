#include "deliveryPartnerMgr.hpp"

DeliveryPartnerMgr* DeliveryPartnerMgr::deliveryPartnerMgrInstance = nullptr;
mutex DeliveryPartnerMgr::mtx;

DeliveryPartnerMgr* DeliveryPartnerMgr::getDeliveryPartnerMgr() {
	if (deliveryPartnerMgrInstance == nullptr) {
		mtx.lock();
		if (deliveryPartnerMgrInstance == nullptr) {
			deliveryPartnerMgrInstance = new DeliveryPartnerMgr();
		}
		mtx.unlock();
	}
	return deliveryPartnerMgrInstance;
}

void DeliveryPartnerMgr::addDeliveryPartner(string pDeliveryPartnerName, DeliveryPartner* pDeliveryPartner) {
	deliveryPartnersMap[pDeliveryPartnerName] = pDeliveryPartner;
}

DeliveryPartner* DeliveryPartnerMgr::getDeliveryPartner(string pDeliveryPartnerName) {
	return deliveryPartnersMap[pDeliveryPartnerName];
}