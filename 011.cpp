#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size() - 1;
        auto i = height.begin();
        auto j = --height.end();
        int max = 0;
        while (i < j) {
            // std::cout << *i << ' ' << *j << ' ' << len << '\n';
            if (*i < *j) {
                max = std::max(max, len * *i);
                --len;
                ++i;
            } else {
                max = std::max(max, len * *j);
                --len;
                --j;
            }
        }
        return max;
    }
};

int main() {
    return 0;
}
