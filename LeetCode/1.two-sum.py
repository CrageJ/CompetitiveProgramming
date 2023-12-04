#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
import sys
import math
import collections
import typing
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i_map  = dict(map(lambda num: (num[1],num[0]),enumerate(nums)))
        print(i_map)
        for idx, num in enumerate(nums):
            if target-num in i_map and i_map[target-num] is not idx:
                return [idx,i_map[target-num]]
            
        return [-1,-1]
   
# @lc code=end

