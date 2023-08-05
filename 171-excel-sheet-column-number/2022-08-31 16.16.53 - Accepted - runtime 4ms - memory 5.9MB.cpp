class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans{};
        for(int i = 0; i < columnTitle.size() ; i++)
            ans = ans * 26 + (columnTitle[i] - 'A' + 1);
        return ans;
    }
};