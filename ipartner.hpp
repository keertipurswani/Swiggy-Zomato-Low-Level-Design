#pragma once
#include "common.hpp"

class IPartner {
protected:
	string name;
	RATING rating;
	//kyc details
public:
	IPartner(string pName) : name(pName) {
		rating = RATING::UNASSIGNED;
	}
	string getName() {
		return name;
	}
	//void performKyc() = 0;
};