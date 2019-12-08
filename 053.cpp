class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane’s Algorithm
        int n = nums.size();
        int maxSum = nums[0];
        int prevSum = nums[0];
        for (int i = 1; i < n; ++i) {
            prevSum = nums[i] + max(0, prevSum);
            maxSum = max(maxSum, prevSum);
        }
        return maxSum;
    }
};
