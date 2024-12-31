# First python leetcode omg
# brute force - try every possible combination of numbers

# omg accepted on first try with no syntax errors 
#   just had to chatgpt how to do the i, j = i + 1
# Solved in 4.5 min
# Time - O(n^2)
# Space - O(1)
'''
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if (nums[i] + nums[j] == target):
                    return [i, j]
        return [-1, -1]
'''

# Optimize with hashmap (dictionary in python)
# Solved in 6 min
#   had to figure out how to check if key exists in dict
# Time - O(1)
# Space - O(n)

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for i in range(len(nums)):
            if (target - nums[i]) in map:
                return [i, map[target - nums[i]]]
            else:
                map[nums[i]] = i
        return [-1, -1]