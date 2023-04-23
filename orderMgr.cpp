#include "orderMgr.hpp"

#include "smsNotificationSender.hpp"

OrderMgr* OrderMgr::orderMgrInstance = nullptr;
mutex OrderMgr::mtx;

void OrderMgr::addUserForNotificationUpdates(string pOrderId, Order* pOrder) {
	NotificationMgr* notificationMgr = NotificationMgr::getNotificationMgr();
	//we can add push or whatsapp notifications in same way. Basically, we are keeping all notifications customisable
	notificationMgr->addNotificationSender(pOrderId, pOrder->getUserId(), new SMSNotificationSender());
	//this configuration level should be in user class and not in order mgr
}

void OrderMgr::manageDelivery(string pOrderId, Order* pOrder) {
	DeliveryMetaData* metaData = new DeliveryMetaData(pOrderId, pOrder->getUserLocation(), pOrder->getRestaurantLocation());
	deliveryMgr->manageDelivery(pOrderId, metaData);
}

void OrderMgr::manageFood(string pOrderId, Order* pOrder) {
	foodMgr->prepareFood(pOrderId, pOrder->getRestaurantId(), pOrder->getDishes());
}

void OrderMgr::createOrder(string pOrderId, Order* pOrder) {

	addUserForNotificationUpdates(pOrderId, pOrder);

	manageFood(pOrderId, pOrder);

	manageDelivery(pOrderId, pOrder);
}

OrderMgr* OrderMgr::getOrderMgr() {
	if (orderMgrInstance == nullptr) {
		mtx.lock();
		if (orderMgrInstance == nullptr) {
			orderMgrInstance = new OrderMgr();
		}
		mtx.unlock();
	}
	return orderMgrInstance;
}

Order* OrderMgr::getOrder(string pOrderName) {
	return ordersMap[pOrderName];
}