//
// Created by Yoonahhh on 2022/11/20.
//

#ifndef CPP_PROJECT_CARD_2_0_H
#define CPP_PROJECT_CARD_2_0_H

#include "Card_1.0.h"

class FlowerField : public Card {
public:
    FlowerField(int c = FLOWER_FIELD_COST, const string &n = FLOWER_FIELD_NAME,
                const string &d = FLOWER_FIELD_DESCRIPTION,
                Range r = {4, 4}, Color _color = Color::blue, Symbol s = Symbol::wheat,
                Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};
private:
};

class MackerelFishboat : public Card {
public:
    MackerelFishboat(int c = MACKEREL_FISHBOAT_COST, const string &n = MACKEREL_FISHBOAT_NAME,
                     const string &d = MACKEREL_FISHBOAT_DESCRIPTION,
                     Range r = {8, 8}, Color _color = Color::blue, Symbol s = Symbol::boat,
                     Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};
private:
};

class TunaFishboat : public Card {
public:
    TunaFishboat(int c = TUNA_FISHBOAT_COST, const string &n = TUNA_FISHBOAT_NAME,
                 const string &d = TUNA_FISHBOAT_DESCRIPTION,
                 Range r = {12, 14}, Color _color = Color::blue, Symbol s = Symbol::boat,
                 Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};
private:
    int cardFunction(string s, int dice) const { return dice; }
};

class FlowerShop : public Card {
public:
    FlowerShop(int c = FLOWER_SHOP_COST, const string &n = FLOWER_SHOP_NAME, const string &d = FLOWER_SHOP_DESCRIPTION,
               Range r = {6, 6}, Color _color = Color::green, Symbol s = Symbol::shop,
               Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};
private:
    int cardFunction(string s, int flower_num) const { return flower_num; }
};

class FoodMarket : public Card {
public:
    FoodMarket(int c = FOOD_MARKET_COST, const string &n = FOOD_MARKET_NAME, const string &d = FOOD_MARKET_DESCRIPTION,
               Range r = {12, 13}, Color _color = Color::green, Symbol s = Symbol::food,
               Type t = Type::factory)
            : Card(c, n, d, r, _color, s, t) {};

    int cardFunction(int symbolAmount);

private:
};

class Publisher : public Card {
public:
    Publisher(int c = PUBLISHER_COST, const string &n = PUBLISHER_NAME, const string &d = PUBLISHER_DESCRIPTION,
              Range r = {7, 7}, Color _color = Color::blue, Symbol s = Symbol::tower,
              Type t = Type::special)
            : Card(c, n, d, r, _color, s, t) {};

    void functionPurple(PlayerNode &) const;

private:
};

class TaxOffice : public Card {
public:
    TaxOffice(int c = TAX_OFFICE_COST, const string &n = TAX_OFFICE_NAME, const string &d = TAX_OFFICE_DESCRIPTION,
              Range r = {8, 9}, Color _color = Color::blue, Symbol s = Symbol::tower,
              Type t = Type::special)
            : Card(c, n, d, r, _color, s, t) {};

    void functionPurple(PlayerNode &) const;

private:
};

class BurgerShop : public Card {
public:
    BurgerShop(int c = BURGER_SHOP_COST, const string &n = BURGER_SHOP_NAME, const string &d = BURGER_SHOP_DESCRIPTION,
               Range r = {8, 8}, Color _color = Color::red, Symbol s = Symbol::food,
               Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};

    int cardFunction(string s, Player &playerRoll, Player &p2);

private:
};

class PizzaShop : public Card {
public:
    PizzaShop(int c = PIZZA_SHOP_COST, const string &n = PIZZA_SHOP_NAME, const string &d = PIZZA_SHOP_DESCRIPTION,
              Range r = {7, 7}, Color _color = Color::red, Symbol s = Symbol::food,
              Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};

    int cardFunction(string s, Player &playerRoll, Player &p2);

private:
};

class SushiShop : public Card {
public:
    SushiShop(int c = SUSHI_SHOP_COST, const string &n = SUSHI_SHOP_NAME, const string &d = SUSHI_SHOP_DESCRIPTION,
              Range r = {1, 1}, Color _color = Color::red, Symbol s = Symbol::food,
              Type t = Type::normal)
            : Card(c, n, d, r, _color, s, t) {};

    int cardFunction(string s, Player &playerRoll, Player &p2);

private:
};

class Game_Port : public Game_Basic {

public:

    void setcards();
//
//    static Game_Port &getInstance() {
//        if (handler.instance == nullptr)
//            handler.instance = new Game_Port();
//        return *handler.instance;
//    }
//
//    static void libererInstance() {
//        delete handler.instance;
//        handler.instance = nullptr;
//    }

    const Card &getflowerField(int i) const { return *flowerField[i]; }

    const Card &getmackerelFishboat(int i) const { return *mackerelFishboat[i]; }

    const Card &gettunaFishboat(int i) const { return *tunaFishboat[i]; }

    const Card &getpublisher(int i) const { return *publisher[i]; }

    const Card &getflowerShop(int i) const { return *flowerShop[i]; }

    const Card &getfoodMarket(int i) const { return *foodMarket[i]; }

    const Card &gettaxOffice(int i) const { return *taxOffice[i]; }

    const Card &getburgerShop(int i) const { return *burgerShop[i]; }

    const Card &getpizzaShop(int i) const { return *pizzaShop[i]; }

    const Card &getsushiShop(int i) const { return *sushiShop[i]; }


//protected:

    //单例设计模式
    /*------------------------------------------------------------------------------------------------*/
    Game_Port() {};

    ~Game_Port() {};

//    Game_Port(const Game_Basic &g) = delete;
//
//    Game_Port &operator=(const Game_Basic &g) = delete;
//
//    class Handler {
//    public:
//        Game_Port *instance;
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

protected:

    const FlowerField *flowerField[6];

    const MackerelFishboat *mackerelFishboat[6];

    const TunaFishboat *tunaFishboat[6];

    const Publisher *publisher[4];

    const FlowerShop *flowerShop[6];

    const FoodMarket *foodMarket[6];

    const TaxOffice *taxOffice[4];

    const BurgerShop *burgerShop[6];

    const PizzaShop *pizzaShop[6];

    const SushiShop *sushiShop[6];

};


#endif //CPP_PROJECT_CARD_2_0_H
