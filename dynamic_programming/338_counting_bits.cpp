
//if i is even, (# of 1s) of i == (# of 1s ) of i/2 
//if i is even, (# of 1s) of i == (# of 1s ) of i/2 + 1

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        
        for (int i = 1; i <= num; ++i){
            if (i % 2 == 0) res[i] = res[i / 2];
            else res[i] = res[i / 2] + 1;
        }
        return res;
    }
};
