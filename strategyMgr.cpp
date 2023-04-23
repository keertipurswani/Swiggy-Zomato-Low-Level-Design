#include "strategyMgr.hpp"

StrategyMgr* StrategyMgr::strategyMgrInstance = nullptr;
mutex StrategyMgr::mtx;

StrategyMgr* StrategyMgr::getStrategyMgr() {
	if (strategyMgrInstance == nullptr) {
		mtx.lock();
		if (strategyMgrInstance == nullptr) {
			strategyMgrInstance = new StrategyMgr();
		}
		mtx.unlock();
	}
	return strategyMgrInstance;
}

IDeliveryPartnerMatchingStrategy* StrategyMgr::determineDeliveryPartnerMatchingStrategy(DeliveryMetaData* metaData) {
	cout << "Based on location, weather and other factors, setting partner strategy" << endl;
	return new LocBasedDeliveryPartnerMatchingStrategy();
}

