class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area{0}, min{0};
        int num = heights.size();
        
        for(int i=0;i<num;i++){

            if(area<heights[i])
            area = heights[i];
            min = heights[i];

            for(int j=i+1;j<num;j++){
                if(heights[j]<min)
                min = heights[j];

                if(area<(j+1-i)*min)
                area = (j+1-i)*min;
            }
        }
        return area;
    }
};