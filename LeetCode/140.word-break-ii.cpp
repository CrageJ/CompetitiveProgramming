/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start


#include <bits/stdc++.h>
using namespace std;



class Node {
    public:
    char c = '\0';
    bool isWord = false;
    Node(char c){
        this->c = c;
    }
    Node(){
        c = '\0';
    }

    Node * array[26] = {NULL};

    Node * insertChar(char c){
        if (array[c- 'a'] != NULL){
            return array[c-'a'];
        }
        array[c-'a'] = new Node(c);
        return array[c-'a'];
    }

    //NUll if no
    Node * containsChar(char c){
        return array[c-'a'];
    }

    void setWord(bool b){
        this->isWord = b;
    }

};

class Tree{
    public:
    Node * root;
    Tree(){
        root = new Node();
        root->isWord = true;
    }
    
    void insert(string s){
        Node * curr = root;
        for (auto c: s){
            curr = curr->insertChar(c);
        }
        curr->setWord(true);
    }

    bool contains(string s){
        Node * curr = root;
        for (auto c:s){
            Node * ptr = curr->containsChar(c);
            if (ptr == NULL){
                return false; 
            }
            else{
                curr = ptr;
            }
            
        }
        bool a = curr->isWord;
        return a;
    }
};

class Solution {
public:


    Tree * dictionary;

    vector<string> dp(string s){
        //cout<<"processing"<<s<<endl;

        if (s.size() == 0){
            return {""};
        }

        vector<string> v;

        int strsize = s.size();
        
        for (int sublen = 1;sublen<=10 && sublen<= s.size();sublen++){
            string sub = s.substr(0,sublen);
            if (dictionary->contains(sub)){
                cout<<"found word"<<sub<<endl;
                for (auto subword: dp(s.substr(sublen, strsize-sublen))){
                    string subCombined = sub +" "+subword;
                    if (subCombined.back() == ' '){
                        subCombined = subCombined.substr(0,subCombined.size()-1);
                    }
                    v.push_back(subCombined);
                }
            }
            
        }

        return v;

        

    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dictionary = new Tree();


        for (auto word:wordDict){
            dictionary->insert(word);    
        }

        

        return dp(s);

        
    }
};
// @lc code=end

