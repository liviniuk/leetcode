import numpy as np

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums = np.array(nums)
        nums = np.sort(nums)
        ans = []
        
        for a in range(len(nums) - 3):
            # to prevent answer duplicates consider only the FIRST duplicating num
            if a == 0 or nums[a - 1] != nums[a]:
                for d in range(a + 3, len(nums)):
                    # to prevent answer duplicates consider only the LAST duplicating num
                    if d == len(nums) - 1 or nums[d] != nums[d+1]:
                        # target for b + c = t = target - a - d
                        t = target - nums[a] - nums[d]
                        # store seen values in a set
                        s = set()
                        for c in range(a + 1, d):
                            t_b = t - nums[c]
                            # to prevent answer duplicates consider only the LAST duplicating num
                            if t_b in s and (c == d - 1 or nums[c] != nums[c + 1]):
                                ans.append([nums[a], t_b, nums[c], nums[d]])
                            s.add(nums[c])
        
        return ans
