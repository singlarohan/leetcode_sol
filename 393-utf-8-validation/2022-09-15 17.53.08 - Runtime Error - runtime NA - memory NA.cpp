class Solution {
public:
    bool check_next(int n){
        int i = 6;
        while(i--)
            n = n >> 1;
        if(n == 2)
            return true;
        return false;
    }
    
    bool validUtf8(vector<int>& data) {
        unordered_map <int, int> mp;
        mp[0] = 1;
        mp[6] = 2;
        mp[14] = 3;
        mp[30] = 4;
        
        for(int i = 0; i < data.size(); i++){
            int temp  = data[i];
            int n = 3;
            while(n--)
                temp = temp >> 1;
            if(temp == 31)
                return false;
            while(!mp[temp])
                temp = temp >> 1;
            n = mp[temp] - 1;
            while(n--){
                i++;
                if(!check_next(data[i]))
                    return false;
            }
        }
        return true;
    }
};