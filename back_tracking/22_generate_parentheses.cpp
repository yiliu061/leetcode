
class Solution{
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, 0, 0, "", res);
        return res;
    }
    
    void generate(int n, int left, int right, string curr, vector<string>& res){// the left and right bracket in curr
        if(left == n && right == n) {
            res.push_back(curr);
            return;   
        }
        
        if(left < n) generate(n, left + 1, right, curr + '(', res);//put a left bracket if we haven't put all of them
        if (right < left) generate(n, left, right + 1, curr + ')', res); //put a right bracket if there is more left ones in the result

    }
};
