#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "solutionTemplate.hpp"
using namespace std;


Solution::Solution(string fileName1,readType readName1,string fileName2,readType readName2){
    file = fileName1;
    
    inputProcessor in1(fileName1);

    switch(readName1){
        case lines:
        p1 = in1.getLines();
        break;
        case csv:
        p1 = in1.getCSV();
        break;
        case spaced:
        p1 = in1.getSpaced();
        break;
    }

    if (fileName1 != fileName2){
        inputProcessor in2(fileName2);
        switch(readName2){
            case lines:
            p2 = in2.getLines();
            break;
            case csv:
            p2 = in2.getCSV();
            break;
            case spaced:
            p2 = in2.getSpaced();
            break;
        }
        isDifferent = true;

    }
    else{
        p2 = p1;
    }
};
Solution::Solution(string fileName1,readType readName1) : Solution(fileName1,readName1,fileName1,readName1){};

void Solution::printInput(){
    cout<<"Printing input for "<<file<<" p1"<<endl;
    for (vector<string> line : p1){
        for (string l : line){
            cout<<l<<' ';
        }        
        cout<<endl;
    }
    if (!isDifferent){
        return;
    }
    cout<<"Printing input for "<<file<<" p2"<<endl;
    for (vector<string> line : p1){
        for (string l : line){
            cout<<l<<' ';
        }        
        cout<<endl;
    }
}
