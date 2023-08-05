class Solution {
public:
    static bool comp(pair<char,int> &a, pair<char, int> &b){
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        vector<pair<char, int>> v(100, pair<char, int> {' ', 0});
        for(int i = 0; i<s.size(); i++){
            v[s[i] - '0'].first = s[i];
            v[s[i] - '0'].second++;
        }
        sort(v.begin(), v.end(), comp);
        s = "";
        for(int i = 0; i < v.size(); i++)
            while(v[i].second--)
                s.push_back(v[i].first);
        return s;
    }
};