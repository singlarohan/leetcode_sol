class Solution {
public:
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);

            if (hash1 != hash2) {
                return hash1 ^ hash2;             
            }

              return hash1;
        }
    };
    
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<int> delrow = {-1, -1, 0, 0};        
        vector<int> delcol = {-1, 0, -1, 0};
        
        unordered_map<int, long long> st;
        st[0] = (n - 1) * (m - 1);
        unordered_map<pair<int, int>, long long, hash_pair> mp;
        
        for(auto x:coordinates){
            int i = x[0];
            int j = x[1];
            for(int k = 0; k < 4; k++){
                int ni = i + delrow[k];
                int nj = j + delcol[k];

                if(ni < 0 || nj < 0 || ni == n - 1 || nj == m - 1) continue;
                st[mp[{ni,nj}]]--;
                // cout<<i<<" "<<j<<" "<<ni<<" "<<nj<<" "<<mp[{ni, nj}]<<" "<<st[mp[{ni, nj}]]<<endl;
                mp[{ni, nj}]++;
                st[mp[{ni, nj}]]++;
            }
        }
        vector<long long> ans(5, 0);
        for(int i = 0; i < 5; i++){
            ans[i] = st[i];
        }
        return ans;
    }
};