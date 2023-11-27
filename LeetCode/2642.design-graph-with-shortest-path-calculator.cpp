/*
 * @lc app=leetcode id=2642 lang=cpp
 *
 * [2642] Design Graph With Shortest Path Calculator
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

class Graph {
public:

    vector<vector<pair<int,int>>> g;// ll edges
    int n = 0;
    //from , <to,cost>
    Graph(int n, vector<vector<int>>& edges) {
        g.resize(n,vector<pair<int,int>>(0,{0,0}));
        this->n = n;
        for (auto  e : edges){
            addEdge(e);
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1],edge[2]});
        //g[edge[1]].push_back({edge[0],edge[2]});
    }
    

    int shortestPath(int node1, int node2) {
        // Min heap: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialize distances
        vector<int> distances(n, INT_MAX);

        pq.push({0, node1});
        distances[node1] = 0;

        while (!pq.empty()) {
            auto node_ = pq.top();
            int node = node_.second;
            int dist = node_.first;
            pq.pop();

            // skip if better path processed.
            if (dist > distances[node]) {
                continue;
            }

            for (const auto& neighbor_ : g[node]) {
                int neighbour = neighbor_.first;
                int neighbourdist = neighbor_.second;

                if (dist + neighbourdist < distances[neighbour]) {
                    distances[neighbour] = dist + neighbourdist;
                    pq.push({distances[neighbour], neighbour});
                }
            }
        }

        return distances[node2] != INT_MAX ? distances[node2] : -1;
    }
};
/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end

