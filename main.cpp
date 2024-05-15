#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>//rand(), srand()
#include <ctime>//time()
#include "home_page.h"
#include "rules.h"

using namespace std;

struct Card {
    string hazzard_name;
    int costs[3];
    int free_cards_num;

    string knowledge_name;
    int fight_point;
    int remove_price;
    int usable_time;

    void init(string hazzard, int c1, int c2, int c3, int free,
      string knowledge, int fight, int price, int time) {
        this->hazzard_name = hazzard;
        this->costs[0] = c1;
        this->costs[1] = c2;
        this->costs[2] = c3;
        this->free_cards_num = free;
        this->knowledge_name = knowledge;
        this->fight_point = fight;
        this->remove_price = price;
        this->usable_time = time;
    }
};
// generating all the cards which are of the type "Card"
void upload_all_cards(Card hazzard[], Card starting[], Card aging[], Card pirates[]) {
   hazzard[0].init("Raft Wreck", 0, 1, 3, 1, "Food: +1 life", 0, 1, 1);
   hazzard[1].init("Raft Wreck", 0, 1, 3, 1, "Food: +1 life", 0, 1, 1);
   hazzard[2].init("Raft Wreck", 0, 1, 3, 1, "Mimesis: 1x copy", 0, 1, 1);
   hazzard[3].init("Raft Wreck", 0, 1, 3, 1, "Cognition: 1x destroy", 0, 1, 1);
   hazzard[4].init("Raft Wreck", 0, 1, 3, 1, "Trick: 1x below the stack", 0, 1, 1);
   hazzard[5].init("Raft Wreck", 0, 1, 3, 1, "Books: -1 stage", 0, 1, 1);
   hazzard[6].init("Raft Wreck", 0, 1, 3, 1, "Strategy: 2x exchange", 0, 1, 2);
   hazzard[7].init("Raft Wreck", 0, 1, 3, 1, "Strategy: 2x exchange", 0, 1, 2);
   hazzard[8].init("Raft Wreck", 0, 1, 3, 1, "Toolbox: +2 cards", 0, 1, 2);
   hazzard[9].init("Raft Wreck", 0, 1, 3, 1, "Toolbox: +2 cards", 0, 1, 2);
   hazzard[10].init("Island Exploration", 1, 3, 6, 2, "Cognition: 1x detroy", 1, 1, 1);
   hazzard[11].init("Island Exploration", 1, 3, 6, 2, "Mimesis: 1x copy", 0, 1, 1);
   hazzard[12].init("Island Exploration", 1, 3, 6, 2, "Weapon", 2, 1, 0);
   hazzard[13].init("Island Exploration", 1, 3, 6, 2, "Weapon", 2, 1, 0);
   hazzard[14].init("Island Exploration", 1, 3, 6, 2, "Food: +1 life", 1, 1, 1);
   hazzard[15].init("Island Exploration", 1, 3, 6, 2, "Food: +1 life", 1, 1, 1);
   hazzard[16].init("Island Exploration", 1, 3, 6, 2, "Trick: 1x below the stack", 1, 1, 1);
   hazzard[17].init("Island Exploration", 1, 3, 6, 2, "Production: 1x double", 1, 1, 1);
   hazzard[18].init("Deep Island Exploration", 2, 5, 8, 3, "Production: 1x double", 2, 1, 1);
   hazzard[19].init("Deep Island Exploration", 2, 5, 8, 3, "Food: +1 life", 2, 1, 1);
   hazzard[20].init("Deep Island Exploration", 2, 5, 8, 3, "Strategy: 1x exchange", 2, 1, 1);
   hazzard[21].init("Deep Island Exploration", 2, 5, 8, 3, "Vision: sort 3 cards", 2, 1, 3);
   hazzard[22].init("Deep Island Exploration", 2, 5, 8, 3, "Cognition: 1x detroy", 2, 1, 1);
   hazzard[23].init("Deep Island Exploration", 2, 5, 8, 3, "Experience: +1 card", 2, 1, 1);
   hazzard[24].init("Wild Beasts", 4, 7, 11, 4, "Strategy: 1x exchange", 3, 1, 1);
   hazzard[25].init("Wild Beasts", 4, 7, 11, 4, "Vision: sort 3 cards", 3, 1, 3);
   hazzard[26].init("Wild Beasts", 4, 7, 11, 4, "Experience: +1 card", 3, 1, 1);
   hazzard[27].init("Wild Beasts", 4, 7, 11, 4, "Cognition: 1x destroy", 3, 1, 1);
   hazzard[28].init("Cannibals", 5, 9, 14, 5, "Weapon", 4, 1, 0);
   hazzard[29].init("Cannibals", 5, 9, 14, 5, "Weapon", 4, 1, 0);

   starting[0].init("", 0, 0, 0, 0, "Muse", 2, 1, 0);
   starting[1].init("", 0, 0, 0, 0, "Muse", 2, 1, 0);
   starting[2].init("", 0, 0, 0, 0, "Muse", 2, 1, 0);
   starting[3].init("", 0, 0, 0, 0, "Unconcentrated", -1, 1, 0);
   starting[4].init("", 0, 0, 0, 0, "Unconcentrated", -1, 1, 0);
   starting[5].init("", 0, 0, 0, 0, "Unconcentrated", -1, 1, 0);
   starting[6].init("", 0, 0, 0, 0, "Normal", 0, 1, 0);
   starting[7].init("", 0, 0, 0, 0, "Normal", 0, 1, 0);
   starting[8].init("", 0, 0, 0, 0, "Normal", 0, 1, 0);
   starting[9].init("", 0, 0, 0, 0, "Weak", 0, 1, 0);
   starting[10].init("", 0, 0, 0, 0, "Weak", 0, 1, 0);
   starting[11].init("", 0, 0, 0, 0, "Weak", 0, 1, 0);
   starting[12].init("", 0, 0, 0, 0, "Eat: +2 life", 0, 1, 1);
   starting[13].init("", 0, 0, 0, 0, "Eat: +2 life", 0, 1, 1);
   starting[14].init("", 0, 0, 0, 0, "Eat: +2 life", 0, 1, 1);
   starting[15].init("", 0, 0, 0, 0, "Concentrated", 1, 1, 0);
   starting[16].init("", 0, 0, 0, 0, "Concentrated", 1, 1, 0);
   starting[17].init("", 0, 0, 0, 0, "Concentrated", 1, 1, 0);

   aging[0].init("", 0, 0, 0, 0, "Very Hungry: -2 life", 0, 2, -1);
                    //"-1 usable time" means the function is activated automatically.
   aging[1].init("", 0, 0, 0, 0, "Hungry: -1 life", 0, 2, -1);
   aging[2].init("", 0, 0, 0, 0, "Very Unconcentrated", -2, 2, 0);
   aging[3].init("", 0, 0, 0, 0, "Unconcentrated", -1, 2, 0);
   aging[4].init("", 0, 0, 0, 0, "Fear: highest card = 0", 0, 2, -1);
   aging[5].init("", 0, 0, 0, 0, "Sleepy: stop", 0, 2, -1);
   aging[6].init("", 0, 0, 0, 0, "Stupid", -2, 2, 0);
   aging[7].init("", 0, 0, 0, 0, "Suicide", -5, 2, 0);
   aging[8].init("", 0, 0, 0, 0, "Very Stupid", -3, 2, 0);
   aging[9].init("", 0, 0, 0, 0, "Mad", -4, 2, 0);

   pirates[0].init("The Thriller Bark Pirates", 0, 0, 15, 5, "", 0, 0, 0);
                    //costs[2] means the goal point.
   pirates[1].init("The Fire Tank Pirates", 0, 0, 20, 6, "", 0, 0, 0);
   pirates[2].init("The Kid Pirates", 0, 0, 25, 7, "", 0, 0, 0);
   pirates[3].init("The Kuja Pirates", 0, 0, 16, 7, "", 0, 0, 0);
   pirates[4].init("The Golden Lion Pirates", 0, 0, 24, 8, "", 0, 0, 0);
   pirates[5].init("The Straw Hat Pirates", 0, 0, 30, 8, "", 0, 0, 0);
   pirates[6].init("The Blackbeard Pirate Fleet", 0, 0, 22, 9, "", 0, 0, 0);
   pirates[7].init("The Big Mom Pirates", 0, 0, 35, 9, "", 0, 0, 0);
   pirates[8].init("The Beasts Pirates", 0, 0, 40, 10, "", 0, 0, 0);
   pirates[9].init("The Red Hair Pirates", 0, 0, 52, 10, "", 0, 0, 0);
}

void displayFightCard(Card card){
    cout << " { "
         << card.knowledge_name << "  "
         << card.fight_point << "  "
         << card.remove_price << " [ "
         << card.usable_time << "] }" <<endl;
}

// enabling print in different color
string black_print(string out){
    return "\033[30;1m" + out + "\033[0m";
}
string red_print(string out){
    return "\033[31;1m" + out + "\033[0m";
}
string green_print(string out){
    return "\033[32;1m" + out + "\033[0m";
}
string yellow_print(string out){
    return "\033[33;1m" + out + "\033[0m";
}
string blue_print(string out){
    return "\033[34;1m" + out + "\033[0m";
}
string purple_print(string out){
    return "\033[35;1m" + out + "\033[0m";
}
string bluegreen_print(string out){
   return "\033[36;1m" + out + "\033[0m";
}
string white_print(string out){
    return "\033[37;1m" + out + "\033[0m";
}

// display cards
void displayHand(vector<Card> hand) {
  //display current cards
  cout <<purple_print("Your hands : ") << endl;
  int i = 1; //Marks the index of the card.
  vector<Card>::iterator iter;
  for(iter = hand.begin(); iter != hand.end(); iter++){
    cout << i;
      displayFightCard(*iter);
    i++;
  }
}

void initial(Card &card, Card h_p[], Card k_p[]) {   //Initialiazes the usable_time
                             //and the effects of a drawn card;
  for (int i = 0; i < 30; i++) {
    if (h_p[i].knowledge_name == card.knowledge_name) card.usable_time = h_p[i].usable_time;
  }
  for (int i = 0; i < 18; i++) {
    if (k_p[i].knowledge_name == card.knowledge_name) card.usable_time = k_p[i].usable_time;
  }
}

// undo the function of card
void eliminate_effect(vector<Card> &hand, vector<Card> &hazzard_pile,
  Card card, Card h_p[], Card k_p[], int* life_p, int* stage_p) {//Eliminates the drawn card's effect
  int reverse_time;//To calculate how many times the card's function is used.
  for (int i = 0; i < 30; i++) {
    if (h_p[i].knowledge_name == card.knowledge_name) reverse_time = h_p[i].usable_time - card.usable_time;
  }
  for (int i = 0; i < 18; i++) {
    if (k_p[i].knowledge_name == card.knowledge_name) reverse_time = h_p[i].usable_time - card.usable_time;
  }

  for (int i = 0; i < reverse_time; i++) {//Repeat `reverse_time` times.
    if (card.knowledge_name == "Food: +1 life") {
      (*life_p) -= 1;
    }
    else if (card.knowledge_name == "Eat: +2 life") {
      (*life_p) -= 2;
    }
    else if (card.knowledge_name == "Hungry: -1 life") {
      (*life_p) += 1;
    }
    else if (card.knowledge_name == "Very Hungry: -2 life") {
      (*life_p) += 2;
    }
    else if (card.knowledge_name == "Books: -1 stage") {
      (*stage_p)++;
    }
    else if (card.knowledge_name == "Production: 1x double") {
      vector<Card>::iterator iter;
      for (iter = hand.begin(); iter != hand.end(); iter++) {
        if ((*iter).knowledge_name == card.knowledge_name) continue;
        else (iter->fight_point) /= 2;
      }
    }
    else if (card.knowledge_name == "Fear: highest card = 0") {
      vector<Card>::iterator iter;
      for (iter = hand.begin(); iter != hand.end(); iter++) {
        for (int i = 0; i < 30; i++) {
          if (h_p[i].knowledge_name == (iter->knowledge_name))
            (*iter).fight_point = h_p[i].fight_point;
        }
        for (int i = 0; i < 18; i++) {
          if (k_p[i].knowledge_name == (iter->knowledge_name))
            (*iter).fight_point = h_p[i].fight_point;
        }
      }
    }
    else if (card.knowledge_name == "Sleepy: stop") {
      for (int i = 0; i < 30; i++) {
        if (h_p[i].hazzard_name == (hazzard_pile.begin()->hazzard_name)) {
          hazzard_pile.begin()->free_cards_num = h_p[i].free_cards_num;
        }
      }
    }
  }
}
//destroy certain cards
void destroy(vector<Card> &hand, vector<Card> &hazzard_pile, int &price,
   Card h_p[], Card k_p[], int* life_p, int* stage_p) {
  char destroy_more = 'y';
  while (destroy_more == 'y') {
    cout << "Pls choose a card in hand to be destroyed (index): ";
    int index;
    cin >> index;
    while (index > hand.size()){
        cout << "index invalid, please enter again";
        cin >> index;
    }
    if (price == -1) {    //When "destroy" works as a card function, no cost.
      eliminate_effect(hand, hazzard_pile, *(hand.begin() + index - 1),
       h_p, k_p, life_p, stage_p);
      initial(*(hand.begin() + index - 1), h_p, k_p);
      hand.erase(hand.begin() + index - 1);
    }

    else if (price >= (hand.begin() + index - 1)->remove_price) {//When costs life
      price -= (hand.begin() + index - 1)->remove_price;
      eliminate_effect(hand, hazzard_pile, *(hand.begin() + index - 1),
       h_p, k_p, life_p, stage_p);
      initial(*(hand.begin() + index - 1), h_p, k_p);
      hand.erase(hand.begin() + index - 1);
    }
    else {//When cannot destroy any more cards.
      cout << "You cannot destroy any more cards." << endl;
      break;
    }
    displayHand(hand);
    cout << "Continue to destroy? (y/n): ";
    cin >> destroy_more;
  }
}

// copy a card
void copy(vector<Card> &hand, Card this_card, int* fight_p, Card h_p[], Card k_p[]) {
  while (true) {
    cout << "Choose another card to copy (index): ";
    int index;
    cin >> index;
    while (index > hand.size()){
        cout << "index invalid, please enter again";
        cin >> index;
    }
    if ((*(hand.begin() + index - 1)).knowledge_name == this_card.knowledge_name
     || index > hand.size() || index <= 0) {
      cout << "! Invalid index :( Please type again.\n";
      continue;
    }
    else {
      //Store the hand to tmp_hand before changing the former, for furhter usage.
      vector<Card> tmp_hand = hand;
      vector<Card>::iterator iter;
      for (iter = hand.begin(); iter != hand.end(); iter++) {
        if ((*iter).knowledge_name == this_card.knowledge_name) {
          (*iter) = (*(hand.begin() + index - 1));
          (*fight_p) -= this_card.fight_point;
          (*fight_p) += (*iter).fight_point;
          initial((*iter), h_p, k_p);
        }
      }
      displayHand(hand);
      break;
    }
  }
}

// Choose another card to put below the discard knowledge pile
void below(vector<Card> &hand, vector<Card> &knowledge_pile, Card this_card,
  int* fight_p, Card h_p[], Card k_p[]) {
  while (true) {
    cout << "Choose another card to put below the discard knowledge pile (index): ";
    int index;
    cin >> index;
    while (index > hand.size()){
        cout << "index invalid, please enter again";
        cin >> index;
    }
    if ((*(hand.begin() + index - 1)).knowledge_name == this_card.knowledge_name
     || index > hand.size() || index <= 0) {
      cout << "! Invalid index :( Please type again.\n";
      continue;
    }
    else {
      knowledge_pile.push_back(*(hand.begin() + index - 1));
      (*fight_p) -= (*(hand.begin() + index - 1)).fight_point;
      initial(*(hand.begin() + index - 1), h_p, k_p);
      hand.erase(hand.begin() + index - 1);
      displayHand(hand);
      break;
    }
  }
}
//Choose another card to exchange
void exchange(vector<Card> &hand, vector<Card> &knowledge_pile,
  vector<Card> &discard_knowledge_pile, Card this_card, Card h_p[], Card k_p[]) {
  while (true) {
    cout << "Choose another card to exchange (index): ";
    int index;
    cin >> index;
    while (index > hand.size()){
        cout << "index invalid, please enter again";
        cin >> index;
    }
    if ((*(hand.begin() + index - 1)).knowledge_name == this_card.knowledge_name
     || index > hand.size() || index <= 0) {
      cout << "! Invalid index :( Please type again.\n";
      continue;
    }
    else {
      vector<Card>::iterator iter;
      for (iter = hand.begin(); iter != hand.end(); iter++) {
        if ((*iter).knowledge_name == (*(hand.begin() + index - 1)).knowledge_name) {
          initial(*(iter), h_p, k_p);
          discard_knowledge_pile.push_back(*(iter));
          (*iter) = (*knowledge_pile.begin());
          knowledge_pile.erase(knowledge_pile.begin());
        }
      }
      displayHand(hand);
      break;
    }
  }
}
// double the fight point of certain card
void Double(vector<Card> &hand, Card card) {
  vector<Card>::iterator iter;
  for (iter = hand.begin(); iter != hand.end(); iter++) {
    if ((*iter).knowledge_name == card.knowledge_name) continue;
    else (iter->fight_point) *= 2;
  }
  displayHand(hand);
}

//preview the 3 knowledge cards on knowledge_pile top
void sort(vector<Card> knowledge_pile) {
  cout << "Now you can preview the 3 knowledge cards on knowledge_pile top: \n";
  vector<Card>::iterator iter;
  for (iter = knowledge_pile.begin(); iter != knowledge_pile.begin() + 3; iter++) {
    displayFightCard(*iter);
  }
}

// decrease fight point to zero
void fear(vector<Card> &hand) {
  vector<Card>::iterator iter;
  for (iter = hand.begin(); iter != hand.end(); iter++) {
    if ((*iter).fight_point > 0) (*iter).fight_point = 0;
  }
  displayHand(hand);
}

// can't draw cards
void stop(Card &card) {
  card.free_cards_num = 0;
}
// realize the function of cards
void do_function(vector<Card> &hand, vector<Card> &knowledge_pile,
  vector<Card> &discard_knowledge_pile, vector<Card> &hazzard_pile, Card card,
  int* life_p, int* fight_p, int* stage_p, Card h_p[], Card k_p[]) {
  if (card.knowledge_name == "Food: +1 life") {
        (*life_p) += 1;
  }
  else if (card.knowledge_name == "Eat: +2 life") {
    (*life_p) += 2;
  }
  else if (card.knowledge_name == "Hungry: -1 life") {
    (*life_p) -= 1;
  }
  else if (card.knowledge_name == "Very Hungry: -2 life") {
    (*life_p) -= 2;
  }
  else if (card.knowledge_name == "Mimesis: 1x copy") {
    copy(hand, card, fight_p, h_p, k_p);
  }
  else if (card.knowledge_name == "Cognition: 1x destroy") {
    int price = -1;
    destroy(hand, hazzard_pile, price, h_p, k_p, life_p, stage_p);
  }
  else if (card.knowledge_name == "Trick: 1x below the stack") {
    below(hand, knowledge_pile, card, fight_p, h_p, k_p);
  }
  else if (card.knowledge_name == "Books: -1 stage") {
    (*stage_p)--;
  }
  else if (card.knowledge_name == "Strategy: 1x exchange") {
    exchange(hand, knowledge_pile, discard_knowledge_pile, card, h_p, k_p);
  }
  else if (card.knowledge_name == "Strategy: 2x exchange") {
    exchange(hand, knowledge_pile, discard_knowledge_pile, card, h_p, k_p);
    exchange(hand, knowledge_pile, discard_knowledge_pile, card, h_p, k_p);
  }
  else if (card.knowledge_name == "Experience: +1 card") {
    hand.push_back(*(knowledge_pile.begin()));
    knowledge_pile.erase(knowledge_pile.begin());
    displayFightCard(hand.back());
  }
  else if (card.knowledge_name == "Toolbox: +2 cards") {
    hand.push_back(*(knowledge_pile.begin()));
    knowledge_pile.erase(knowledge_pile.begin());
    displayFightCard(hand.back());
    hand.push_back(*(knowledge_pile.begin()));
    knowledge_pile.erase(knowledge_pile.begin());
    displayFightCard(hand.back());
  }
  else if (card.knowledge_name == "Production: 1x double") {
    Double(hand, card);
  }
  else if (card.knowledge_name == "Vision: sort 3 cards") {
    sort(knowledge_pile);//简化版，只是看knowledge_pile牌顶的三张牌 q^q
  }
  else if (card.knowledge_name == "Fear: highest card = 0") {
    fear(hand);
  }
  else if (card.knowledge_name == "Sleepy: stop") {
    stop(*(hazzard_pile.begin()));
  }
}



// start a play
void Play(int* life_p, int* free_p, int* fight_p, int* stage_p, string* i2_p,
      vector<Card> &hand, vector<Card> &knowledge_pile,
      vector<Card> &discard_knowledge_pile, vector<Card> &hazzard_pile,
      Card h_p[], Card k_p[], Card danger) {

    while (true) {
      if ((*i2_p) == "1" || (*i2_p) == "3") { //draw a knowledge card to hand
        if ((*i2_p) == "3") {               //draw card by paying life points
            (*life_p) -= 1;
        }
        hand.push_back(*(knowledge_pile.begin()));
        knowledge_pile.erase(knowledge_pile.begin());
        cout << "# A card has been drawn from you knowledge_pile to your hand: \n";
        cout << (hand.back().fight_point) << endl;       
        (*fight_p) += (hand.back().fight_point);
        if ((*free_p) > 0){
          (*free_p) --;
        }
        if ((*free_p) <= 0){
          (*life_p) -= 2;
        }
        displayHand(hand);

        if (hand.back().usable_time < 0) { // suffer the effects of aging card atomatically
          do_function(hand, knowledge_pile, discard_knowledge_pile,
            hazzard_pile, hand.back(), life_p, fight_p, stage_p, h_p, k_p);
        }
        break;
      }

      else if ((*i2_p) == "2") {      // use the function of card
        bool isValid = 0;
        while (isValid == 0) {
          cout << "Of which card function do you want to use?"
          << " (Enter a index)";
          int index;
          cin >> index;
          while (index > hand.size()){
            cout << "index invalid, please enter again";
            cin >> index;
    }
          if ((hand.begin() + index - 1)->usable_time <= 0) {
            cout << "! Invalid input :(\n";
            continue;
          }
          else {
            do_function(hand, knowledge_pile, discard_knowledge_pile,
              hazzard_pile, *(hand.begin() + index - 1), life_p, fight_p, stage_p, h_p, k_p);
            (hand.begin() + index - 1)->usable_time--;
            isValid = 1;
          }
        }
        break;
      }

      else if ((*i2_p) == "4") {      //use life to skip hazard
        int price = (hazzard_pile.begin())->costs[(*stage_p)-1] - (*fight_p);
        cout << "Are you sure to pay " << price << " to skip this danger? (y/n) ";
        char ans;
        cin >> ans;
        if (ans == 'y') {
          (*life_p) -= price;
          cout << "Now your life point is " << *life_p << ". "<<endl;
          //destroy(hand, hazzard_pile, price, h_p, k_p, life_p, stage_p);
          break;
        }
        else {
          cout << "Make a choice again: ";
          cin >> *i2_p;
        }
      }
    }

}
// reset the situation 
void Reset(vector<Card> &hand, vector<Card> &discard_knowledge_pile,
  int* stage_p, int* fight_p, Card h_p[], Card k_p[]) {
  vector<Card>::iterator iter;
  for (iter = hand.begin(); iter != hand.end(); iter++) {
    if ((*iter).knowledge_name == "Books: -1 stage") {
      (*stage_p)++;
    }
    initial(*iter, h_p, k_p);
    discard_knowledge_pile.push_back(*iter);
    //hand.erase(iter);
  }
  hand.clear();
  (*fight_p) = 0;
}

// check whether win or fail or running out of card 
int Check(vector<Card> hazzard_pile, vector<Card> knowledge_pile, int* fight_p,
          int* stage_p, int* life_p, string* i2_p) {
  Card danger = (*(hazzard_pile.begin()));
  bool win = ((*fight_p) >= (hazzard_pile.begin())->costs[(*stage_p)-1]);
  if ((*life_p) < 0) return 0;
  else if (knowledge_pile.size() == 0) return 1;
  else if (win) return 2;
  else if ((!win) && ((*i2_p) == "4")) return 3;
  else return 4;
}

#define HEART   "\xE2\x99\xA5"
// display interface 1
void interface1(int* stage_p, int* life_p, int* free_p, vector<Card> knowledge_pile,
  vector<Card> aging_pile, vector<Card> hazzard_pile, vector<Card> discard_knowledge_pile,
  vector<Card> discard_hazzard_pile, char* i1_p){
    // cout  Stage  with color
    if ( (*stage_p) == 1){
        cout  << "\033[32;1m"<< "Step : "<<*stage_p<<"\033[0m"<< endl;
    }
    if ( (*stage_p) == 2){
        cout << "\033[33;1m" << "Step : " <<*stage_p<<"\033[0m"<< endl;
    }
    if ( (*stage_p) == 3){
        cout << "\033[31;1m" << "Step : " <<*stage_p<<"\033[0m"<< endl;
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
        <<  "\033[32;1m"<< (hazzard_pile.begin()+1)->costs[0] << "\033[0m"<<" : "
        << "\033[33;1m"<< (hazzard_pile.begin()+1)->costs[1] << "\033[0m"<<" : "
        << "\033[31;1m"<< (hazzard_pile.begin()+1)->costs[2] <<"\033[0m"<< "   "

         << (hazzard_pile.begin()+1)->free_cards_num << purple_print(" | ")

      // display the knowledge side of this danger card
        << (hazzard_pile.begin()+1)->knowledge_name << "  "
         << (hazzard_pile.begin()+1)->fight_point << "  "
         << (hazzard_pile.begin()+1)->remove_price << " [ "
         << (hazzard_pile.begin()+1)->usable_time << "] " <<purple_print("}") <<endl;
    //choose
    cout << "\033[34;1m" <<"Please choose a danger card by inputting 1 or 2"
     <<"\033[0m" << endl;
    cin >>  *i1_p;

}

void DisplayACurrentCard (Card card){
    cout << " { "
         << card.knowledge_name << "  "
         << card.fight_point << "  "
         << card.remove_price << " [ "
         << card.usable_time << "] }" <<endl;

}

// display interface 2
void interface2(int* stage_p, int* life_p, int* free_p, int* fight_p, vector<Card> knowledge_pile,
  vector<Card> aging_pile, vector<Card> hazzard_pile, vector<Card> discard_knowledge_pile,
  vector<Card> discard_hazzard_pile, vector<Card> hand, char* i1_p, string* i2_p){

    cout << "～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～" << endl;

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

    cout <<purple_print( "Goal in current stage: " )<< (hazzard_pile.begin())->costs[(*stage_p)-1] << endl;

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
    //<< "Back to my home page                      --> Enter b\n"
    <<"\033[0m" << endl;
    if ((*fight_p) >= (hazzard_pile.begin())->costs[(*stage_p)-1]) {
        cout << "Note: You already win this hazard card!\n"
        << "Still want to draw card? (y/n): \n";
        cin >> *i2_p;

    }
        //hazzard_pile.begin()->costs[(*stage_p)-1] !=0
    if (((*i2_p) != "no input") && ((*i2_p) == "y"
    || ((*fight_p) < (hazzard_pile.begin())->costs[(*stage_p)-1]))) {
      if ((*i2_p) == "y") {
        (*i2_p) = 1;
      }
      else   cin >> *i2_p;
    }

    }

    // shuffle the cards by generating a randomly new vector
    void shuffle(vector<Card>oldArray, vector<Card> &newArray) {

        for (int i=oldArray.size(); i>0; i--) {
            srand(unsigned(time(NULL)));
            // pick a random index
            int index = rand()%i;
            // push the element with that index to the new vector
            newArray.push_back(oldArray[index]);
            // delelte the picked element from the original vector
            oldArray.erase(oldArray.begin()+index);
        }
    }

void show_background() {
    cout << "                     Basic Theme                  \n" << endl;
    cout << " You are Friday and spend your time on a deserted island.\n After Robinson suddenly capsizes with his ship and runs ashore at your beach, \n your peaceful times are disturbed. To give Robinson a chance to leave the Island again,\n you start to teach him to improve his survival abilities against the hazards of the Island.\n If Robinson beats two Pirates at the end of the game, he successfully leaves the island \n and you will have your beloved peace back ... " << endl;
    }


// the main function officially start from here
int main() {

  int home_page_input = 0;//storing home_page_input
  int rules_page_input = 0;//storing rules_page_input
  char interface1_input = 0;//storing interface1_input
  string interface2_input = "0";//storing interface2_input

  int* home_p = &home_page_input;
  int* rule_p = &rules_page_input;
  char* i1_p = &interface1_input;
  string* i2_p = &interface2_input;

  int stage = 1;//steps of the game
  int life_points = 22;
  int fight_point = 0;
  int free_cards = 0;

  int* stage_p = &stage;
  int* life_p = &life_points;
  int* fight_p = &fight_point;
  int* free_p = &free_cards;

  // ramdomly generating seversl set of cards
  Card h_p[30], k_p[18], a_p[10], p_p[10];
  upload_all_cards(h_p, k_p, a_p, p_p);
  vector<Card> tmp_hazzard_pile;
  vector<Card> tmp_knowledge_pile;
  vector<Card> tmp_aging_pile;
  vector<Card> tmp_pirate_pile;


  for (int i = 0; i < 30; i++) {
    tmp_hazzard_pile.push_back(h_p[i]);
  }
  for (int i = 0; i < 18; i++) {
    tmp_knowledge_pile.push_back(k_p[i]);
  }
  for (int i = 0; i < 10; i++) {
    tmp_aging_pile.push_back(a_p[i]);
  }
  for (int i = 0; i < 10; i++) {
    tmp_pirate_pile.push_back(p_p[i]);
  }

  vector<Card> discard_hazzard_pile, discard_knowledge_pile, hand;
  vector<Card> hazzard_pile;
  vector<Card> knowledge_pile;
  vector<Card> aging_pile;
  vector<Card> pirate_pile;

  shuffle(tmp_hazzard_pile, hazzard_pile);
  shuffle(tmp_knowledge_pile, knowledge_pile);
  shuffle(tmp_aging_pile, aging_pile);
  shuffle(tmp_pirate_pile, pirate_pile);


  // offically start the game
  show_background();
  while (true) {
   
    while ((*home_p) != 1 && (*rule_p) != 1) {
      home_page(home_p);//1: “start”， 2: ”rules”

      if ((*home_p) == 2) {
        show_rules(rule_p); 
      }
    }

    while ((*stage_p) <= 4) {
      interface1(stage_p, life_p, free_p, knowledge_pile, aging_pile,
        hazzard_pile, discard_knowledge_pile, discard_hazzard_pile,
         i1_p);// choose hazard card
         
      if ((*i1_p) == 'b') {
          
        break;
      }
      else if ((*i1_p) == '1') {

        discard_hazzard_pile.push_back(*(hazzard_pile.begin() + 1));// unpick hazard go to discard pile
        hazzard_pile.erase(hazzard_pile.begin() + 1);
        (*free_p) = (hazzard_pile.begin())->free_cards_num;
      }
      else if ((*i1_p) == '2') {
        discard_hazzard_pile.push_back(*(hazzard_pile.begin()));
        hazzard_pile.erase(hazzard_pile.begin());
        (*free_p) = (hazzard_pile.begin())->free_cards_num;
      }
      else {
        cout << "! Invalid input :(\n  Please try again \n";
        break;
      }

      if ((*i1_p) == 'b') {
        
        break;}

      while ((*i2_p) != "b") {// interface2
        int challenge_result;
        int * result_p;
        result_p = &challenge_result;
        interface2(stage_p, life_p, free_p, fight_p, knowledge_pile, aging_pile,
          hazzard_pile, discard_knowledge_pile, discard_hazzard_pile, hand,
          i1_p, i2_p);
        if ((*i2_p) == "b") {
          break;
        }
        else {
          if (hazzard_pile.begin()->costs[(*stage_p)-1]==0){

              discard_knowledge_pile.push_back(*(hazzard_pile.begin()));
              
              cout << "You get ";
              displayFightCard(discard_hazzard_pile.back());
              
              cin >> *i2_p;
              Reset(hand, discard_knowledge_pile, stage_p, fight_p, h_p, k_p);
              //The hand is moved to the knowledge card discard pile, and the combat power, stage, usage and other values are restored;
              break;

          }

          Play(life_p, free_p, fight_p, stage_p, i2_p, hand, knowledge_pile,
                discard_knowledge_pile, hazzard_pile, h_p, k_p,
              *(hazzard_pile.begin()));
              //Including operations such as continuing to draw cards, using card functions, and error reporting of invalid operations, one-step operation at a time (effect prompt);
          string tmp = (*i2_p);
          //To prevent the next line of interface2 from entering input again
          (*i2_p) = "no input";
          interface2(stage_p, life_p, free_p, fight_p, knowledge_pile, aging_pile,
            hazzard_pile, discard_knowledge_pile, discard_hazzard_pile, hand,
            i1_p, i2_p);
          (*i2_p) = tmp;
          (*result_p) = Check(hazzard_pile, knowledge_pile, fight_p,
                    stage_p, life_p, i2_p);//Check the status after each step

          int price; 
          vector<Card>::iterator iter;
          switch (challenge_result) {
            case 0://die
              break;
            case 1://The knowledge card fold pile is gone
              if (aging_pile.size() > 0) {
                discard_knowledge_pile.push_back(*(aging_pile.begin()));
                aging_pile.erase(aging_pile.begin());
              }
              shuffle(discard_knowledge_pile, knowledge_pile);
              for (iter = discard_knowledge_pile.begin(); iter != discard_knowledge_pile.end(); iter++) {
                discard_knowledge_pile.erase(iter);
              }
              break;

            case 2://Challenge success
              discard_knowledge_pile.push_back(*(hazzard_pile.begin()));
              
              cout << "You succeed in challenging this hazzard!\n Now you get ";
              displayFightCard(discard_hazzard_pile.back());
              cout << "\nEnter 1: Continue to next challenge \n";
              cin >> *i2_p;
              Reset(hand, discard_knowledge_pile, stage_p, fight_p, h_p, k_p);
              //The hand is moved to the knowledge card discard pile, and the combat power, stage, usage and other values are restored;
              break;

            case 3://Challenge failed
              discard_hazzard_pile.push_back(*(hazzard_pile.begin()));
              price = (hazzard_pile.begin())->costs[(*stage_p)-1] - (*fight_p);
              //destroy(hand, hazzard_pile, price, h_p, k_p, life_p, stage_p);
              cout << "\nEnter 1: Continue to next challenge \n";
              cin >> *i2_p;
              Reset(hand, discard_knowledge_pile, stage_p, fight_p, h_p, k_p);
              break;

            case 4://In addition to the above four, we must continue
              break;
            }
          if ((*result_p) != 1 && (*result_p) != 4) break;//Loop out of interface 2 (jump twice in a row)
    }

    if ((*i2_p) == "b") break;

    if ((*result_p) == 2 || (*result_p) == 3) {
      hazzard_pile.erase(hazzard_pile.begin());
      if (hazzard_pile.size() == 0) {//Run out of crisis cards and move on to the next stage
        shuffle(discard_hazzard_pile, hazzard_pile);
        (*stage_p)++;
        if (*stage_p < 4) cout << "Stage " << *stage_p << "!\n";
        else {cout << "Now come the pirates!";}
      }
    }
    else if (challenge_result == 0) break;
  }

  if (*life_p < 0) cout << "You fail. :(" << endl;
  else if ((*i1_p) == 'b') continue;
  else if(*(stage_p)==4 && hazzard_pile.size()==0) cout << "You win! Congratulations!" << endl;

    }//end
  }
return 0;

}
