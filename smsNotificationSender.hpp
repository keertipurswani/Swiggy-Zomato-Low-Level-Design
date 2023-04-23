#pragma once
#include "inotificationSender.hpp"

class SMSNotificationSender : public INotificationSender {
public:
    void sendNotification(string pUserId, string pMsg) {
        cout << "SMS Notification for "<< pUserId <<" is " << pMsg << endl;
    }
};