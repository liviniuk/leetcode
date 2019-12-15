class Solution {
private:
    vector<bool> used;
    
    void recursive_permutate(vector<int>& nums, vector<int>& perm, vector<vector<int>>& perms) {
        // cout << "pos: " << pos << " perm: "; for (auto i : perm) cout << i; cout << endl;
        if (perm.size() == nums.size()) {
            perms.push_back(perm);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) 
                continue;
            else if (i > 0 && nums[i - 1] == nums[i] && used[i - 1]) // to avoid repetitions use only at the first [unused] occurance
                continue;
            perm.push_back(nums[i]);
            used[i] = true;
            recursive_permutate(nums, perm, perms);
            used[i] = false;
            perm.pop_back();
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        vector<vector<int>> perms = vector<vector<int>>();
        vector<int> perm = vector<int>();
        recursive_permutate(nums, perm, perms);
        return perms;
    }
};
