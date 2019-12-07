class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int j = 0;
        int count = 0;
        while (j < len) {
            while (j < len - 1 and nums[j+1] == nums[j])
                ++j;
            nums[count++] = nums[j++];
        }
        return count;
    }
};
