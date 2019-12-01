#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for (auto i = 0; i < n; ++i) {
            auto diff_it = hash.find(target - nums[i]);
            if (diff_it != hash.end())
                return vector<int> {diff_it->second, i};
            hash[nums[i]] = i;
        }
        return vector<int>({0,0});
    }
};

int main() {
    Solution solution;

    vector<int> input = {2, 7, 11, 15};
    vector<int> true_answer = {0, 1};
    
    cout << (solution.twoSum(input, 9) == true_answer ? "correct" : "wrong") << '\n';

    return 0;
}
