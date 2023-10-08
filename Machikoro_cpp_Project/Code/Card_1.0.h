//card部分未完任务:地标建筑，特殊建筑的function未设置


#ifndef UNTITLED1_CARD_1_0_H
#define UNTITLED1_CARD_1_0_H

#ifndef PLAYER_1_0_H
#define PLAYER_1_0_H

class Player;

struct PlayerNode {
    Player *player_ptr;
    PlayerNode *nextPlayer;
};

#include <iostream>
#include <vector>
#include<string>
#include "Player.h"
#include "Constant.h"
#include "version.h"


using namespace std;


class Card {
public:
    struct Range {
        int min;
        int max;
    };
    //Constructor
    /*------------------------------------------------------------------------------------------------*/
    Card(int c, const string &n, const string &d, Range r, Color _color, Symbol s, Type t) :
            cost(c), name(n), description(d), range(r), color(_color), symbol(s), type(t) {}

    Card(int c, const string &n, const string &d, Color _color, Symbol s, Type t) :
            cost(c), name(n), description(d), color(_color), symbol(s), type(t) {}

    Card() {};

    ~Card() {};

    //Getters
    /*------------------------------------------------------------------------------------------------*/
    int getCost() const { return cost; }

    string getDescription() const { return description; }

    string getName() const { return name; }

    Range getRange() const { return range; }

    Color getColor() const { return color; }

    Symbol getSymbol() const { return symbol; }

    Type getType() const { return type; }


    //setters
    /*------------------------------------------------------------------------------------------------*/
    void setDescription(string _description) { description = _description; }

    void setCost(int _cost) { cost = _cost; }

    void setRange(Range newRange) {
        setrangeMin(newRange.min);
        setrangeMax(newRange.max);
    }

    void setRange(int _min, int _max) {
        setrangeMin(_min);
        setrangeMax(_max);
    }

    void setrangeMin(int _min) { range.min = _min; }

    void setrangeMax(int _max) { range.max = _max; }

    void setName(string _name) { name = _name; }

    void setCardType(Type _type) { type = _type; }

    void setCardSymbol(Symbol _symbol) { symbol = _symbol; }


    //Methods
    /*------------------------------------------------------------------------------------------------*/
    //蓝卡，商店卡
    virtual int cardFunction(string s) const {
        if (s == WHEAT_FIELD_NAME) { return 1; }
        if (s == RANCH_NAME) { return 1; }
        if (s == BAKERY_NAME) { return 1; }
        if (s == CONVENIENCE_STORE_NAME) { return 3; }
        if (s == FOREST_NAME) { return 1; }
        if (s == MINE_NAME) { return 5; }
        if (s == FLOWER_FIELD_NAME) { return 1; }
        if (s == MACKEREL_FISHBOAT_NAME) { return 3; }
        if (s == APPLE_ORCHARD_NAME) { return 3; }
        else {
            cout << "wrong card function";
            return 0;
        }
    };

    //红卡
    virtual int cardFunction(string s, Player &playerRoll, Player &p2) const;

    //工厂类卡
    virtual int cardFunction(string s, int symbolAmount) const {
        if (s == CHEESE_FACTORY_NAME) { return 3 * symbolAmount; }
        if (s == FURNITURE_FACTORY_NAME) { return 3 * symbolAmount; }
        if (s == FOOD_MARKET_NAME) { return 2 * symbolAmount; }
        if (s == FARMERS_MARKET_NAME) { return 2 * symbolAmount; }
        else {
            cout << "wrong card function";
            return 0;
        }
    }

    //紫卡
    virtual void functionPurple(PlayerNode &) const {};


private:

    int cost;//cost 价格
    string name;//name 名字 “string  ”
    string description;//description 描述  “  从某某那拿多少钱 ”
    Range range;//activation 骰子触发范围 range(min,max)
    Color color;//color or type 颜色 建筑类型 （）
    Symbol symbol;//symbol  符号
    Type type;//类型
};


//子类
/*------------------------------------------------------------------------------------------------*/
class WheatField : public Card {
public:
    WheatField(int c = WHEAT_FIELD_COST, const string &n = WHEAT_FIELD_NAME, const string &d = WHEAT_FIELD_DESCRIPTION,
               Range r = {1, 1}, Color _color = Color::blue, Symbol s = Symbol::wheat,
               Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};
private:

};


class Ranch : public Card {
public:
    Ranch(int c = RANCH_COST, const string &n = RANCH_NAME, const string &d = RANCH_DESCRIPTION,
          Range r = {2, 2}, Color _color = Color::blue, Symbol s = Symbol::animal,
          Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};

private:

};


class Bakery : public Card {
public:
    Bakery(int c = BAKERY_COST, const string &n = BAKERY_NAME, const string &d = BAKERY_DESCRIPTION,
           Range r = {2, 3}, Color _color = Color::green, Symbol s = Symbol::shop,
           Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};

private:


};


class Cafe : public Card {
public:
    Cafe(int c = CAFE_COST, const string &n = CAFE_NAME, const string &d = CAFE_DESCRIPTION,
         Range r = {3, 3}, Color _color = Color::red, Symbol s = Symbol::food, Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};

    int cardFunction(Player &playerRoll, Player &p2);

private:


};

class ConvenienceStore : public Card {
public:
    ConvenienceStore(int c = CONVENIENCE_STORE_COST, const string &n = CONVENIENCE_STORE_NAME,
                     const string &d = CONVENIENCE_STORE_DESCRIPTION,
                     Range r = {4, 4}, Color _color = Color::green, Symbol s = Symbol::shop,
                     Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};

private:

};


class Forest : public Card {
public:
    Forest(int c = FOREST_COST, const string &n = FOREST_NAME, const string &d = FOREST_DESCRIPTION,
           Range r = {5, 5}, Color _color = Color::blue, Symbol s = Symbol::gear, Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};

private:

};


class Stadium : public Card {
public:
    Stadium(int c = STADIUM_COST, const string &n = STADIUM_NAME, const string &d = STADIUM_DESCRIPTION,
            Range r = {6, 6}, Color _color = Color::purple, Symbol s = Symbol::tower, Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};

    void functionPurple(PlayerNode &) const;

private:

};


class TVStation : public Card {
public:
    TVStation(int c = TV_STATION_COST, const string &n = TV_STATION_NAME, const string &d = TV_STATION_DESCRIPTION,
              Range r = {6, 6}, Color _color = Color::purple, Symbol s = Symbol::tower,
              Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};

    void functionPurple(PlayerNode &) const;

private:

};


class BusinessCenter : public Card {
public:
    BusinessCenter(int c = BUSINESS_CENTER_COST, const string &n = BUSINESS_CENTER_NAME,
                   const string &d = BUSINESS_CENTER_DESCRIPTION,
                   Range r = {6, 6}, Color _color = Color::purple, Symbol s = Symbol::tower,
                   Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};
private:
    void functionPurple(PlayerNode &) const;
};


class CheeseFactory : public Card {
public:
    CheeseFactory(int c = CHEESE_FACTORY_COST, const string &n = CHEESE_FACTORY_NAME,
                  const string &d = CHEESE_FACTORY_DESCRIPTION,
                  Range r = {7, 7}, Color _color = Color::green, Symbol s = Symbol::animal,
                  Type t = Type::factory)
            : Card(c, n, d,/*r,*/_color, s, t) {};

    int cardFunction(int symbolAmount);

private:

};


class FurnitureFactory : public Card {
public:
    FurnitureFactory(int c = FURNITURE_FACTORY_COST, const string &n = FURNITURE_FACTORY_NAME,
                     const string &d = FURNITURE_FACTORY_DESCRIPTION,
                     Range r = {8, 8}, Color _color = Color::green, Symbol s = Symbol::gear,
                     Type t = Type::factory)
            : Card(c, n, d, r, _color, s, t) {};

    int cardFunction(int symbolAmount);

private:


};


class Mine : public Card {
public:
    Mine(int c = MINE_COST, const string &n = MINE_NAME, const string &d = MINE_DESCRIPTION,
         Range r = {9, 9}, Color _color = Color::blue, Symbol s = Symbol::gear,
         Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};

private:

};


class FamilyRestaurant : public Card {
public:
    FamilyRestaurant(int c = FAMILY_RESTAURANT_COST, const string &n = FAMILY_RESTAURANT_NAME,
                     const string &d = FAMILY_RESTAURANT_DESCRIPTION,
                     Range r = {9, 10}, Color _color = Color::red, Symbol s = Symbol::food,
                     Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};

    int cardFunction(Player &playerRoll, Player &p2);

private:


};


class AppleOrchard : public Card {
public:
    AppleOrchard(int c = APPLE_ORCHARD_COST, const string &n = APPLE_ORCHARD_NAME,
                 const string &d = APPLE_ORCHARD_DESCRIPTION,
                 Range r = {10, 10}, Color _color = Color::blue, Symbol s = Symbol::wheat,
                 Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};


private:


};


class FarmersMarket : public Card {
public:
    FarmersMarket(int c = FARMERS_MARKET_COST, const string &n = FARMERS_MARKET_NAME,
                  const string &d = FARMERS_MARKET_DESCRIPTION,
                  Range r = {11, 12}, Color _color = Color::green, Symbol s = Symbol::wheat,
                  Type t = Type::factory)
            : Card(c, n, d, r, _color, s, t) {};

    int cardFunction(int symbolAmount);

private:


};


//Game类
/*------------------------------------------------------------------------------------------------*/
class Game_Basic {
public:

    //Getters
    /*------------------------------------------------------------------------------------------------*/

    virtual const Card &getwheatfield(int i) const { return *wheatfieldcards[i]; }

    virtual const Card &getranch(int i) const { return *ranchcards[i]; }

    virtual const Card &getbakeryfield(int i) const { return *bakerycards[i]; }

    virtual const Card &getcafe(int i) const { return *cafecards[i]; }

    virtual const Card &getconveniencestore(int i) const { return *conveniencestorecards[i]; }

    virtual const Card &getstadiumfield(int i) const { return *stadiumcards[i]; }

    virtual const Card &gettvstation(int i) const { return *tvstationcards[i]; }

    virtual const Card &getbusinesscenter(int i) const { return *businesscentercards[i]; }

    virtual const Card &getfurniturefactoryfield(int i) const { return *furniturefactorycards[i]; }

    virtual const Card &getappleorchard(int i) const { return *appleorchardcards[i]; }

    virtual const Card &getcheesefactory(int i) const { return *cheesefactorycards[i]; }

    virtual const Card &getfarmersmarket(int i) const { return *farmersmarketcards[i]; }

    virtual const Card &getforest(int i) const { return *forestcards[i]; }

    virtual const Card &getmine(int i) const { return *minecards[i]; }

    virtual const Card &getfamilyrestaurant(int i) const { return *familyrestaurantcards[i]; }

    //Methods
    /*------------------------------------------------------------------------------------------------*/
    virtual void setcards();//初始化所有成员

    //单例设计模式
    /*------------------------------------------------------------------------------------------------*/
//    static Game_Basic &getInstance() {
//        if (handler.instance == nullptr)
//            handler.instance = new Game_Basic();
//        return *handler.instance;
//    }
//
//    static void libererInstance() {
//        delete handler.instance;
//        handler.instance = nullptr;
//    }


//protected:

    //单例设计模式
    /*------------------------------------------------------------------------------------------------*/
    Game_Basic() {};

    ~Game_Basic() {};
//
//    Game_Basic(const Game_Basic &g) = delete;
//
//    Game_Basic &operator=(const Game_Basic &g) = delete;
//
//    class Handler {
//    public:
//        Game_Basic *instance;
//
//        Handler() : instance(nullptr) {}
//
//        ~Handler() {
//            delete instance;
//            instance = nullptr;
//        }
//    };
//
//    static Handler handler;

    //成员变量
    /*------------------------------------------------------------------------------------------------*/
    const WheatField *wheatfieldcards[6];
    const Ranch *ranchcards[6];
    const Bakery *bakerycards[6];
    const Cafe *cafecards[6];
    const ConvenienceStore *conveniencestorecards[6];
    const Stadium *stadiumcards[4];
    const TVStation *tvstationcards[4];
    const BusinessCenter *businesscentercards[4];
    const FurnitureFactory *furniturefactorycards[6];
    const Mine *minecards[6];
    const FamilyRestaurant *familyrestaurantcards[6];
    const AppleOrchard *appleorchardcards[6];
    const CheeseFactory *cheesefactorycards[6];
    const FarmersMarket *farmersmarketcards[6];
    const Forest *forestcards[6];
};


#endif //PLAYER_1_0_H

#endif //UNTITLED1_CARD_1_0_H