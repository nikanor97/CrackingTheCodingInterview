//
// Created by nikita on 06.07.19.
//

#include <iostream>
#include <string>

void fillSpaces(std::string & s){
    int numEndSpases = 0;
    for (int i = s.length() - 1; i != -1; i--){
        if (s[i] == ' '){
            numEndSpases++;
        }
        else{
            break;
        }
    }
    for (int i = s.length() - 1 - numEndSpases; i != -1; i--){
        if (numEndSpases < 0){
            break;
        }
        if (s[i] != ' '){
            s[i + numEndSpases] = s[i];
        }
        else{
            s[i + numEndSpases] = '0';
            s[i + numEndSpases - 1] = '2';
            s[i + numEndSpases - 2] = '%';
            numEndSpases -= 2;
        }
    }
}

int main(){
    std::string s1;
    std::getline(std::cin, s1);
    //std::cout << s1.length() << std::endl;
    fillSpaces(s1);
    std::cout << s1 << std::endl;
    return 0;
}