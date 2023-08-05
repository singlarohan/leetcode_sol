class Solution {
public:
    bool solve(long long n1, long long n2, long long curr, int i, string &nums){
        if(i >= nums.size()) return n1 + n2 == curr;
        bool ans{};
        if(n2 == -1){
            if(n1 < (LONG_MAX - (nums[i] - '0'))/10)
            ans |= solve(n1 * 10 + nums[i] - '0', n2, curr, i + 1, nums);
            ans |= solve(n1, nums[i] - '0', curr, i + 1, nums);
        }
        else if(curr == -1e9){
            if(n2 < (LONG_MAX - (nums[i] - '0'))/10)
            ans |= solve(n1,n2 * 10 + nums[i] - '0', curr, i + 1, nums);
            ans |= solve(n1, n2, nums[i] - '0', i + 1, nums);
        }
        else{
            if(curr < (LONG_MAX - (nums[i] - '0'))/10)
            ans |= solve(n1,n2, curr * 10 + nums[i] - '0', i + 1, nums);
            ans |= n1 + n2 == curr && solve(n2, curr, nums[i] - '0', i + 1, nums);
        }
        return ans;
    }

    bool isAdditiveNumber(string num) {
        return solve(0, -1, -1e9, 0, num);
    }
};