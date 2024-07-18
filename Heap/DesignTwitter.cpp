struct Tweet {
public:
    int userId;
    int tweetId;
    Tweet* next;
    Tweet(int userId, int tweetId) {
        this->userId = userId;
        this->tweetId = tweetId;
        this->next = NULL;
    }
};
class Twitter {
    map<int, set<int>> f;
    Tweet* head = NULL;
    Tweet* tail = NULL;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        if (this->head == NULL) {
            this->head = this->tail = new Tweet(userId, tweetId);
        } else {
            Tweet* newTweet = new Tweet(userId, tweetId);
            newTweet->next = head;
            head = newTweet;
        }
    }

    vector<int> getNewsFeed(int userId) {
        Tweet* temp = this->head;
        vector<int> ans;
        int count = 10;
        while (count && temp) {
            if (f[userId].count(temp->userId) != 0 || temp->userId == userId) {
                count--;
                ans.push_back(temp->tweetId);
            }
            temp = temp->next;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        f[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        f[followerId].erase(followeeId);
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