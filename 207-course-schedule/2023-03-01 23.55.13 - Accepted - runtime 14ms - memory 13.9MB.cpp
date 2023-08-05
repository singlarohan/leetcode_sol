class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        //false if there is a cycle
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prereq.size(); i++)
            adj[prereq[i][1]].push_back(prereq[i][0]);
        vector<int> vis(numCourses, 0);
        auto dfs = [&](int i, auto &&self) -> bool{
            vis[i] = 2;
            for(auto x: adj[i]){
                if(vis[x] == 2 || (!vis[x] && self(x, self)))
                return true;
            }
            vis[i] = 1;
            return false;
        };
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i, dfs))
                    return false;
            }
        }
        return true;
    }
};