class Solution {
public:
    vector<int> grayCode(int n) {
        std::vector<int> gray_code;

        // Base case: for n=0
        if (n == 0) {
            gray_code.push_back(0);
            return gray_code;
        }

        // Recursive call to generate the Gray code sequence for n-1 bits
        gray_code = grayCode(n - 1);

        // Calculate the size of the Gray code sequence for n-1 bits
        int size = gray_code.size();

        // Reflect the Gray code sequence
        for (int i = size - 1; i >= 0; i--) {
            int num = gray_code[i];
            // Set the most significant bit for the n-bit Gray code
            num |= (1 << (n - 1));
            gray_code.push_back(num);
        }

        return gray_code;
    }

};