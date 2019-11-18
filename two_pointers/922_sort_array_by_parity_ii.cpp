// two pointers, one to 'odd' and one to 'even'. Keep moving the pointers till there are mismatches, then swap the values. 
// O(n)

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int oddPtr = 1, evenPtr = 0;
        
        while(oddPtr < A.size() && evenPtr < A.size()){
            if (A[oddPtr] % 2 == 1) oddPtr += 2;
            else if (A[evenPtr] % 2 == 0) evenPtr +=2;
            else swap ( A[evenPtr], A[oddPtr]);
        }
        return A;
    }
};
