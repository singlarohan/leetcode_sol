class Solution {
public:
    int maxConsecutiveAnswers(string key, int k) {
        //for replacing F with T
        int cntF{}, cntT{};
        //for replceing T with F
        int cF{}, cT{}, lf{};

        int ans{};
        int l = 0;
        for(int i = 0; i < key.size(); i++){
            if(key[i] == 'T'){
                cT++;
                cntT++;
                while(cT > k){
                    if(key[lf] == 'F') cF--;
                    else cT--;
                    lf++;
                }
            }
            else{
                cF++;
                cntF++;
                while(cntF > k){
                    if(key[l] == 'T')
                        cntT--;
                    else cntF--;
                    l++;
                }
            }
            ans = max(ans, cntT + cntF);
            ans = max(ans, cT + cF);
        }
        return ans;
    }
};