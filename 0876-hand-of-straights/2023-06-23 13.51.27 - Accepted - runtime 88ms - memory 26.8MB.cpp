class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if(hand.size() % k != 0) return false;

        sort(hand.begin(), hand.end());
        unordered_map<int, int> mp;

        for(auto x:hand) mp[x]++;

        for(int i = 0; i <= hand.size() - k; i++){
            if(mp.find(hand[i]) != mp.end()){
                for(int j = hand[i]; j < hand[i] + k; j++){
                    if(mp.find(j) == mp.end()) return false;
                    mp[j]--;
                    if(mp[j] == 0) mp.erase(j);
                }
            }
        }
        return true;
    }
};