class Twitter {
    long timeCounter = 0;
    vector<tuple<long,int,int>>allTweets; //(time,userId,tweetId)
    unordered_map<int,unordered_set<int>>follows;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        allTweets.push_back({timeCounter++,userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>feed;
        feed.reserve(10);

        for(int i = allTweets.size()-1; i>= 0 && feed.size() < 10; i--){
            auto[t,uid,tid] = allTweets[i];
            if(uid == userId || follows[userId].count(uid)){
                feed.push_back(tid);
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */