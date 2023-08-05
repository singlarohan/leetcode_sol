class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;

        unordered_set<string> st;
        for(auto &s:deadends) st.insert(s);
        
        if(st.find("0000") != st.end()) return -1;

        queue<string> q;
        q.push("0000");

        string temp;
        int level = 0;

        unordered_set<string> vis;
        vis.insert("0000");

        while(!q.empty()){
            int size = q.size();
            while(size--){
                temp = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    temp[i] = (temp[i] - '0' + 1) % 10 + '0';
                    if(temp == target) return level + 1;

                    if(vis.find(temp) == vis.end() && st.find(temp) == st.end()){
                        vis.insert(temp);
                        q.push(temp);
                    }

                    temp[i] = (temp[i] - '0' - 2 + 10) % 10 + '0';
                    if(temp == target) return level + 1;

                    if(vis.find(temp) == vis.end() && st.find(temp) == st.end()){
                        vis.insert(temp);
                        q.push(temp);
                    }
                    temp[i] = (temp[i] - '0' + 1) % 10 + '0';
                }
            }
            level++;
        }
        return -1;
    }
};