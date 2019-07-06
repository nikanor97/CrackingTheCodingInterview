//
// Created by nikita on 04.07.19.
//
#include <iostream>
#include <string>
#include <memory.h>

void reverse(char* str){
    int len = strlen(str);
    char tmp_c;
    for (int i = 0; i < len / 2; i++){
        tmp_c = str[len - 1 - i];
        str[len - 1 - i] = str[i];
        str[i] = tmp_c;
    }
}

int main(){
    std::string inp;
    std::getline(std::cin, inp);
    char* str = new char[inp.length()];
    strcpy(str, inp.c_str());
    reverse(str);
    std::cout << str << std::endl;
    delete [] str;
    return 0;
}