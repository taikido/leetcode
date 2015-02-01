"""============================================================================
* Name : solution.py
* Author: taikido
* Description: Leetcode Problem 4: Median of 2 Sorted Arrays
* Source: https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
* Date: Jan.2015
* Status: Accepted
*==========================================================================="""

class Solution:
    # @return a float
    def findMedianSortedArrays(self, A, B):
        n = len(A)
        m = len(B)

        if n == 1 and m == 0:
            return A[0]
        if m == 0 and n == 1:
            return B[0]

        num_elems = n+m
        med_idx =  int((num_elems)/2)

        print "Median Idx: ", med_idx
        i, j, k, prev, curr = 0, 0, 0, 0, 0

        while n > 0 and m > 0:
            if A[i] < B[j]:
                curr = A[i]
                i += 1
                n -= 1
            else:
                curr = B[j]
                j += 1
                m -= 1

            if k == med_idx:
                if num_elems % 2 != 0: # Mod the num_elems and not med_idx
                    return curr
                else:
                    return float(prev + curr)/2

            k += 1
            prev = curr



        while n > 0:
            curr = A[i]
            if k == med_idx:
                if num_elems % 2 != 0:
                    return curr
                else:
                    return float(prev + curr)/2
            i += 1
            k += 1
            prev = curr
            n -= 1

        while m > 0:
            curr = B[j]
            if k == med_idx:
                if num_elems % 2 != 0:
                    return curr
                else:
                    return float(prev + curr)/2

            j += 1
            k += 1
            prev = curr
            m -= 1


def test():
#     b = float(2 + 3)/2
#     print b
    t = Solution()
    A = [1, 2, 3]
    B = [4, 5, 6, 7]

    A = [1, 2]
    B = [3, 4]

    A = []
    B = [2, 3]

    A = [6, 7, 8, 10]
    B = [9]

#     A = [5, 8, 10, 12]
#     B = [4, 6, 9, 10]


    print t.findMedianSortedArrays(A, B)


test()
