class Solution {
public:
    string removeDuplicates(string s, int k) {
        //Stack and Two pointer
        //keeping count of last distinct element
        string ans;
        stack<pair<char, int>> st;
        for(int i = 0; i < s.size(); i++){
            if(!st.empty() && st.top().first == s[i]){
                pair<char, int> temp = st.top();
                temp.second++;
                st.pop();
                st.push(temp);
                if(st.top().second == k)
                    st.pop();
            }
            else
                st.push({s[i], 1});
        }
        while(!st.empty()){
            pair<char, int> temp = st.top();
            while(temp.second--)
                ans.push_back(temp.first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};