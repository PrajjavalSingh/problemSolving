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
            const multimap<int,int>& lru_key = needreread_ ? getLRUKey() : mmlrukey_;
            newcount_ = lru_key.rbegin()->first + 1;
            lrukey_[key] = newcount_;
            needreread_ = true;
            return data_[key];
        }

        return -1;
    }
    
    void put(int key, int value) 
    {
        if ( data_.size() == maxsz_ && !data_.contains(key) )
        {
            multimap<int,int>& lru_key = needreread_ ? getLRUKey() : mmlrukey_;
            const int idx_toerase = lru_key.begin()->second;
            data_.erase( idx_toerase );
            lrukey_.erase( idx_toerase );
        }

        data_[key] = value;
        if ( lrukey_.size() )
            lrukey_[key] = ++newcount_;
        else
            lrukey_[key] = 0;

        needreread_ = true;
    }

protected:
    multimap<int,int>& getLRUKey()
    {
        mmlrukey_.erase(mmlrukey_.begin(),mmlrukey_.end());
        for ( auto& lru : lrukey_ )
            mmlrukey_.insert( pair<int,int>(lru.second,lru.first) );

        needreread_ = false;
        return mmlrukey_;
    }

private:
    unordered_map<int,int>              data_;
    unordered_map<int,int>              lrukey_;
    multimap<int,int>                   mmlrukey_;
    uint                                maxsz_  = 0;
    int                                 newcount_ = 0;
    bool                                needreread_ = true;
};
