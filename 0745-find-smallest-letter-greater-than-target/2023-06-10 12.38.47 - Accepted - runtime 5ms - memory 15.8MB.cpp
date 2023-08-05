class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int mini{INT_MAX};
        for(int i = 0; i < letters.size(); i++){
            int temp = letters[i] - target;
            if(!(temp <= 0))
            mini = min(mini, temp);
        }
        return mini == INT_MAX ? letters[0] : target + mini;
    }
};