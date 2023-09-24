//https://leetcode.com/problems/lru-cache/
class LRUCache {
public:
    LRUCache(int capacity) 
    {
        maxsz_ = capacity;
    }
    
    int get(int key) 
    {
        if ( data_.find(key) != data_.end() )
        {
            const multimap<int,int> lru_key = getLRUKey();
            int count = lru_key.rbegin()->first + 1;
            lrukey_[key] = count;
            return data_[key];
        }

        return -1;
    }
    
    void put(int key, int value) 
    {
        multimap<int,int> lru_key;
        bool lru_key_assigned = false;
        if ( data_.size() == maxsz_ && !data_.contains(key) )
        {
            lru_key = getLRUKey();
            data_.erase( lru_key.begin()->second );
            lrukey_.erase( lru_key.begin()->second );
            lru_key_assigned = true;
        }

        data_[key] = value;
        if ( lrukey_.size() )
        {
            if ( !lru_key_assigned )
                lru_key = getLRUKey();

            lrukey_[key] = lru_key.rbegin()->first+1;
        }
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
    unordered_map<int,int>              data_;
    unordered_map<int,int>              lrukey_;
    uint                                maxsz_  = 0;
    int                                 newcount_ = 0;
};
