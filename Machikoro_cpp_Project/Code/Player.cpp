//
// Created by 86182 on 2022/10/18.
//

#include "Card_1.0.h"

static int DICE_FOR_TUNA_FISHBOAT=0;
//增加建筑
void Player::addEstablishment(const Card &c) {
    int purple_number = getEstablishment_Num(STADIUM_NAME) + getEstablishment_Num(TV_STATION_NAME) +
                        getEstablishment_Num(BUSINESS_CENTER_NAME);
    if (purple_number >= 1 && c.getColor() == Color::purple) {
        cout << "You can not do this" << endl;
    } else {
        establishments.push_back(&c);
    }

    //要增加这张牌能否添加的判断，如果是紫卡只能有一张 if(Card.getType)
}


//获取指定建筑数量
int Player::getEstablishment_Num(string cardName) {
    vector<const Card *>::iterator it;
    int number = 0;
    for (it = establishments.begin(); it != establishments.end(); it++) {
        if ((*it)->getName() == cardName) {
            number++;
        }
    }
    if (cardName == WHEAT_FIELD_NAME || cardName == BAKERY_NAME) number++;//两张基础卡数量加一
    return number;
}

//获取指定类型建筑
int Player::getSymbol_Number(int symbol) {
    vector<const Card *>::iterator it;
    int number = 0;
    for (it = establishments.begin(); it != establishments.end(); it++) {
        if (int((*it)->getSymbol()) == symbol) {
            number++;
        }
    }
    return number;
}

//移除建筑
void Player::removeCard(string removeName) {
    vector<const Card *>::iterator it;
    for (it = establishments.begin(); it != establishments.end(); it++) {
        if ((*it)->getName() == removeName) {
            establishments.erase(it);
            break;
        }
    }
}

//拿卡
const Card *Player::getCard(string card_name) {
    vector<const Card *>::iterator it;
    for (it = establishments.begin(); it != establishments.end(); it++) {
        if ((*it)->getName() == card_name) {
            return *it;
        }
    }
    cout << "# Can't find the Card " << endl;
    return nullptr;
}

//购买建筑,从桌面上拿取牌
void Player::buyEstablishment(const Card &c) {
    int a = 0;
    if (c.getCost() <= money) {
        addEstablishment(c);
        money -= c.getCost();
    } else {
        cout << "You can not buy this card" << endl;
    }
}


//结算
//card部分需要getRange（），cardFunction（）

void Player::settleAccount(int roll, Player &p1_roll, Player &p2) {
    vector<const Card *>::iterator it1;
    int add = 0;
    for (it1 = p2.establishments.begin(); it1 != p2.establishments.end(); it1++) {
        //若当前玩家是掷骰玩家，触发绿卡
        if (&p1_roll == &p2) {
            if ((roll <= (*it1)->getRange().max && (*it1)->getRange().min <= roll) &&
                (*it1)->getColor() == Color::green) {
                //为工厂类卡片时需要与symbol联动
                if ((*it1)->getType() == Type::factory) {
                    int symbol = 0;
                    if ((*it1)->getName() == FARMERS_MARKET_NAME) ++symbol;
                    vector<const Card *>::iterator it2;
                    for (it2 = p2.establishments.begin(); it2 != p2.establishments.end(); it2++) {
                        if ((*it2)->getSymbol() == (*it1)->getSymbol() && (*it2)->getType() != Type::factory) {
                            ++symbol;
                        }
                    }
                    add = add + (*it1)->cardFunction((*it1)->getName(), symbol);
                }//不是工厂类绿卡时，会根据shoppingmall地标状态，改变结算金额
                else {
                    if (p2.getShoppingMallBool() == true) {
                        add = add + (*it1)->cardFunction((*it1)->getName()) + 1;
                    } else {
                        add = add + (*it1)->cardFunction((*it1)->getName());
                    }
                }

            }
        }//若当前玩家不是掷骰玩家，触发红卡
        else {
            if ((roll <= (*it1)->getRange().max && (*it1)->getRange().min <= roll) &&
                (*it1)->getColor() == Color::red) {
                add = add + (*it1)->cardFunction((*it1)->getName(), p1_roll, p2);
            }
        }
        //无论当前玩家是否掷骰玩家，触发蓝卡
        if ((roll <= (*it1)->getRange().max && (*it1)->getRange().min <= roll) &&
            (*it1)->getColor() == Color::blue) {
            add = add + (*it1)->cardFunction((*it1)->getName());
        }
    }
    //起手卡牌单独结算
    if (roll == 1) {
        add++;
    } else if (roll <= 3 && roll >= 2 && &p1_roll == &p2) {
        if (p2.getShoppingMallBool() == true) {
            add += 2;
        } else {
            add++;
        }
    }
    //循环结束，结算
    p2.setMoney(add + p2.money);
}


void Player::purpleCardfunction(PlayerNode &p, int roll) {
    Player *current_p = (p.player_ptr);
    for (auto it = current_p->establishments.begin(); it != current_p->establishments.end(); ++it) {
        if (rollRange(roll, it) && (*it)->getColor() == Color::purple) {
            (*it)->functionPurple(p);
            break;
        }
    }
}

//检测卡片触发范围与骰子点数是否一致
bool Player::rollRange(int roll, vector<const Card *>::iterator it) {
    if (roll <= (*it)->getRange().max && (*it)->getRange().min <= roll) { return true; }
    else { return false; }
}

////playerbasic
//检测胜利者
bool Player_Basic::checkWinner() const {
    return trainStation && shoppingMall && amusementPark && radioTower;
}

string Player_Basic::buyLandmark(int landmark_num) {
    if (landmark_num == 16) {
        setTrainStationBool(true);
        money -= TRAIN_STATION_COST;
        return "Train Station";
    } else if (landmark_num == 17) {
        setShoppingMallBool(true);
        money -= SHOPPING_MALL_COST;
        return "Shopping Mall";
    } else if (landmark_num == 18) {
        setAmusementParkBool(true);
        money -= AMUSEMENT_PARK_COST;
        return "Amusement Park";
    } else if (landmark_num == 19) {
        setRadioTowerBool(true);
        money -= RADIO_TOWER_COST;
        return "Radio Tower";
    } else {
        return "wrong number";
    }
}

////playerport
string Player_Port::buyLandmark(int landmark_num) {
    if (landmark_num == 26) {
        setTrainStationBool(true);
        money -= TRAIN_STATION_COST;
        return "Train Station";
    } else if (landmark_num == 27) {
        setShoppingMallBool(true);
        money -= SHOPPING_MALL_COST;
        return "Shopping Mall";
    } else if (landmark_num == 28) {
        setAmusementParkBool(true);
        money -= AMUSEMENT_PARK_COST;
        return "Amusement Park";
    } else if (landmark_num == 29) {
        setRadioTowerBool(true);
        money -= RADIO_TOWER_COST;
        return "Radio Tower";
    } else if (landmark_num == 30) {
        setPortBool(true);
        money -= PORT_COST;
        return "Port";
    } else if (landmark_num == 31) {
        setAirportBool(true);
        money -= AIRPORT_COST;
        return "Airport";
    } else if (landmark_num == 32) {
        setTown_hallBool(true);
        money -= TOWN_HALL_COST;
        return "Town Hall";
    } else {
        return "wrong number";
    }
}

void Player_Port::settleAccount(int roll, Player &p_roll, Player &p) {
    vector<const Card *>::iterator it1;
    Player_Port &p1_roll = dynamic_cast<Player_Port &>(p_roll);
    Player_Port &p2 = dynamic_cast<Player_Port &>(p);

    int add = 0;
    //金枪鱼船需要色子
//    int dice1;
//    int dice2;
//    srand((unsigned int)time(NULL));
//    dice1 = rand() % 6 + 1;
//    dice2 = rand() % 6 + 1;
//    cout<<"#in Port version, if we have "<<TUNA_FISHBOAT_NAME<<",its dice is "<<dice1+dice2<<endl;
    for (it1 = p2.establishments.begin(); it1 != p2.establishments.end(); it1++) {
        //若当前玩家是掷骰玩家，触发绿卡
        if (&p1_roll == &p2) {
            if ((roll <= (*it1)->getRange().max && (*it1)->getRange().min <= roll) &&
                (*it1)->getColor() == Color::green) {
                //为工厂类卡片时需要与symbol联动
                if ((*it1)->getType() == Type::factory) {
                    int symbol = 0;
                    if ((*it1)->getName() == FARMERS_MARKET_NAME) ++symbol;
                    vector<const Card *>::iterator it2;
                    for (it2 = p2.establishments.begin(); it2 != p2.establishments.end(); it2++) {
                        if ((*it2)->getSymbol() == (*it1)->getSymbol() && (*it2)->getType() != Type::factory) {
                            ++symbol;
                        }
                    }
                    add = add + (*it1)->cardFunction((*it1)->getName(), symbol);
                }//不是工厂类绿卡时，会根据shoppingmall地标状态，改变结算金额
                else {
                    //单独结算特殊商店类型：花店
                    int symbol = 0;
                    if ((*it1)->getName() == FLOWER_SHOP_NAME) {
                        vector<const Card *>::iterator it2;
                        for (it2 = p2.establishments.begin(); it2 != p2.establishments.end(); it2++) {
                            if ((*it2)->getName() == FLOWER_FIELD_NAME) {
                                ++symbol;
                            }
                        }
                        add = add + (*it1)->cardFunction((*it1)->getName(), symbol);
                    } else {//结算普通商店
                        add = add + (*it1)->cardFunction((*it1)->getName());
                    }
                    //结算商业中心地标
                    if (p2.getShoppingMallBool() == true) {
                        add = add + 1;
                    } else {
                        add = add;
                    }
                }
            }
        }//若当前玩家不是掷骰玩家，触发红卡
        else {
            if ((roll <= (*it1)->getRange().max && (*it1)->getRange().min <= roll) &&
                (*it1)->getColor() == Color::red) {
                add = add + (*it1)->cardFunction((*it1)->getName(), p1_roll, p2);
            }
        }
        //无论当前玩家是否掷骰玩家，触发蓝卡
        if ((roll <= (*it1)->getRange().max && (*it1)->getRange().min <= roll) &&
            (*it1)->getColor() == Color::blue) {
//            int sum = dice2 + dice1;
            if ((*it1)->getName() == TUNA_FISHBOAT_NAME) {

                add = add + (*it1)->cardFunction((*it1)->getName(), DICE_FOR_TUNA_FISHBOAT);
            } else {
                add = add + (*it1)->cardFunction((*it1)->getName());
            }
        }
    }
        //起手卡牌单独结算
        if (roll == 1) {
            add++;
        } else if (roll <= 3 && roll >= 2 && &p1_roll == &p2) {
            if (p2.getShoppingMallBool() == true) {
                add += 2;
            } else {
                add++;
            }
        }
        //循环结束，结算
        p2.setMoney(add + p2.money);

}


int Player_Port::landmark_after_roll(int dice) {
    int dice1;
    int dice2;
    srand((unsigned int)time(NULL));
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    DICE_FOR_TUNA_FISHBOAT=dice1+dice2;
    cout<<"#in Port version, if we have "<<TUNA_FISHBOAT_NAME<<",its dice is "<<DICE_FOR_TUNA_FISHBOAT<<endl;
    if (dice > 10) {
        cout << "#Whether add 2 at dice number? (1:yes/0:no)" << endl;
        int a;
        cin >> a;
        if (a == 0) {
            cout<<"#Your dice is "<<dice<<endl;
            return dice;
        } else {
            cout<<"#Your dice is "<<dice+2<<endl;
            return dice + 2;
        }
    } else {
        cout<<"#Your dice is "<<dice<<endl;
        return dice;
    }

}

//投色子
int Player::roll() {
    return rand() % 6 + 1;
}
//
/*vector<int>::iterator it;
for(it=array.begin();it!=array.end();it++)
cout<<*it<<endl;*/




