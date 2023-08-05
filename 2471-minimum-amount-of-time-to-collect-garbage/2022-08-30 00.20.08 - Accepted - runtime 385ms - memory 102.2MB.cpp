class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans{};
        int pptr{}, metr{}, gltr{}; 
        for(int i = 0; i < garbage.size(); i++){
            for(int j = 0; j < garbage[i].size(); j++){
                if(garbage[i][j] == 'M'){
                    while(metr != i){
                        ans += travel[metr];
                        metr++;
                    }
                }
                else if(garbage[i][j] == 'P'){
                    while(pptr != i){
                        ans += travel[pptr];
                        pptr++;
                    }
                }
                else if(garbage[i][j] == 'G'){
                    while(gltr != i){
                        ans += travel[gltr];
                        gltr++;
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};