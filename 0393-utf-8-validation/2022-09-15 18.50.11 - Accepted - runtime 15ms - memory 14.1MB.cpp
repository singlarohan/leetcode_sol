class Solution {
public:
    bool validUtf8(vector<int>& data) {
        unordered_map <int, int> mp;
        mp[0] = 1, mp[6] = 2, mp[14] = 3, mp[30] = 4;
        
        for(int i = 0; i < data.size(); i++){
            if(data[i] < 128)
                continue;
            int temp  = data[i];
            temp = temp >> 3;
        
            for(int j = 0; j < 4 && (!mp[temp]); j++){
                temp = temp / 2;
                if(j == 3 && temp != 0)
                    return false;
            }

            for(int j = 0; j < mp[temp] - 1; j++, i++)
                if(i >= data.size() - 1 || data[i+1] >> 6 != 2)
                    return false;
        }
        return true;
    }
};