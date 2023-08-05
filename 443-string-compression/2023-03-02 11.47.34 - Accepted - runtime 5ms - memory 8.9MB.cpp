class Solution {
public:
    int compress(vector<char>& chars) {
        int slow = 0, count = 1;
        for(int i = 0; i < chars.size(); i++){
            if(i != chars.size() - 1 && chars[i+1] == chars[i]){
                count++;
            }
            else{
                chars[slow++] = chars[i];
                if(count > 1){
                    string temp = to_string(count);
                    for(auto x:temp){
                        chars[slow++] = x;
                    }
                }
                count = 1;
            }
        }
        return slow;
    }
};