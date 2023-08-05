class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end());
        vector<vector<int>> v;
        for(int i = 0; i < properties.size(); i++)
            if(i == properties.size() - 1 || properties[i][0] != properties[i+1][0])
                v.push_back(properties[i]);
        int ans{};
        for(int i = 0; i < properties.size() ; i++){
            int l{};
            while(l < v.size() && v[l][0] <= properties[i][0])
                l++;
            while(l < v.size() && v[l][1] <= properties[i][1])
                l++;
            if(l < v.size())
                ans++;
        }
        return ans;
    }
};