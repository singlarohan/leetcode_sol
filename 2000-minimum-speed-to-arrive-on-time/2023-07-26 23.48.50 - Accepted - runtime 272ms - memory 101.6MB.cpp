class Solution {
public:
    bool check(vector<int> &dist, int s, double hour){
        double time = 0;
        for(auto x:dist)
            time = ceil(time) + (1.0*x/s);
        
        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = 1e7;

        int ans = -1;

        while(left <= right){
            int mid = (left + right) / 2;

            if(check(dist, mid, hour)){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        return ans;
    }
};