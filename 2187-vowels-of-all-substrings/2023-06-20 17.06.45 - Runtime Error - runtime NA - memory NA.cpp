class Solution {
public:
    long long countVowels(string word) {
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        long long ans{};
        int n = word.size();

        for(int i = 0; i < n; i++){
            if(st.find(word[i]) != st.end()){
                ans += ((n - i) * (i + 1));
            }
        }
        return ans;
    }
};