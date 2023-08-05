class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> ifvisited(arr.size(), false);
        auto dfs = [&](int i, auto &&self){
            if(i >= arr.size() || i < 0)
                return false;
            if(arr[i] == 0)
                return true;
            if(ifvisited[i])
                return false;
            ifvisited[i] = true;
            bool a = self(i + arr[i], self) || self(i - arr[i], self);
            ifvisited[i] = false;
            return a;
        };
        return dfs(start, dfs);
    }
};