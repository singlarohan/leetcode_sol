class Solution {
public:
    // unordered_map<int, unordered_map<int, int>> mp;
    bool reorderedPowerOf2(int n) {
        // vector<int> arr;
        // for(int i = 0; i<31; i++)
        //     arr.push_back(pow(2,i));
        unordered_map<int, int> temp;
        while(n != 0){
            temp[n%10]++;
            n = n / 10;
        }
        for(int i = 0; i < 31; i++){
            unordered_map<int, int> temp2;
            int temp1 = pow(2,i);
            if(temp1)
            while(temp1 != 0){
                temp2[temp1%10]++;
                temp1 = temp1/10;
            }
            if(temp2 == temp)
                return true;
        }

        // for(auto &it:mp){
        //     if(it.second == temp)
        //         return true;
        // }
        return false;
    }
};