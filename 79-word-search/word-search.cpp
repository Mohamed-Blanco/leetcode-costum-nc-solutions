class Solution {
public:

    bool dfs(int index,int i , int j , std::string& word, int n ,int m , vector<vector<char>> &board)
    {
        if(index == word.size()) return true ; 
        if(i < 0 || i >= n || j < 0 || j >= m || word[index] != board[i][j]) //inssuring that are indexes are not out of bound and also the current char is in there 
        {
            return false ; 
        }
        
        char tmp {board[i][j]};// i just removed it of the word to not get used again .
        board[i][j] = '.'; 

        bool found = dfs(index+1,i+1,j,word,n,m,board) || dfs(index+1,i-1,j,word,n,m,board) || dfs(index+1,i,j+1,word,n,m,board) || dfs(index+1,i,j-1,word,n,m,board); 
        
        board[i][j] = tmp; 
        return found ;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n  = board.size();
        int m = std::size(board[0]); 
        for(int i {};  i < n ; ++i)
        {
            for(int j {}; j < m ; ++j)
            {
                if(board[i][j] == word[0])
                {
                    std::cout << "\nFound char = " << word[0] << " at i = " << i << " j == " << j ; 
                    if(dfs(0,i,j,word,n,m,board))
                    {
                        return true; 
                    }
                }
            }
        }

        return false; 
    }
};