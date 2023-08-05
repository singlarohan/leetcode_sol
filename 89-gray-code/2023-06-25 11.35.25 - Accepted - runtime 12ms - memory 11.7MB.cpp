class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray_code;
        if (n <= 0) {
            return gray_code;
        }

        // Base case: single-bit Gray code sequence
        gray_code.push_back(0);
        gray_code.push_back(1);

        int mask = 1;
        for (int i = 1; i < n; i++) {
            // Calculate mask for toggling the bit
            mask <<= 1;

            // Add new gray codes based on previous codes in reverse order
            for (int j = gray_code.size() - 1; j >= 0; j--) {
                gray_code.push_back(gray_code[j] | mask);
            }
        }
        return gray_code;
    }

};