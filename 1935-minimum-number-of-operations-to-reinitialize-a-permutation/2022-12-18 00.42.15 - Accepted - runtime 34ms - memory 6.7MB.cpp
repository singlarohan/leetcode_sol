class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        for(int i = 0; i < n; i++) perm[i] = i;
        vector<int> check = perm;
        int count{0};
        vector<int> temp;
        while(1){
            temp = perm;
            for(int i = 0; i < n; i++){
                if(i % 2 == 0) perm[i] = temp[i / 2];
                else perm[i] = temp[n / 2 + (i - 1) / 2];
            }
            count++;
            if(perm == check) break;
        }
        return count;
    }
};