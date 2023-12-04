#include <bits/stdc++.h>
#include "src/solutionTemplate.hpp"
#include "src/solutionTemplate.cpp"

using namespace std;

int maxX = 0;
int maxY = 0;
bool oob(int x, int y){
    if (x < 0 || x >= maxX || y < 0 || y >= maxY){
        return true;
    }
    return false;
}

void Solution::part1() {

    int count = 0;
    vector<string> v;
    for (auto l_ : p1){
        v.push_back(l_[0]);
    }
    maxX = v[0].length();
    maxY = v.size();

    std::vector<std::vector<int>> neighbours = {
    {0, 1},   // right
    {1, 0},   // down
    {-1, 0},  // up
    {0, -1},  // left
    {1, 1},   // bottom right
    {-1, 1},  // top right
    {1, -1},  // bottom left
    {-1, -1}  // top left
};

    for (int y = 0;y< maxY;y++){

        
        //cout <<l<<endl;
        //dots are blank
        //numbers are numbers
        //everything else is a symbol
        int currBase = 1;
        int currNum = 0;
        bool isStarred = false; // * represents ANY symbol not '.'
        for (int x = maxX-1;x>=0;x--){
            char c = v[y][x];

            if (c == '.'){
                if (isStarred){
                 //   cout<<"added number "<<currNum<<endl;
                    count+=currNum;
                }
                isStarred = false;
                currBase = 1;
                currNum = 0;
            }

            else if ('0'<=c && c <= '9'){
                int num = c-'0';
               // cout<<"added num: "<<num;
                currNum += num*currBase;

                //is a surrounding char a special char 
                if (!isStarred){
                    for (auto n:neighbours){
                        int nX = x + n[0];
                        int nY = y + n[1];
                        if (!oob(nX,nY)){
                            char nc = v[nY][nX];
                            if ((nc < '0' || nc > '9') && nc != '.' ){
                                isStarred = true;
                                break;
                            }
                        }
                    }
                }
                //cout<<" starred: "<<isStarred<<endl;
                

                currBase *= 10;
            }

            else{
                //ANY symbol
                //cout<<"added number "<<count<<endl;
                count += currNum;
                currNum = 0;
                currBase = 1;
                isStarred = true;
            }
        }

        if (isStarred){
            count += currNum;
        }
    }


    cout<<"Part 1: "<<count<<endl;
}

string coordHash(int x, int y){
    string res = {(char)(x-'0')}; 
    res += {' '};
    res += {(char)(y-'0')};
    return res;
}

void Solution::part2() {

    int count = 0;
    vector<string> v;
    for (auto l_ : p1){
        v.push_back(l_[0]);
    }
    maxX = v[0].length();
    maxY = v.size();

    //hash of coord , [mult value,count]
    unordered_map<string,pair<int,int>> gears;

    std::vector<std::vector<int>> neighbours = {
    {0, 1},   // right
    {1, 0},   // down
    {-1, 0},  // up
    {0, -1},  // left
    {1, 1},   // bottom right
    {-1, 1},  // top right
    {1, -1},  // bottom left
    {-1, -1}  // top left
};

    for (int y = 0;y< maxY;y++){

        
        //cout <<l<<endl;
        //dots are blank
        //numbers are numbers
        //everything else is a symbol
        int currBase = 1;
        int currNum = 0;
        bool isGeared = false; // * represents ANY symbol not '.'
        set<string> gearList;

        auto gearProcess = [&](){
            for (auto neighbourGear :  gearList){
                    if (gears.count(neighbourGear) ==0){
                        gears[neighbourGear] = {currNum,1};
                    }
                    else{
                        pair<int,int> gearpair = gears[neighbourGear];
                        gears[neighbourGear] = {currNum*gearpair.first,gearpair.second+1};
                        if (gears[neighbourGear].second > 2){
                            gears[neighbourGear].first = 0;
                        }
                    }
                }
                gearList.clear();
        };



        for (int x = maxX-1;x>=0;x--){
            char c = v[y][x];

            if (c == '.' || c == '*'){
                gearProcess();
                currBase = 1;
                currNum = 0;
            }

            else if ('0'<=c && c <= '9'){
                int num = c-'0';
                //cout<<"added num: "<<num;
                currNum += num*currBase;

                //is a surrounding char a special char 
                for (auto n:neighbours){
                    int nX = x + n[0];
                    int nY = y + n[1];
                    if (!oob(nX,nY)){
                        char nc = v[nY][nX];
                        if ((nc < '0' || nc > '9') && nc != '.' ){
                            auto ghash = coordHash(nX,nY);
                            gearList.insert(ghash);
                        }
                    }
                }
                
                //cout<<" starred: "<<isStarred<<endl;
                

                currBase *= 10;
            }
        }

        gearProcess();
    }


    for (pair<string,pair<int,int>> g : gears){
        if (g.second.second == 2){
            count += g.second.first;
        }
    }

    std::cout<<"Part 2: "<<count<<endl;

}

int main(void) {
    Solution s("3.2023.1", Solution::readType::lines);
    //s.printInput();
    s.part1();
    s.part2();

    return 0;
};