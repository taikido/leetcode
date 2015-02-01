"""============================================================================
* Name : solution.py
* Author: taikido
* Description: Leetcode Problem 3: Longest Substring Without Repeating Characters
* Source: https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
* Date: Jan.2015
* Status: Accepted
*==========================================================================="""

class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        d = {}
        maxL = 0
        l = 0
        idx = 0

        for i in range(len(s)):
            if (s[i]) not in d.keys():
                d[s[i]] = i
                l += 1
            else:
                if (d[s[i]] >= idx):
                    l = i - d[s[i]]
                    idx = d[s[i]] + 1 #Start of new unique substring
                    d[s[i]] = i
                else:
                    # If char is already in dict but appears outside of range of new substring,
                    # index char in dict and increment length count (same as first if)
                    d[s[i]] = i
                    l += 1

            maxL = l if l > maxL else maxL

        return maxL

def test():
    #s = "bbcdefbb"
    #s = "bcbafdeab"
    # s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco"
    s = "hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcacwlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco"
    #print "String: ", s
    t = Solution()
    print "length: ", t.lengthOfLongestSubstring(s)


if __name__ == "__main__":
    test()


