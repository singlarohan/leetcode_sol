class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26, 0);
        queue<int> q;
        for(int i = 0; i < s.size(); i++){
            if(++count[s[i] - 'a'] == 1) q.push(i);
            while(!q.empty() && count[s[q.front()] - 'a'] > 1)
                q.pop();
        }        
        return q.empty() ? -1 : q.front();
    }
};