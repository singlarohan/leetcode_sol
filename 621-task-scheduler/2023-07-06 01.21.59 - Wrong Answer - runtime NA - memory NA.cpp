class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> arr(26, 0);
        
        for(auto &c:tasks) arr[c - 'A']++;
        
        // for(auto x:mp) if(x != 0) pq.push(x);

        // n spaces to be filled after any u know;
        int ans{};
        while(1){
            int mini = 0;
            for(int i = 1; i < 26; i++)
                if(arr[mini] == 0 || (arr[i] != 0 && arr[i] < arr[mini])) mini = i;
            
            if(arr[mini] == 0) break;
            
            int diff = arr[mini];
            arr[mini] = 0;
            int k = n;
            
            ans += (n + 1) * diff;

            for(int i = 0; i < 26 && k != 0; i++) {
                if(arr[i] != 0) {
                    arr[i] -= diff;
                    k--;
                }
            }
            
            ans -=k;
        }
        return ans;
    }
};