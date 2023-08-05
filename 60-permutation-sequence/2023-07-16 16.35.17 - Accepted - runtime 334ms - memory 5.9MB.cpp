class Solution {
public:
    void nextPermutation(string &nums) {
        int i = nums.size() - 2, j = nums.size() - 1;
        while(i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }
        if(i >= 0){
            while(j > i && nums[i] >= nums[j])
            j--;
            swap(nums[i], nums[j]);
        }
        sort(nums.begin() + i + 1, nums.end());
    }

    string getPermutation(int n, int k) {
        string temp;
        for(int i = 0; i < n; i++)
            temp.push_back(i + 1 + '0');
        
        while(--k) nextPermutation(temp);

        return temp;
    }
};