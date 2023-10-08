#ifndef UNTITLED1_CONTROLER_1_0_H
#define UNTITLED1_CONTROLER_1_0_H

#ifndef DESK_1_0_H
#define DESK_1_0_H

#include <iostream>

#include "desk_1.0.h"
#include <cstdlib>
#include <ctime>
#include <unordered_map>

#include "desk_2.0.h"

class Player;

class ControlerException : public exception { //no need
    string info;
public:
    ControlerException(const string &exceptionStr) noexcept: info(exceptionStr) {}

    virtual ~ControlerException() noexcept {}

    const char *what() const noexcept { return info.c_str(); }
};

class Controler {
public:
    /*          数据成员              */

    Game_Basic *game = nullptr;
    Player *player_List[4];
    vector<string> playerNames;
    PlayerNode player_Node1{nullptr, nullptr};
    PlayerNode player_Node2{nullptr, nullptr};
    PlayerNode player_Node3{nullptr, nullptr};
    PlayerNode player_Node4{nullptr, nullptr};


    Desk_Basic *desk_uni = nullptr;
    int nb_Player;
    int nb_Computer;
    bool isFinished = false;  //判断游戏是否结束*
    string Winner;
    int Count = 0;
    int Round = 1;

    friend class Version;

/*          成员函数              */

//    Controler() {        //默认构造
//        init_game();
//        player_Node1.player_ptr = player_List[0];
//        player_Node2.player_ptr = player_List[1];
//        player_Node3.player_ptr = player_List[2];
//        player_Node4.player_ptr = player_List[3];
//    }

    Controler(int nb) {
        init_game(nb);
    }

    ~ Controler() = default;  //需要手动释放内存 暂时没写


    void show_player();

    void init_game(int n);

    void init_PlayerLinkedList();  //生成player环形链表

    std::pair<int, bool> roll(PlayerNode &p);

    void begin_round(PlayerNode &cur_playerNode);

    void play_round(PlayerNode &cur_playerNode);

    void end_round(PlayerNode &cur_playerNode);

    void round(); //内部循环start_round, play_round, end_round

    void show_Winner();

    void settle_account(int dice, PlayerNode &cur_playerNode);

    string buy_card(PlayerNode &cur_playerNode);
};


class Version {
public:
    Version() = default;

    ~Version() = default;

    int init_version();

    static void init_player(int n, Controler &c);

    static void init_cards(int n, Controler &c);

    static void init_desk(int n, Controler &c);

    void set_version(Controler &ctrl, int n);

private:
    string name_version;

};


#endif //DESK_1_0_H
#endif //UNTITLED1_CONTROLER_1_0_H
