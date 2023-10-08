//
// Created by zy20200721 on 2022/10/15.
//

#ifndef UNTITLED1_PLAYER_1_0_H
#define UNTITLED1_PLAYER_1_0_H

#ifndef CARD_1_0_H
#define CARD_1_0_H

class Card;

#include <iostream>
#include "Card_1.0.h"
#include <vector>
#include <cstdlib>
#include <ctime>
//#include "Card_2.0.h"
//#include "Constant.h"
using namespace std;


class Player {
public:
    // Constructors
    /*------------------------------------------------------------------------------------------------*/
    Player() = default;

    Player(string _ID, bool _isHuman) : ID(_ID), isHuman(_isHuman) {}

    Player(const Player &_oldPlayer) = default;

    Player &operator=(const Player &_oldPlayer) = default;

    ~Player() {};

    //接口
    /*---------------------------------------------------------------------------*/

    virtual bool checkWinner() const = 0;

    virtual string buyLandmark(int landmark_num) = 0;

    virtual int get_Landmark_Number() = 0;


    // Getters
    /*------------------------------------------------------------------------------------------------*/
    bool getIsHuman() const { return isHuman; }

    string getID() const { return ID; }

    int getMoney() const { return money; }

    bool getTrainStationBool() const { return trainStation; }

    bool getShoppingMallBool() const { return shoppingMall; }

    bool getAmusementParkBool() const { return amusementPark; }

    bool getRadioTowerBool() const { return radioTower; }

    //Setters
    /*------------------------------------------------------------------------------------------------*/
    void setHuman() { isHuman = true; }

    void setID(string _ID) { ID = _ID; }

    void setMoney(int _money) { money = _money; }

    void setTrainStationBool(bool _trainStation) { trainStation = _trainStation; }

    void setShoppingMallBool(bool _shoppingMall) { shoppingMall = _shoppingMall; }

    void setAmusementParkBool(bool _amusementPark) { amusementPark = _amusementPark; }

    void setRadioTowerBool(bool _radioTower) { radioTower = _radioTower; }

    //Methods
    /*------------------------------------------------------------------------------------------------*/

    void addEstablishment(const Card &c);

    int getEstablishment_Num(string cardName);

    int getSymbol_Number(int symbol);

    void removeCard(string removeName);

    const Card *getCard(string card_name);

    void addMoney(int roll, Player *p);

    void buyEstablishment(const Card &c);

    virtual void settleAccount(int roll, Player &p1_roll, Player &p2);

    void purpleCardfunction(PlayerNode &p, int roll);

    bool rollRange(int roll, vector<const Card *>::iterator it);


    int roll();

    virtual void buy_card(string card_name, const Card *card) {}

    virtual void landmark_before_roll() {}

    virtual int landmark_after_roll(int dice) { return 0; };

    virtual void landmark_before_buy() {};

    virtual void landmark_after_buy(string s) {};

protected:

    bool isHuman = false;
    string ID;
    int money = 3;//起始资产为3 , test
    bool trainStation = false;
    bool shoppingMall = false;
    bool amusementPark = false;
    bool radioTower = false;

    vector<const Card *> establishments;

};

class Player_Basic : public Player {
public:
    Player_Basic(string _ID, bool _isHuman) : Player(_ID, _isHuman) {}

    virtual bool checkWinner() const;

    virtual string buyLandmark(int landmark_num);

    virtual int get_Landmark_Number() override { return trainStation + shoppingMall + amusementPark + radioTower; };

};

class People_Basic : public Player_Basic {
public:
    People_Basic(string _ID, bool _isHuman) : Player_Basic(_ID, _isHuman) {}

    void buy_card(string card_name, const Card *card) override {
        buyEstablishment(*card);
        cout << "# You buy " << card_name << endl;
        cout << "*Please enter 'ok' to continue:";
        string temp_str;
        cin >> temp_str;
    }

};

class Robot_Basic : public Player_Basic {
public:
    Robot_Basic(string _ID, bool _isHuman) : Player_Basic(_ID, _isHuman) {}

    void buy_card(string card_name, const Card *card) override {
        buyEstablishment(*card);
        cout << "# " << ID << " buy " << card_name << endl;

    }
};


class Player_Port : public Player {
public:
    Player_Port(string _ID, bool _isHuman) : Player(_ID, _isHuman) {}

    //getters
    bool getPortBool() const { return port; }

    bool getAirportBool() const { return airport; }

    bool getTown_hallBool() const { return town_hall; }

    //setters
    void setPortBool(bool b) { port = b; }

    void setAirportBool(bool b) { airport = b; }

    void setTown_hallBool(bool b) { town_hall = b; }

    //methods
    virtual bool checkWinner() const {
        return trainStation && shoppingMall && amusementPark && radioTower && port && airport && town_hall;
    }

    virtual string buyLandmark(int landmark_num);

    virtual int get_Landmark_Number() override {
        return trainStation + shoppingMall + amusementPark + radioTower + port + airport + town_hall;
    };


    virtual int landmark_after_roll(int dice) override;//港口功能

    virtual void landmark_before_buy() override { if (money == 0){cout <<"#You have no money but you have town_hall(landmark) " << endl; money += 1;} };//市政厅功能

    void settleAccount(int roll, Player &p1_roll, Player &p2) override ;

    virtual void landmark_after_buy(string s) {
        if (s=="nothing"&&airport){
            cout <<"#You buy nothing but you have airport(landmark) ,you can get 10 money" << endl<< endl<< endl;
            money += 10;
        }
    };//飞机场功能

protected:
    bool port = false;
    bool airport = false;
    bool town_hall = true;
};

class People_Port : public Player_Port {
public:
    People_Port(string _ID, bool _isHuman) : Player_Port(_ID, _isHuman) {}

    void buy_card(string card_name, const Card *card) override {
        buyEstablishment(*card);
        cout << "# You buy " << card_name << endl;
        cout << "*Please enter 'ok' to continue:";
        string temp_str;
        cin >> temp_str;
    }

};

class Robot_Port : public Player_Port {
public:
    Robot_Port(string _ID, bool _isHuman) : Player_Port(_ID, _isHuman) {}

    void buy_card(string card_name, const Card *card) override {
        buyEstablishment(*card);
        cout << "# " << ID << " buy " << card_name << endl;

    }
};

#endif //CARD_1_0_H

#endif //UNTITLED1_PLAYER_1_0_H
