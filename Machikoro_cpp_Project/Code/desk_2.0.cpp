//
// Created by Administrator on 2022/11/21.
//
#include "desk_2.0.h"
string Desk_Port::back(int m) {
    if (m == 1) { return WHEAT_FIELD_NAME; }
    if (m == 2) { return RANCH_NAME; }
    if (m == 3) { return BAKERY_NAME; }
    if (m == 4) { return CAFE_NAME; }
    if (m == 5) { return CONVENIENCE_STORE_NAME; }
    if (m == 6) { return FOREST_NAME; }
    if (m == 7) { return STADIUM_NAME; }
    if (m == 8) { return TV_STATION_NAME; }
    if (m == 9) { return BUSINESS_CENTER_NAME; }
    if (m == 10) { return CHEESE_FACTORY_NAME; }
    if (m == 11) { return FURNITURE_FACTORY_NAME; }
    if (m == 12) { return MINE_NAME; }
    if (m == 13) { return FAMILY_RESTAURANT_NAME; }
    if (m == 14) { return APPLE_ORCHARD_NAME; }
    if (m == 15) { return FARMERS_MARKET_NAME; }
    if (m == 16) { return FLOWER_FIELD_NAME; }
    if (m == 17) { return MACKEREL_FISHBOAT_NAME; }
    if (m == 18) { return TUNA_FISHBOAT_NAME; }
    if (m == 19) { return FLOWER_SHOP_NAME; }
    if (m == 20) { return FOOD_MARKET_NAME; }
    if (m == 21) { return PUBLISHER_NAME; }
    if (m == 22) { return TAX_OFFICE_NAME; }
    if (m == 23) { return BURGER_SHOP_NAME; }
    if (m == 24) { return PIZZA_SHOP_NAME; }
    if (m == 25) { return SUSHI_SHOP_NAME; }
    if (m == 26) { return "landmark"; }
    if (m == 27) { return "landmark"; }
    if (m == 28) { return "landmark"; }
    if (m == 29) { return "landmark"; }
    if (m == 30) { return "landmark"; }
    if (m == 31) { return "landmark"; }
    if(m==32) { return "landmark"; }
    else {return "wrong desk back num";}

}

int Desk_Port::back_cost(int m) {
    if (m == 1) { return WHEAT_FIELD_COST; }
    if (m == 2) { return RANCH_COST; }
    if (m == 3) { return BAKERY_COST; }
    if (m == 4) { return CAFE_COST; }
    if (m == 5) { return CONVENIENCE_STORE_COST; }
    if (m == 6) { return FOREST_COST; }
    if (m == 7) { return STADIUM_COST; }
    if (m == 8) { return TV_STATION_COST; }
    if (m == 9) { return BUSINESS_CENTER_COST; }
    if (m == 10) { return CHEESE_FACTORY_COST; }
    if (m == 11) { return FURNITURE_FACTORY_COST; }
    if (m == 12) { return MINE_COST; }
    if (m == 13) { return FAMILY_RESTAURANT_COST; }
    if (m == 14) { return APPLE_ORCHARD_COST; }
    if (m == 15) { return FARMERS_MARKET_COST; }
    if (m == 16) { return FLOWER_FIELD_COST; }
    if (m == 17) { return MACKEREL_FISHBOAT_COST; }
    if (m == 18) { return TUNA_FISHBOAT_COST; }
    if (m == 19) { return FLOWER_SHOP_COST; }
    if (m == 20) { return FOOD_MARKET_COST; }
    if (m == 21) { return PUBLISHER_COST; }
    if (m == 22) { return TAX_OFFICE_COST; }
    if (m == 23) { return BURGER_SHOP_COST; }
    else { return PIZZA_SHOP_COST; }

}

void Desk_Port::setDesk(Player **pp1, Game_Basic *g1) {

    Game_Port* g2 = dynamic_cast<Game_Port*>(g1);

    Desk_Basic::setDesk(reinterpret_cast<Player **>(pp1), g1); //基础班卡牌

    for (int i = 0; i < 6; i++) {
        desk.push_back(&g2->getflowerField(i));
        desk.push_back(&g2->getmackerelFishboat(i));
        desk.push_back(&g2->gettunaFishboat(i));
        desk.push_back(&g2->getburgerShop(i));
        desk.push_back(&g2->getflowerShop(i));
        desk.push_back(&g2->getfoodMarket(i));
        desk.push_back(&g2->getpizzaShop(i));
        desk.push_back(&g2->getsushiShop(i));
    }
    for (int i = 0; i < 4; i++) {
        desk.push_back(&g2->gettaxOffice(i));
        desk.push_back(&g2->getpublisher(i));
    }
}

void Desk_Port::start(Player *p) { //港口版本打印玩家信息

    Player_Port *pp = dynamic_cast<Player_Port*>(p);
    cout << "+-----------------+-----------------+" << endl;
    cout << left;
    cout << '|' << "player:  " << setw(8) << pp->getID() << "|" << "money:  " << setw(9) << pp->getMoney() << "|" << endl;
    cout << "+-----------------+-----------------+" << endl;
    cout << '|' << setw(16) << "trainStation:" << pp->getTrainStationBool() << "|" << setw(16) << "shoppingMall:"
         << pp->getShoppingMallBool() << "|" << endl;
    cout << "+-----------------+-----------------+" << endl;
    cout << '|' << setw(16) << "amusementPark:" << pp->getAmusementParkBool() << "|" << setw(16) << "radioTower:"
         << pp->getRadioTowerBool() << "|" << endl;
    cout << "+-----------------+-----------------+" << endl;
    cout << '|' << setw(16) << "port:" << pp->getPortBool() << "|" << setw(16) << "airport:"
         << pp->getAirportBool() << "|" << endl;
    cout << "+-----------------+-----------------+" << endl;
    cout << '|' << setw(16) << "town_hall:" << pp->getTown_hallBool() << " " << setw(16) << "   "
         << " "<< "|" << endl;
    cout << "+-----------------+-----------------+" << endl;
    cout << setw(36) << "|              card" << "|" << endl;
    for (int i = 1; i < 26; i++) {
        if (pp->getEstablishment_Num(back(i)) > 0) {
            cout << "|" << setw(28) << back(i) << ":" << pp->getEstablishment_Num(back(i)) << "     |" << endl;
        }
    }
    cout << "+***********************************+" << endl;


}

void Desk_Port::all() {
    start(l1);
    start(l2);
    start(l3);
    start(l4);
}

void Desk_Port::shop(Player *p) {

    Player_Port* pp = dynamic_cast<Player_Port*>(p);
    cout << "|    Establishments You Can Buy:    |" << endl;
    cout << "+ID--------------------Nb-------Cost+" << endl;

    for (int i = 1; i < 26; i++) {
        int number = 0;
        if (i==16) {
            cout << "+-------Port Extended Version:------+" << endl;
        }
        for (auto itbegin = desk.begin(); itbegin != desk.end(); itbegin++) {
            if ((*itbegin)->getName() == back(i)) {
                number++;
            }
        }
        cout << left;
        cout << "|" << setw(3) << i << setw(17) << back(i) << "  " << number << setw(12) << right << back_cost(i) << "|"
             << endl;;
    }
    cout << "+-------------Landmarks:------------+" << endl;
    cout << left;
    cout << "|" << setw(3) << 26 << setw(17) << "Train Station" << "  " << 1 - pp->getTrainStationBool() << setw(12)
         << right << TRAIN_STATION_COST << "|"
         << endl;
    cout << left;
    cout << "|" << setw(3) << 27<< setw(17) << "Shopping Mall" << "  " << 1 - pp->getShoppingMallBool() << setw(12)
         << right << SHOPPING_MALL_COST << "|"
         << endl;
    cout << left;
    cout << "|" << setw(3) << 28<< setw(17) << "Amusement Park" << "  " << 1 - pp->getAmusementParkBool() << setw(12)
         << right << AMUSEMENT_PARK_COST << "|"
         << endl;
    cout << left;
    cout << "|" << setw(3) << 29 << setw(17) << "Radio Tower" << "  " << 1 - pp->getRadioTowerBool() << setw(12) << right
         << RADIO_TOWER_COST << "|"
         << endl;
    cout << left;
    cout << "|" << setw(3) << 30<< setw(17) <<"Port" << "  " << 1 - pp->getPortBool() << setw(12) << right
         << PORT_COST << "|"
         << endl;
    cout << left;
    cout << "|" << setw(3) << 31 << setw(17) <<"Airport" << "  " << 1 - pp->getAirportBool() << setw(12) << right
         << AIRPORT_COST << "|"
         << endl;
    cout << left;
    cout << "|" << setw(3) << 32<< setw(17) << "Town_hall" << "  " << 1 - pp->getTown_hallBool() << setw(12) << right
         << TOWN_HALL_COST << "|"
         << endl;
    cout << "+-----------------------------------+" << endl << endl << endl;
}

const Card *Desk_Port::remove_deskcard(string s) {
    const Card *tmp = nullptr;

    int i = 0;
    for (auto it = desk.begin(); it != desk.end(); it++) {
        if ((*it)->getName() == s) {
            tmp = *it;
            desk.erase(it);
            return tmp;
        }
    }
    return tmp;
}
