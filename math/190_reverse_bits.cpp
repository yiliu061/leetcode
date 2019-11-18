class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res;
        
        for (int i = 0; i < 32; ++i){
            res = (res << 1) + (n >> i & 1); //if the current digit is 0, no need to add
        }
        
        return res;
    }
};
