//interface2
////标准界面2文本打印，输入string，b返回主页
//包含displayFightCards()
#include <iostream>
#include <string>
#include <cstdio>//?
#include <vector>
#include <cstdlib>//rand(), srand()
using namespace std;

#define HEART   "\xE2\x99\xA5"

// a function for displaying a current card

void DisplayACurrentCard (Card card){
    cout << " { "
         << card.knowledge_name << "  "
         << card.fight_point << "  "
         << card.remove_price << " [ "
         << card.usable_time << "] }" <<endl;

}


void interface2(int* stage_p, int* life_p, int* free_p, vector<Card> knowledge_pile,
  vector<Card> aging_pile, vector<Card> hazzard_pile, vector<Card> discard_knowledge_pile,
  vector<Card> discard_hazzard_pile, vector<Card> hand, char* i1_p, string* i2_p){

    cout << "～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～" << endl;

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


    // cout << "life : " with heart
    cout << purple_print("Life Point(s) : ")<< *life_p << HEART << endl;

    cout << purple_print("Knowledge Cards : ") << knowledge_pile.size()<<" : "<< discard_knowledge_pile.size()<< "      ";
    cout << purple_print("Aging Cards : " )<< aging_pile.size()<<" : "<< 10-aging_pile.size()<< "      ";
    cout << purple_print("Hazzard Cards : " ) << hazzard_pile.size()<<" : "<< discard_hazzard_pile.size()<<endl;

    //display the  danger card

      // display the danger side of this danger card

    cout <<purple_print("Danger : {")
            << (hazzard_pile.begin())->hazzard_name << "   "
        // display danger point in each stage with color
           <<  "\033[32;1m"<< (hazzard_pile.begin())->costs[0] << "\033[0m"<<" | "
           << "\033[33;1m"<< (hazzard_pile.begin())->costs[1] << "\033[0m"<<" | "
           << "\033[31;1m"<< (hazzard_pile.begin())->costs[2] <<"\033[0m"<< "   "

         << (hazzard_pile.begin())->free_cards_num << "}" << endl;

    cout <<purple_print( "Goal in current stage: " )<< (hazzard_pile.begin())->costs[*stage_p] << endl;

    cout << purple_print("Fight Point(s) : ") << *fight_p << endl;
    cout <<purple_print( "Current number of free cards :" )<< *free_p << endl;

    //display current cards
    cout <<purple_print("Your hands : ") << endl;
    int i = 1; //Marks the index of the card.
    vector<Card>::iterator iter;
    for(iter = hand.begin(); iter != hand.end(); iter++){
      cout << i;
        DisplayACurrentCard (*iter);
      i++;
    }

    cout << "\033[34;1m" <<"Please decide what to do next: \n"
    << "(Continue to) Draw a card                 --> Enter 1\n"
    << "Use a card function                       --> Enter 2\n"
    << "Pay my life points to draw another card   --> Enter 3\n"
    << "Pay my life points to skip this danger    --> Enter 4\n"
    << "WTF? back to my home page                 --> Enter b\n"<<"\033[0m" << endl;
    cin >>  *i2_p;

    }
