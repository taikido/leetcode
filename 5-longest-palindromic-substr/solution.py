"""============================================================================
* Name : solution.py
* Author: taikido
* Description: Leetcode Problem 5: Longest Palindromic Substring
* Source: https://oj.leetcode.com/problems/longest-palindromic-substring/
* Date: Jan.2015
* Status: Time Limit Exceeded,
* Updates: Updated to return longest word and not just word
*==========================================================================="""

class Solution:

    def isPalindrome(self, s):
        n = len(s)

        if n <= 2:
            return True

        mid = int(n/2)
        isEven = (n % 2 == 0)

        if isEven:
            stopRange = mid-1
        else:
            stopRange = mid
        # print "Is string even: ", isEven
        # for i in range(n-1, -1, -1)
        j = 0
        for i in range(n-1, stopRange, -1):
            if s[i] != s[j]:
                return False
            j += 1
        return True

    # @return a string
    def longestPalindrome(self, s):
        n = len(s)

        if n == 0:
            return ""

        if n <= 2:
            return s
        p = n
        found = 0

        longest = s[0]

        while not found:
            # print "p: ", p
            # print "========================="
            # for i in range(p):
            for j in range(n-p+1):
                word = s[j:j+p]
                # print "test: ", word
                if self.isPalindrome(word):
                    found = 1

                    if len(word) > len(longest):
                        longest = word;

            p -= 1

            if p == 0:
                found = 1
        return longest
