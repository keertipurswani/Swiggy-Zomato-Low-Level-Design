#pragma once
#include "ideliveryPartnerMatchingStrategy.hpp"

class LocBasedDeliveryPartnerMatchingStrategy : public IDeliveryPartnerMatchingStrategy {
public:
	vector<DeliveryPartner*> matchDeliveryPartners(DeliveryMetaData* pMetaData) {
		DeliveryPartnerMgr* deliveryPartnerMgr = DeliveryPartnerMgr::getDeliveryPartnerMgr();

		cout << "Quadtrees can be used to get nearest delivery partners, "<<
			"Delivery partner manager can be used to get details of partners. " <<
			"Returning all delivery partners for demo purposes for now."<<endl;

		vector<DeliveryPartner*> nearestDeliveryPartners;
		for (auto deliveryPartnerDetails : deliveryPartnerMgr->getDeliveryPartnersMap())
			nearestDeliveryPartners.push_back(deliveryPartnerDetails.second);
		return nearestDeliveryPartners;
	}
};