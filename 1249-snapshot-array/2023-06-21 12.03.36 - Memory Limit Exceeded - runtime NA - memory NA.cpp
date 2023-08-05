class SnapshotArray {
private:
    vector<vector<int>> arr;
    int curr_sid;
public:
    SnapshotArray(int length) {
        arr.push_back(vector<int> (length, 0));
        curr_sid = 0;
    }
    
    void set(int index, int val) {
        arr[curr_sid][index] = val;
    }
    
    int snap() {
        curr_sid++;
        arr.push_back(arr.back());
        return curr_sid - 1;
    }
    
    int get(int index, int snap_id) {
        return arr[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */