# Approach

## Solution 1 
* Insert all elements into a linked list in order. Run Time and space O(N)
* Count length of longest consecutive sequence in list O(N)
* Time limit was exceeded 
* Solution implemented in solution1.cpp

## Solution 2
* Insert all the elements in a map
* C++ STL map is implemented using a red black tree so the elements are naturally sorted
* Traverse map and count length of longest cons. seq.
* If the map wasn't sorted you could iterate through map and set and for each element search to left or right for longest seq.
