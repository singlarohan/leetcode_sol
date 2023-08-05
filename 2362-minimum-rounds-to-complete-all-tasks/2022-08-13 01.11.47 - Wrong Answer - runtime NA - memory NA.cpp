class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        vector<int> count_arr;
        int count{1};
        for(int i = 1; i<tasks.size(); i++){
            if(tasks[i] != tasks[i-1]){
                count_arr.push_back(count);
                if(count == 1)
                    return -1;
                count = 1;
            }
            else
                count++;
        }
        count_arr.push_back(count);
        count = 0;
        for(int i = 0; i<count_arr.size(); i++){
            count += (count_arr[i] + 2) / 3;
        }
        return count;
    }
};