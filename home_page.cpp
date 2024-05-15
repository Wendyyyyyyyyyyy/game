

#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>//rand(), srand()
#include <ctime>//time()
#include "home_page.h"
using namespace std;

void home_page(int* home_p) {
  cout << "～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～" << endl;
  cout << "FRIDAY"<< endl;
  cout << "Home Page" << endl;
  cout << "Please choose: " << endl;
  cout << "1: Start     2: Show Rules\n";
  cin >> *home_p;
}
