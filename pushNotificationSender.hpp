#pragma once
#include "inotificationSender.hpp"

class PushNotificationSender : public INotificationSender {
public:
    void sendNotification(string pUserId, string pMsg) {
        cout << "Push Notification for "<<pUserId<< " is " << pMsg << endl;
    }
};