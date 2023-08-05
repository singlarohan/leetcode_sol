class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        for(int i = 0; i < s1.size(); i++) {
            arr1[s1[i] - 'a']++;
            arr2[s2[i] - 'a']++;
        }
        for(int i = s1.size(); i < s2.size(); i++){
            if(arr1 == arr2) return true;
            arr2[s2[i - s1.size()] - 'a']--;
            arr2[s2[i] - 'a']++;
        }
        return arr1 == arr2;
    }
};