
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);

        // Combine the hashes using XOR (^)
        return hash1 ^ hash2;
    }
};*/

/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start

class Schedule
{
public:
    int start;
    int end;
    int profit;
    Schedule(int s, int e, int p)
    {
        this->start = s;
        this->end = e;
        this->profit = p;
    };
    bool operator < (const Schedule& job) {
        if (start != job.start){
            return start < job.start;
        }
        
        if (end != job.end){
            return end < job.end;
        }
        return profit > job.profit;
    }
};

class Solution
{
public:
    unordered_map<int, int> memo;
    vector<Schedule> v = {};


    int getNextIndex(int ptr, int time)
    {

        ptr++;

        while (ptr < v.size())
        {

            if (v[ptr].start >= time)
            {
                return ptr;
            }

            ptr++;
        }
        return ptr;
    }

    int dp(int ptr)
    {
        if (memo.count(ptr) != 0)
        {
            return memo[ptr];
        }
        if (ptr >= v.size())
        {
            return 0;
        }

        Schedule curr = v[ptr];
        int nIndex = getNextIndex(ptr, curr.start);
        int tIndex = getNextIndex(ptr,curr.end);

        // take
        int take = dp(tIndex) + curr.profit;
        // go to next
        int next = dp(nIndex);
        int best = max(next, take);

        memo[ptr] = best;
        return best;
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {

        for (int i = 0; i < startTime.size(); i++)
        {
            Schedule s(startTime[i], endTime[i], profit[i]);
            v.push_back(s);
        }

        sort(v.begin(), v.end());

        return dp(0);
    };
    
};
// @lc code=end
