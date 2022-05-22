class Solution {
public:
    string removeSpecialCharacter(string s)
    {
        string temp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a'&& s[i]<='z' || s[i]>='0'&&s[i]<='9')
                temp += s[i];
            else if(s[i]>='A'&&s[i]<='Z') 
                temp += s[i]-'A'+'a';
            else 
                continue;
        }
        return temp;
    }
    
    // bool checkIfPalindrome(string s, int i, int n) {
    //     if(i >= n/2) return true;
    //     if(s[i] != s[n-i-1]) return false;
    //     return checkIfPalindrome(s, i+1, n);
    // }
    
    bool isPalindrome(string s) {
        s = removeSpecialCharacter(s);
        // transform(s.begin(), s.end(), s.begin(), ::tolower);
        // int n = s.length();
        // bool ans = checkIfPalindrome(s, 0, n);
        for(int i=0,max=s.size()-1;i<s.size()/2;i++,max--){
            if(s[i]==s[max])
                continue;
            else
                return false;
        }
        return true;
        // return ans;
    }
};
