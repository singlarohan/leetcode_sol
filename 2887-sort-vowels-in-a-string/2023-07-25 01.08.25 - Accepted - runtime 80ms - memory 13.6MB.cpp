class Solution {
public:
    string sortVowels(string s) {
        unordered_map<int, char> mp;
        mp[0] = 'A', mp[1] = 'E', mp[2] = 'I', mp[3] = 'O', mp[4] = 'U';
        mp[5] = 'a', mp[6] = 'e', mp[7] = 'i', mp[8] = 'o', mp[9] = 'u';
        
        unordered_map<char, int> chtoind;
        for(auto &x:mp)
            chtoind.insert({x.second, x.first});
        
        vector<int> count(10, 0);
        for(int i = 0; i < s.size(); i++)
            if(chtoind.find(s[i]) != chtoind.end()) count[chtoind[s[i]]]++;
        
        int counter = 0;
        for(int i = 0; i < s.size(); i++){
            if(chtoind.find(s[i]) != chtoind.end()){
                while(count[counter] == 0) counter++;
                s[i] = mp[counter];
                count[counter]--;
            }
        }
        return s;
    }
};