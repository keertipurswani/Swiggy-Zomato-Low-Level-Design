#pragma once
#include "dish.hpp"
#include "vector"

class Menu {
	vector<Dish*> dishes;
public:
	Menu(vector<Dish*> pDishes) : dishes(pDishes) {}
};
