class Solution {
public:
    long long continuousSubarrays(vector<int>& array) {
    int count = 0;
    int n = array.size();
    int left = 0;
    int right = 0;
    int maxElem = array[0];
    int minElem = array[0];

    while (right < n) {
        maxElem = std::max(maxElem, array[right]);
        minElem = std::min(minElem, array[right]);

        if (std::abs(maxElem - minElem) <= 2) {
            count += (right - left + 1);
        } else {
            while (std::abs(maxElem - minElem) > 2) {
                maxElem = *std::max_element(array.begin() + left + 1, array.begin() + right + 1);
                minElem = *std::min_element(array.begin() + left + 1, array.begin() + right + 1);
                ++left;
            }
            count += (right - left + 1);
        }

        ++right;
    }

    return count;
    }
};