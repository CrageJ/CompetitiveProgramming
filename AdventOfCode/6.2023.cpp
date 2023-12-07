
#include <bits/stdc++.h>
#include "src/solutionTemplate.hpp"
#include "src/solutionTemplate.cpp"

using namespace std;
typedef long long ll;

void Solution::part1(){
    int win = 0;
    int prod = 1;
    for (int i = 1;i<p1[0].size();i++){
        ll time = stoll(p1[0][i]);
        ll distance = stoll(p1[1][i]);
        int ways = 0;
        for (ll buttonPress = 1;buttonPress < time;buttonPress++){
            if ((time - buttonPress)*buttonPress > distance ){
                ways ++;
            }
        }
        prod*=ways;
    }
    cout<<"Part 1: "<< prod;
    cout<<endl;
}


void Solution::part2(){
    int prod = 0;
    string time;
    string distance;
    for (int i = 1;i<p1[0].size();i++){
        time += p1[0][i];
        distance += p1[1][i];
    }
    ll t = stoll(time);
    ll d = stoll(distance);
    //rscan
    ll r;
    for (r = t-1;r >= 0;r--){
        if ((t - r)*r > d ){
                break;
            }
    }
    //lscan
    ll l;
    for (l = 1; l< r;l++){
        if ((t - l)*l > d ){
                break;
            }
    }
    cout<<"Part 2: "<< r-l+1;
    cout<<endl;
}



int main(void){
    auto precomp = std::chrono::high_resolution_clock::now();

    Solution s("6.2023.1",Solution::readType::spaced);

    auto start = std::chrono::high_resolution_clock::now();
    auto readin = std::chrono::duration_cast<std::chrono::microseconds>(start - precomp);
    cout<<"--------------Read time: "<<readin.count()/1e3<<" milliseconds------------------"<<endl;
    start = std::chrono::high_resolution_clock::now();

    s.part1();
    auto p1finish =  std::chrono::high_resolution_clock::now();

    s.part2();
    auto stop = std::chrono::high_resolution_clock::now();

    auto p1duration = std::chrono::duration_cast<std::chrono::microseconds>(p1finish - start);
    auto p2duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - p1finish);
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    auto totalduration = std::chrono::duration_cast<std::chrono::microseconds>(stop - precomp);
    cout<< "Part 1 Execution Time: "<<p1duration.count()/1e3<<" milliseconds"<<endl;
    cout<< "Part 2 Execution Time: "<<p2duration.count()/1e3<<" milliseconds"<<endl;
    cout << "Execution Time: " << duration.count() / 1e3 << " milliseconds" << endl;
    cout << "Total Time: " << totalduration.count() / 1e3 << " milliseconds" << endl;



    return 0;
};