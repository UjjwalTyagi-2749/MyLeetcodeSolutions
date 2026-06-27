class Twitter {
private:
    int timestamp = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int,int,int,int>> pq;

        auto addTweets = [&](int uid) {
            if (tweets.count(uid) && !tweets[uid].empty()) {
                int idx = tweets[uid].size() - 1;
                auto& [time, tid] = tweets[uid][idx];
                pq.push({time, tid, uid, idx});
            }
        };

        addTweets(userId);
        for (int uid : following[userId]) addTweets(uid);

        vector<int> feed;
        while (!pq.empty() && feed.size() < 10) {
            auto [time, tid, uid, idx] = pq.top(); pq.pop();
            feed.push_back(tid);
            if (idx > 0) {
                auto& [t, id] = tweets[uid][idx - 1];
                pq.push({t, id, uid, idx - 1});
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};