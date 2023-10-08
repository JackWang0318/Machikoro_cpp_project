#include <iostream>
#include "Card_1.0.h"
#include "desk_1.0.h"
//#include "version.h"
#include <algorithm>
#include "Controler.h"
#include "Card_2.0.h"
int main() {
    class Version version;
    cout << "|-----# Welcome to Machikoro! #-----|" << endl;
    int set_nb = version.init_version();
    class Controler ctrl(set_nb);
    version.set_version(ctrl,set_nb);

    try {
        ctrl.round();
        ctrl.show_Winner();
    }catch(exception& e)
    {
        cout<<e.what()<<"\n";
    }
}
