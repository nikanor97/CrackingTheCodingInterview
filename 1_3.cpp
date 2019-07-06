//
// Created by nikita on 04.07.19.
//

#include <iostream>
#include <string>
#include <unordered_map>

int main(){
    std::string s1, s2;
    std::unordered_map<char, int> m1, m2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);
    for (int i = 0; i < s1.length(); i++){
        if (m1.find(s1[i]) == m1.end()){
            m1.insert(std::make_pair(s1[i], 1));
        }
        else{
            m1[s1[i]] += 1;
        }
    }
    for (int i = 0; i < s2.length(); i++){
        if (m2.find(s2[i]) == m2.end()){
            m2.insert(std::make_pair(s2[i], 1));
        }
        else{
            m2[s2[i]] += 1;
        }
    }
    for (auto it = m1.begin(); it != m1.end(); it++){
        char key = it->first;
        int value = it->second;
        if (m2.find(key) == m2.end()){
            std::cout << "no" << std::endl;
            return 0;
        }
        else{
            if (m2.find(key)->second != value){
                std::cout << "no" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "yes" << std::endl;
    return 0;
}