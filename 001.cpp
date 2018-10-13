#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        for (int i = 0; i != size - 1; i++) {
            for (int j = i + 1; j != size; j++) {
                if (nums[i] + nums[j] == target) {
                    return vector<int>({i, j});
                }
            }
        }
    }
};

int main() {
    Solution solution;

    vector<int> input = {2, 7, 11, 15};
    vector<int> true_answer = {0, 1};
    
    cout << (solution.twoSum(input, 9) == true_answer ? "correct" : "wrong") << '\n';

    return 0;
}
