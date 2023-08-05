class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), greater<vector<int>>());
        vector<vector<int>> v;
        int maxDef{INT_MIN};
        for(int i = 0; i < properties.size(); i++){
            if(i == 0 || properties[i][0] != properties[i-1][0]){
                if(properties[i][1] > maxDef){
                    v.push_back(properties[i]);
                    maxDef = properties[i][1];
                }
            }
        }
        int ans{}, l = properties.size() - 1;
        for(int i = 0; i < properties.size() ; i++){
            while(l >= 0 && v[l][0] <= properties[i][0])
                l--;
            int l2 = l;
            while(l2 >= 0 && v[l2][1] <= properties[i][1])
                l2--;
            if(l2 >= 0)
                ans++;
        }
        return ans;
    }
};