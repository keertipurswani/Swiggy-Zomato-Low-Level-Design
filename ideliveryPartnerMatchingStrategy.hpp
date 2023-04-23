#pragma once

#include "deliveryMetaData.hpp"
#include "deliveryPartnerMgr.hpp"

class IDeliveryPartnerMatchingStrategy {
public:
	virtual vector<DeliveryPartner*> matchDeliveryPartners(DeliveryMetaData* pDeliveryMetaData) = 0;
};