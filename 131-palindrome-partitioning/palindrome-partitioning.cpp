class Solution {
public:

    vector<vector<string>> subsets{}; 
    
    bool isPalindrome(std::string str)
    {
        int i {},j = std::ssize(str)-1; 
        while(i < j)
        {
            if(str[i] != str[j])
            {
                return false; 
            }
            ++i; 
            --j; 
        }

        return true ; 
    }  

    void bfs(int index,std::string str,std::vector<std::string> subset)
    {
        if( index >= str.size())
        {
            subsets.push_back(subset); 
            return ; 
        }

        for( int i {index} ; i < str.size(); ++i)
        {
            if(isPalindrome(str.substr(index,i-index+1)))
            {
                subset.push_back(str.substr(index,i-index+1)); 
                bfs(i+1,str,subset);
                subset.pop_back(); 
            }
        }
        
    }

    vector<vector<string>> partition(string s) {
        bfs(0,s,{}); 
        return subsets;
    }
};