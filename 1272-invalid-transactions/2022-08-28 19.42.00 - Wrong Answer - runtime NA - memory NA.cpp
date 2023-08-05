class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        pair<int, string> emp;
        vector<string> ans;
        unordered_map<string, pair<string, pair<string, int>>> mp;
        for(int i = 0; i < transactions.size(); i++){
            vector<string> temp(4);
            int count{};
            for(int j = 0; j < transactions[i].size(); j++){
                if(transactions[i][j] == ',')
                    count++;
                else
                temp[count].push_back(transactions[i][j]);
            }
            if(stoi(temp[2]) > 1000)
                ans.push_back(transactions[i]);
            else if(mp.find(temp[0]) != mp.end() &&  stoi(temp[1]) - stoi(mp[temp[0]].first) <= 60 && mp[temp[0]].second.first != temp[3]){
                ans.push_back(transactions[i]);
                ans.push_back(transactions[mp[temp[0]].second.second]);
                }
            mp[temp[0]] = {temp[1], {temp[3], i}};
        }
        return ans;
    }
};