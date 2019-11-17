/* 7.Reverse Integer */


//O(log10(num))

class Solution{
public:
    int reverse(int num){
        int res = 0;

        while(num != 0){
            if(res > INT_MAX / 10 || res < INT_MIN / 10) return 0;//check before res gets too large
            res = res * 10 + num % 10;
            num /= 10;

        }
        return res;
    }
};
