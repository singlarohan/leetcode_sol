class Solution {
public:
    int maxConsecutiveAnswers(string key, int k) {
        //for replacing F with T
        int cntF{}, cntT{};

        int ans{}, minor;
        int l = 0;
        for(int i = 0; i < key.size(); i++){
            if(key[i] == 'T') cntT++;
            else cntF++;

            minor = min(cntT, cntF);
            while(minor > k){
                if(key[l] == 'T') cntT--;
                else cntF--;
                minor = min(cntT, cntF);
                l++;
            }
            
            ans = max(ans, cntT + cntF);
        }
        return ans;
    }
};