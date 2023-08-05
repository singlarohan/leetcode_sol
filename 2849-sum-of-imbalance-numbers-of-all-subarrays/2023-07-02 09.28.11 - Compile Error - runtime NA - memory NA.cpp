class Solution {
public:
    int sumImbalanceNumbers(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 0; i < arr.size() - 1; i++){
            priority_queue<int, vector<int>, greater<int>> pq;
            //for i and i + 1th element
            pq.push(arr[i]);            
            pq.push(arr[i+1]);
            int curr = abs(arr[i + 1] - arr[i]);
            
            for(int j = i + 2; arr.size(); j++){
                
            }

            
        }
    }
};