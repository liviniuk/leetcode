#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int len = s.size();
        std::string result = std::string(len, '-');
        int i = 0;
        // first row
        for (int j = 0; j < len; j += 2 * numRows - 2) {
            result[i++] = s[j];
        }
        // middle rows
        for (int row = 1; row < numRows - 1; row++) {
            for (int j = row; j < len; j += 2 * numRows - 2) {
                result[i++] = s[j];
                int second = j + 2 * (numRows - row - 1);
                if (second < len) {
                    result[i++] = s[second];
                }
            }
        }
        // last row
        for (int j = numRows - 1; j < len; j += 2 * numRows - 2) {
            result[i++] = s[j];
        }
        return result;
    }
};

int main() {
    return 0;
}
