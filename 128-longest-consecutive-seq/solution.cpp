/*============================================================================
* Name : solution.cpp
* Author: taikido
* Description: Longest Consecutive Sequence
* Source: https://oj.leetcode.com/problems/longest-consecutive-sequence/
* Date: Sun.Feb.1.2015
* Status: Accepted
*===========================================================================*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {

        if (num.size() == 0) return 0;
        if (num.size() == 1) return 1;

        map<int, bool> m;

        for(int i=0; i<num.size(); i++)
        {
            m[num[i]] = true;
        }

        map<int, bool>::iterator it = m.begin();
        int x = it->first;

        int count = 1;
        int max_count = 1;

        while (it != m.end())
        {
            it++;

            if (it != m.end())
            {
                int y = it->first;

                if ((y - x) == 1)
                {
                    count++;
                }
                else count = 1;

                if (count > max_count) max_count = count;

                x = it->first;
            }


        }


        return max_count;


//        int min_val = *min_element(num.begin(), num.end());
//        int max_val = *max_element(num.begin(), num.end());
//
//        if (max_val == min_val) return 1;
//
//        int count = 1;
//        int max_count = 1;
//
//        bool search_mode = true;
//        int i = min_val+1;
//
//        while (search_mode)
//        {
//            if(m.find(i) != m.end())
//            {
//                count++;
//            }
//            else
//            {
//                count = 1;
//            }
//
//            if (i == max_val) search_mode = false;
//
//            i++;
//            if (count > max_count) max_count = count;
//
//
//        }
//
//        return max_count;
    }


};