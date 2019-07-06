//
// Created by nikita on 06.07.19.
//

#include <iostream>
#include <string>
#include <vector>

std::string compressString(const std::string & s){
    std::string resStr;
    int resStrLen = 0;
    if (s.length() == 1){
        return s;
    }
    else {
        int seqLen = 0;
        char curChar = s[0];
        for (char i : s) {
            if (i == curChar) {
                seqLen += 1;
            } else {
                resStrLen += 2;
                curChar = i;
                seqLen = 1;
            }
        }
        resStrLen += 2;
    }
    if (resStrLen >= s.length()){
        return s;
    }
    resStr.reserve(resStrLen);
    if (s.length() > 1) {
        int seqLen = 0;
        char curChar = s[0];
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == curChar){
                seqLen += 1;
            }
            else{
                resStr += curChar;
                resStr += std::to_string(seqLen);
                curChar = s[i];
                seqLen = 1;
            }
        }
        resStr += curChar;
        resStr += std::to_string(seqLen);
    }
    return resStr;
}

int main(){
    std::string s;
    std::getline(std::cin, s);
    std::cout << compressString(s);
    return 0;
}