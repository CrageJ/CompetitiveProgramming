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
# @lc app=leetcode id=9 lang=python3
#
# [9] Palindrome Number
#

# @lc code=start
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if (x < 0):
            return False
        i  = x
        invx  = 0
        while (i != 0):
            invx = invx *10 + i%10
            i//=10

        
        return invx == x


# @lc code=end
    
def main():
    s = Solution()
    i = s.isPalindrome(20)
    print (i)

if __name__ == "__main__":
    main()



    

