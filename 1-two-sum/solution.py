"""============================================================================
* Name : solution.py
* Author: taikido
* Description: Leetcode Problem 1: Two Sum
* Source: https://oj.leetcode.com/problems/two-sum/
* Date: Jan.2015
* Status: Accepted
*==========================================================================="""

class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        d = {}
        for i in range (len(num)):
            j=target - num [i]
            if j in d.keys():
                idx = d[j]
                return (i+1, idx+1) if i < idx else (idx+1,i+1)
            d [num [i]] = i
