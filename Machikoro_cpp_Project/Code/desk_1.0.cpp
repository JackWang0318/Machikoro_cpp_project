//
// Created by 86182 on 2022/10/18.
//

#include "desk_1.0.h"


string Desk_Basic::back(int m) {
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
    if (m == 16) { return "landmark"; }
    if (m == 17) { return "landmark"; }
    if (m == 18) { return "landmark"; }
    if (m == 19) { return "landmark"; }
    else {return "wrong desk back num";}

}

int Desk_Basic::back_cost(int m) {
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
    else { return FARMERS_MARKET_COST; }

}


void Desk_Basic::setDesk(Player **pp1, Game_Basic *g1) {
    l1 = *pp1;
    l2 = *(pp1 + 1);
    l3 = *(pp1 + 2);
    l4 = *(pp1 + 3);
    for (int i = 0; i < 6; i++) {
        desk.push_back(&g1->getwheatfield(i));
        desk.push_back(&g1->getranch(i));
        desk.push_back(&g1->getbakeryfield(i));
        desk.push_back(&g1->getcafe(i));
        desk.push_back(&g1->getconveniencestore(i));
        desk.push_back(&g1->getforest(i));
        desk.push_back(&g1->getcheesefactory(i));
        desk.push_back(&g1->getfurniturefactoryfield(i));
        desk.push_back(&g1->getmine(i));
        desk.push_back(&g1->getfamilyrestaurant(i));
        desk.push_back(&g1->getappleorchard(i));
        desk.push_back(&g1->getfarmersmarket(i));
    }
    for (int i = 0; i < 4; i++) {
        desk.push_back(&g1->getstadiumfield(i));
        desk.push_back(&g1->gettvstation(i));
        desk.push_back(&g1->getbusinesscenter(i));
    }

}

void Desk_Basic::start(Player *p) {

    cout << "+-----------------+-----------------+" << endl;
    cout << left;
    cout << '|' << "player:  " << setw(8) << p->getID() << "|" << "money:  " << setw(9) << p->getMoney() << "|" << endl;
    cout << "+-----------------+-----------------+" << endl;
    cout << '|' << setw(16) << "trainStation:" << p->getTrainStationBool() << "|" << setw(16) << "shoppingMall:"
         << p->getShoppingMallBool() << "|" << endl;
    cout << "+-----------------+-----------------+" << endl;
    cout << '|' << setw(16) << "amusementPark:" << p->getAmusementParkBool() << "|" << setw(16) << "radioTower:"
         << p->getRadioTowerBool() << "|" << endl;
    cout << "+-----------------+-----------------+" << endl;
    cout << setw(36) << "|              card" << "|" << endl;
    for (int i = 1; i < 16; i++) {
        if (p->getEstablishment_Num(back(i)) > 0) {
            cout << "|" << setw(28) << back(i) << ":" << p->getEstablishment_Num(back(i)) << "     |" << endl;
        }
    }
    cout << "+***********************************+" << endl;


}

void Desk_Basic::all() {
    start(l1);
    start(l2);
    start(l3);
    start(l4);
}

void Desk_Basic::shop(Player *p) {
    cout << "|    Establishments You Can Buy:    |" << endl;
    cout << "+ID--------------------Nb-------Cost+" << endl;

    for (int i = 1; i < 16; i++) {
        int number = 0;
        for (auto itbegin = desk.begin(); itbegin != desk.end(); itbegin++) {
            if ((*itbegin)->getName() == back(i)) {
                number++;
            }
        }
        cout << left;
        cout << "|" << setw(3) << i << setw(17) << back(i) << "  " << number << setw(12) << right << back_cost(i) << "|"
             << endl;;
    }
    cout << left;
    cout << "|" << setw(3) << 16 << setw(17) << "Train Station" << "  " << 1 - p->getTrainStationBool() << setw(12)
         << right << TRAIN_STATION_COST << "|"
         << endl;
    cout << left;
    cout << "|" << setw(3) << 17 << setw(17) << "Shopping Mall" << "  " << 1 - p->getShoppingMallBool() << setw(12)
         << right << SHOPPING_MALL_COST << "|"
         << endl;
    cout << left;
    cout << "|" << setw(3) << 18 << setw(17) << "Amusement Park" << "  " << 1 - p->getAmusementParkBool() << setw(12)
         << right << AMUSEMENT_PARK_COST << "|"
         << endl;
    cout << left;
    cout << "|" << setw(3) << 19 << setw(17) << "Radio Tower" << "  " << 1 - p->getRadioTowerBool() << setw(12) << right
         << RADIO_TOWER_COST << "|"
         << endl;

    cout << "+-----------------------------------+" << endl << endl << endl;
}

const Card *Desk_Basic::remove_deskcard(string s) {
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