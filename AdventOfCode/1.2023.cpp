
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
    //one"," two"," three"," four"," five"," six"," seven"," eight"," and nine

   // cout<<s<<endl;

    int size= s.length();


    for (int l = 0;l<size-2;l++){
        for(int r = 3; r<= 5;r++){
            
            //cout<<'l';
            string sub = s.substr(l,r);
            if (sset.count(sub) != 0){
                return sset[sub];
            }

        }
    }
    // s contains word

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
        //cout<<"LINE: "<<line<<endl;
        for (int i = 0;i< size;i++){
            if ('0'<= line[i] && line[i] <='9'){
                l = line[i]-'0';
                break;
            }
            sub = line.substr(0,i+1);
            //cout<<"i: "<<"0 "<<i<<' '<<sub<<endl;
            int wrd = findWord(sub);
            if (wrd!=-1){
                l= wrd;
                break;
            }
        }
        //cout<<'<';
        for (int i = size-1;i>=0;i--){
            if ('0'<= line[i] && line[i] <='9'){
                r = line[i]-'0';
                break;
            }

            //cout<<sub<<endl;
            sub = line.substr(i,size-i);
            //cout<<"i: "<<i<<' '<<size-i<<' '<<sub<<endl;
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
    Solution s("1.2023.1",Solution::readType::lines);
    s.part1();
    s.part2();

    return 0;
};