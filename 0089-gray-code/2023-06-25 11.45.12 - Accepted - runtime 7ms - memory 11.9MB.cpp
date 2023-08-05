class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray_code;

        // Calculate the total number of codes
        int total_codes = 1 << n;

        // Generate the Gray code sequence
        for (int i = 0; i < total_codes; i++) {
            int code = i ^ (i >> 1);
            gray_code.push_back(code);
        }

        return gray_code;
    }

};