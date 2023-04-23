#pragma once
#include "common.hpp"
#include "vector"
#include "dishAddOn.hpp"

class Dish {
	string name;
	CUISINE cuisine;
	string description;
	double price;
	vector<string> dishImages;
	vector<DishAddOn*> addons;	//could have had decorator design pattern for add ons but
								//seemed overkill since restaurant owners are going to create addons
public:
	Dish(string pName, CUISINE pCuisine, double pPrice) : 
		name(pName), cuisine(pCuisine), price(pPrice) {}
	void addAddOn(DishAddOn* pAddOn) {
		addons.push_back(pAddOn);
	}
	//remove add on function
	double getPrice() { 
		double totalPrice = price;
		for (auto addOn : addons)
			totalPrice += addOn->getPrice();
		return totalPrice; 
	}
	string getDescription() { return description; }
	string getDishName() { return name; }
	CUISINE getCuisine() { return cuisine; }
};
