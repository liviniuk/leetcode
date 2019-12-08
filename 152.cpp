class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currProd = 1;
        int maxProd = nums[0];
        int firstNegProd;
        bool negEncountered = false;
        for (auto it = nums.begin(); ; ++it) {
            if (it == nums.end() or *it == 0) {
                // Consider case when odd number of negative nums used
                if (negEncountered and currProd < 0) {
                    currProd /= firstNegProd;
                    maxProd = max(maxProd, currProd);
                }
                // Exit loop
                if (it == nums.end())
                    break;
                // Reset algorithm if 0 encountered
                if (*it == 0) {
                    maxProd = max(maxProd, 0);
                    negEncountered = false;
                    currProd = 1;
                    continue;
                }
            }
            
            // Include current num in the product
            currProd *= *it;
            maxProd = max(currProd, maxProd);
            
            // Store product at first negative num encountered
            // Unless next is 0 or end
            if (!negEncountered and *it < 0)
                if ((it + 1) != nums.end() and *(it + 1) != 0) {
                    negEncountered = true;
                    firstNegProd = currProd;
                    auto lastNeg = it;                    
                }
        }
        return maxProd;
    }
};
