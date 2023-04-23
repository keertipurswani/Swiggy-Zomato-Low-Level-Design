#pragma once
#include "common.hpp"
#include "inotificationSender.hpp"
#include "unordered_map"
#include "vector"
#include "mutex"

//This class corresponds to subject in the observer design pattern
//NotificationSender is the observer interface

class NotificationMgr {
	NotificationMgr() {}
	static NotificationMgr* notificationMgrInstance;
	static mutex mtx;
	unordered_map<string, vector<pair<string,INotificationSender*>>> notificationSendersMap;

public:
	static NotificationMgr* getNotificationMgr();
	//register observer
	void addNotificationSender(string pOrderId, string pUserId, INotificationSender* pNotificationSender) {
		if (find(notificationSendersMap[pOrderId].begin(), notificationSendersMap[pOrderId].end(), make_pair(pUserId, pNotificationSender))
			== notificationSendersMap[pOrderId].end()) {
			//making sure the sender is already not there in the vector
			//if this check is not put, then multiple notifications will be sent by same sender
			notificationSendersMap[pOrderId].push_back(make_pair(pUserId, pNotificationSender));
		}
	}

	//unregister observer
	void removeNotificationSender(string pOrderId, string pUserId, INotificationSender* pNotificationSender) {
		auto senderPos = find(notificationSendersMap[pOrderId].begin(),
			notificationSendersMap[pOrderId].end(), make_pair(pUserId, pNotificationSender));
		if (senderPos != notificationSendersMap[pOrderId].end()) {
			notificationSendersMap[pOrderId].erase(senderPos);
		}
	}

	//notify Observers
	void notify(string pOrderId, string pMsg) {
		for (auto sender : notificationSendersMap[pOrderId])
			sender.second->sendNotification(sender.first, pMsg);
	}

	//notify particular user by a particular method
	void notifyParticularUser(string pUserId, string pMsg, INotificationSender* sender) {
		sender->sendNotification(pUserId, pMsg);
	}
};