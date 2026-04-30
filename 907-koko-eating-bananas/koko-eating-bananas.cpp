class Solution {
public:

    
    bool doesWork(int rate, int h, const auto& piles)
    {
        for(int i = 0 ;  i < std::size(piles) ; ++i)
        {
            if(piles[i]%rate == 0) 
            {
                h -= (piles[i]/rate); 
            }else
            {
                h -= (piles[i]/rate)+1; 
            }
        }

        return (h >= 0) ; 
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1, r = piles[0]; 
        //getting the minmum : 
        for(int i = 1 ; i < std::size(piles) ; ++i )
        {
            if(r < piles[i]) r = piles[i];  // deduire le maximum 
        }
        
        int rate  ; 
        while(l<r)
        {
            rate = (l+r)/2; 
            if(doesWork(rate,h,piles))
            {
                r = rate ; 
            }else
            {
                l = rate+1; 
            }
        }
        
        return l; 
    }
};