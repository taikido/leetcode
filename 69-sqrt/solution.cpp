class Solution {
public:
    int sqrt(int x) {

       return sqrt(x, 0, x);

    }

    int sqrt(int x, long lo, long hi)
    {

        if (x == 0 || x == 1) return x;
        if (x < 0) return -1;

        if ((hi - lo) == 1 && (hi* hi) > x && (lo * lo) < x)
            return lo;

        long mid = (hi + lo)/2;

        if ((mid*mid) == x) return mid;

        if ((mid * mid) < x)
            return sqrt(x, mid, hi);

        else return sqrt(x, lo, mid);
    }
};


/*
    Previous sqrt answers produced overflow error
*/

    /*
    int sqrt(int x, int lo, int hi)
    {

        if (x == 0 || x == 1) return x;
        if (x < 0) return -1;

        // Check for overflow

        if (hi > INT_MAX/2) return -1;


        //long temp = hi * hi;
        //if (temp > INT_MAX) return -1;


        if ((hi - lo) == 1 && (hi* hi) > x && (lo * lo) < x)
            return lo;

        int mid = (hi + lo)/2;

        if ((mid*mid) == x) return mid;

        if ((mid * mid) < x)
            return sqrt(x, mid, hi);

        else return sqrt(x, lo, mid);
    }
    */

    /*
    int sqrt(int target, int x)
    {

        if (x == 0 || x = 1) return x;
        if (x < 0) return -1;

        int mid = (x/2);

        if ((mid*mid) == target) return mid;

        if ((mid * mid) < x)
        {

            int x = (mid + x)/2;
            return sqrt(target, x);
        }
        else return sqrt(target, x/2);
    }
    */