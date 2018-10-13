#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int n = 0;
        int i = 0;
        while (str[i] == ' ') {
            i++;
        }
        
        int sign = 1;
        if (str[i] == '+') {
            i++;
        } else if (str[i] == '-') {
            sign = -1;
            i++;
        }
        
        while(str[i] >= '0' and str[i] <= '9') {
            int tmp = 10 * n + str[i] - '0';
            if ((long)n * 10 + str[i] - '0' != (long)tmp) {
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            n = tmp;
            i++;
        }
        return n * sign;
    }
};

int main() {
    return 0;
}
