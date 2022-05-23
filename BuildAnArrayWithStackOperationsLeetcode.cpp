class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i=1,j=0;
        while(i<=n && j<target.size()) {
            if(target[j]==i) {
                ans.push_back("Push");
                j++;
                i++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
        }
        return ans;
    }
};
