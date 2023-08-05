class Solution {
public:
    static bool comp(string &a, string &b){
        return a.size() < b.size();
    }
    
    void sort(vector<string> &s, int n){
        for (int i=1 ;i<n; i++)
        {
            string temp = s[i];

            // Insert s[j] at its correct position
            int j = i - 1;
            while (j >= 0 && temp.length() < s[j].length())
            {
                s[j+1] = s[j];
                j--;
            }
            s[j+1] = temp;
        }
    }
    
    string arrangeWords(string text) {
        text[0] += 32;
        vector<string> v;
        for(int i = 0; i < text.size(); i++){
            v.push_back("");
            while(i < text.size() && text[i] != ' '){
                v.back().push_back(text[i]);
                i++;
            }
        }
        // sort(v.begin(), v.end(), comp);
        sort(v, v.size());
        string ans;
        for(int i = 0; i < v.size(); i++)
            ans += v[i] + ' ';
        ans.pop_back();
        ans[0] -= 32;
        return ans;
    }
};