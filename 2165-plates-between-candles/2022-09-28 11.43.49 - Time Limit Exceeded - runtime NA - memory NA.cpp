class Solution {
public:
    int leftmostBinary(vector<int> &arr, int start, int end){
        if(start > end)
            return INT_MAX;
        int mid = (start + end)/2;
        int a = leftmostBinary(arr, start, mid - 1);
        if(arr[mid] != -1)
            return min(mid, a);
        if(a != INT_MAX)
            return a;
        else return leftmostBinary(arr, mid + 1, end);
    }
    int rightmostBinary(vector<int> &arr, int start, int end){
        if(start > end)
            return INT_MIN;
        int mid = (start + end)/2;
        int a = rightmostBinary(arr, mid + 1, end);
        if(arr[mid] != -1)
            return max(mid, a);
        if(a != INT_MIN)
            return a;
        return rightmostBinary(arr, start, mid - 1);
    }
    
    
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> prefix(s.size(), -1);
        // unordered_map<int, int> prefix;
        int i{};
        while(i < s.size() && s[i] == '*')
            i++;
        int count{};
        while(i < s.size()){
            if(s[i] == '*')
                count++;
            if(s[i] == '|')
                prefix[i] = count;
            i++;
        }
        vector<int> ans;
        // Binary search to process through queries
        for(int i = 0; i < queries.size(); i++){
            //we have to find first '|' on right of queries[i][0]
            //and first '|' on the left of queries[i][1]
            // int left = INT_MAX, right = INT_MIN;
            // for(auto it:prefix){
            //     if(it.first >= queries[i][0] && it.first <= queries[i][1]){
            //         left = min(left, it.first);
            //         right = max(right, it.first);
            //     }
            // }
            int left = leftmostBinary(prefix, queries[i][0], queries[i][1]);
            int right = rightmostBinary(prefix, queries[i][0], queries[i][1]);
            if(left == INT_MAX || right == INT_MIN)
                ans.push_back(0);
            else
                ans.push_back(prefix[right] - prefix[left]);
        }
        return ans;
    }
};