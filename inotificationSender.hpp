#pragma once
#include "common.hpp"


//This class corresponds to observer interface in the observer design pattern
//Notification Mgr is the subject

class INotificationSender {
public:
    virtual void sendNotification(string pUserId, string msg) = 0;
};
