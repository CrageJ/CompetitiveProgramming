/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
struct PairHash {
    std::size_t operator()(const std::pair<T, T>& p) const {
        auto hash1 = std::hash<T>{}(p.first);
        auto hash2 = std::hash<T>{}(p.second);
        return hash1 ^ hash2;
    }
};

class LRUCache {
public:
std::unordered_map<int, std::list<std::pair<int, int>>::iterator> mmp;
list<std::pair<int, int>> q; // key,value
int cap = 0;
int count = 0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key,int value = -1) {
        if (mmp.count(key)== 0){
            return -1;
        }
        pair<int,int> element = * mmp[key];

        if (value != -1){
            *mmp[key] = {key,value};
        }

        q.splice(q.end(),q,mmp[key]);

        return element.second;
    }
    
    void put(int key, int value) {
        if (mmp.count(key)==0){
            pair<int,int> item = {key,value};
            list<pair<int,int>>::iterator it;

            q.push_back(item);
            it = std::prev(q.end());
            mmp[key] = it;
            count++;
        }
        else{
            get(key,value);
        }

        if (count > cap){
            pair<int,int> e = q.front();
            mmp.erase(e.first);
            q.pop_front();
            count--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

