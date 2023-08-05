class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - 1;
        int add{-1};
        while(left < right){
            int mid = (left + right)/2;
            if(arr[mid] == x){
                add = mid;
                break;
            }
            else if(arr[mid] < x) left = mid + 1;
            else right = mid - 1;
        }
        if(add == -1) add = left;
        deque<int> dq;
        dq.push_back(arr[add]);
        left = add - 1;
        right = add + 1;
        while((left >= 0 || right < arr.size()) && dq.size() <= k){
            if(((left+1)) && (right >= arr.size() || abs(arr[left] - x) <= abs(arr[right] - x))){
                dq.push_front(arr[left]);
                left--;
            }
            else{
                dq.push_back(arr[right]);
                right++;
            }
        }
        if(dq.size() > k){
            if(abs(dq.front() - x) <= abs(dq.back() - x))
            dq.pop_back();
            else dq.pop_front();
        }
        vector<int> ans;
        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};