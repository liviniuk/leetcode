class Solution {
public:
    vector<vector<int>> combinationSumRecursive(vector<int>& candidates, int target, int startIndex) {
        vector<vector<int>> solutionSet;
        int n = candidates.size();
        for (int i = startIndex; i < n; ++i) {
            if (candidates[i] > target)
                continue;
            else if (candidates[i] < target) {
                vector<vector<int>> solutions = combinationSumRecursive(candidates, target - candidates[i], i);
                for (vector<int> solution : solutions) {
                    solution.insert(solution.begin(), candidates[i]);
                    solutionSet.push_back(solution);
                }
            } else { // candidates[i] == target
                vector<int> solution = {candidates[i]};
                solutionSet.push_back(solution);
            }
        }
        return solutionSet;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return combinationSumRecursive(candidates, target, 0);
    }
};
