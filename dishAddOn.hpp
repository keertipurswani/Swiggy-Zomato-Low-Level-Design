#pragma once

class DishAddOn {
	string name;
	string description;
	double price;
	bool isAvail;
	vector<string> images;
public:
	DishAddOn(string pName, double pPrice) : name(pName), price(pPrice) {}
	//getters setters
	double getPrice() { return price; }
};
