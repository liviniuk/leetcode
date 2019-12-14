class Solution {
private:
    void recursive_permutate(vector<int>& nums, vector<int>& perm, vector<vector<int>>& perms, int pos) {
        if (pos == nums.size())
            perms.push_back(perm);
        
        for (int i = pos; i < nums.size(); ++i) {
            perm.push_back(nums[i]);
            swap(nums[i], nums[pos]);
            recursive_permutate(nums, perm, perms, pos + 1);
            swap(nums[i], nums[pos]);
            perm.pop_back();
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms = vector<vector<int>>();
        vector<int> perm = vector<int>();
        recursive_permutate(nums, perm, perms, 0);
        return perms;
    }
};
