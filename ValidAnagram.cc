//https://leetcode.com/problems/valid-anagram/?envType=study-plan-v2&envId=top-interview-150
//Fastest 3ms solution at the end
//slow approach 16ms
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        const int sz = s.size();
        if ( sz != t.size() )
            return false;

        map<char,int> anagrammap;
        
        for ( auto ch1 : s )
        {
            if ( anagrammap.find(ch1) == anagrammap.end() )
            {
                anagrammap[ch1] = 1;
            }
            else
                anagrammap[ch1]++;
        } 

        bool status = true;
        for ( auto ch2 : t )
        {
            if ( anagrammap.find(ch2) == anagrammap.end() )
            {
                status = false;
                break;
            }
            else
            {
                anagrammap[ch2]--;
                if ( anagrammap[ch2] < 0 )
                {
                    status = false;
                    break;
                }
            }

        }

        auto it = anagrammap.begin();
        while ( it != anagrammap.end() )
        {
            if ( it->second != 0 )
            {
                status = false; 
                break;
            }

            it++;
        }


        return status;
        
    }
};

//still slow 10 ms
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        const int sz = s.size();
        if ( sz != t.size() )
            return false;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;      
    }
};

//still slow approach 18 ms
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        const int sz = s.size();
        if ( sz != t.size() )
            return false;

        map<char,int> anagrammap;
        for ( int idx=0; idx<sz; idx++ )
        {
            char ch1 = s[idx];
            char ch2 = t[idx];
            if ( ch1 == ch2 )
                continue;

            if ( anagrammap.find(ch1) == anagrammap.end() )
            {
                anagrammap[ch1] = 1;
            }
            else
                anagrammap[ch1]++;

            if ( anagrammap.find(ch2) == anagrammap.end() )
            {
                anagrammap[ch2] = -1;
            }
            else
                anagrammap[ch2]--;
        }

        auto it = anagrammap.begin();
        while ( it != anagrammap.end() )
        {
            if ( it->second != 0 )
                return false;

            it++;
        }

        return true;
              
    }
};

//11ms solution
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        const int sz = s.size();
        if ( sz != t.size() )
            return false;

        map<char,int> anagrammap;
        for( int idx=0;idx<sz;idx++ )
            anagrammap[s[idx]]++;
        
        for(int idx=0;idx<sz;idx++ )
            anagrammap[t[idx]]--;


        auto it = anagrammap.begin();
        while ( it != anagrammap.end() )
        {
            if ( it->second != 0 )
                return false;

            it++;
        }

        return true;
              
    }
};

//another way using all_of
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        const int sz = s.size();
        if ( sz != t.size() )
            return false;

        unordered_map<char,int> anagrammap;
        for( int idx=0;idx<sz;idx++ )
            anagrammap[s[idx]]++;
        
        for(int idx=0;idx<sz;idx++ )
            anagrammap[t[idx]]--;


        return all_of(anagrammap.begin(),anagrammap.end(),[](const auto& p) {return !p.second;});
    }
};


//3ms solution
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        const int sz = s.size();
        if ( sz != t.size() )
            return false;

        unordered_map<char,int> anagrammap;
        for( int idx=0;idx<sz;idx++ )
            anagrammap[s[idx]]++;
        
        for(int idx=0;idx<sz;idx++ )
            anagrammap[t[idx]]--;


        auto it = anagrammap.begin();
        while ( it != anagrammap.end() )
        {
            if ( it->second != 0 )
                return false;

            it++;
        }

        return true;
              
    }
};
