#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
public:


vector<vector<int>> arr;
int size = 2048;


    MyHashSet() {
        arr.clear();
        arr.resize(size,{});
    }

    int hash(int key){
        return key % size;
    }
    
    
    void add(int key) {
        int h = hash(key);
        
        auto& v = arr[h];

        for (auto value : v){
            if (value == key){
                return;
            }
        }
        v.push_back(key);
    }
    
    bool contains(int key) {
        int h = hash(key);
        
        auto& v = arr[h];
        for (auto value : v){
            
            if (value == key){
                return true;
            }
        }

        return false;
    }

    void remove(int key){
        int h = hash(key);
        vector<int>& v = arr[h];
        int idx = 0;
        for (auto value : v){
            if (value == key){
                v.erase(v.begin()+idx);
                return;
            }
            idx++;
        }
        return;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

