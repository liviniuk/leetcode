#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(closest - target);
        
        for (auto i = nums.begin(); i != nums.end() - 2; i++) {
            for (auto j = i + 1; j != nums.end() - 1; j++) {
                for (auto k = j + 1; k != nums.end(); k++) {
                    int sum = *i + *j + *k;
                    int diff2 = abs(sum - target);
                    // cout << *i << ' ' << *j << ' ' << *k << ' ' << sum << ' ' << diff2 << '\n';
                    if (diff2 < diff) {
                        closest = sum;
                        diff = diff2; 
                    }
                }
            }
        }
        return closest;
    }
};

int main() {
    return 0;
}
