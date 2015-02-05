class Solution {
public:
    vector<vector<int> > generate(int numRows) {

        vector<vector<int> > result;

        if (numRows == 0) return result;

        vector<int> prev(1, 1); // first row
        result.push_back(prev);

        if (numRows == 1) return result;


        for(int i=1; i<numRows; i++)
        {
            vector<int> curr(i+1, 1);
            for(int j=1; j<=i-1; j++)
            {
                curr[j] = prev[j-1] + prev[j];
            }
            result.push_back(curr);
            prev = curr;

        }

        return result;

    }
};