#pragma once
#include <iostream>

using namespace std;

enum class CUISINE {
	NORTH_INDIAN,
	SOUTH_INDIAN,
	CHINESE,
	STREET_FOOD,
	SWEETS,
	ITALIAN,
};

enum class ORDER_STATUS {
	PLACED,
	ORDERED,
	ACCEPTED,
	ON_THE_WAY,
	REACHED,
	DELIVERED,
	CANCELLED
};

enum class RATING {
	UNASSIGNED,
	ONE_STAR,
	TWO_STARS,
	THREE_STARS,
	FOUR_STARS,
	FIVE_STARS,
};

class Location {
	double latitude;
	double longitude;
public:
	Location(double pLat, double pLong) : latitude(pLat), longitude(pLong) {}
	double getLatitude() {
		return latitude;
	}
	double getLongitude() {
		return longitude;
	}
};