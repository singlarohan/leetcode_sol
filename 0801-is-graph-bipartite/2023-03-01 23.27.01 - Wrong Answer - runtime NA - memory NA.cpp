class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        q.push(0);
        vector<int> color(graph.size(), -1);
        color[0] = 0;
        while(!q.empty()){
            int i = q.front();
            int col = !color[i];
            q.pop();
            for(int j = 0; j < graph[i].size(); j++){
                if(color[graph[i][j]] == -1) {
                    q.push(graph[i][j]);
                    color[graph[i][j]] = col;
                }
                else if (col != color[graph[i][j]])
                    return false;
            }
        }
        return true;
    }
};