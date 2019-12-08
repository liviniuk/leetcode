class Solution {
private:
    void backtracking(vector<int>& candidates, int target, int startIndex, vector<vector<int>>& solutionSet, vector<int>& combination) {
        if (target == 0) {
            // combination is a valid solution
            solutionSet.push_back(combination);
            return;
        }
        for (int i = startIndex; i < candidates.size() && candidates[i] <= target; ++i) {
            combination.push_back(candidates[i]); // progress
            backtracking(candidates, target - candidates[i], i, solutionSet, combination); // recurse
            combination.pop_back(); // backtrack
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> solutionSet;
        vector<int> combination;
        backtracking(candidates, target, 0, solutionSet, combination);
        return solutionSet;
    }
};
