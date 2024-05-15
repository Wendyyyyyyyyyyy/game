//interface1
//标准界面1文本打印，选择危机牌 1或2, b返回主页
#include "color.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
using namespace std;

#define HEART   "\xE2\x99\xA5"

void interface1(int* stage_p, int* life_p, int* free_p, vector<Card> knowledge_pile,
  vector<Card> aging_pile, vector<Card> hazzard_pile, vector<Card> discard_knowledge_pile,
  vector<Card> discard_hazzard_pile, char* i1_p){
    // cout  Stage  with color
    if ( (*stage_p) == 1){
        cout  << "\033[32;1m"<< "Stage : "<<*stage_p<<"\033[0m"<< endl;
    }
    if ( (*stage_p) == 2){
        cout << "\033[33;1m" << "Stage : " <<*stage_p<<"\033[0m"<< endl;
    }
    if ( (*stage_p) == 3){
        cout << "\033[31;1m" << "Stage : " <<*stage_p<<"\033[0m"<< endl;
    }

    cout << purple_print("Life Point(s) : ")<< *life_p << HEART << endl;

    cout << purple_print("Knowledge Cards : ") << knowledge_pile.size()<<" : "<< discard_knowledge_pile.size()<< "      ";
    cout << purple_print("Aging Cards : " )<< aging_pile.size()<<" : "<< 10-aging_pile.size()<< "      ";
    cout << purple_print("Hazzard Cards : " ) << hazzard_pile.size()<<" : "<< discard_hazzard_pile.size()<<endl;

    cout << "\033[34;1m" <<"Please Select A Hazzard Card : " <<"\033[0m" << endl;
    cout <<purple_print("                              (danger | knowledge)")<< endl;/*needs adjustment for space*/
    //display the first danger card
      // display the danger side of this danger card
    cout <<purple_print("1) {") <<  (hazzard_pile.begin())->hazzard_name << "   "
        // display danger point in each stage with color
           <<  "\033[32;1m"<< (hazzard_pile.begin())->costs[0] << "\033[0m"<<" : "
           << "\033[33;1m"<< (hazzard_pile.begin())->costs[1] << "\033[0m"<<" : "
           << "\033[31;1m"<< (hazzard_pile.begin())->costs[2] <<"\033[0m"<< "   "

         << (hazzard_pile.begin())->free_cards_num <<purple_print(" | ")

      // display the knowledge side of this danger card
        << (hazzard_pile.begin())->knowledge_name << "  "
         << (hazzard_pile.begin())->fight_point << "  "
         << (hazzard_pile.begin())->remove_price << " [ "
         << (hazzard_pile.begin())->usable_time << "] " <<purple_print("}") <<endl;



    //display the second danger card
        // display the danger side of this danger card

    cout <<purple_print("2) {")  << (hazzard_pile.begin()+1)->hazzard_name << "   "
        // display danger point in each stage with color
        <<  "\033[32;1m"<< (hazzard_pile.begin())->costs[0] << "\033[0m"<<" : "
        << "\033[33;1m"<< (hazzard_pile.begin())->costs[1] << "\033[0m"<<" : "
        << "\033[31;1m"<< (hazzard_pile.begin())->costs[2] <<"\033[0m"<< "   "

         << (hazzard_pile.begin()+1)->free_cards_num << purple_print(" | ")

      // display the knowledge side of this danger card
        << (hazzard_pile.begin()+1)->knowledge_name << "  "
         << (hazzard_pile.begin()+1)->fight_point << "  "
         << (hazzard_pile.begin()+1)->remove_price << " [ "
         << (hazzard_pile.begin()+1)->usable_time << "] " <<purple_print("}") <<endl;
    //choose
    cout << "\033[34;1m" <<"Please choose a danger card by inputting 1 or 2"
    << "( Enter \"b\" to go back to home page )" <<"\033[0m" << endl;
    cin >>  *i1_p;

}
