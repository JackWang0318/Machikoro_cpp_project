//
// Created by Yoonahhh on 2022/11/20.
//

#include <iostream>
#include "Constant.h"
#include "Card_1.0.h"
#include "Player.h"
#include "desk_1.0.h"
#include "Card_2.0.h"

//Game_Port::Handler Game_Port::handler;


//金枪鱼船







//港口紫卡

//出版社
void Publisher::functionPurple(PlayerNode &p) const {
    cout << "        # Publisher activated #  " << endl;
    cout << "        *Take as many coins as food and shop combined from all other players*  " << endl;
    cout << "*    Enter ok to collect your coins    *" << endl;
    int number;
    string temp;
    cin >> temp;
    PlayerNode *next = p.nextPlayer;
    for (int a = 0; a < 3; a++) {
        number = next->player_ptr->getSymbol_Number(int(Symbol::food)) +
                 next->player_ptr->getSymbol_Number(int(Symbol::shop));
        if (next->player_ptr->getMoney() < number) {
            p.player_ptr->setMoney(p.player_ptr->getMoney() + next->player_ptr->getMoney());
            next->player_ptr->setMoney(0);
        } else {
            p.player_ptr->setMoney(p.player_ptr->getMoney() + number);
            next->player_ptr->setMoney(next->player_ptr->getMoney() - number);

        }
        next = next->nextPlayer;
    }
}

//税务厅
void TaxOffice::functionPurple(PlayerNode &p) const {
    cout << "        # TaxOffice activated #  " << endl;
    cout << "* Choose one player with coins more than 10 to give you half his coins (enter 1,2,3 )" << endl;
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
    if (next->player_ptr->getMoney() > 10) {
        next->player_ptr->setMoney(next->player_ptr->getMoney() / 2);
        p.player_ptr->setMoney(p.player_ptr->getMoney() + next->player_ptr->getMoney() / 2);
    } else { cout << "* you can't take his coin" << endl; }

}


void Game_Port::setcards() {

    Game_Basic::setcards();

    for (int i = 0; i < 6; i++) {
        flowerField[i] = new FlowerField;
        mackerelFishboat[i] = new MackerelFishboat;
        tunaFishboat[i] = new TunaFishboat;
        flowerShop[i] = new FlowerShop;
        foodMarket[i] = new FoodMarket;
        burgerShop[i] = new BurgerShop;
        pizzaShop[i] = new PizzaShop;
        sushiShop[i] = new SushiShop;

    }
    for (int i = 0; i < 4; i++) {
        publisher[i] = new Publisher;
        taxOffice[i] = new TaxOffice;
    }
}


