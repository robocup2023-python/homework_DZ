#include <bits/stdc++.h>
using namespace std;

class Twitter
{
public:
    struct node
    {
        int ID;
        unordered_set<int> tweetID;
        unordered_set<int> followerID;
        node *next;
        node()
        {
            next = NULL;
        }
    };
    node *head;
    node *tail;
public:
    int pp_sum;
    int tweet_sum;
    map<int, string> tweet;//tweetId---tweet
    map<int, node*> user; //userId---usernode
public:
    Twitter()
    {
        head = NULL;
        tail = NULL;
        pp_sum = 0;
        tweet_sum = 0;
    }
    void createuser(int userId)
    {
        if (!find_user(userId))
        {
            if (!pp_sum)
            {
                node *n = new node();
                pp_sum = userId;
                n->ID = userId;
                head = n;
                tail = n;
                user[userId] = n;
            }
            else
            {
                if (userId < head->ID)
                {
                    node *n = new node();
                    n->ID = userId;
                    n->next = head;
                    head = n;
                    user[userId] = n;
                }
                else if (userId > tail->ID)
                {
                    node *n = new node();
                    n->ID = userId;
                    tail->next = n;
                    tail = tail->next;
                    user[userId] = n;
                }
                else
                {
                    node *n = new node();
                    n->ID = userId;
                    node *p = head, *prev;
                    while (p != NULL)
                    {
                        if (p->ID > userId && prev->ID < userId)
                        {
                            break;
                        }
                        prev = p;
                        p = p->next;
                    }
                    n->next = p;
                    prev->next = n;
                    user[userId] = n;
                }
            }
        }

    }
    // void out()
    // {
    //     node *curr = head;
    //     while (curr != NULL)
    //     {
    //         cout<<curr->ID<<endl;
    //         curr = curr->next;
    //     }
    // }
    bool find_user(int userId)
    {
        node *curr = head;
        while (curr != NULL)
        {
            if (curr->ID == userId)
            {
                return true;
            }
            else if (curr->ID > userId)
            {
                return false;
            }
            curr = curr->next;
        }
        return false;
    }
    void postTweet(int userId, string tweetContent)
    {
        createuser(userId);
        tweet_sum++;
        user[userId]->tweetID.insert(tweet_sum);
        tweet[tweet_sum] = tweetContent;
    }
    // void postTweet(int userId, int tweetID)//leetcode
    // {
    //     createuser(userId);
    //     user[userId]->tweetID.push_back(tweetID);
    //     if (tweet_sum < tweetID)
    //     {
    //         tweet_sum = tweetID;
    //     }
    // }
    vector<int> getNewsFeed(int userId)
    {
        vector<int> ans;
        ans.clear();
        int k = tweet_sum, cnt = 0;
        while (cnt < 10)
        {
            if (!k)
            {
                break;
            }
            if (user[userId]->tweetID.find(k) != user[userId]->tweetID.end())
            {
                ans.push_back(k);
                cnt++;
            }
            else
            {
                for (auto p = user[userId]->followerID.begin(); p != user[userId]->followerID.end(); p++)
                {
                    if (user[*p]->tweetID.find(k) != user[*p]->tweetID.end())
                    {
                        ans.push_back(k);
                        cnt++;
                        break;
                    }
                }
            }
            k--;
        }
        return ans;
    }
    void follow(int followerId, int followeeId)
    {
        createuser(followerId);
        createuser(followeeId);
        user[followerId]->followerID.insert(followeeId);
    }
    void unfollow(int followerId, int followeeId)
    {
        createuser(followerId);
        createuser(followeeId);
        user[followerId]->followerID.erase(followeeId);
    }
};

int main()
{
    vector<int> ans;
    Twitter *twitter = new Twitter();
    twitter->postTweet(1, "abswu"); 
    twitter->follow(1, 2); 
    twitter->postTweet(2, "suqisbiqdbqd"); 
    twitter->follow(1, 5); 
    ans = twitter->getNewsFeed(1); 
    int n = ans.size();
    for (int p = 0; p < n; p++)
    {
        cout << twitter->tweet[ans[p]] << ' ';
    }
    cout<<endl;
    ans.clear();
    twitter->unfollow(1, 2); 
    ans = twitter->getNewsFeed(1); 
    n = ans.size();
    for (int p = 0; p < n; p++)
    {
        cout << twitter->tweet[ans[p]] << ' ';
    }
}