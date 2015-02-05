class Solution {
public:
    vector<vector<int> > combine(int n, int k) {

        set<vector<int> > set_result;

        vector<int> num;

        for(int i=1; i<=n; i++) num.push_back(i);

        perm( num, 0, k, set_result);

        vector<vector<int> > result;

        set<vector<int> >::iterator it;

        for(it = set_result.begin(); it != set_result.end(); it++)
            result.push_back(*it);

        return result;

    }

    void perm(vector<int>& num, int i, int r, set<vector<int> >& result)
    {
        int n = num.size();
        if (i == n)
        {
            vector<int> v(num.begin(), num.begin()+r);
            sort(v.begin(), v.end());
            result.insert(v);
        }

        for(int j=i; j<n; j++)
        {
            swap(num[i], num[j]);
            perm(num, i+1, r, result);
            swap(num[i], num[j]);
        }
    }
};