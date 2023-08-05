class Solution {
public:
    bool check_next(int n){
        for(int i = 0; i < 6; i++)
            n = n / 2;
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
            if(temp < 128)
                continue;
            for(int j = 0; j < 3; j++)
                temp = temp / 2;
            
            for(int j = 0; j < 4 && (!mp[temp]); j++){
                temp = temp / 2;
                if(j == 3 && temp != 0)
                    return false;
            }

            for(int j = 0; j < mp[temp] - 1; j++, i++)
                if(i >= data.size() - 1 || !check_next(data[i+1]))
                    return false;
        }
        return true;
    }
};