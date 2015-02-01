# Lessons

The most important tip for solving the problem was figuring out how to halve it. 
I initially tried to approach it with the typical binary search method - but it became unnecessarily complex
when I turned to using logs etc.

The pattern is clear from the following:
* 2^2 = 2^1 * 2^1
* 2^5 = 2^2 * 2^2 * 2^1
* 3^10 = 3^5 * 3^5
* 5^13 = 5^6 * 5^6 * 5^1

If n is even powered then:
* x^n = x^(n/2) * x^(n/2)

Else if n is odd powered then:
* x^n = x^(n/2) * x^(n/2) * x^1
