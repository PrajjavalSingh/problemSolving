//https://leetcode.com/problems/design-twitter/description/

struct Tweet
{
    int userid_ = -1;
    int tweetid_ = -1;
};


class UserData
{
    public:
                    UserData(int userid)
                    {
                        userid_ = userid;
                    }
    
    void            addTweet(Tweet tweet)
                    { tweets_.push_back(tweet); }    
                   
    vector<Tweet>   getData() const
                    { return tweets_; }

    bool            isFollowing(int id)
                    {
                        auto it = find( followerids_.begin(), followerids_.end(), id );
                        return it != followerids_.end();
                    }

    bool            addFollower( int id, string& msg )
                    {
                        auto it = find( followerids_.begin(), followerids_.end(), id );
                        if ( it != followerids_.end() )
                        {
                            msg = to_string( userid_ ) + " already following " + to_string( id );
                            return false;
                        }
                        
                        followerids_.push_back(id);
                        msg = to_string( userid_ ) + " now following " + to_string( id );
                        return true;
                    }

    void            removeFollower( int id, string& msg )
                    {
                        auto it = find( followerids_.begin(), followerids_.end(), id );
                        if ( it != followerids_.end() )
                        {
                            followerids_.erase( it );
                            msg = to_string( userid_ ) + " unfollowed " + to_string( id );
                        }
                        else
                            msg = to_string( userid_ ) + " is not in the followers list of " + to_string( id );

                        cout << "Cleaning up tweets" << endl;
                        for ( int idx=tweets_.size()-1; idx>=0; idx-- )
                        {
                            Tweet twt = tweets_[idx];
                            if ( twt.userid_ == id )
                            {
                                auto twtit = tweets_.begin() + idx;
                                tweets_.erase(twtit);
                                cout << "Removed tweet with user id : " << id << endl;
                            }
                        }
                    }
    
    private:
    int             userid_ = 0;
    vector<Tweet>   tweets_;
    vector<int>     followerids_;
};


class Twitter {
public:
    Twitter() 
    {
        
    }
    
    void postTweet(int userId, int tweetId) 
    {
        auto it = find( activeusers_.begin(), activeusers_.end(), userId );
        Tweet tweet;
        tweet.userid_ = userId;
        tweet.tweetid_ = tweetId;
        if ( it == activeusers_.end() )
        {
            UserData data( userId );
            data.addTweet( tweet );
            datas_.push_back( data );
            activeusers_.push_back( userId );
        }
        
        for ( int idx = 0; idx<datas_.size(); idx++ )
        {
            UserData& data = datas_[idx];
            if ( data.isFollowing(userId) )
                data.addTweet(tweet);

        }
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<Tweet> newsfeed;
        auto it = find( activeusers_.begin(), activeusers_.end(), userId );
        if ( it == activeusers_.end() )
        {
            cout << "User does not exists" << endl;
        }
        else
        {
            const int idx = it - activeusers_.begin();
            vector<Tweet> tweets = datas_[idx].getData();
            reverse( tweets.begin(), tweets.end() );
            if ( tweets.size() <= 10 )
                copy( tweets.begin(), tweets.end(), back_inserter(newsfeed) );
            else
                copy( tweets.begin(), tweets.begin()+10, back_inserter(newsfeed) );
        }

        vector<int> ret;
        for(int idx=0;idx<newsfeed.size(); idx++ )
            ret.push_back(newsfeed[idx].tweetid_);

        return ret;
    }
    
    void follow(int followerId, int followeeId) 
    {
        auto it = find( activeusers_.begin(), activeusers_.end(), followeeId );
        if ( it == activeusers_.end() )
            cout << "Following an invalid id : " << to_string( followeeId ) << endl;

        auto it_fllwr = find( activeusers_.begin(), activeusers_.end(), followerId );
        string message;
        const int idx = it_fllwr - activeusers_.begin();
        datas_[idx].addFollower( followeeId, message );
        cout << message << endl;
        
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        auto it = find( activeusers_.begin(), activeusers_.end(), followeeId );
        if ( it == activeusers_.end() )
            cout << "unFollowing an invalid id : " << to_string( followeeId ) << endl;

        auto it_fllwr = find( activeusers_.begin(), activeusers_.end(), followerId );
        string message;
        const int idx = it_fllwr - activeusers_.begin();
        datas_[idx].removeFollower( followeeId, message );
        cout << message << endl;
    }

private:
    vector<UserData>    datas_;
    vector<int>         activeusers_;

};

