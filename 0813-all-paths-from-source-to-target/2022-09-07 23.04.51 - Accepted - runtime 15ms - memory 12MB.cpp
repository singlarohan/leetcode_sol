class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int> &temp, vector<vector<int>> &graph){
        temp.push_back(i);
        if(i == graph.size() - 1)
            ans.push_back(temp);
        for(int j = 0; j < graph[i].size(); j++)
            solve(graph[i][j], temp, graph);
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        solve(0, temp, graph);
        return ans;
    }
};