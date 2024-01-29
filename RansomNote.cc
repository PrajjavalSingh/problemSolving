//https://leetcode.com/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        const auto rsz = ransomNote.size();
        const auto msz = magazine.size();
        if ( rsz > msz )
            return false;

        
        unordered_map<char,int> rmap;
        unordered_map<char,int> mmap;

        for ( int idx=0; idx<rsz; idx++ )
        {
            auto it = rmap.find(ransomNote[idx]);
            if ( it == rmap.end() )
                rmap[ransomNote[idx]] = 1;
            else
                it->second += 1;
        }

        for ( int idx=0; idx<msz; idx++ )
        {
            auto it = mmap.find(magazine[idx]);
            if ( it == mmap.end() )
                mmap[magazine[idx]] = 1;
            else
                it->second += 1;
        }

        for ( auto entry : rmap )
        {
            auto it = mmap.find(entry.first);
            if ( it == mmap.end() )
                return false;
            else if ( entry.second > it->second )
                return false;
        }

        return true;
    }
};
