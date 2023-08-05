class Solution {
public:
    // Simple sorting O(nlogn) approach
//     static bool cmp(const vector<int> &a, const vector<int> &b){
//         if(a[0] != b[0])
//             return a[0] > b[0];
//         return a[1] < b[1];
//     }
    
//     int numberOfWeakCharacters(vector<vector<int>>& properties) {
//         sort(properties.begin(), properties.end(), cmp);
//         int maxTnow{INT_MIN}, ans{};
//         for(auto v:properties)
//             if(v[1] < maxTnow) ans++;
//             else maxTnow = v[1];
//         return ans;
//     }
    //BETTER WITH COUNTING SORT
    //Max value of attack defence is 10^5

    int numberOfWeakCharacters(vector<vector<int>> & prop){
        vector<int> ct(100002, 0);
        int ans{}, ma{};
        for(int i = 0; i < prop.size() ; i++){
            ct[prop[i][0]] = max(ct[prop[i][0]], prop[i][1]);
            ma = max(ma, prop[i][0]);
        }
        for(int i = ma - 1; i >=0; i--)
            ct[i] = max(ct[i], ct[i + 1]);
        for(int i = 0; i < prop.size(); i++)
            if(ct[prop[i][0] + 1] > prop[i][1]) ans++;
        return ans;
    }
};