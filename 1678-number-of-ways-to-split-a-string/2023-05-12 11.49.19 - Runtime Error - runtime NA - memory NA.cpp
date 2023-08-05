class Solution {
public:
    int numWays(string s) {
        int count{};
        int M = 1e9 + 7;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '1') count++;
        if(count % 3 != 0) return 0;
        count /= 3;
        int co{}, cz{}, ans{1};
        //co -> current number of ones, cz = current number of zeros after that 1
        int n = s.size();
        if (count == 0) return ans = ((n-2)*(n-1))/2;
        for(int i = 0; i < n; i++){
            if(co == count){
                if(s[i] == '0') cz++;
                else{
                    co = 1;
                    ans = (ans * (cz + 1)) % M;
                    cz = 0;
                }
            }
            else if(s[i] == '1') co++;
        }
        // ans = (ans * (cz + 1)) % M;
        return ans;
    }
};