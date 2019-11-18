class Solution{
public:
    int getSum(int a, int b) {
	
	if (b == 0) return a;
	
	int sum = a ^ b; //sum, without thinking about the carry
	int carry = (a & b & 0x7ffffff) << 1; //remember to shift; 0xfffffff is to limit to 32 bits
	
	return getSum(sum, carry);
    }
};
