class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    //then we do binary search on vector to find  a given string
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
        return;
    }
    
    string get(string key, int timestamp) {
        // vector<pair<string, int>> tofind = mp[key];
        int n = mp[key].size();
        int left = 0, right = n - 1;
        string ans;
        while(left <= right){
            int mid = (left + right)/2;
            if(timestamp < mp[key][mid].second){
                right = mid - 1;
            }
            else{
                ans = mp[key][mid].first;
                left = mid + 1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */