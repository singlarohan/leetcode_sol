class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n, 0);
        for(int i = 0; i < n; i++)
            score[edges[i]] += i;

        int maxi = 0;
        for(int i = 1; i < n; i++)
            if(score[maxi] < score[i]) maxi = i;
        return maxi;
    }
};