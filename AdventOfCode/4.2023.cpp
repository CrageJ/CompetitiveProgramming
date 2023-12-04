#include <bits/stdc++.h>
#include "src/solutionTemplate.hpp"
#include "src/solutionTemplate.cpp"

using namespace std;

void Solution::part1() {
    int count = 0;

    for (auto row : p1) {
        set<string> nums;
        int cc = 1;
        int i = 2;
        for (i; row[i] != "|";i++) {
            nums.insert(row[i]);
        }
        i++;
        for (i;i<row.size();i++){
            if (nums.count(row[i]) != 0){
                cc*=2;
            }
        }
        cc = cc/2;
        count+= cc;
    }
    cout<<"Part 1: "<<count<<endl;
}

void Solution::part2() {
    int count = 0;
    map<int,int> mmp; //cards,count. stores # copies of eah card

    for (int i =0;i< p2.size();i++){
        mmp[i] = 1;
    }
    
    for (int r = 0;r< p2.size();r++) { // 2d matrix of values
        auto row = p2[r];
        set<string> nums;
        int cc = 0;
        int i = 2;
        for (i; row[i] != "|";i++) { // space separated values
            nums.insert(row[i]); // count guess values
        }
        i++;
        for (i;i<row.size();i++){
            if (nums.count(row[i]) != 0){ // count guess/scratched values
                cc++;
            }
        }
        //!!!!!! speedup potential?
        for (int idx = r+1;idx <=min(r+cc,(int)p2.size()-1);idx++){
            mmp[idx] += (mmp[r]); 
        }
        //!!!!!!
        count += mmp[r];
    }
    cout<<"Part 2: "<<count<<endl;
}



int main(void) {
    Solution s("4.2023.1", Solution::readType::spaced);
    //s.printInput();
    s.part1();
    s.part2();

    return 0;
};