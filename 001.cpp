#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> m;
        int n = nums.size();
        for (auto i = 0; i < n; ++i) {
            int diff = target - nums[i];
            if (m.find(diff) != m.end())
                return std::vector<int>({m[diff], i});
            m.insert(pair<int, int>(nums[i],i));
        }
        return std::vector<int>({0,0});
    }
};

int main() {
    Solution solution;

    vector<int> input = {2, 7, 11, 15};
    vector<int> true_answer = {0, 1};
    
    cout << (solution.twoSum(input, 9) == true_answer ? "correct" : "wrong") << '\n';

    return 0;
}
