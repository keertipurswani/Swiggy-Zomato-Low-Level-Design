#pragma once
#include "ipartner.hpp"

class RestaurantOwner : public IPartner {
public:
	RestaurantOwner(string pName) : IPartner(pName) {}
};
