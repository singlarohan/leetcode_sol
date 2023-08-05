class Solution {
public:
    string getPermutation(int n, int k) {
        string temp;
        for(int i = 0; i < n; i++)
            temp.push_back(i + 1 + '0');
        
        while(--k) next_permutation(temp.begin(), temp.end());

        return temp;
    }
};