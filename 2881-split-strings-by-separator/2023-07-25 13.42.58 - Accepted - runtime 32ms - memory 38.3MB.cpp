class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        string temp;
        vector<string> ans;
        for(auto &x:words){
            temp = "";
            for(int i = 0; i < x.size(); i++){
                if(x[i] == separator) {
                    if(temp.size())
                        ans.push_back(temp);
                    temp = "";
                }
                else temp.push_back(x[i]);
            }
            if(temp.size()) ans.push_back(temp);
        }
        return ans;
    }
};