/*============================================================================
* Name : solution.cpp
* Author: taikido
* Description: Leetcode Problem 50: pow(x, n)
* Source: https://oj.leetcode.com/problems/powx-n/
* Date: Jan.2015
* Status: Accepted
*===========================================================================*/

class Solution {
public:
    double pow(double x, int n) {
        //return powL(x, n);

        if (n == 0) return 1;
        if (x == 0) return 0;
        if (n == 1) return x;

        if (n > 1) return pow2(x, n);
        else return 1/pow2(x, n);
    }


    double pow2(double x, int n)
    {
        if (n == 0) return 1;

        double half_pow = pow2(x, n/2);
        if (n%2 == 0)
            return half_pow * half_pow;
        else
            return half_pow * half_pow * x;

    }


    /*
    double pow(double x, double n, long double lo, long double hi)
    {

        long double mid = (hi + lo)/2;
        double p = 1/n;

        if ()
    }



    double pow(double x, double n, long double hi)
    {
        long double p = logg(x, hi);

        if (p == n) return hi;

        if (p < n)
            return pow(x, n, hi*hi);
        else return pow(x, n, sqrt(hi));

    }

    // Convert log base 10 to log with any base
    double logg(long double b, long double x)
    {
        return log10(x)/log10(b);
    }

    double powL(double x, int n)
    {

        if (n == 0) return 1;
        if (x == 0) return 0;
        if (n == 1) return x;

        double result = x;
        for(int i=0; i<n; i++)
            result *= result;

        return result;

    }

    */
};