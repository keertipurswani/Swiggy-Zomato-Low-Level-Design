#pragma once

#include "user.hpp"
#include "mutex"
#include "unordered_map"
#include "common.hpp"

class UserMgr {
	UserMgr() {}
	static UserMgr* userMgrInstance;
	static mutex mtx;
	unordered_map<string, User*> usersMap;
public:
	static UserMgr* getUserMgr();
	void addUser(string puserName, User* puser);
	User* getUser(string puserName);
};
