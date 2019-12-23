//binary search, iterative: O(log n), O(1)

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0; i /= 2) { // not i > 0, because i can be negative
            if (i % 2 != 0) res *= x;
            x *= x; //! no else
        }
        return n < 0 ? 1 / res : res;
    }
};
