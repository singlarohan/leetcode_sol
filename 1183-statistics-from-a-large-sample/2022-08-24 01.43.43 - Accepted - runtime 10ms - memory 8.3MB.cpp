class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans(5, 0);
        ans[0] = -1;
        double total_freq{0};
        for(int i = 0; i< count.size(); i++){
            if(ans[0] == -1 && count[i] != 0)
                ans[0] = i;
            if(count[i] != 0)
                ans[1] = i;
            ans[2] += i*(double)count[i];
            total_freq += count[i];
            if(count[i] > count[ans[4]])
                ans[4] = i;
        }
        ans[2] /= total_freq;
        double curr_freq{};
        for(int i = 0; i < count.size(); i++){
            if(count[i] != 0)
                curr_freq += count[i];
            if(curr_freq > total_freq/2){
                if(ans[3] == 0)
                    ans[3] += i/2.0;
                ans[3] += i/2.0;
                break;
            }
            if(curr_freq == total_freq/2 && ans[3] == 0)
                ans[3] += i/2.0;
        }
        return ans;
    }
};