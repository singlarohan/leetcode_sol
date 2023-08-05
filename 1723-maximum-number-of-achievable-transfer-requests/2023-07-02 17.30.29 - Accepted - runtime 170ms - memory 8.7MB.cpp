class Solution {
private:
    vector<int> count;
public:
    int solve(int i, vector<vector<int>> &req){
        if(i >= req.size()) {
            return *max_element(count.begin(), count.end()) == 0 ? 0 : -1e9;
        }

        int ans{};
        //choose
        count[req[i][0]]--, count[req[i][1]]++;
        ans = 1 + solve(i + 1, req);
        count[req[i][0]]++, count[req[i][1]]--;

        //not choose
        ans = max(ans, solve(i + 1, req));
        return ans;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        count = vector<int> (n,0);
        return solve(0, requests);
    }
};