class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> mp;
        for(int i = 0; i < candyType.size(); i++)
            mp.insert(candyType[i]);
        return min(candyType.size()/2, mp.size());
    }
};