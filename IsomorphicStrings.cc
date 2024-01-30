//https://leetcode.com/problems/isomorphic-strings/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    void fillUnorderedMap(unordered_map<char,vector<int>>& smap, const string& s )
    {
        for ( int idx=0; idx<s.size(); idx++ )
        {
            char currchar = s[idx];
            auto it = smap.find(currchar);
            if ( it != smap.end() )
            {
                it->second.push_back(idx);
            }
            else
            {
                vector<int> val;
                val.push_back(idx);
                smap[currchar] = val;
            }
        }
    }

    bool isIsomorphic(string s, string t) 
    {
        if ( s.size() != t.size() )
            return false;

        unordered_map<char,vector<int>> smap;
        unordered_map<char,vector<int>> tmap;
        fillUnorderedMap( smap, s );
        fillUnorderedMap( tmap, t );
        for ( int idx=0; idx<s.size(); idx++ )
        {
            const auto currchar_s = s[idx];
            const auto currchar_t = t[idx];
            auto itrsmap = smap.find(currchar_s);
            auto itrtmap = tmap.find(currchar_t);
            auto vec_smap = itrsmap->second;
            auto vec_tmap = itrtmap->second;
            if ( vec_smap.size() != vec_tmap.size() )
                return false;

            if ( !equal(vec_tmap.begin(), vec_tmap.end(), vec_smap.begin()) )
                return false;
        }

        return true;
    }
};

//second solution more faster
class Solution {
public:

    bool isIsomorphic(string s, string t) 
    {
        if ( s.size() != t.size() )
            return false;

        unordered_map<char,char> map;
        unordered_map<char,char> tmap;
        for ( int idx=0; idx<s.size(); idx++ )
        {
            const auto currchar_s = s[idx];
            const auto currchar_t = t[idx];
            auto itx = map.find(currchar_s);
            auto itxm = tmap.find(currchar_t);
            if ( itx != map.end() && itxm != tmap.end() )
            {
                if ( itx->second == currchar_t )
                    continue;
                else
                    return false;
            }
            else if ( (itx == map.end() && itxm == tmap.end()) )
            {
                map[currchar_s] = currchar_t;
                tmap[currchar_t] = currchar_s;
            }
            else
                 return false;

        }

        return true;
    }
};
