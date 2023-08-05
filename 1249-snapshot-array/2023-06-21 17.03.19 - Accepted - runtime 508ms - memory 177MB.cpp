class SnapshotArray {
private:
    // unordered_map<int, unordered_map<int, int>> mp;
    vector<vector<pair<int, int>>> arr;
    int curr_sid;
public:
    SnapshotArray(int length) {
        arr = vector<vector<pair<int, int>>> (length);
        for(auto &x:arr) x.push_back({0,0});
        curr_sid = 0;
    }
    
    void set(int index, int val) {
        if(arr[index].back().first != curr_sid)
            arr[index].push_back({curr_sid, val});
        else arr[index].back().second = val;
    }
    
    int snap() {
        curr_sid++;
        return curr_sid - 1;
    }
    
    int get(int index, int snap_id) {
        auto &it = arr[index];
        //it[i].first == snap_id, it[i].second == val;
        int l = 0, r = it.size() - 1;
        int ans = INT_MAX;
        while(l <= r){
            int mid = (l + r)/2;
            if(it[mid].first > snap_id){
                r = mid - 1;
            }
            else if(it[mid].first < snap_id){
                l = mid + 1;
                ans = mid;
            }
            else{
                return it[mid].second;
            }
        }
        return it[ans].second;
        //we have to find 
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */