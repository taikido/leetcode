class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();

        if (n == 0) return -1;
        if (n == 1) return 0;
        if (n == 2)
        {
            if (num[0] > num[1]) return 0;
            else if (num[1] > num[0]) return 1;
        }

        // Check first 2 elements
        if (num[0] > num[1]) return 0;




        for(int i=0; i<n-2; i++)
        {
            int max_num = max(num[i], num[i+1], num[i+2]);
            if ( max_num == num[i+1] && max_num > num[i] && max_num > num[i+2])
                return i+1;
        }

        // Check last 2
        if (num[n-1] > num[n-2]) return n-1;

        return -1; // not found

    }

    int max(int a, int b, int c)
    {
        return max(a, max(b, c));
    }

    int max(int a, int b)
    {
        return (a > b ? a : b);
    }
};