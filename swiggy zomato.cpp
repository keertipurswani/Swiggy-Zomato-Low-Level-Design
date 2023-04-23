#include "common.hpp"
#include "userMgr.hpp"
#include "restaurantMgr.hpp"
#include "deliveryPartnerMgr.hpp"
#include "orderMgr.hpp"

int main() {
	//Chinese Restaurant
	RestaurantOwner* owner1 = new RestaurantOwner("owner1");
	Restaurant* chineseRest = new Restaurant("chinese vala", owner1, new Location(1, 2));
	Dish* noodles = new Dish("noodles", CUISINE::CHINESE, 200);
	noodles->addAddOn({ new DishAddOn("premium sauce", 20) });
	Dish* fried_rice = new Dish("fried rice", CUISINE::CHINESE, 180);
	Dish* spring_rolls = new Dish("spring rolls", CUISINE::CHINESE, 120);
	Menu* chinese_menu = new Menu({ noodles, fried_rice, spring_rolls });
	chineseRest->addMenu(chinese_menu);

	//South Indian Restaurant
	RestaurantOwner* owner2 = new RestaurantOwner("owner2");
	Restaurant* southIndianRest = new Restaurant("south indian food", owner2, new Location(2, 3));
	Dish* idli = new Dish("idli", CUISINE::SOUTH_INDIAN, 200);
	Dish* dosa = new Dish("dosa", CUISINE::SOUTH_INDIAN, 180);
	Dish* uthappam = new Dish("uthappam", CUISINE::SOUTH_INDIAN, 120);
	Menu* south_indian_menu = new Menu({ idli, dosa, uthappam});
	southIndianRest->addMenu(south_indian_menu);

	//Note that restaurant owners can exist without restaurants, we have used aggregation relationship
	//This can lead to owners being present with no restaurants and thus not added in restaurant manager
	//This is how we have designed and we should know consequences of the way we have structured.

	RestaurantMgr* restaurantMgr = RestaurantMgr::getRestaurantMgr();
	restaurantMgr->addRestaurant("chinese vala", chineseRest);
	restaurantMgr->addRestaurant("south indian food", southIndianRest);

	//////////////////////////////////////////////////////////////////////////////////////////////////

	DeliveryPartner* alpha = new DeliveryPartner("alpha");
	DeliveryPartner* beta = new DeliveryPartner("beta");
	DeliveryPartner* gamma = new DeliveryPartner("gamma");

	DeliveryPartnerMgr* deliveryPartnerMgr = DeliveryPartnerMgr::getDeliveryPartnerMgr();
	deliveryPartnerMgr->addDeliveryPartner("alpha", alpha);
	deliveryPartnerMgr->addDeliveryPartner("beta", beta);
	deliveryPartnerMgr->addDeliveryPartner("gamma", gamma);

	//////////////////////////////////////////////////////////////////////////////////////////////////

	User* keerti = new User("keerti", new Location(10,11));
	User* gaurav = new User("gaurav", new Location(13, 14));
	User* yogita = new User("yogita", new Location(15, 16));
	//users can exist without usermgr as well. That's why it is an aggregation relationship

	UserMgr* userMgr = UserMgr::getUserMgr();
	userMgr->addUser("keerti", keerti);
	userMgr->addUser("gaurav", gaurav);
	userMgr->addUser("yogita", yogita);

	//////////////////////////////////////////////////////////////////////////////////////////////////

	//I am passing same dish object that was created by res, for C++ folks - it should be different dish object

	unordered_map<Dish*, int> cart;
	cart.insert({ noodles, 2 });
	cart.insert({fried_rice, 1});
	Order* order1 = new Order(keerti, chineseRest, cart);
	
	OrderMgr* orderMgr = OrderMgr::getOrderMgr();
	orderMgr->createOrder("order1", order1); // Ideally, the id should be created in order manager when order is created
												//This is just for simplicity purposes and has been mentioned in the class as well
												//We have done same for all ids - user, restaurant, delivery partner etc.

	return 0;
}