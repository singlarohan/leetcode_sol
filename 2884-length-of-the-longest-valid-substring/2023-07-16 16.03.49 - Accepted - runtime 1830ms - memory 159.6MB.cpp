class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forb) {
        map<string,int> m;
        for(auto  a:forb)
        {
            reverse(a.begin(),a.end()); // store the reverse string which will help in the time for matching with a substring of word.
            m[a]=1;
        }
        int ans=0,st=0;
        for(int i=0;i<word.size();i++)
        {
            string temp;
            for(int j=i;j>=max(i-10,st);j--)
            {
                temp.push_back(word[j]);
                if(m[temp])
                {
                    st=j+1;
                    break;
                }
            }
            ans=max(ans,i-st+1);
        }
        return ans;
    }
};