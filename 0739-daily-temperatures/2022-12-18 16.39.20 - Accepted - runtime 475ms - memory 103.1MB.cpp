class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size());
        stack<int> ind;
        for(int i = 0; i < temp.size(); i++){
            while(!ind.empty() && temp[ind.top()] < temp[i]){
                ans[ind.top()] = i - ind.top();
                ind.pop();
            }
            ind.push(i);
        }
        while(ind.empty()){
            ans[ind.top()] = 0;
            ind.pop();
        }
        return ans;
    }
};