class Solution {
    int count;
public:
    int countArrangement(int N) {
        count = 0;
        std::vector<bool> visited(N + 1, false);
        calculate(N, 1, visited);
        return count;
    }
    
    void calculate(int N, int pos, std::vector<bool>& visited) {
        if (pos > N)
            count++;
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                visited[i] = true;
                calculate(N, pos + 1, visited);
                visited[i] = false;
            }
        }
    }
};