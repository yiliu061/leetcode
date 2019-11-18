// XOR the two numbers, then count all 1s. O(log(max(x,y)))


class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x ^ y;
        int res = 0;
        
        for(int i = 0; i < 32; ++i){
            if ((temp >> i) & 1) ++res;
        }
        return res;   
    }
};
