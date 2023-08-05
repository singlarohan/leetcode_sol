class SnapshotArray {
private:
    vector<vector<pair<int, int>>> arr;
    int curr_sid;
public:
    SnapshotArray(int length) {
        curr_sid = 0;
        arr = vector<vector<pair<int, int>>> (length);
        for(int i = 0; i < length; i++) {
            arr[i].push_back({0,0});
        }
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
        int l = 0, r = arr[index].size() - 1;
        int ans = INT_MAX;
        while(l <= r){
            int mid = (l + r)/2;
            if(arr[index][mid].first > snap_id){
                r = mid - 1;
            }
            else if(arr[index][mid].first < snap_id){
                l = mid + 1;
                ans = mid;
            }
            else{
                return arr[index][mid].second;
            }
        }
        return arr[index][ans].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */