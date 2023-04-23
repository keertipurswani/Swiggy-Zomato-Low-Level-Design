#include "userMgr.hpp"

UserMgr* UserMgr::userMgrInstance = nullptr;
mutex UserMgr::mtx;


UserMgr* UserMgr::getUserMgr() {
	if (userMgrInstance == nullptr) {
		mtx.lock();
		if (userMgrInstance == nullptr) {
			userMgrInstance = new UserMgr();
		}
		mtx.unlock();
	}
	return userMgrInstance;
}

void UserMgr::addUser(string pUserName, User* pUser) {
	usersMap[pUserName] = pUser;
}

User* UserMgr::getUser(string pUserName) {
	return usersMap[pUserName];
}