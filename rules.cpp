#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>//rand(), srand()
#include <ctime>//time()
#include "rules.h"
using namespace std;

void show_rules(int* rule_p)
{
    ifstream fin;
    fin.open("rules.txt");
    if (fin.fail())
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    string line;

    while (getline(fin, line))
    {
        cout << line << endl;
    }

    fin.close();
    cout<< "Please enter 1 to start game" << endl;

    cin >> *rule_p;
    while (*rule_p !=1){
        cout<< "Please enter 1 to start game" << endl;
        cin >> *rule_p;

    }
}
