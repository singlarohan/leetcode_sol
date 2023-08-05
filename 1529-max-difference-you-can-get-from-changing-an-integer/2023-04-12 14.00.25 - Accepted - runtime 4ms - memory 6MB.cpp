class Solution {
public:
    int maxDiff(int num) {
        string a = to_string(num);
        string b = a;
        int i{}, j{};
        while(i < a.size() && (a[i] == '1' || a[i] == '0')) i++;
        while(j < a.size() && a[j] == '9') j++;
        char a1 = a[i],b1 = b[j];
        bool flag = i == 0;
        // cout<<i<<" "<<j<<endl;
        for(int k = 0; k < a.size(); k++){
            if(i < a.size() && a1 == a[k]) a[k] = '0' + flag;
            if(j < b.size() && b1 == b[k]) b[k] = '9';
            // cout<<a<< " "<<b<<endl;
        }
        return stoi(b) - stoi(a);
    }
};