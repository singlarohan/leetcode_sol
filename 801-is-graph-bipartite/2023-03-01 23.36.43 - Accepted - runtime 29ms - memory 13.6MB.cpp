class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //BFS
        // queue<int> q;
        vector<int> color(graph.size(), -1);
        // for(int x = 0; x < graph.size(); x++){
        //     if(color[x] == -1)
        //         q.push(x);
        //         color[x] = 0;
        //     while(!q.empty()){
        //         int i = q.front();
        //         int col = !color[i];
        //         q.pop();
        //         for(int j = 0; j < graph[i].size(); j++){
        //             if(color[graph[i][j]] == -1) {
        //                 q.push(graph[i][j]);
        //                 color[graph[i][j]] = col;
        //             }
        //             else if (col != color[graph[i][j]])
        //                 return false;
        //         }
        //     }
        // }
        // return true;
        //DFS
        auto solve = [&](int i, bool col, auto &&self){
            if(color[i] != -1){
                if(color[i] == col) return true;
                else return false;
            }
            color[i] = col;
            bool ans = true;
            for(auto x:graph[i])
                ans = ans && self(x, !col, self); 
            return ans;
        };
        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1)
                if(solve(i, 0, solve) == false)
                return false;
        }
        return true;
    }
};