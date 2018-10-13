#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max = 1;
        int first = 0; // index of the first letter
        int len = s.size();
        if (len <= 1) {
            return s;
        }
        for (int center = 0; center < len; center++) {
            // explore every letter a center node of a palindrom
            int l = 0;
            bool palindrom = true;
            while (palindrom and l < center and center + l + 1 < len) {
                if (s[center - l - 1] != s[center + l + 1]) {
                    palindrom = false;
                } else {
                    l++;
                }
            }
            int max_candidate = 2 * l + 1;
            if (max_candidate >= max) {
                max = max_candidate;
                first = center - l;
            }
            
            // explore every letter a left-to-center node of a palindrom
            l = 0;
            palindrom = true;
            while (palindrom and l <= center and center + 1 + l < len) {
                if (s[center - l] != s[center + 1 + l]) {
                    palindrom = false;
                } else {
                    l++;
                }
            }
            max_candidate = 2 * l;
            if (max_candidate >= max) {
                max = max_candidate;
                first = center - l + 1;
            }
        }
        return s.substr(first, max);
    }
};
int main() {
    return 0;
}
