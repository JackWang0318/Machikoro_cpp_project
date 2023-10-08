//任务：桌面card容器的打印（名字，数量）与删除，与player交互（player从desk选卡，存入play，移出desk）


#ifndef CPP_PROJECT_DESK_1_0_H
#define CPP_PROJECT_DESK_1_0_H


#include "Player.h"
#include <iostream>
#include"string"
#include <iomanip>
#include "Card_1.0.h"
#include "vector"

using namespace std;

//forward declaration 前置声明, 解决了很多报错
class Game_Basic;

class Card;

class Desk_Basic {
public:

    //constructor
    /*------------------------------------------------------------------------------------------------*/
    Desk_Basic() = default;

    //Method
    /*------------------------------------------------------------------------------------------------*/
    virtual void setDesk(Player **pp1,  Game_Basic *g1);

    void all();

    virtual void start(Player *p);

    virtual void shop(Player *p);

    virtual string back(int m);//里面放着数组名字；

    virtual int back_cost(int m);//存放cost

    const Card *remove_deskcard(string s);

    vector<const Card *> desk;
protected:

    Player *l1;
    Player *l2;
    Player *l3;
    Player *l4;

};


#endif //CPP_PROJECT_DESK_1_0_H
