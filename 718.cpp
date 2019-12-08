class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        // 1. Consider all substrings starting at 0: A[0:i] and B[0:j]
        // 2. For each pair, find the Longest Common Suffix
        // Dynamic programming will produce O(m*n) runtime.
        int m = A.size();
        int n = B.size();
        int suffix[m+1][n+1];
        int result = 0;
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= n; ++j) {
                if (i == 0 or j == 0 or A[i-1] != B[j-1])
                    suffix[i][j] = 0;
                else {
                    suffix[i][j] = suffix[i-1][j-1] + 1;
                    result = max(result, suffix[i][j]);
                }
            }
        return result;
    }
};
