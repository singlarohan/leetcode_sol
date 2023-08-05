class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wList) {
        int m = endWord.size();
        int n = wList.size();
        vector<vector<int>> adj(n + 1);
        int bind{n}, eind = INT_MAX;
        for(int i = 0; i < n; i++){
            if(beginWord == wList[i]) bind = i;
            if(endWord == wList[i]) eind = i;
            for(int j = i + 1; j < n; j++){
                int count{};
                for(int k = 0; k < m; k++)
                    if(wList[i][k] != wList[j][k]) count++;
                if(count == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        if(bind == n){
            for(int j = 0; j < n; j++){
                int count{};
                for(int k = 0; k < m; k++)
                    if(beginWord[k] != wList[j][k]) count++;
                if(count == 1){
                    adj[n].push_back(j);
                    adj[j].push_back(n);
                }
            }
        }
        if(eind == INT_MAX) return 0;
        queue<int> q;
        q.push(bind);
        vector<int> dist(n + 1, INT_MAX);
        dist[bind] = 1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto it:adj[temp]){
                if(dist[it] > dist[temp] + 1){
                    dist[it] = min(dist[it], dist[temp] + 1);
                    q.push(it);
                }
            }
        }
        return dist[eind] == INT_MAX ? 0 : dist[eind];
    }
};