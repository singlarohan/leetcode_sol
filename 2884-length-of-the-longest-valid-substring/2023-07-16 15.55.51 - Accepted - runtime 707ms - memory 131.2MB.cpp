class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> st;
        for(auto x:forbidden) st.insert(x);
        
        int n = word.size();
        
        vector<int> foundForb(n);
        for(int l = 1; l <= 10; l++){
            for(int i = 0; i <= n - l; i++){
                if(foundForb[i] != 0) continue;

                if(st.find(word.substr(i, l)) != st.end()){
                    foundForb[i] = l;
                }
            }
        }

        int ans = 0, next_idx = 0;
        while(ans < n - next_idx && next_idx != n){
            int cnt = INT_MAX, curr = 0;
            for(int i = next_idx; i < n; i++, cnt--, curr++){
                if(foundForb[i] != 0){
                    if(cnt > foundForb[i] - 1){
                        cnt = foundForb[i] - 1;
                        next_idx = i;
                    }
                }
                if(cnt == 0)
                    break;
            }
            next_idx++;
            ans = max(ans, curr);
        }
        return ans;
    }
};