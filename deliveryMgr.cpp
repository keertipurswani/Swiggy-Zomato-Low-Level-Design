#include "deliveryMgr.hpp"

DeliveryMgr* DeliveryMgr::deliveryMgrInstance = nullptr;
mutex DeliveryMgr::mtx;


DeliveryMgr* DeliveryMgr::getDeliveryMgr() {
	if (deliveryMgrInstance == nullptr) {
		mtx.lock();
		if (deliveryMgrInstance == nullptr) {
			deliveryMgrInstance = new DeliveryMgr();
		}
		mtx.unlock();
	}
	return deliveryMgrInstance;
}

//This function should be broken down into sub parts and every method should have one small respinsibility
void DeliveryMgr::manageDelivery(string pOrderId, DeliveryMetaData* pDeliveryMetaData) {
	StrategyMgr* strategyMgr = StrategyMgr::getStrategyMgr();

	IDeliveryPartnerMatchingStrategy* partnerMatchingStrategy = 
		strategyMgr->determineDeliveryPartnerMatchingStrategy(pDeliveryMetaData);

	vector<DeliveryPartner*> deliverypartners = 
		partnerMatchingStrategy->matchDeliveryPartners(pDeliveryMetaData);

	NotificationMgr* notificationMgr = NotificationMgr::getNotificationMgr();
	//Send push notifications to the nearest delivery partners
	for (auto deliveryPartner : deliverypartners) {
		notificationMgr->notifyParticularUser(deliveryPartner->getName(), "Delivery Request", new PushNotificationSender());
	}

	DeliveryPartner* assignedDeliveryPartner = deliverypartners[0];

	//Assume first delivery partner accepted it
	notificationMgr->notify(pOrderId, "Delivery Partner " + assignedDeliveryPartner->getName() + " assigned for the order " + pOrderId);


	assignedDeliveryPartner->performDelivery(pOrderId, pDeliveryMetaData);
}