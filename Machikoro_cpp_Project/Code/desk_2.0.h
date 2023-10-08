//
// Created by Administrator on 2022/11/21.
//

#ifndef CPP_PROJECT_DESK_2_0_H
#define CPP_PROJECT_DESK_2_0_H
#include "Player.h"
#include <iostream>
#include"string"
#include <iomanip>
#include "Card_2.0.h"
#include "desk_1.0.h"
#include "vector"

using namespace std;

//forward declaration 前置声明, 解决了很多报错
class Game_Port;

class Card;

class Desk_Basic;

class Desk_Port: public Desk_Basic {
public:

    //constructor
    /*------------------------------------------------------------------------------------------------*/
    Desk_Port() = default;

    //Method
    /*------------------------------------------------------------------------------------------------*/
    void setDesk(Player **pp1,  Game_Basic *g1);

    void all();
    string back(int m);
    int back_cost(int m);
    void start(Player *p);

    void shop(Player *p);

    const Card *remove_deskcard(string s);


};
#endif //CPP_PROJECT_DESK_2_0_H
