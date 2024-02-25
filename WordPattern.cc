//https://leetcode.com/problems/word-pattern/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        map<char,string> mapset1;
        map<string,char> mapset2;
        stringstream ss( s );
        string word;
        vector<string> words;
        while( ss >> word )
        {
            words.push_back(word);
        }
        
        const int pattern_size = pattern.size();
        const int words_size = words.size();

        if ( pattern_size != words_size )
            return false;

        for ( int idx=0; idx<pattern_size; idx++ )
        {
            char currchar = pattern[idx];
            string currword = words[idx];
            if ( (mapset1.find(currchar) == mapset1.end()) &&
                    (mapset2.find(currword) == mapset2.end()) )
            {
                mapset1[currchar] = currword;
                mapset2[currword] = currchar;
            }
            else if ( (mapset1[currchar] != currword) || (mapset2[currword] != currchar) )
                return false;
        }

        return true;
    }
};
