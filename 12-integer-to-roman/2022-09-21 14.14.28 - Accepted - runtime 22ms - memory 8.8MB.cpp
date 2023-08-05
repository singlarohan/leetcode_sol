class Solution {
public:
    string intToRoman(int num) {
        string ans;
        
        // unordered_map<int, string> mp;
        // mp[1] = "I", mp[4] = "IV", mp[5] = "V", mp[9] = "IX", mp[10] = "X", mp[40] = "XL" ,mp[50] = "L", mp[90] = "XC", mp[100] = "C", mp[400] = "CD", mp[500] = "D", mp[900] = "CM", mp[1000] = "M";
        
        vector<int> arr{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> rom{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        
        int i = arr.size()-1;
        while(num != 0){
            while(num >= arr[i]){
                ans += rom[i];
                num -= arr[i];
            }
            i--;
        }
        return ans;
    }
};