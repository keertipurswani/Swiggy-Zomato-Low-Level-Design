#pragma once
#include <string>
#include "common.hpp"

using namespace std;

class User {
	string name;
	Location* location;
public:
	User(string pName, Location* pLoc) : name(pName), location(pLoc) {}
	Location* getLocation() {
		return location;
	}
	string getId() {
		return name;
	}
};