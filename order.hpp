#pragma once
#include "common.hpp"
#include "dish.hpp"
#include "unordered_map"
#include "user.hpp"
#include "restaurant.hpp"

class Order {
	User* user;
	Restaurant* restaurant;		//we can choose to store only ids of user and restaurant for further decoupling
	unordered_map<Dish*, int> dishes; //quantity for each dish
	//We are assuming that a dish is separate from the same dish with addon
	//There are many ways to store dishes that are being ordered but 
	//we should know our design assumptions properly
	string discountCode;	
	string paymentId;		
	ORDER_STATUS status;

public:
	Order(User* pUser, Restaurant* pRestaurant, unordered_map<Dish*, int> pDishes) :
		user(pUser), restaurant(pRestaurant), dishes(pDishes) {
		status = ORDER_STATUS::PLACED;
	}

	string getUserId() {
		return user->getId();
	}
	string getRestaurantId() {
		return restaurant->getId();
	}
	unordered_map<Dish*, int> getDishes() {
		return dishes;
	}

	//Another way to get the location would be to get the entire user or location object and get location from there
	//BUT we should not expose info that is not required. Location is imp info for delivery and is imp for order
	//So, it made sense to put getters for both locations here
	Location* getUserLocation() {
		return user->getLocation();
	}
	Location* getRestaurantLocation() {
		return restaurant->getLocation();
	}
};