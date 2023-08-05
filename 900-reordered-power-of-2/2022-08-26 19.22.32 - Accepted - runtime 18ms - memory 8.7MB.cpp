class Solution {
public:
    unordered_map<int, unordered_map<int, int>> mp;
    bool reorderedPowerOf2(int n) {
        vector<int> arr;
        for(int i = 0; i<31; i++)
            arr.push_back(pow(2,i));
        for(int i = 0; i < arr.size(); i++){
            int temp = arr[i];
            while(temp != 0){
                (mp[arr[i]])[temp%10]++;
                temp = temp/10;
            }
        }
        unordered_map<int, int> temp;
        while(n != 0){
            temp[n%10]++;
            n = n / 10;
        }
        for(auto &it:mp){
            if(it.second == temp)
                return true;
        }
        return false;
    }
};