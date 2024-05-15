#include <iostream>
#include <string>

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
