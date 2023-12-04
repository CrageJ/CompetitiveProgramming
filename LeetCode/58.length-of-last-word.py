#
# @lc app=leetcode id=58 lang=python3
#
# [58] Length of Last Word
#

# @lc code=start
class Solution:
    def lengthOfLastWord(self, s: str) -> int:

        sp = len(s.split()[-1])
        s =s.lstrip()
        s =s.rstrip()
        #print("sss",int(" "))
        for idx,val in enumerate(reversed(s)):
            #print(val)
            #print(val, int(val))
            print(val, val == " ")
            if (val == ' '):
                return idx
                
        return len(s)
        
# @lc code=end

