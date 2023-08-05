class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        int i = 0, j = 0;
        int m = ver1.size(), n = ver2.size();
        while(i < m || j < n){
            int temp1{};
            while(i < m && ver1[i] != '.'){
                temp1 = temp1 * 10 + (ver1[i] - '0');
                i++;
            }
            int temp2{};
            while(j < n && ver2[j] != '.'){
                temp2 = temp2 * 10 + (ver2[j] - '0');
                j++;
            }
            if(temp1 < temp2) return -1;
            if(temp1 > temp2) return 1;
            i++, j++;
        }
        return 0;
    }
};