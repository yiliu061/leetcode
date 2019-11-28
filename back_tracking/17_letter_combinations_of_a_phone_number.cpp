class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> umap;
        // vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        umap[2] = "abc";
        umap[3] = "def";
        umap[4] = "ghi";
        umap[5] = "jkl";
        umap[6] = "mno";
        umap[7] = "pqrs";
        umap[8] = "tuv";
        umap[9] = "wxyz";
        
        vector<string> res;
        if (digits.empty()) return res;
        
        explore(digits, umap, res, "", 0);
        return res;
    }
    
    void explore(string digits, unordered_map<int, string> umap, vector<string>& res, string sub_res, int level){
        if (level == digits.size()) res.push_back(sub_res);
        
        string str = umap[digits[level] - '0'];       
        for (char c : str){
            explore(digits, umap, res, sub_res + c, level + 1);
        }
    }
    
};
