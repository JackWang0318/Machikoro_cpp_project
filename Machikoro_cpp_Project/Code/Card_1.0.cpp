//
// Created by 86182 on 2022/10/17.
//
#include <iostream>
#include "Constant.h"
#include "Card_1.0.h"
#include "desk_1.0.h"

//Game_Basic::Handler Game_Basic::handler;


//cardFunction of shop
int Card::cardFunction(string s, Player &playerRoll, Player &p2) const {
    //设置罚款金额
    int fine;
    if (s == CAFE_NAME) {
        fine = 1;
        //判断是否购买shoppmall
        if (p2.getShoppingMallBool()) ++fine;
    }
    if (s == FAMILY_RESTAURANT_NAME) {
        fine = 2;
        if (p2.getShoppingMallBool()) ++fine;
    }
    Player_Port &p3 = dynamic_cast<Player_Port &>(p2);
    if (s == BURGER_SHOP_NAME) {
        fine = 1;
        if (p2.getShoppingMallBool()) ++fine;
    }
    if (s == PIZZA_SHOP_NAME) {
        fine = 1;
        if (p2.getShoppingMallBool()) ++fine;
    }
    if (s == SUSHI_SHOP_NAME) {
        if (p3.getPortBool()) fine = 3;
    }
    int money = playerRoll.getMoney();
    if (playerRoll.getMoney() < fine) {
        playerRoll.setMoney(0);
        return money;
    } else {
        playerRoll.setMoney(money - fine);
        return fine;
    }

}

void Stadium::functionPurple(PlayerNode &p) const {
    cout << "        # Stadium activated #" << endl;
    cout << "# Each player should give you 2 coins  #" << endl;
    cout << "*    Enter ok to collect your coins    *" << endl;
    string temp;
    cin >> temp;
    PlayerNode *next = p.nextPlayer;
    for (int a = 0; a < 3; a++) {
        if (next->player_ptr->getMoney() < 2) {
            p.player_ptr->setMoney(p.player_ptr->getMoney() + next->player_ptr->getMoney());
            next->player_ptr->setMoney(0);
        } else {
            p.player_ptr->setMoney(p.player_ptr->getMoney() + 2);
            next->player_ptr->setMoney(next->player_ptr->getMoney() - 2);

        }
        next = next->nextPlayer;
    }
}

void TVStation::functionPurple(PlayerNode &p) const {
    cout << "        # TVStation activated #  " << endl;
    cout << "* Choose one player after you to give you 5 coins (enter 1,2,3 )" << endl;
    int i;
    cin >> i;
    PlayerNode *next;
    if (i == 1) {
        next = p.nextPlayer;
    } else if (i == 2) {
        next = p.nextPlayer->nextPlayer;
    } else if (i == 3) {
        next = p.nextPlayer->nextPlayer->nextPlayer;
    }
    //end if
    if (next->player_ptr->getMoney() < 5) {
        p.player_ptr->setMoney(next->player_ptr->getMoney() + p.player_ptr->getMoney());
        next->player_ptr->setMoney(0);
    } else {
        next->player_ptr->setMoney(next->player_ptr->getMoney() - 5);
        p.player_ptr->setMoney(p.player_ptr->getMoney() + 5);
    }
}

void BusinessCenter::functionPurple(PlayerNode &p) const {  //换卡操作
    //选择是否要换卡
    cout << "        # BusinessCenter activated #" << endl;
    cout << "* Do you want to exchange cards? (Enter 1/0 for Yes/No) " << endl;
    int temp;

    cin >> temp;

    if (temp == 1) {
        cout << "* Choose the player after you to exchange (enter 1,2,3 )" << endl;
        int i;
        string j, k;
        cin >> i;
        PlayerNode *next;  // 被选择换的玩家
        if (i == 1) {
            next = p.nextPlayer;
        } else if (i == 2) {
            next = p.nextPlayer->nextPlayer;
        } else if (i == 3) {
            next = p.nextPlayer->nextPlayer->nextPlayer;
        }//end if 下面是交换卡片操作
        cout << "* Choose your card (enter the card ID): ";
        cin >> j;
        string card_name1 = j;
        cout << "* Choose the card you want (enter the card ID): ";
        cin >> k;
        string card_name2 = k;
        const Card *temp1 = p.player_ptr->getCard(card_name1);
        const Card *temp2 = next->player_ptr->getCard(card_name2);

        p.player_ptr->removeCard(card_name1);
        p.player_ptr->addEstablishment(*temp2);  //next的卡给自己
        next->player_ptr->removeCard(card_name2);
        next->player_ptr->addEstablishment(*temp1); //p的卡给next
    } else {
        cout << "#   No Exchanging Cards  # ";

    }


}

//生成卡片
void Game_Basic::setcards() {

    for (int i = 0; i < 6; i++) {
        wheatfieldcards[i] = new WheatField;
        ranchcards[i] = new Ranch;
        bakerycards[i] = new Bakery;
        cafecards[i] = new Cafe;
        conveniencestorecards[i] = new ConvenienceStore;
        forestcards[i] = new Forest;
        cheesefactorycards[i] = new CheeseFactory;
        furniturefactorycards[i] = new FurnitureFactory;
        minecards[i] = new Mine;
        familyrestaurantcards[i] = new FamilyRestaurant;
        appleorchardcards[i] = new AppleOrchard;
        farmersmarketcards[i] = new FarmersMarket;

    }
    for (int i = 0; i < 4; i++) {
        stadiumcards[i] = new Stadium;
        tvstationcards[i] = new TVStation;
        businesscentercards[i] = new BusinessCenter;
    }

}






