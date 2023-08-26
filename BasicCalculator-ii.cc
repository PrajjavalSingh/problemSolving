// Online C++ compiler to run C++ program online
// Online C++ compiler to run C++ program online
//
// https://leetcode.com/problems/basic-calculator-ii/
// Failing with stoi error, running for 41 cases
#include <iomanip>

class Solution {
public:

    int calcValue( vector<char>& allsymbols, string& numstr )
    {
        //Since valid expression so symbols cannot be at the end or begining other than negative symbol.
        // Handle negative cases now
        if ( allsymbols.size() == 0 )
        {
            return stoi(numstr);
        }

        char currsymbol = allsymbols[0];
        auto it = std::find(numstr.begin(),numstr.end(),currsymbol);
        if ( it == numstr.end() )
        {
            allsymbols.erase(allsymbols.begin(),allsymbols.begin()+1); 
            return calcValue( allsymbols, numstr );
        }
        else if ( it == numstr.begin() )
        {
            return stoi(numstr);
        }

        string num1str = "";
        string num2str = "";
        bool num1_found = false;
        bool num2_found = false;
        string::iterator right_iterator = std::find_if( it, numstr.end(), [=](auto ch) { return (int)ch>47 && (int)ch<58; } );
        string::iterator left_iterator = it - 1;
        
        while ( !num1_found || !num2_found )
        {

            if ( !num1_found )
            {
                if ( left_iterator != numstr.begin() && (((int)*left_iterator>47 && (int)*left_iterator<58) || *left_iterator == '-')  )
                {    
                    num1str.push_back( *left_iterator );
                     if ( *left_iterator != '-' )
                        --left_iterator;
                    else
                        num1_found = true;
                }
                else if ( *left_iterator == ' ' && num1str.size() == 0 )
                {
                    --left_iterator;
                }
                else if ( left_iterator == numstr.begin() )
                {
                    num1str.push_back( *left_iterator );
                    num1_found = true;
                }
                else
                    num1_found = true;
            }

            if ( !num2_found )
            {
                if ( right_iterator != numstr.end() && (int)*right_iterator>47 && (int)*right_iterator<58 )
                {
                    num2str.push_back(*right_iterator);
                    if ( (int)*(right_iterator+1)>47 && (int)*(right_iterator+1)<58 )
                        ++right_iterator;
                    else
                        num2_found = true;
                }
                else
                    num2_found = true;
            }
            
        }

        string value;
        int val = 0;
        int num1 = 0;
        int num2 = 0;
        if( num1str.size() )
        {
            std::reverse(num1str.begin(),num1str.end());
            num1 = stoi(num1str);
        }
        
        if ( num2str.size() )
            num2 = stoi(num2str);

        switch(currsymbol)
        {
            case '/':
                if ( num2 != 0|| num1 != 0 )
                    val = num1/num2;
                break;
            case '*':
                val = num1*num2;
                break;
            case '+':
                val = num1+num2;
                break;
            case '-':
                val = num1-num2;
                break;
        }

        value = to_string(val);
        if ( left_iterator == numstr.begin() && right_iterator != numstr.end() )
        {
            if ( num1 < 0 )
                numstr.erase(left_iterator+1,right_iterator+1);
            else    
                numstr.erase(left_iterator,right_iterator+1);
        }
        else if ( left_iterator != numstr.begin() && right_iterator == numstr.end() )
            numstr.erase(left_iterator+1,right_iterator);
        else if ( left_iterator != numstr.begin() && right_iterator != numstr.end() )
            numstr.erase(left_iterator+1,right_iterator+1);
        else
        {
            if ( num1 < 0 )
                numstr.erase(left_iterator+1,right_iterator);
            else    
                numstr.erase(left_iterator,right_iterator);
        }

        if ( left_iterator != numstr.begin() )
        {
            if ( num1 < 0 && val > 0 )
            {
                const int idx = left_iterator-numstr.begin();
                numstr.replace(idx, 1,"+");
            }
            else if ( num1 > 0 && val < 0 )
            {
                const int idx = left_iterator-numstr.begin();
                numstr.replace(idx, 1,"-");
            }
        } 
     
        if ( numstr.size() )
        {
            for ( int idx=0; idx<value.size(); idx++ )
            {
                char valstr = value[idx];
                if ( left_iterator - numstr.begin() == 0 )
                    numstr.insert(left_iterator,valstr);
                else
                    numstr.insert(left_iterator+1,valstr);
                left_iterator++;
            }
        }
        else
            numstr = value;

        return calcValue(allsymbols,numstr);
    }


    int calculate(string s) 
    {
        vector<char> symbols;
        symbols.push_back('/');
        symbols.push_back('*');
        symbols.push_back('+');
        symbols.push_back('-');
        for ( int idx=0; idx<symbols.size(); idx++ )
        {
            char symbol = symbols[idx];
            if ( std::find(s.begin(), s.end(),symbol) == s.end() )
                symbols.erase(symbols.begin()+idx);
        }
        int val = calcValue( symbols, s );
        return val;
    }
};
