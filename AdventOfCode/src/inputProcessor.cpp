
#include <bits/stdc++.h>
using namespace std;

#include <unistd.h>
#include <fstream>
#include <string>


struct inputProcessor{
    
    vector<string> lines;

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

    vector<vector<string>> getByDelim(char delim) {
        vector<vector<string>> arr;

        for (string& line : lines) {
            vector<string> curr;
            stringstream ss(line);
            string token;

            // Use find_first_of to get the positions of delimiters
            size_t pos = line.find_first_of(delim, 0);

            while (pos != string::npos) {
                // Extract the substring between two delimiters
                string ssub = line.substr(0, pos);
                if (ssub.size() > 0){
                    curr.push_back(ssub);
                // Move to the next character after the delimiter
                }

                line = line.substr(pos + 1);
                pos = line.find_first_of(delim, 0);
            }

            // Add the remaining part of the line
            curr.push_back(line);

            arr.push_back(curr);
        }

        return arr;
    }

    vector<vector<string>> getLines(){ // no seperators
        return getByDelim('\0');
    } 
    vector<vector<string>> getCSV(){
        return getByDelim(',');
    }
    vector<vector<string>> getSpaced(){
        return getByDelim(' ');
    }



};