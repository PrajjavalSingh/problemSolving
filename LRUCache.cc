//https://leetcode.com/problems/lru-cache/
class LRUCache {
public:
    LRUCache(int capacity) 
    {
        maxsz_ = capacity;
    }
    
    int get(int key) 
    {
        if ( data_.contains(key) )
        {
            int count = lrukey_[key];
            lrukey_[key] = ++count;
            return data_[key];
        }

        return -1;
    }
    
    void put(int key, int value) 
    {
        const multimap<int,int> lru_key = getLRUKey();
        if ( data_.size() == maxsz_ )
        {
            data_.erase( lru_key.begin()->second );
            lrukey_.erase( lru_key.begin()->second );
        }

        data_[key] = value;
        if ( lru_key.size() )
            lrukey_[key] = lru_key.rbegin()->first;
        else
            lrukey_[key] = 0;
    }

protected:
    multimap<int,int> getLRUKey() const
    {
        multimap<int,int> mmlrukey;
        for ( auto& lru : lrukey_ )
            mmlrukey.insert( pair<int,int>(lru.second,lru.first) );

        return mmlrukey;
    }

private:
    map<int,int>            data_;
    map<int,int>            lrukey_;
    uint                    maxsz_  = 0;
    int                     newcount_ = 0;
};
