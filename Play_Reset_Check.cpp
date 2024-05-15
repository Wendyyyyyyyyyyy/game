void displayFightCard(Card card){
    cout << " { "
         << card.knowledge_name << "  "
         << card.fight_point << "  "
         << card.remove_price << " [ "
         << card.usable_time << "] }" <<endl;
}


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

void initial(Card &card) {   //Initialiazes the usable_time
                             //and the effects of a drawn card;
  for (int i = 0; i < 30; i++) {
    if (h_p[i].knowledge_name == card.knowledge_name) card.usable_time = h_p[i].usable_time;
  }
  for (int i = 0; i < 18; i++) {
    if (k_p[i].knowledge_name == card.knowledge_name) card.usable_time = k_p[i].usable_time;
  }
}

void eliminate_effect(vector<Card> &hand, vector<Card> &hazzard_pile, Card card) {//Eliminates the drawn card's effect
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

void destroy(vector<Card> &hand, vector<Card> &hazzard_pile, int &price) {
  char destroy_more = 'y';
  while (destroy_more == 'y') {
    cout << "Pls choose a card in hand to be destroyed (index): ";
    int index;
    cin >> index;
    if (price == -1) {    //When "destroy" works as a card function, no cost.
      eliminate_effect(hand, hazzard_pile, *(hand.begin() + index - 1));///////
      initial(*(hand.begin() + index - 1));
      hand.erase(hand.begin() + index - 1);
    }

    else if (price >= (hand.begin() + index - 1)->remove_price) {//When costs life
      price -= (hand.begin() + index - 1)->remove_price;
      eliminate_effect(hand, hazzard_pile, *(hand.begin() + index - 1));///////
      initial(*(hand.begin() + index - 1));
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

void copy(vector<Card> &hand, Card this_card) {
  while (true) {
    cout << "Choose another card to copy (index): ";
    int index;
    cin >> index;
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
          initial(*iter);
        }
      }
      displayHand(hand);
      break;
    }
  }
}

void below(vector<Card> &hand, vector<Card> &knowledge_pile, Card this_card) {
  while (true) {
    cout << "Choose another card to put below the discard knowledge pile (index): ";
    int index;
    cin >> index;
    if ((*(hand.begin() + index - 1)).knowledge_name == this_card.knowledge_name
     || index > hand.size() || index <= 0) {
      cout << "! Invalid index :( Please type again.\n";
      continue;
    }
    else {
      knowledge_pile.push_back(*(hand.begin() + index - 1));
      (*fight_p) -= (*(hand.begin() + index - 1)).fight_point;
      initial(*(hand.begin() + index - 1));
      hand.erase(hand.begin() + index - 1);
      displayHand(hand);
      break;
    }
  }
}

void exchange(vector<Card> &hand, vector<Card> &knowledge_pile,
  vector<Card> &discard_knowledge_pile, Card this_card) {
  while (true) {
    cout << "Choose another card to exchange (index): ";
    int index;
    cin >> index;
    if ((*(hand.begin() + index - 1)).knowledge_name == this_card.knowledge_name
     || index > hand.size() || index <= 0) {
      cout << "! Invalid index :( Please type again.\n";
      continue;
    }
    else {
      vector<Card>::iterator iter;
      for (iter = hand.begin(); iter != hand.end(); iter++) {
        if ((*iter).knowledge_name == (*(hand.begin() + index - 1)).knowledge_name) {
          initial(*(iter));
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

void Double(vector<Card> &hand, Card card) {
  vector<Card>::iterator iter;
  for (iter = hand.begin(); iter != hand.end(); iter++) {
    if ((*iter).knowledge_name == card.knowledge_name) continue;
    else (iter->fight_point) *= 2;
  }
  displayHand(hand);
}

void sort(vector<Card> knowledge_pile) {
  cout << "Now you can see the 3 knowledge cards on knowledge_pile top: \n";
  vector<Card>::iterator iter;
  for (iter = knowledge_pile.begin(); iter != knowledge_pile.begin() + 3; iter++) {
    displayFightCard(*iter);
  }
}

void fear(vector<Card> &hand) {
  vector<Card>::iterator iter;
  for (iter = hand.begin(); iter != hand.end(); iter++) {
    if ((*iter).fight_point > 0) (*iter).fight_point = 0;
  }
  displayHand(hand);
}

void stop(Card &card) {
  card.free_cards_num = 0;
}

void do_function(vector<Card> &hand, vector<Card> &knowledge_pile,
  vector<Card> &discard_knowledge_pile, vector<Card> &hazzard_pile, Card card) {
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
    copy(hand, card);
  }
  else if (card.knowledge_name == "Cognition: 1x destroy") {
    int price = -1;
    destroy(hand, hazzard_pile, price);
  }
  else if (card.knowledge_name == "Trick: 1x below the stack") {
    below(hand, knowledge_pile, card);
  }
  else if (card.knowledge_name == "Books: -1 stage") {
    (*stage_p)--;
  }
  else if (card.knowledge_name == "Strategy: 1x exchange") {
    exchange(hand, knowledge_pile, discard_knowledge_pile, card);
  }
  else if (card.knowledge_name == "Strategy: 2x exchange") {
    exchange(hand, knowledge_pile, discard_knowledge_pile, card);
    exchange(hand, knowledge_pile, discard_knowledge_pile, card);
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
    double(hand);
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





void Play(int* life_p, int* free_p, int* fight_p, string* i2_p,
      vector<Card> &hand, vector<Card> &knowledge_pile,
      vector<Card> &discard_knowledge_pile, vector<Card> &hazzard_pile, Card danger) {

    while (true) {
      if ((*i2_p) == "1" || (*i2_p) == "4") { //抽一张知识牌到手牌
        if ((*i2_p) == "4") {               //选择消耗生命力来抽牌
          (*life_p) -= 1;
        }
        hand.push_back(*(knowledge_pile.begin()));
        knowledge_pile.erase(knowledge_pile.begin());
        cout << "# A card has been drawn from you knowledge_pile to your hand: \n";
        (*fight_p) += (hand.end()->fight_point);
        (*free_p) --;
        displayHand(hand);

        if (hand.end()->usable_time < 0) { //抽到衰老牌自动发动功能
          do_function(hand, knowledge_pile, discard_knowledge_pile,
            hazzard_pile, hand.back());
        }
        break;
      }

      else if ((*i2_p) == "2") {      //执行牌功能
        bool isValid = 0;
        while (isValid == 0) {
          cout << "Of which card function do you want to use?"
          << " (Enter a index)";
          int index;
          cin >> index;
          if ((hand.begin() + index - 1)->usable_time <= 0) {
            cout << "! Invalid input :(\n";
            continue;
          }
          else {
            do_function(hand, knowledge_pile, discard_knowledge_pile,
              hazzard_pile, *(hand.begin() + index - 1));
            (hand.begin() + index - 1)->usable_time--;
            isValid = 1;
          }
        }
        break;
      }

      else if ((*i2_p) == "3") {      //消耗生命力to skip
        int price = (hazzard_pile.begin())->costs[*stage_p] - (*fight_p);
        cout << "Are you sure to pay " << price << " to skip this danger? (y/n) ";
        char ans;
        cin >> ans;
        if (ans == 'y') {
          (*life_p) -= price;
          cout << "Now your life point is " << *life_p << ". ";
          destroy(hand, hazzard_pile, price);
          break;
        }
        else {
          cout << "Make a choice again: ";
          cin >> *i2_p;
        }
      }
    }

}

void Reset(vector<Card> &hand, vector<Card> &discard_knowledge_pile) {
  vector<Card>::iterator iter;
  for (iter = hand.begin(); iter != hand.end(); iter++) {
    if ((*iter).knowledge_name == "Books: -1 stage") {
      (*stage_p)++;
    }
    initial(*iter);
    discard_knowledge_pile.push_back(*iter);
    hand.erase(iter);
  }
  (*fight_p) = 0;
}

int Check(vector<Card> hazzard_pile, vector<Card> knowledge_pile, int* fight_p,
          int* stage_p, int* life_p, string* i2_p) {
  Card danger = (*(hazzard_pile.begin()));
  bool win = ((*fight_p) >= (hazzard_pile.begin())->costs[*stage_p]);
  if ((*life_p) < 0) return 0;
  else if (knowledge_pile.size() == 0) return 1;
  else if (win) return 2;
  else if ((!win) && ((*i2_p) == "4")) return 3;
  else return 4;
}
