class Solution {
public:
    long long minimumTime(vector<int>& time, int total) {
        // n / 3 + n / 2 + n == 5
        //binary search on time;
        long long left = 0, right = 1e14;
        // long long time{};
        long long ans = 1e14;
        while(left < right){
            long long mid = (left + right) / 2;
            long long curr{};
            for(auto &it:time)
                curr += mid / it;
            // cout<<"left = "<<left<<" "<<"right = "<<" "<<right<<" "<<mid<<" " << curr<<endl;
            if(curr >= total){
                right = mid;
                ans = min(ans, mid);
            }
            else left = mid + 1;
        }
        return ans;
    }
};