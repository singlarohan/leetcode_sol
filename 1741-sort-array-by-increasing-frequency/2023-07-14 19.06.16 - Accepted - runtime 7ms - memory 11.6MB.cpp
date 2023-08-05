class Solution {
public:
    static bool sortbysecdesc( pair<int,int> &a, pair<int,int> &b)
    {
        if(a.first != b.first)
            return (a.first < b.first);
        return (a.second > b.second); 
    }

    vector<int> frequencySort(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        vector <pair<int,int>>v;
        vector<int>ans;
        for(auto it:m)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.begin(), v.end(), sortbysecdesc);
        int k=v.size();
        for(int i=0;i<k;i++)
        {
           for(int j=0;j<v[i].first;j++)
           {
               ans.push_back(v[i].second);
           }
        }
        return ans;

    }
};