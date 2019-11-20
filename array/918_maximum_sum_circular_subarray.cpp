// count local max for the normal cases, and count local min for circular cases, then take the max of the two

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int lmn = 0, lmx = 0; //local min and max
        int mn = INT_MAX, mx = INT_MIN; //'global' min and max
        int sum = 0; // sum of every elements in the input array
        int res;

        for (int a : A){
            lmn = min(lmn + a, a);
            mn = min(mn, lmn);
            lmx = max(lmx + a, a);
            mx = max(mx, lmx);
            sum += a;
        }
        
        res = (sum - mn == 0) ? mx : max(mx, sum - mn); //corner case: if all elements are negative, then mn == sum, sum - mn == 0 > mx;
        return res;
    }
};


