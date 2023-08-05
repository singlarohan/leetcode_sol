class Solution {
public:
    bool check_next(int n){
        for(int i = 0; i < 6; i++)
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
            for(int j = 0; j < 4 && (!mp[temp]); j++){
                temp = temp >> 1;
                if(j == 3 && temp != 0)
                    return false;
            }
            // n = mp[temp] - 1;
            // while(n--){
            for(int j = 0; j < mp[temp] - 1; j++){
                i++;
                if(i >= data.size() || !check_next(data[i]))
                    return false;
            }
        }
        return true;
    }
};