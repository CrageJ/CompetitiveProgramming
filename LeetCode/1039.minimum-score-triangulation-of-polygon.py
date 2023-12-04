# coding: utf-8
import queue
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
# @lc app=leetcode id=1039 lang=python3
#
# [1039] Minimum Score Triangulation of Polygon
#

# @lc code=start
class Solution:
    @lru_cache(maxsize=None)
    def helper(self, values : tuple) -> int:
        edges = len(values)
        triangles = edges -2
        
        if (triangles <= 0):
            return 0
        
        if (triangles == 1):
            return math.prod(values)
        
        maxSum:int =sys.maxsize
        for i in range(edges):
            # get first 3 values as triangle
            triangle : int = math.prod(values[0:3])

            #construct rest of shape
            otherValues: List[int] = [values[0]]
            otherValues.extend(values[2:])

            #
            rest_of = self.minScoreTriangulation(otherValues)
            
            maxSum = min(maxSum, triangle + rest_of)
            
            t1 : tuple = values[1:]
            t2 : tuple = (values[0],)


            values = t1 + t2
            #print(values)
        

        return maxSum
        

    def minScoreTriangulation(self, values: List[int]) -> int:
        return (self.helper(tuple(values)))
 
        
        
        
# @lc code=end

