class Solution {
public:
    static bool sortFunc( const vector<int>& p1, const vector<int>& p2 ) {
        if(p1[0] == p2[0])
            return p1[1] > p2[1];
        else
            return p1[0] < p2[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //sort by width asc
        //if 2 width are same, sort by height desc
        sort(envelopes.begin(), envelopes.end(), sortFunc);

        //now it is reduced to Longest increasing Subsequence problem on heights
        int i, j, n=envelopes.size();
        vector<int>lis;
        
        for(i=0; i<n; i++){
            auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
            if(it==lis.end()){lis.push_back(envelopes[i][1]);}
            else {
                *it = envelopes[i][1];
            }
        }
        return lis.size();
    }
};
