class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i{}, j{}, curr1{}, curr2{};
        while(1){
            if(curr1 == word1[i].size())
                curr1 = 0, i++;
            if(curr2 == word2[j].size())
                curr2 = 0, j++;
            if(i == word1.size() && j == word2.size())
                return true;
            if(i == word1.size() || j == word2.size() || word1[i][curr1] != word2[j][curr2])
                return false;
            curr1++, curr2++;
        }
        return true;
    }
};