class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> shash(26, 0);
        vector<int> phash(26, 0);
        vector<int> ans;
        if(s.size() < p.size())
            return ans;
        for(auto &x: p)
            phash[x - 'a']++;
        int left = 0, right = p.size() - 1;
        for(int i = 0; i < p.size(); i++)
            shash[s[i] - 'a']++;
        while(right < s.size()){
            if(phash == shash)
                ans.push_back(left);
            shash[s[left] - 'a']--;
            if(right < s.size() - 1)
                shash[s[right + 1] - 'a']++;
            left++, right++;
        }
        return ans;
    }
};