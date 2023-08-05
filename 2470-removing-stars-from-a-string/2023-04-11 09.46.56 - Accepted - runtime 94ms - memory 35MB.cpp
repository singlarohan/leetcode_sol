class Solution {
public:
    string removeStars(string s) {
        vector<int> pos;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                pos.pop_back();
            }
            else pos.push_back(i);
        }
        string ans;
        for(auto x:pos){
            ans.push_back(s[x]);
        }
        return ans;
    }
};