class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())
        return "";
        unordered_map<char, int> tmp;
        unordered_map<char, int> smp1;
        unordered_map<char, int> smp2;
        int begin{0}, end{INT_MAX};
        //smp1 tracks if contains enough for tmp
        //smp2 tracks all characters of current window
        for(int i = 0; i < t.size(); i++)
            tmp[t[i]]++;
        int i{}, j{};
        while(j < s.size()){
            while(j < s.size() && smp1 != tmp){
                if(tmp.find(s[j]) != tmp.end()){
                    smp2[s[j]]++;
                    if(smp1[s[j]] < tmp[s[j]])
                        smp1[s[j]]++;
                }
                j++;
            }
            if(j - i < end - begin && smp1 == tmp)
                begin = i, end = j;
            while(smp1 == tmp){
                if(tmp.find(s[i]) != tmp.end()){
                    if(smp2[s[i]] != tmp[s[i]])
                        smp2[s[i]]--;
                    else{
                        if(j - i < end - begin)
                            begin = i, end = j;
                        smp2[s[i]]--, smp1[s[i]]--;
                        i++;
                        break;
                    }
                }
                if(smp1 == tmp) i++;
            }
            if(end - begin == t.size())
                break;
        }
        if(end == INT_MAX)
        return "";
        string ans = "";
        while(begin < end){
            ans += s[begin];
            begin++;
        }
        return ans;
    }
};