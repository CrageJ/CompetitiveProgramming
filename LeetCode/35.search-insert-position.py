# coding: utf-8
from string import *
from re import *
from datetime import *
from collections import *
from heapq import *
from bisect import *
from copy import *
from math import *
from random import *
from statistics import *
from itertools import *
from functools import *
from operator import *
from io import *
from sys import *
from json import *
from builtins import *

import string
import re
import datetime
import collections
import heapq
import bisect
import copy
import math
import random
import statistics
import itertools
import functools
import operator
import io
import sys
import json

from typing import *
#
# @lc app=leetcode id=35 lang=python3
#
# [35] Search Insert Position
#

# @lc code=start
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums)-1

        while (l <= r):
            m = ( l + r ) // 2
            left = nums[l]
            right = nums[r]
            middle = nums[m]
            if (left == target):
                return l
            if (right == target):
                return r
            if (middle == target):
                return m
            if (target < middle ):
                r = m - 1
            elif target > middle:
                l = m + 1
            
        return l
        
        

        
# @lc code=end

