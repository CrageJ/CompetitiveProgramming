
#include <bits/stdc++.h>
#include "src/solutionTemplate.hpp"
#include "src/solutionTemplate.cpp"

using namespace std;
typedef long long ll;
struct Hand{
    string cards;
    
    enum Type{
        fivekind = 7,
        fourkind = 6,
        fullhouse = 5,
        threekind = 4,
        twopair = 3,
        onepair = 2,
        alldiff = 1
    };

    Type type;
    
    ll value;

    Hand(string s, ll v,bool isPart1 ){
        value = v;
        for (int i = 0;i< s.length();i++){
            char c = s[i];            
            char n=c;
            switch(c){
                case 'A':
                n='Z';
                break;
                case 'K':
                n='Y';
                break;
                case 'Q':
                n='X';
                break;
                case 'J':
                n='W';
                break;
                case 'T':
                n='V';
                break;
            }
            if (!isPart1){
                if (n=='W'){
                    n='#';
                }
            }
            s[i] = n;

        }
        
        this->cards = s;
        if (isPart1){
            this->part1Type();
        }
        else{
            this->part2Type();
        }
    }
    void part2Type(){
        part1Type();
        string originalCards = this->cards;
        Type originalType = this->type;

        string currCards = this->cards;
        Type currType = this->type;


        std::vector<char> jokerReplace = {'Z', 'Y', 'X', 'V', '9', '8', '7', '6', '5', '4', '3', '2'};
        for (auto j : jokerReplace){
            auto s = originalCards;
            for (int i = 0;i<originalCards.length();i++){
                if (s[i] == '#'){
                    this->cards[i] = j;
                }
            }
            this->part1Type();

            if (this->type > currType){
                currType = this->type;
            }
        }
        this->type = currType;
        this->cards = originalCards;
        return;
    };
    
    void part1Type(){
        map<char,int> cardcount;
        for (auto ch : cards){
            cardcount[ch] = 0;
        }
        for (auto ch : cards){
            cardcount[ch]++;
        }
        int size = cardcount.size();
        if (size == 1){ // all the same card
            type = Type::fivekind;
            return;
        }
        if (size == 5){ // all different cards
            type = Type::alldiff;
            return;
        }
        if (size == 2){ // fourkind, fullhouse
            for (auto ch : cards){
                if (cardcount[ch] == 4){
                    type = Type::fourkind;
                    return;
                }
                if (cardcount[ch] == 3){
                    type = Type::fullhouse;
                    return;
                }
            }
            return;
        }
        if (size == 4){ // onepair
            type = Type::onepair;
            return;
        }
        if (size == 3){ // twopair,threekind
            for (auto ch : cards){
                if (cardcount[ch] == 3){
                    type = Type::threekind;
                    return;
                }
            }
            type = Type::twopair;
            return;
        }

    }

};

bool operator== (const Hand& a,const Hand& b ){
    return (a.cards == b.cards);
}

bool operator< (const Hand& a,const Hand& b ){
    if (a == b){
        return false;
    }
    if (a.type < b.type){
        return true;
    }
    if (a.type > b.type){
        return false;
    }
    
    return a.cards < b.cards;
    
    
    return false;
}


void Solution::part1(){
    vector<Hand> hands;
    for (int i = 0;i<p1.size();i++){
        hands.push_back(Hand(p1[i][0],stoll(p1[i][1]),true));
    }
    sort(hands.rbegin(),hands.rend());
    ll size = (ll)p1.size();
    ll res = 0;
    for (auto h : hands){
        res += h.value*size;
        size--;
    }
    cout<<"Part 1: "<< res<<endl;
}


void Solution::part2(){
    vector<Hand> hands;
    for (int i = 0;i<p2.size();i++){
        hands.push_back(Hand(p2[i][0],stoll(p2[i][1]),false));
    }
    sort(hands.rbegin(),hands.rend());
    ll size = (ll)p2.size();
    ll res = 0;
    for (auto h : hands){
        //cout<<h.cards<<' ';
        res += h.value*size;
        size--;
    }
    cout<<"Part 2: "<< res<<endl;
}



int main(void){
    auto precomp = std::chrono::high_resolution_clock::now();

    Solution s("7.2023.1",Solution::readType::spaced);

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