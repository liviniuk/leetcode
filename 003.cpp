#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len <= 1) {
            return len;
        }
        int max = 1;
        int first = 0; // beginning of the current substring
        for (int last = 1; last < len; last++) {
            // check if repetition
            for (int i = first; i < last; i++) {
                if (s[i] == s[last]) {
                    first = i + 1;
                }
            }
            if (max < last - first + 1) {
                max = last - first + 1;
            }
        }
        return max;
    }
};

int main() {
    return 0;
}
