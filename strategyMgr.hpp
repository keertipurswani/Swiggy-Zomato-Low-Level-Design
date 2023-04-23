#pragma once
#include "common.hpp"
#include "mutex"
#include "deliveryChargeCalculationStrategy.hpp"
#include "ideliveryPartnerMatchingStrategy.hpp"
#include "locBasedDeliveryPartnerMatchingStrategy.hpp"


class StrategyMgr {
	StrategyMgr() {}
	static StrategyMgr* strategyMgrInstance;
	static mutex mtx;

public:
	static StrategyMgr* getStrategyMgr();
	IDeliveryPartnerMatchingStrategy* determineDeliveryPartnerMatchingStrategy(DeliveryMetaData* metaData);
};