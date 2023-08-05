class Solution {
public:
    // class Compare{
    //     public:
    //     bool comparator()(const pair)
    // }
    static bool comp(const pair<string, int> &a, const pair<string, int> &b){
        return a.second < b.second;
    }
    
    string arrangeWords(string text) {
        text[0] += 32;
        // priority_queue<pair<string, int>> pq (pair<string, int>, vector<pair<string, int>>, Compare());
        vector<pair<string, int>> v;
        for(int i = 0; i < text.size(); i++){
            v.push_back({"", 0});
            while(i < text.size() && text[i] != ' '){
                v.back().first.push_back(text[i]);
                v.back().second++;
                i++;
            }
        }
        sort(v.begin(), v.end(), comp);
        string ans;
        for(int i = 0; i < v.size(); i++)
            ans += v[i].first + ' ';
        ans.pop_back();
        ans[0] -= 32;
        return ans;
    }
};