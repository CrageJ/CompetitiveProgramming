#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "inputProcessor.cpp"
using namespace std;



class Solution{
    public:
    enum readType{
        lines,
        csv,
        spaced
    };
    //readType read;
    string file;

    vector<vector<string>> p1;
    vector<vector<string>> p2;
    bool isDifferent = false;

    Solution(string fileName1,readType readName1,string fileName2,readType readName2);
    Solution(string fileName1,readType readName1);

    void printInput();

    void part1();

    void part2();

};