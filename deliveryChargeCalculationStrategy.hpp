#pragma once
#include "deliveryMetaData.hpp"
#include "deliveryPartner.hpp"

class DeliveryChargeCalculationStrategy {
public:
	virtual double calculateDeliveryCharge(DeliveryMetaData* pDeliveryMetaData) = 0;
};