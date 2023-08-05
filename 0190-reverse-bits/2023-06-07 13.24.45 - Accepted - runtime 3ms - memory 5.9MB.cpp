class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i = 0; i <= 15; i++){
            //(we need to check for i & (31 - i))
            int x1 = n & (1 << i);
            int x2 = n & (1 << (31 - i));
            // cout<<n<<" "<<x1<<" "<<x2<<endl;
            int temp{};
            temp = 1 << (31 - i);
            n &= -1 - temp;
            if(x1 != 0){ //means there is a one at ith position
                // cout<<-1 - temp<<endl;
                n |= temp;
            }
            temp = 1 << i;
            n &= -1 - temp; 
            if(x2 != 0){
                // cout<<-1 - temp<<endl;
                n |= temp;
            }
        }
        return n;
    }
};