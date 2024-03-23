//https://leetcode.com/problems/letter-combinations-of-a-phone-number/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    // Following works only for the cases where all the digits are different
    // bool helper(vector<string>& ans, string& curr, vector<string>& processed,
    //                                                 const vector<string>& letterset, int expectednr  )
    // {
    //     if ( curr.size() == letterset.size() )
    //     {
    //         ans.push_back( curr );
    //         return ans.size() == expectednr;
    //     }

    //     for ( auto letterstr : letterset )
    //     {
    //         if ( find(processed.begin(),processed.end(),letterstr) == processed.end() )
    //         {
    //             processed.push_back(letterstr);
    //             for ( auto ch : letterstr )
    //             {
    //                 if ( find(curr.begin(),curr.end(),ch) == curr.end() )
    //                 {
    //                     curr.push_back( ch );
    //                     if (helper( ans, curr, processed, letterset, expectednr ) )
    //                         return true;

    //                     curr.pop_back();
    //                 }
    //             }
                
    //             processed.pop_back();
    //         }
    //     }

    //     return false;
    // }

    void helper( vector<string>& ans, string& curr, int nr, const vector<string>& letterset, int idx )
    {
        if ( curr.size() == nr )
        {
            ans.push_back( curr );
            return;
        }

        string curr_x = letterset[idx];
        for ( auto ch : curr_x )
        {
            curr.push_back( ch );
            helper( ans, curr, nr, letterset, idx+1 );
            curr.pop_back();
        }

    }


    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        if ( digits.empty() )
            return ans;

        string curr;
        //97–122
        vector<string> letterset;
        int expectednr = 1;
        for ( auto ch : digits )
        {
            string s;
            s += ch;
            const int num = stoi(s);
            string letter;
            if ( num <=6 )
            {
                const int startidx = (num-2)*3 + 97;
                const int endidx = num == 9 ? startidx + 3 : startidx + 2;
                for ( int idx = startidx; idx<=endidx; idx++ )
                    letter += char(idx);
            }
            else
            {
                switch(num)
                {
                    case 7:
                        letter = "pqrs";
                        break;
                    case 8:
                        letter = "tuv";
                        break;
                    case 9:
                        letter = "wxyz";
                        break;
                }
            }

            expectednr *= letter.size();
            letterset.push_back(letter);
        }

        vector<string> processed;     
        helper( ans, curr, digits.size(), letterset, 0 );
        return ans;
    }
};
