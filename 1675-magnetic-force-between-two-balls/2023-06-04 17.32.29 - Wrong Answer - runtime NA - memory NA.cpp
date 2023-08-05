class Solution {
public:
    bool verify(int dis, int m, vector<int> &position){
        int x = position[0];
        int i = 1;
        for(i = 1; i < position.size() - 1 && m != 0; i++){
            if(position[i] - x >= dis){
                x = position[i];
                m--;
            }
        }
        if(m != 0 || position.back() - x < dis) return false;
        return true;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        if(m == 2) return position.back() - position[0];
        int left = 1, right = position.back() - position[0];
        int ans{INT_MIN};
        while(left < right){
            int mid = (left + right) / 2;
            if(verify(mid, m - 2, position)){
                left = mid + 1;
                ans = max(mid, ans);
            }
            else right = mid - 1;
        }
        return ans;
    }
};