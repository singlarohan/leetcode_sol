class Solution {
public:
    bool isValidSerialization(string pre) {
        if(pre.size() == 0) return false;
        int l = 0;
        int count = 1;
        while(l < pre.size() && count != 0){
            count--;
            if(pre[l++] != '#') count += 2;
            while(l == 0 || (l < pre.size() && pre[l - 1] != ',')) l++;
        }
        return count == 0 && l >= pre.size();
    }
};