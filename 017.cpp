#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<int, string> buttons {
        {'1', "*"},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
        
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        for (auto l = buttons[digits[0]].begin(); l != buttons[digits[0]].end(); l++) {
            vector<string> next = letterCombinations(digits.substr(1));
            if (next.size() == 0)
                next.push_back("");
            for (auto m = next.begin(); m != next.end(); m++) {
                combinations.push_back(*l + *m);
            }
        }
        return combinations;
    }
};

int main() {
    return 0;
}
