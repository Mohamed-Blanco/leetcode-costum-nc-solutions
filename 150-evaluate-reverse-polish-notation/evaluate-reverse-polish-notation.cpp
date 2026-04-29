#include <algorithm>
#include <cctype>

class Solution {
public:

    bool isNumerique(const string& s )
    {
        try
        {
            std::stoi(s);
            return true ; 
        }catch(...)
        {
            return false; 
        }   
    }

    int evalRPN(vector<string>& tokens) {
        
        //numbers vector ! 
        std::vector<int> numbers {};

        for(const auto& token : tokens )
        {            
            if(isNumerique(token))
            {
                numbers.push_back(stoi(token)); 
            }else
            {
                int a = numbers.back();
                numbers.pop_back(); 

                int b =numbers.back();  
                numbers.pop_back(); 
                
                switch(token[0])
                {
                    case '+':
                        numbers.push_back(a+b); 
                        break; 
                    case '-':
                        numbers.push_back(b-a); 
                        break; 
                    case '/':
                        numbers.push_back(b/a); 
                        break; 
                    case '*':
                        numbers.push_back(a*b); 
                        break; 
                    default : 
                        break; 
                }
            }
        }


        
        return numbers.back(); 
    }
};