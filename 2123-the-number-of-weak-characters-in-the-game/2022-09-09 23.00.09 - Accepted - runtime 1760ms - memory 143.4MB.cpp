class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b){
        if(a[0] != b[0])
            return a[0] > b[0];
        return a[1] < b[1];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        int maxTnow{INT_MIN}, ans{};
        for(auto v:properties)
            if(v[1] < maxTnow) ans++;
            else maxTnow = v[1];
        return ans;
    }
};