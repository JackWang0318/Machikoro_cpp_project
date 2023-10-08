//
// Created by zy20200721 on 2022/10/15.
//

#ifndef UNTITLED1_CONSTANT_1_0_H
#define UNTITLED1_CONSTANT_1_0_H


#include <iostream>

using namespace std;


//定义枚举类型
enum class Color {
    blue, green, red, purple
}; //卡的颜色
enum class Type {
    normal, special, factory, landmark
}; //卡的类型  type = { 基础建筑 };
enum class Symbol {
    wheat, animal, shop, food, gear, tower, boat
}; //卡的符号 ，每个卡名字旁边的圆形标志代表的意思,按规则书顺序命名，
// 例如：第一张牌是小麦标志，第二张动物，第三张商店，第四张食物


//名字
const string WHEAT_FIELD_NAME = "Wheat Field";
const string RANCH_NAME = "Ranch";
const string BAKERY_NAME = "Bakery";
const string CAFE_NAME = "Cafe";
const string CONVENIENCE_STORE_NAME = "Convenience Store";
const string FOREST_NAME = "Forest";
const string STADIUM_NAME = "Stadium";
const string TV_STATION_NAME = "TV Station";
const string BUSINESS_CENTER_NAME = "Business Center";
const string CHEESE_FACTORY_NAME = "Cheese Factory";
const string FURNITURE_FACTORY_NAME = "Furniture Factory";
const string MINE_NAME = "Mine";
const string FAMILY_RESTAURANT_NAME = "Family Restaurant";
const string APPLE_ORCHARD_NAME = "Apple Orchard";
const string FARMERS_MARKET_NAME = "Farmers Market";


//港口拓展卡包名字
const string FLOWER_FIELD_NAME = "Flower Field";
const string MACKEREL_FISHBOAT_NAME = "Mackerel Fishboat";
const string TUNA_FISHBOAT_NAME = "Tuna Fishboat";
const string FLOWER_SHOP_NAME = "Flower Shop";
const string FOOD_MARKET_NAME = "Food Market";
const string PUBLISHER_NAME = "Publisher";
const string TAX_OFFICE_NAME = "Tax Office";
const string BURGER_SHOP_NAME = "Burger Shop";
const string PIZZA_SHOP_NAME = "Pizza Shop";
const string SUSHI_SHOP_NAME = "Sushi Shop";

//描述
const string WHEAT_FIELD_DESCRIPTION = "Get 1 coin from the bank (anyone's turn)";
const string RANCH_DESCRIPTION = "Get 1 coin from the bank (anyone's turn)";
const string BAKERY_DESCRIPTION = "Get 1 coin from the bank (your turn only)";
const string CAFE_DESCRIPTION = "Take 1 coin from the active player (opponent's turn)";
const string CONVENIENCE_STORE_DESCRIPTION = "Get 3 coins from the bank (your turn only)";
const string FOREST_DESCRIPTION = "Get 1 coin from the bank (on anyone's turn)";
const string STADIUM_DESCRIPTION = "Get 2 coins from all players (on your turn only)";
const string TV_STATION_DESCRIPTION = "Take 5 coins from any one player (on your turn only)";
const string BUSINESS_CENTER_DESCRIPTION = "Trade one non 'tower' establishment with another player (on your turn only)";
const string CHEESE_FACTORY_DESCRIPTION = "Get 3 coins from the bank for each 'cow' establishment that you own (on your turn only)";
const string FURNITURE_FACTORY_DESCRIPTION = "Get 3 coins from the bank for each 'gear' establishment that you own (on your turn only)";
const string MINE_DESCRIPTION = "Get 5 coins from the bank, (on anyone's turn)";
const string FAMILY_RESTAURANT_DESCRIPTION = "Get 2 coins from the player who rolled the dice";
const string APPLE_ORCHARD_DESCRIPTION = "Get 3 coins from the bank (on anyone's turn)";
const string FARMERS_MARKET_DESCRIPTION = "Get 2 coins from the bank for each 'wheat' establishment that you own (on your turn only)";


//港口拓展卡包描述
const string FLOWER_FIELD_DESCRIPTION = "Get 1 coin from the bank (anyone's turn)";
const string MACKEREL_FISHBOAT_DESCRIPTION = "Get 3 coin from the bank (anyone's turn) if you have port";
const string TUNA_FISHBOAT_DESCRIPTION = "everyone with tuna fishboat get Sum of dice coins form the bank(on your turn only)";
const string FLOWER_SHOP_DESCRIPTION = "Get 1 coin from the bank (on anyone's turn)";
const string FOOD_MARKET_DESCRIPTION = "Get 2 coins from the bank for each 'flower field' establishment that you own (on your turn only)";
const string PUBLISHER_DESCRIPTION = "Take 1 coin for each 'flower field' and 'cafe' from from all players (on your turn only)";
const string TAX_OFFICE_DESCRIPTION = "Take half of the coin from the player who owns coins above 10(on your turn only)";
const string BURGER_SHOP_DESCRIPTION = "Take 1 coin from the player who roll the 8(opponent's turn)";
const string PIZZA_SHOP_DESCRIPTION = "Take 1 coin from the player who roll the 7(opponent's turn)";
const string SUSHI_SHOP_DESCRIPTION = "Take 3 coin from the player who roll the 1(opponent's turn)";

//价格
const int WHEAT_FIELD_COST = 1;
const int RANCH_COST = 1;
const int BAKERY_COST = 1;
const int CAFE_COST = 2;
const int CONVENIENCE_STORE_COST = 2;
const int FOREST_COST = 3;
const int STADIUM_COST = 6;
const int TV_STATION_COST = 7;
const int BUSINESS_CENTER_COST = 8;
const int CHEESE_FACTORY_COST = 5;
const int FURNITURE_FACTORY_COST = 3;
const int MINE_COST = 6;
const int FAMILY_RESTAURANT_COST = 3;
const int APPLE_ORCHARD_COST = 3;
const int FARMERS_MARKET_COST = 2;


//港口拓展卡包价格
const int FLOWER_FIELD_COST = 2;
const int MACKEREL_FISHBOAT_COST = 2;
const int TUNA_FISHBOAT_COST = 5;
const int FLOWER_SHOP_COST = 1;
const int FOOD_MARKET_COST = 2;
const int PUBLISHER_COST = 5;
const int TAX_OFFICE_COST = 4;
const int BURGER_SHOP_COST = 1;
const int PIZZA_SHOP_COST = 1;
const int SUSHI_SHOP_COST = 2;


//地标建筑价格
const int TRAIN_STATION_COST = 4;
const int SHOPPING_MALL_COST = 10;
const int AMUSEMENT_PARK_COST = 16;
const int RADIO_TOWER_COST = 22;

const int PORT_COST = 2;
const int AIRPORT_COST = 30;
const int TOWN_HALL_COST = 0;


#endif //UNTITLED1_CONSTANT_1_0_H
