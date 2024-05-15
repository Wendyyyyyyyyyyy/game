//shuffle for cards
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>//rand(), srand()
#include <ctime>//time()
using namespace std;

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
// the code below can be used for testing.


/*
void Print( vector<Card>oldArray, vector<Card> &newArray ) {
    cout<<"原数组：";
    for (vector<Card>::iterator it = oldArray.begin() ; it!=oldArray.end() ; it++) {
        cout<<*it<<" ";
    }

    cout<<endl<<"打乱后的数组：";
    for (vector<Card>::iterator it = newArray.begin() ; it!=newArray.end() ; it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main() {

  vector<Card> old;
  vector<Card> new1;
  int LENGTH = old.size();

  for (int i = 0; i< 10; i++){
      old.push_back(i);
  }

  shuffle(old, new1);
  Print(old, new1);

  return 0;
}

*/
