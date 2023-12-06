
#include <bits/stdc++.h>
#include "src/solutionTemplate.hpp"
#include "src/solutionTemplate.cpp"

using namespace std;


void Solution::part1(){
    int sum = 0;
    for (auto lines : p1){
        string line = lines[0];
        int size = line.length();
        int l = 0;
        int r = 0;
        for (int i = 0;i< size;i++){
            if ('0'<= line[i] && line[i] <='9'){
                l = line[i]-'0';
                break;
            }
        }
        for (int i = size-1;i>=0;i--){
            if ('0'<= line[i] && line[i] <='9'){
                r = line[i]-'0';
                break;
            }
        }
        sum += l*10 + r;
    }
    cout<<"Part 1: "<<sum<<endl;
}

unordered_map<string,int> sset = {{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9}};

int findWord(string s){
    int size= s.length();
    for (int l = 0;l<size-2;l++){
        for(int r = 3; r<= 5;r++){
            string sub = s.substr(l,r);
            if (sset.count(sub) != 0){
                return sset[sub];
            }

        }
    }
    return -1;
}

void Solution::part2(){
    int sum = 0;
    string sub;
    for (auto lines : p1){
        string line = lines[0];
        int size = line.length();
        int l = 0;
        int r = 0;
        for (int i = 0;i< size;i++){
            if ('0'<= line[i] && line[i] <='9'){
                l = line[i]-'0';
                break;
            }
            sub = line.substr(0,i+1);
            int wrd = findWord(sub);
            if (wrd!=-1){
                l= wrd;
                break;
            }
        }
        for (int i = size-1;i>=0;i--){
            if ('0'<= line[i] && line[i] <='9'){
                r = line[i]-'0';
                break;
            }
            sub = line.substr(i,size-i);
            int wrd = findWord(sub);
            if (wrd!=-1){
                r= wrd;
                break;
            }
        }
        sum += l*10 + r;
    }
        cout<<"Part 2: "<<sum<<endl;
    
}


int main(void){
    auto precomp = std::chrono::high_resolution_clock::now();

    Solution s("1.2023.1",Solution::readType::lines);

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