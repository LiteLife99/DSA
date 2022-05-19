class Solution {
public:
    int romanToInt(string s) {
     unordered_map<char,int> mp;
     mp['M'] = 1000;
     mp['D'] = 500;
     mp['C'] = 100;
     mp['L'] = 50;
     mp['X'] = 10; 
     mp['I'] = 1;
     mp['V'] = 5;
     int total = 0;
     int i = 0;
       while( i < s.length()){

            if(s.length()-i>=2 && mp[s[i]] < mp[s[i+1]]){
                //handle subtraction
                total = total + (mp[s[i+1]] - mp[s[i]]);
                i += 2;

            } else {
                total = total + mp[s[i]];
                i += 1;
            }

        }

        return total;
    }
};
