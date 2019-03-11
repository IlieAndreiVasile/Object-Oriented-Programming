//#pragma once
//#include "ShopBasket.h"
//#include "Repository.h"
//#include "Controller.h"
//#include <assert.h>
//
//
//void tests()
//{
//	TrenchCoat tc1(35, "black", 95, 5, "http://nord.imgix.net/Zoom/6/_11769446.jpg?fit=fill&bg=FFF&fm=jpg&w=391&h=600&dpr=1.5&q=52.5");
//	TrenchCoat tc2(35, "navy", 265, 7, "http://nord.imgix.net/Zoom/3/_12903783.jpg?fit=fill&bg=FFF&fm=jpg&w=704&h=1080&dpr=1.5&q=52.5");
//	TrenchCoat tc3{ 35, "beige", 180, 2, "http://nord.imgix.net/Zoom/7/_12997767.jpg?fit=fill&bg=FFF&fm=jpg&w=391&h=600&dpr=1.5&q=52.5" };
//	TrenchCoat tc4{ 36, "beige",330, 3, "http://nord.imgix.net/Zoom/11/_10465371.jpg?fit=fill&bg=FFF&fm=jpg&w=391&h=600&dpr=1.5&q=52.5" };
//	TrenchCoat tc5{ 36, "grey", 190, 3, "http://nord.imgix.net/Zoom/18/_12894638.jpg?fit=fill&bg=FFF&fm=jpg&w=391&h=600&dpr=1.5&q=52.5" };
//	TrenchCoat tc6{ 38, "black",100, 1, "http://nord.imgix.net/Zoom/15/_13181655.jpg?fit=fill&bg=FFF&fm=jpg&w=391&h=600&dpr=1.5&q=52.5" };
//	TrenchCoat tc7{ 38, "camel", 130, 6, "http://nord.imgix.net/Zoom/19/_100241779.jpg?fit=fill&bg=FFF&fm=jpg&w=391&h=600&dpr=1.5&q=52.5" };
//	TrenchCoat tc8{ 39, "brown", 110, 4, "http://nord.imgix.net/Zoom/7/_9619387.jpg?fit=fill&bg=FFF&fm=jpg&w=704&h=1080&dpr=1.5&q=52.5" };
//	TrenchCoat tc9{ 39, "grey", 150, 4, "http://nord.imgix.net/Zoom/14/_100589234.jpg?fit=fill&bg=FFF&fm=jpg&w=391&h=600&dpr=1.5&q=52.5" };
//	TrenchCoat tc10{ 39, "navy", 105, 8, "http://nord.imgix.net/Zoom/19/_100299079.jpg?fit=fill&bg=FFF&fm=jpg&w=391&h=600&dpr=1.5&q=52.5" };
//
//	Repository repo;
//	Controller ctrl(repo);
//
//	
//
//	ctrl.addToRepository(tc2);
//
//	tc1.displayPhotograph();
//
//	assert(ctrl.getSizeRepository() == 1);
//
//	assert(tc2.getSize() == 35);
//	assert(tc2.getColour() == "navy");
//	assert(tc2.getPrice() == 265);
//	assert(tc2.getQuantity() == 7);
//	assert(tc2.getPhotograph() == "http://nord.imgix.net/Zoom/3/_12903783.jpg?fit=fill&bg=FFF&fm=jpg&w=704&h=1080&dpr=1.5&q=52.5");
//
//	tc2.setQuantity(1);
//	assert(tc2.getQuantity() == 1);
//
//
//	assert(ctrl.addToRepository(tc1) == true);
//	assert(ctrl.addToRepository(tc1) == false);
//
//	assert(ctrl.deleteFromRepository(tc1) == true);
//	assert(ctrl.deleteFromRepository(tc1) == false);
//
//	ctrl.addToRepository(tc5);
//	assert(ctrl.updateFromRepository(tc5, tc2) == true);
//	assert(ctrl.updateFromRepository(tc5, tc2) == false);
//
//
//	ctrl.addToShopBasket(tc9);
//	assert(ctrl.getShopBasketSum() == 150);
//
//	ctrl.printShopBasket();
//	ctrl.printRepository();
//	auto v = ctrl.getAllRepository();
//}