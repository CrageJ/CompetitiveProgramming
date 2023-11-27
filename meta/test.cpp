#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    string StudentGuess(vector<string> back,vector<string> front){
        auto colourMap = [](string colour) ->int {
            if (colour == "red") return 1;
            if (colour == "green") return 2;
            if (colour == "blue") return 3;
            return 0;
        };
        auto revColourMap = [](int colour) ->string {
            if (colour == 1) return "red";
            if (colour == 2) return "green";
            if (colour == 3) return "blue";
            return "";
        };

        auto accumulateColours = [&](int currentSum, const std::string& color)->int{
        return currentSum + colourMap(color);
        };
        

        int front_add = accumulate(front.begin(),front.end(),0,accumulateColours); 
        int back_add = accumulate(back.begin(),back.end(),0,accumulateColours);
        //if this is the back student
        if (back.size() == 0){
            //parity
            int parity = front_add %4;
            //what value would give a "balanced" parity?
            parity = 3-parity;

            string answer = revColourMap(parity);
            return answer;
        }
        //if this isn't the back student
        //measure the discrepancy
        int hatValues = (front_add + back_add)%4;
        //what's the missing value in this to balance the parity?
        int parity = 3-hatValues;

        string answer = revColourMap(parity);
        return answer;
    }
};


int main(void) {

    vector<string> hats = {"red","green","blue","green","green"};
    vector<string> guesses;
    Solution s;

        cout << "Original hats: ";
    for (const auto& hat : hats) {
        cout << hat << " ";
    }
    cout << endl;
    for (int i = 0;i< hats.size();i++){
        auto guess = s.StudentGuess(guesses,vector<string>(hats.begin()+i+1,hats.end()));
        guesses.push_back(guess);
    }
    int correctGuesses = 0;
    for (int i =0;i< hats.size();i++){
        if (hats[i]== guesses[i]){
            correctGuesses++;
        }
    }
        cout << "Guesses: ";
    for (const auto& guess : guesses) {
        cout << guess << " ";
    }
    cout << endl;

    cout<<"Guessed "<<correctGuesses<<" out of "<<hats.size()<<" correctly"<<endl;
    cout<<"Testcase passed: "<<(correctGuesses>=hats.size()-1)<<endl;



    std::cout << "Hello World!\n";
    return 0;
}