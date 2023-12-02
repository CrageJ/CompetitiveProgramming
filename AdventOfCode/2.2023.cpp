#include <bits/stdc++.h>
#include "src/solutionTemplate.hpp"
#include "src/solutionTemplate.cpp"

using namespace std;

void Solution::part1() {

    int count = 0;
    int idx = 0;
    for (auto row : p1) {
        idx++;
        //skip first two words
        unordered_map<string,int> mmp {{"red",0},{"blue",0},{"green",0}};
        //12 13 14
        for (int i = 3;i< row.size();i = i+2) {
            string s = row[i];
            if (i != row.size()-1){
                s = s.substr(0,s.length()-1);
            }
            //s = s.substr(0,s.length()-1);
            mmp[s] = max(stoi(row[i-1]),mmp[s]);
        }

        if (mmp["red"] <= 12 && mmp["green"] <= 13 && mmp["blue"] <= 14){
            count += idx;
        }
    }

    cout<<"Part 1: "<<count<<endl;
}

void Solution::part2() {

    int count = 0;
    int idx = 0;
    for (auto row : p2) {
        idx++;
        //skip first two words
        unordered_map<string,int> mmp {{"red",0},{"blue",0},{"green",0}};
        //12 13 14
        //cout<<"row size for "<<idx<<" "<<row.size()<<endl;
        for (int i = 3;i< row.size();i = i+2) {

            string s = row[i];
            if (i != row.size()-1){
                s = s.substr(0,s.length()-1);
            }
            int val = stoi(row[i-1]);
            //cout<<s<<" val "<<val<<endl;
            mmp[s] = max(stoi(row[i-1]),mmp[s]);
        }
     //   cout<<mmp["red"]<<' '<<mmp["green"] <<' '<<mmp["blue"]<<' '<<mmp["red"] * mmp["green"] * mmp["blue"]<<endl;

        count += mmp["red"] * mmp["green"] * mmp["blue"];
    
    }

    cout<<"Part 2: "<<count<<endl;
}

int main(void) {
    Solution s("2.2023.1", Solution::readType::spaced);
    //s.printInput();
    s.part1();
    s.part2();

    return 0;
};