#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    bool buf[256];
    for (int i; i < 256; i++){
        buf[i] = false;
    }
    std::string inp;
    std::getline(std::cin, inp);
    if (inp.size() > 256){
        std::cout << "nope" << std::endl;
        return 0;
    }
    for (int i = 0; i < inp.size(); i++){
        int idx = (int)inp[i];
        if (buf[idx]){
            std::cout << "nope" << std::endl;
            return 0;
        }
        buf[idx] = true;
    }
    std::cout << "all symbols are different" << std::endl;
    return 0;
}