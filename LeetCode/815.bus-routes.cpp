/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target){
            return 0;
        }
        map<int,vector<int>> stops; // what STOP are connected by what BUSES

        for(int i = 0;i< routes.size();i++){
            for (int j =0;j<routes[i].size();j++){
                stops[routes[i][j]].push_back(i);
            }
        } 

        int minDistance = INT_MAX;
        for (int startingLocationIndex = 0; startingLocationIndex < stops[source].size();startingLocationIndex++){
            int startingBus = stops[source][startingLocationIndex];
            set<int> visitedBuses;
            queue<pair<int,int>> busQueue;

            busQueue.push({startingBus,0});
            visitedBuses.insert(startingBus);

            bool stopSignal = false;
            while (!busQueue.empty() && !stopSignal){
                pair<int,int> currentBus = busQueue.front();

                busQueue.pop();

                int bus = currentBus.first;
                int distance = currentBus.second;

                for (auto stop: routes[bus]){
                    if (stop == target){
                        minDistance = min(distance + 1,minDistance);
                        stopSignal = true;
                        break;
                    }
                    else{
                        for (auto neighbourBus: stops[stop]){
                            if (visitedBuses.count(neighbourBus) == 0){
                                visitedBuses.insert(neighbourBus);
                                busQueue.push({neighbourBus,distance+1});
                                
                            }
                        }
                    }
                }

            }

        }
        if (minDistance == INT_MAX){
            return -1;
        }
        else{
            return minDistance;
        }
             
        
    }
};
// @lc code=end

