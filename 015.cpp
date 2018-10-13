#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        if (nums.size() < 3)
            return answer;
        sort(nums.begin(), nums.end());
        
        for (auto i = nums.begin(); i != nums.end() - 2; i++) {
            unordered_set<int> nums_between;
            // to prevent answer duplicates consider only the FIRST duplicating num
            if (i == nums.begin() or *(i - 1) != *i)
                for (auto j = i + 1; j != nums.end(); j++) {
                    // to prevent answer duplicates consider only the LAST duplicating num
                    if (j + 1 == nums.end() or *(j + 1) != *j) {
                        int num2find = -(*i + *j);
                        if (nums_between.find(num2find) != nums_between.end())
                            answer.push_back(vector<int>({*i, num2find, *j}));
                    }
                    nums_between.insert(*j);
                }
        }
        return answer;
    }
}; 

int main() {
    return 0;
}
