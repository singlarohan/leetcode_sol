class Solution {
public:
    void to_lower(string &str){
        for(auto &c:str)
        c = tolower(c);
        return;
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, bool> banned1;
        unordered_map<string, int> words;
        unordered_map<char, bool> punct;
        punct['!'] = punct['?'] = punct['\''] = punct[','] = punct[';'] = punct['.'] = punct[' '] = true;
        for(int i = 0; i < banned.size(); i++){
            to_lower(banned[i]);        
            banned1[banned[i]] = true;
        }
            string temp;
        for(int i = 0; i < paragraph.size(); i++){
            while(i < paragraph.size() && punct.find(paragraph[i]) == punct.end()){
                temp.push_back(tolower(paragraph[i]));
                i++;
            }
            if(!temp.empty() && banned1.find(temp) == banned1.end())
                words[temp]++;
            temp.clear();
        }
        pair<string, int> ans;
        for(auto it:words){
            if(it.second > ans.second)
            ans = {it.first, it.second};
        }
        return ans.first;
    }
};