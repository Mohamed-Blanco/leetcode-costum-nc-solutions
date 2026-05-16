class Solution {
public:

    std::vector<std::string> permutations {}; 
    void backtrack(int n,std::string curr,int open, int close)
    {
        if(n == open && n == close)
        {
            permutations.push_back(curr); 
            return ; 
        }
        
        if(open < n)
        {
            backtrack(n,curr+"(",open+1,close);
        }
        
        if(close < open)
        {
            backtrack(n,curr+")",open,close+1); 
        }
        
        return; 
    }

    vector<string> generateParenthesis(int n) {
        if(n <= 0 ) return {}; 
        backtrack(n,"",0,0); 
        return permutations ; 
    }
};