#pragma once
#include "common.hpp"
#include "menu.hpp"
#include "restaurantOwner.hpp"
#include <chrono>
#include <thread>
#include "notificationMgr.hpp"

//can also store usual timings, restaurant pics...
class Restaurant {
	string name;	//storing name as id itself for now. id should be generated and name should be passed in ctor
	bool isAvail;
	Location* location;
	Menu* menu;
	RestaurantOwner* owner;	//can support multiple owners, but for simplicity, one owner
public:
	Restaurant(string pName, RestaurantOwner* pOwner, Location* pLoc) : 
			name(pName), owner(pOwner), location(pLoc) {
		isAvail = false;
		menu = nullptr;	//can choose to pass in the constructor but keeping it apart for now
	}
	void addMenu(Menu* pMenu) {
		menu = pMenu;
	}
	string getId() {
		return name;
	}
	Location* getLocation() {
		return location;
	}
	bool prepareFood(string pOrderId, unordered_map<Dish*, int> dishes) {
		cout << "Restaurant accepting the order and starting to prepare it" << endl;

		NotificationMgr* notificationMgr = NotificationMgr::getNotificationMgr();


		notificationMgr->notify(pOrderId, "Food is being prepared in restaurant");

		this_thread::sleep_for(chrono::seconds(5));

		notificationMgr->notify(pOrderId, "Food is ready and can be picked up from restaurant");

		return true;
	}
};
