//
// Created by 86182 on 2022/10/31.
//
//
// Created by 31429 on 2022/10/19.
//
#include "Controler.h"
#include "iterator"
#include <string>

struct PlayerNode;


void Controler::show_player() {
    //显示确认玩家电脑信息
    cout << "# Player List: #" << endl;
    for (int i = 0; i < nb_Player; i++) {
        cout << "Player " << i + 1 << ":  " << playerNames[i] << endl;
    }
    cout << endl;
    if (nb_Computer > 0) {
        cout << "# Computer List: #" << endl;
    } else {
        cout << "# No Computer Player#" << endl;
    }
    for (int i = nb_Player; i < 4; i++) {
        cout << "Computer " << i + 1 << ":  " << playerNames[i] << endl;
    }
}


void Controler::init_game(int n) {
    //输入人类玩家个数,不多于4
    cout << "* Please enter the number of human players: (<= 4) *" << endl;
    cin >> nb_Player;

    // 如果输入nb_Player>4 报错
    if (nb_Player > 4) { throw ControlerException("# Please enter a number <= 4"); }
    nb_Computer = 4 - nb_Player;
    cout << "# Players: " << nb_Player << "  Computers: " << nb_Computer << "#" << endl;

    Version::init_player(n, *this);

    show_player();

    init_PlayerLinkedList();

    Version::init_cards(n, *this);

    Version::init_desk(n, *this);
}


void Controler::init_PlayerLinkedList() {  //生成player环形链表
    player_Node1.nextPlayer = &player_Node2;
    player_Node2.nextPlayer = &player_Node3;
    player_Node3.nextPlayer = &player_Node4;
    player_Node4.nextPlayer = &player_Node1;
    //print the order
    cout << "# The playing order: #" << endl;
    cout << player_Node1.player_ptr->getID() << "  -->  " << player_Node2.player_ptr->getID() <<
         "  -->  " << player_Node3.player_ptr->getID() << "  -->  " << player_Node4.player_ptr->getID() << endl;
}


void Controler::begin_round(PlayerNode &cur_playerNode) {  //回合开始，联动desk.h 负责：打印每个玩家的info 打印商店
    cout << "|       #Begin Round" << Round << " Player" << Count % 4 + 1 << "#      |" << endl;
    cout << "|             Your Info             |" << endl;
    desk_uni->start(cur_playerNode.player_ptr); //打印当前玩家信息
    desk_uni->shop(cur_playerNode.player_ptr);  //打印商店
}


void Controler::play_round(PlayerNode &cur_playerNode) {
    //回合进行，联动player.h 负责：投dice，计算money，
    // 买建筑和地标， 中间规定buyCard的规范（否则throw exception）
    cout << "|--------#Playing_Your_Turn#--------|" << endl;
    cout << "It's player " << cur_playerNode.player_ptr->getID() << "'s turn" << endl << endl;

    //地标卡 判断 相同色子 以及 是否重投
/*--------------------------------------------------调试部分修改-----------------------------------------------------------------------*/

    bool two_dices_same = true;
    while (two_dices_same) {
        std::pair<int, bool> dice = roll(cur_playerNode);
//        dice.first=3;
        two_dices_same = dice.second;
        int dice_num = cur_playerNode.player_ptr->landmark_after_roll(dice.first);
        //结算环节
        settle_account(dice_num, cur_playerNode);
        //买卡环节
        cur_playerNode.player_ptr->landmark_before_buy();
        string buy = buy_card(cur_playerNode);
        cur_playerNode.player_ptr->landmark_after_buy(buy);

        if (two_dices_same == true)
            cout << endl << "# Two dices same," << cur_playerNode.player_ptr->getID() << "'s turn again" << endl;
    }
}


void Controler::end_round(PlayerNode &cur_playerNode) {
    //打印所有玩家信息
    cout << "|----------#End_Your_Turn#----------|" << endl;
    cout << "|          All Player Info          |" << endl;
    desk_uni->all();
    //判断游戏是否结束
    if (cur_playerNode.player_ptr->checkWinner()) {
        isFinished = true;
        Winner = cur_playerNode.player_ptr->getID();
    };
    cout << "*Please enter 'ok' to continue :";
    string temp;
    cin >> temp;
}


void Controler::round() {
    PlayerNode *current;
    current = &player_Node1;
    cout << "* Get ready and please enter 'ok' to start the game:";
    string temp_str;
    cin >> temp_str;
    while (!isFinished) { //round<3 to be deleted
        if (Count % 4 == 0) {
            cout << "|--------------*Round*--------------|" << endl;
            cout << "|                 " << Round << "                 |" << endl;
        }

        begin_round(*current);
        play_round(*current);
        end_round(*current);

        Count++;
        if (Count % 4 == 0) {
            cout << "|------------*End_Round*------------|" << endl;
            cout << "|                 " << Round << "                 |" << endl << endl << endl;
            Round++;
        }


        current = current->nextPlayer;

    }
}


//投骰子（火车站加电视塔）
std::pair<int, bool> Controler::roll(PlayerNode &p) {
    if (p.player_ptr->getIsHuman()) {
        string temp_str1;
        cout << "*Please enter 'ok' to roll your dice:";
        cin >> temp_str1;
        int dice1;
        int dice2;
        srand((unsigned int) time(NULL));
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;

        if (p.player_ptr->getTrainStationBool() == true) {//如果可以投两个骰子
            cout << "# Do you want to use two dice?(1 for yes,0 for no) #" << endl;
            int tmp1;
            cin >> tmp1;
            if (tmp1 == 1)
                cout << "# Two dices are " << dice1 << " and " << dice2 << ",total number is " << dice1 + dice2 << " #"
                     << endl << endl;
            else cout << "# The dice is " << dice1 << " #" << endl << endl;

            //RadioTowerBool Function
            /*---------------------------------------------------------------------------------------------------*/
            if (p.player_ptr->getRadioTowerBool() == true) {//可以选择重投
                int tmp2;
                cout << "# Do you want to roll again? (1 for yes,0 for no) #" << endl;
                cin >> tmp2;
                if (tmp1 == 1 && tmp2 == 1) {//两个骰子，想重投
                    cout << "# You roll again #" << endl;
                    srand((unsigned int) time(NULL));
                    dice1 = rand() % 6 + 1;
                    dice2 = rand() % 6 + 1;
                    cout << "# Two dices are " << dice1 << " and " << dice2 << ",total number is " << dice1 + dice2
                         << " #"
                         << endl;
                } else if (tmp1 == 0 && tmp2 == 1) {//一个骰子，想重投
                    cout << "# You roll again #" << endl;
                    srand((unsigned int) time(NULL));
                    dice1 = rand() % 6 + 1;
                    cout << "# The dice is " << dice1 << " #" << endl;
                } else {
                    cout << "# You don't want to roll again #" << endl;
                    if (tmp1 == 1)
                        cout << "# Two dices are " << dice1 << " and " << dice2 << ",total number is " << dice1 + dice2
                             << " #" << endl;
                    else cout << "# The dice is " << dice1 << " #" << endl;
                }
            }
            if (tmp1 == 1 && dice1 == dice2 && p.player_ptr->getAmusementParkBool())
                return make_pair(dice1 + dice2, true);
            else if (tmp1 == 1) return make_pair(dice1 + dice2, false);
            else return make_pair(dice1, false);
        } else {//只能投一个骰子
            cout << "# The dice is " << dice1 << " #" << endl << endl;
            if (p.player_ptr->getRadioTowerBool() == true) {//可以选择重投
                int tmp2;
                cout << "# Do you want to roll again? (1 for yes,0 for no) #" << endl;
                cin >> tmp2;
                if (tmp2 == 1) {//一个骰子，想重投
                    cout << "# You roll again #" << endl;
                    srand((unsigned int) time(NULL));
                    dice1 = rand() % 6 + 1;
                    cout << "# The dice is " << dice1 << " #" << endl;
                }//不想重投不操作
                else {
                    cout << "# You don't want to roll again #" << endl;
                    cout << "# The dice is " << dice1 << " #" << endl;
                }
            }
            return make_pair(dice1, false);
        }
    } else {//-----------------------机器人扔色子-------------------------------//
        int dice1;
        int dice2;
        srand((unsigned int) time(NULL));
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;

        if (p.player_ptr->getTrainStationBool() == true) {//如果可以投两个骰子
            cout << "# " << p.player_ptr->getID() << " Two dices are " << dice1 << " and " << dice2
                 << ",total number is " << dice1 + dice2 << " #" << endl;
            //RadioTowerBool Function
            /*---------------------------------------------------------------------------------------------------*/
            if (p.player_ptr->getRadioTowerBool() == true && dice1 + dice2 <= 6) {//选择重投
                cout << "# " << p.player_ptr->getID() << " roll again #" << endl;
                srand((unsigned int) time(NULL));
                dice1 = rand() % 6 + 1;
                dice2 = rand() % 6 + 1;
                cout << "# " << p.player_ptr->getID() << " Two dices are " << dice1 << " and " << dice2
                     << ",total number is " << dice1 + dice2 << " #" << endl;
            }
            if (dice1 == dice2 && p.player_ptr->getAmusementParkBool())return make_pair(dice1 + dice2, true);
            else return make_pair(dice1 + dice2, false);
        } else {//只能投一个骰子
            cout << "# " << p.player_ptr->getID() << " dice is " << dice1 << " #" << endl << endl;
            return make_pair(dice1, false);
        }
    }
}

//结算部分
/*------------------------------------------------------------------------------------------------*/
void Controler::settle_account(int dice, PlayerNode &cur_playerNode) {
    //判断有哪种紫卡 以及 进行其效果的触发
    string temp_str1;
    cout << "*Please enter 'ok' to settle account:";
    cin >> temp_str1;
//紫卡结算
    cur_playerNode.player_ptr->purpleCardfunction(cur_playerNode, dice);

    //结算  (包含了先红卡再其他卡的顺序)
    PlayerNode *temp = &cur_playerNode;
    for (int i = 0; i < 4; i++) {
        cur_playerNode.player_ptr->settleAccount(dice, *cur_playerNode.player_ptr, *temp->nextPlayer->player_ptr);
        temp = temp->nextPlayer;
    }


}

//买卡部分，对应函数desk.remove_deskcard，play.buy_card
/*------------------------------------------------------------------------------------------------*/
string Controler::buy_card(PlayerNode &cur_playerNode) {
    string return_string = "nothing";
    if (cur_playerNode.player_ptr->getIsHuman()) {

        desk_uni->shop(cur_playerNode.player_ptr);
        cout << "# Now you have " << cur_playerNode.player_ptr->getMoney() << " money to use #" << endl;
        cout << "# Do you want to buy card ? (Enter card ID (1-max) or 0 for No )" << endl;
        int card_name_num;
        cin >> card_name_num;

        if (desk_uni->back(card_name_num) == "landmark") {
            string card_name = cur_playerNode.player_ptr->buyLandmark(card_name_num);
            cout << "# You buy " << card_name << endl;
            return_string = card_name;
            cout << "*Please enter 'ok' to continue:";
            string temp_str;
            cin >> temp_str;
        } else {
            if (card_name_num != 0) {
                string card_name = desk_uni->back(card_name_num);
                const Card *card = desk_uni->remove_deskcard(card_name);
                cur_playerNode.player_ptr->buy_card(card_name, card);
                return_string = card_name;
            } else {
                cout << "# You buy nothing " << endl;
                cout << "*Please enter 'ok' to continue:";
                return_string = "nothing";
                string temp_str;
                cin >> temp_str;
            }
        }
    } else {//robot_buy
        if ((cur_playerNode.player_ptr->getMoney() > TRAIN_STATION_COST) &&
            cur_playerNode.player_ptr->getTrainStationBool() == false) {
            string card_name = cur_playerNode.player_ptr->buyLandmark(16);
            cout << "# " << cur_playerNode.player_ptr->getID() << " buy " << card_name << endl;
            return_string = card_name;
        } else if ((cur_playerNode.player_ptr->getMoney() > SHOPPING_MALL_COST) &&
                   cur_playerNode.player_ptr->getShoppingMallBool() == false) {
            string card_name = cur_playerNode.player_ptr->buyLandmark(17);
            cout << "# " << cur_playerNode.player_ptr->getID() << " buy " << card_name << endl;
            return_string = card_name;
        } else if ((cur_playerNode.player_ptr->getMoney() > AMUSEMENT_PARK_COST) &&
                   cur_playerNode.player_ptr->getAmusementParkBool() == false) {
            string card_name = cur_playerNode.player_ptr->buyLandmark(18);
            cout << "# " << cur_playerNode.player_ptr->getID() << " buy " << card_name << endl;
            return_string = card_name;
        } else if ((cur_playerNode.player_ptr->getMoney() > RADIO_TOWER_COST) &&
                   cur_playerNode.player_ptr->getRadioTowerBool() == false) {
            string card_name = cur_playerNode.player_ptr->buyLandmark(19);
            cout << "# " << cur_playerNode.player_ptr->getID() << " buy " << card_name << endl;
            return_string = card_name;
        } else {
            int flag = 0;
            for (auto c:desk_uni->desk) {
                if ((cur_playerNode.player_ptr->getMoney() > c->getCost()) && (c->getSymbol() == Symbol::wheat)) {
                    if (cur_playerNode.player_ptr->getTrainStationBool() == false && c->getRange().max <= 6) {
                        const Card *card = desk_uni->remove_deskcard(c->getName());
                        cur_playerNode.player_ptr->buy_card(c->getName(), card);
                        flag = 1;
                        return_string = c->getName();
                        break;
                    } else if (cur_playerNode.player_ptr->getTrainStationBool()) {
                        const Card *card = desk_uni->remove_deskcard(c->getName());
                        cur_playerNode.player_ptr->buy_card(c->getName(), card);
                        flag = 1;
                        return_string = c->getName();
                        break;
                    }
                }
            }
            if (flag == 0) cout << "# " << cur_playerNode.player_ptr->getID() << " buy nothing" << endl;
            return_string = "nothing";
        }
        cout << "*Please enter 'ok' to continue:";
        string temp_str;
        cin >> temp_str;
    }
    return return_string;
}

void Controler::show_Winner() {
    cout << "      The winner is " << Winner << " !!!" << endl
         << "       Congratulations! ";
}


int Version::init_version() {
    int temp;
    cout << "* Enter '0' to set version Machikoro basic *" << endl;
    cout << "* Enter '1' to set version Machikoro Port extended *" << endl;
    cin >> temp;
    if (temp == 0) {
        cout << "# You choose version--Machikoro basic *" << endl;
    } else {
        cout << "# You choose version--Machikoro Port extended *" << endl;
    }
    return temp;
}


void Version::init_player(int n, Controler &c) {
    if (n == 0) { //基础版
        for (int i = 0; i < c.nb_Player; i++) {
            string str;
            cout << "* Please enter Player " << i + 1 << "'s name: *" << endl;
            cin >> str;
            c.playerNames.push_back(str);
            c.player_List[i] = new People_Basic(str, true); // basic人类玩家
        }

        for (int i = 0; i < c.nb_Computer; i++) {
            string str = "Com_";
            string temp;
            cout << "* Please enter Computer " << i + 1 << "'s name: *" << endl;
            cin >> temp;
            str = str + temp;
            c.playerNames.push_back(str);
            c.player_List[c.nb_Player + i] = new Robot_Basic(str, false);  // basic电脑玩家
        }

    } else if (n == 1) {  //港口扩展版
        for (int i = 0; i < c.nb_Player; i++) {
            string str;
            cout << "* Please enter Player " << i + 1 << "'s name: *" << endl;
            cin >> str;
            c.playerNames.push_back(str);
            c.player_List[i] = new People_Port(str, true); // port人类玩家
        }

        for (int i = 0; i < c.nb_Computer; i++) {
            string str = "Com_";
            string temp;
            cout << "* Please enter Computer " << i + 1 << "'s name: *" << endl;
            cin >> temp;
            str = str + temp;
            c.playerNames.push_back(str);
            c.player_List[c.nb_Player + i] = new Robot_Port(str, false);  // port电脑玩家
        }

    }

    for (int i = 0; i < 4; i++) { c.player_List[i]->setID(c.playerNames[i]); }
    c.player_Node1.player_ptr = c.player_List[0];
    c.player_Node2.player_ptr = c.player_List[1];
    c.player_Node3.player_ptr = c.player_List[2];
    c.player_Node4.player_ptr = c.player_List[3];
}

void Version::init_cards(int n, Controler &c) {

    if (n == 0) {
        c.game = new Game_Basic;
        c.game->setcards();
    } else if (n == 1) {
        c.game = dynamic_cast<Game_Port *>(c.game);
        c.game = new Game_Port;
        c.game->setcards();
    }

}

void Version::init_desk(int n, Controler &c) {
    if (n == 0) {
        c.desk_uni = new Desk_Basic;
        c.desk_uni->setDesk(c.player_List, c.game);
    } else if (n == 1) {
        c.desk_uni = dynamic_cast<Desk_Port *>(c.desk_uni);
        c.desk_uni = new Desk_Port;

        c.desk_uni->setDesk(c.player_List, c.game);

    }


}

void Version::set_version(Controler &ctrl, int n) {
    if (n == 0) { //默认basic版本
        this->name_version = "Machikoro_Basic";
        //ctrl默认构造, no need to reconstruct controler
    } else if (n == 1) {
        this->name_version = "Machikoro_Port_Extended";
        //转化controler中成员变量指针

//        ctrl.game = dynamic_cast<Game_Port *>(ctrl.game);
//
//        ctrl.desk_uni = dynamic_cast<Desk_Port *>(ctrl.desk_uni);


    }
}



