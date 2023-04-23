#include "notificationMgr.hpp"


NotificationMgr* NotificationMgr::notificationMgrInstance = nullptr;
mutex NotificationMgr::mtx;

NotificationMgr* NotificationMgr::getNotificationMgr() {
	if (notificationMgrInstance == nullptr) {
		mtx.lock();
		if (notificationMgrInstance == nullptr) {
			notificationMgrInstance = new NotificationMgr();
		}
		mtx.unlock();
	}
	return notificationMgrInstance;
}