class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        for(int i = 0; i < words.size(); i++)
            mp[words[i]]++;
        unordered_map<string, int> mp2 = mp;
        int n = words[0].size();
        int l = 0, curr = 0;
        vector<int> ans;
        while(curr <= s.size() - n + 1){
            string temp = s.substr(curr,n);
            cout<<curr<<" "<<temp<<" "<<curr + n - 1<<endl;
            if(mp2.find(temp) != mp2.end()){
                curr = curr + n;
                mp2[temp]--;
                if(mp2[temp] == 0) mp2.erase(temp);
                if(mp2.empty()){
                    mp2 = mp;
                    ans.push_back(l);
                    l = l + n;
                    curr = l;
                }
            }
            else{
                l++;
                curr = l;
                // curr = l;
                mp2 = mp;
            }
        }
        return ans;
    }
};