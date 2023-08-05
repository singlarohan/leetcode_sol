class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans{};
        for(int i = 0; i < columnTitle.size() ; i++)
            ans += (columnTitle[i] - 'A' + 1) * pow(26, columnTitle.size() - i - 1);
        return ans;
    }
};