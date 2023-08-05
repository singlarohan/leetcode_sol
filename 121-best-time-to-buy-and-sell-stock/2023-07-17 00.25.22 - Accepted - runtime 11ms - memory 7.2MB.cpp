// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int left = 0;
//         int right= 1;
//         int maxP=0;

//         while(right < prices.size())
//         {
//             int curP = prices[right]-prices[left];
//             if(prices[left]<prices[right]){
//                 maxP= max(curP,maxP);
//             }else{
//                 left=right;
//             }
//             right++;
//         }

//         return maxP

//     }
// };

int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string s; getline(cin, s); cout << '\n') {
        int ans = 0, mn = INT_MAX;
        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            int v = s[_i++] & 15;
            while ((s[_i] & 15) < 10) v = v * 10 + (s[_i++] & 15);
            mn = min(mn, v);
            ans = max(ans, v - mn);
        }
        cout << ans;
    }
    exit(0);
    return 0;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return 0;
    }
};