#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct number {
        int value;
        std::string representation;
    };
    
    std::vector<number> lib {
        {1000, std::string("M")},
        {900, std::string("CM")},
        {500, std::string("D")},
        {400, std::string("CD")},
        {100, std::string("C")},
        {90, std::string("XC")},
        {50, std::string("L")},
        {40, std::string("XL")},
        {10, std::string("X")},
        {9, std::string("IX")},
        {5, std::string("V")},
        {4, std::string("IV")},
        {1, std::string("I")},
    };
    
    string intToRoman(int num) {
        std:string answer("");
        int num_k = lib.size();
        for (int k = 0; k < num_k; k++) {
            for (int i = num / lib[k].value; i > 0; i--) {
                answer.append(lib[k].representation);
                num %= lib[k].value;
            }
        }
        return answer;
    }
};

int main() {
    return 0;
}
