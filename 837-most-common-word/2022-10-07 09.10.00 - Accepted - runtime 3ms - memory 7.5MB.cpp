class Solution {
public:
    string to_lower(string str){
        for(auto &c:str)
        c = tolower(c);
        return str;
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> words;
        string temp;
        for(int i = 0; i < paragraph.size(); i++){
            while(i < paragraph.size() && isalpha(paragraph[i])){
                temp.push_back(tolower(paragraph[i]));
                i++;
            }
            if(!temp.empty())
                words[temp]++;
            temp.clear();
        }
        for(auto &s:banned)
            words.erase(to_lower(s));
        pair<string, int> ans;
        for(auto it:words){
            if(it.second > ans.second)
            ans = {it.first, it.second};
        }
        return ans.first;
    }
};