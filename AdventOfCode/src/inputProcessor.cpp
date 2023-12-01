
#include <bits/stdc++.h>
using namespace std;

#include <unistd.h>
#include <fstream>
#include <string>


struct inputProcessor{
    
    vector<string> lines;
    //vector<vector<string>> csv;
    //vector<vector<string>> spaced;

    
    inputProcessor(string fileName){
        string line;
        if (fileName == "stdin"){
            while (getline(cin,line)){
                lines.push_back(line);
            }
            return;
        }

        ifstream in("input/"+fileName);
        
        while (getline(in,line)){
            lines.push_back(line);
        }
        in.close();
        return;
    }
    inputProcessor() : inputProcessor("stdin"){};
    
    vector<vector<string>> getByDelim(char delim){
        vector<vector<string>> arr;
        vector<string> curr;
        for (auto line : lines){
            curr.clear();
            int lastElement = 0; // always points to first valid spot
            for (int i = 0;i< line.size();i++){
                if (line[i] == delim){
                    curr.push_back(line.substr(lastElement,i-lastElement));
                    lastElement = i+1;
                }
            }
            curr.push_back(line.substr(lastElement,line.size()-lastElement));
            arr.push_back(curr);
        }

        return arr;
    }

    vector<vector<string>> getLines(){
        return getByDelim('\0');
    } 
    vector<vector<string>> getCSV(){
        return getByDelim(',');
    }
    vector<vector<string>> getSpaced(){
        return getByDelim(' ');
    }



};