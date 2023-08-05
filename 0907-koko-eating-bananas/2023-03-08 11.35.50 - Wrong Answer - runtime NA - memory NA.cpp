class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //minimum hours(h), taking k as the largest pile = piles.size();
        int left = 1, right = 1e9;
        int ans{};
        while(left < right){
            int count{};
            int mid = (left + right) / 2;
            for(auto x:piles)
                count += ceil((float)x/mid);
            if(count <= h) {
                right = mid;
                ans = mid;
            }
            else left = mid + 1;
        }
        return ans;
    }
};