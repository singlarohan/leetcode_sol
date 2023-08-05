class Solution {
private:
    vector<int> ans;
    vector<bool> vis;
public:
    void solve(vector<int> &curr, int n){
        if(curr.size() == 1 << n){
            ans = curr;
            return;
        }

        if(!ans.empty()) return;

        int last = curr.back();
        for(int i = 0; i < n; i++){
            int temp = last ^ (1 << i);
            if(!vis[temp]){
                vis[temp] = true;
                curr.push_back(temp);
                solve(curr, n);
                vis[temp] = false;
                curr.pop_back();
            }
        }
        return;
    }
    vector<int> grayCode(int n) {
        vector<int> curr;
        curr.push_back(0);
        vis = vector<bool> (1 << n, false);
        vis[0] = true;
        solve(curr, n);
        return ans;
    }
};