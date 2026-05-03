class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int r{1}, l {0};
        int maxProfit{}; 

        while(r < std::ssize(prices) )
        {
            if(maxProfit < (prices[r]-prices[l])){
                maxProfit = prices[r]-prices[l]; 
            }

            if(prices[r] < prices[l])
            {
                l = r ; 
                ++r; 
            }else
            {
                ++r; 
            }
        }

        return maxProfit > 0 ? maxProfit : 0; 
    }   
};