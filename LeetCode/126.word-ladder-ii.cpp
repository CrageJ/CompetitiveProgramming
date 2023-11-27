/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
struct PairHash {
    std::size_t operator()(const std::pair<T, T>& p) const {
        auto hash1 = std::hash<T>{}(p.first);
        auto hash2 = std::hash<T>{}(p.second);
        return hash1 ^ hash2;
    }
};










// @lc code=end

/*
//TLE
class Solution {
public:
    bool hasOneTransform(string a, string b){
        int numberOfTransforms = 0;
        for (int i =0;i<a.size();i++){
            numberOfTransforms += a[i]!=b[i];
        }

        return numberOfTransforms == 1;
    }
    unordered_map<string,unordered_set<string>> previous; // maintains list of previous string
    unordered_map<string,int> distances;



    vector<vector<string>> dp(string current, string target) { // target = startword
        vector<vector<string>> result;
        if (current == target) {
            result.push_back({target});
            return result;
        }

        for (const auto& neighbor : previous[current]) {
            if (distances[neighbor] == distances[current] - 1) {
                auto subPaths = dp(neighbor, target);
                for (auto& path : subPaths) {
                   // cout<<"HIII";
                    path.insert(path.begin(), current);
                    result.push_back(path);
                }
            }
        }

        return result;
    }



    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //adj list
        unordered_map<string,vector<string>> map;

        wordList.push_back(beginWord);
        //wordList.push_back(endWord);

        
        for(int r = 0;r< wordList.size();r++){
            string right = wordList[r];
            distances[right] = INT_MAX;
            previous[right] = {};
            for (int l = r-1;l>=0;l--){
                string left = wordList[l];
                if (hasOneTransform(left,right)){
                    map[left].push_back(right);
                    map[right].push_back(left);
                }

            }

        }

        //cout<<"here1";


        if (map[beginWord].size() == 0 || map.count(endWord) == 0 ||map[endWord].size() == 0){
            return {};
        }

        distances[beginWord] = 0;
        priority_queue<pair<int,string>,vector<pair<int, string>>,greater<pair<int,string>>> q;

        q.push({0,beginWord});

        while (!q.empty()){
            auto element = q.top();
            
            q.pop();
            int dist = element.first;
            string word = element.second;
           // cout<<word<<endl;
            //if processed, skip
            if (dist > distances[word]){
                continue;
            }
            cout<<"processing "<<word<<endl;

//distances[word] = dist; 
            
            for (auto neighbour : map[word]){
               // cout<<"neighbour "<<neighbour<<endl;
                int nDist = dist+1;
                if (nDist <= distances[neighbour]){
                    if (distances[neighbour] == nDist){
                        previous[neighbour].insert(word);
                    }
                    if (distances[neighbour] > nDist){
                        distances[neighbour] = nDist;
                        previous[neighbour].clear(); 
                        previous[neighbour].insert(word);
                    }
                    q.push({nDist,neighbour});
                }
            }
        }

        //cout<<"here2";


        
        auto res =  dp(endWord,beginWord);

        
        //cout<<"here3";

        for (auto& r : res){
            reverse(r.begin(),r.end());
        }
        
        //cout<<"here4";
        return res;
    }
};*/


int main(void){
    Solution s;
    vector<string> wl = {"aaaaa","caaaa","cbaaa","daaaa","dbaaa","eaaaa","ebaaa","faaaa","fbaaa","gaaaa","gbaaa","haaaa","hbaaa","iaaaa","ibaaa","jaaaa","jbaaa","kaaaa","kbaaa","laaaa","lbaaa","maaaa","mbaaa","naaaa","nbaaa","oaaaa","obaaa","paaaa","pbaaa","bbaaa","bbcaa","bbcba","bbdaa","bbdba","bbeaa","bbeba","bbfaa","bbfba","bbgaa","bbgba","bbhaa","bbhba","bbiaa","bbiba","bbjaa","bbjba","bbkaa","bbkba","bblaa","bblba","bbmaa","bbmba","bbnaa","bbnba","bboaa","bboba","bbpaa","bbpba","bbbba","abbba","acbba","dbbba","dcbba","ebbba","ecbba","fbbba","fcbba","gbbba","gcbba","hbbba","hcbba","ibbba","icbba","jbbba","jcbba","kbbba","kcbba","lbbba","lcbba","mbbba","mcbba","nbbba","ncbba","obbba","ocbba","pbbba","pcbba","ccbba","ccaba","ccaca","ccdba","ccdca","cceba","cceca","ccfba","ccfca","ccgba","ccgca","cchba","cchca","cciba","ccica","ccjba","ccjca","cckba","cckca","cclba","cclca","ccmba","ccmca","ccnba","ccnca","ccoba","ccoca","ccpba","ccpca","cccca","accca","adcca","bccca","bdcca","eccca","edcca","fccca","fdcca","gccca","gdcca","hccca","hdcca","iccca","idcca","jccca","jdcca","kccca","kdcca","lccca","ldcca","mccca","mdcca","nccca","ndcca","occca","odcca","pccca","pdcca","ddcca","ddaca","ddada","ddbca","ddbda","ddeca","ddeda","ddfca","ddfda","ddgca","ddgda","ddhca","ddhda","ddica","ddida","ddjca","ddjda","ddkca","ddkda","ddlca","ddlda","ddmca","ddmda","ddnca","ddnda","ddoca","ddoda","ddpca","ddpda","dddda","addda","aedda","bddda","bedda","cddda","cedda","fddda","fedda","gddda","gedda","hddda","hedda","iddda","iedda","jddda","jedda","kddda","kedda","lddda","ledda","mddda","medda","nddda","nedda","oddda","oedda","pddda","pedda","eedda","eeada","eeaea","eebda","eebea","eecda","eecea","eefda","eefea","eegda","eegea","eehda","eehea","eeida","eeiea","eejda","eejea","eekda","eekea","eelda","eelea","eemda","eemea","eenda","eenea","eeoda","eeoea","eepda","eepea","eeeea","ggggg","agggg","ahggg","bgggg","bhggg","cgggg","chggg","dgggg","dhggg","egggg","ehggg","fgggg","fhggg","igggg","ihggg","jgggg","jhggg","kgggg","khggg","lgggg","lhggg","mgggg","mhggg","ngggg","nhggg","ogggg","ohggg","pgggg","phggg","hhggg","hhagg","hhahg","hhbgg","hhbhg","hhcgg","hhchg","hhdgg","hhdhg","hhegg","hhehg","hhfgg","hhfhg","hhigg","hhihg","hhjgg","hhjhg","hhkgg","hhkhg","hhlgg","hhlhg","hhmgg","hhmhg","hhngg","hhnhg","hhogg","hhohg","hhpgg","hhphg","hhhhg","ahhhg","aihhg","bhhhg","bihhg","chhhg","cihhg","dhhhg","dihhg","ehhhg","eihhg","fhhhg","fihhg","ghhhg","gihhg","jhhhg","jihhg","khhhg","kihhg","lhhhg","lihhg","mhhhg","mihhg","nhhhg","nihhg","ohhhg","oihhg","phhhg","pihhg","iihhg","iiahg","iiaig","iibhg","iibig","iichg","iicig","iidhg","iidig","iiehg","iieig","iifhg","iifig","iighg","iigig","iijhg","iijig","iikhg","iikig","iilhg","iilig","iimhg","iimig","iinhg","iinig","iiohg","iioig","iiphg","iipig","iiiig","aiiig","ajiig","biiig","bjiig","ciiig","cjiig","diiig","djiig","eiiig","ejiig","fiiig","fjiig","giiig","gjiig","hiiig","hjiig","kiiig","kjiig","liiig","ljiig","miiig","mjiig","niiig","njiig","oiiig","ojiig","piiig","pjiig","jjiig","jjaig","jjajg","jjbig","jjbjg","jjcig","jjcjg","jjdig","jjdjg","jjeig","jjejg","jjfig","jjfjg","jjgig","jjgjg","jjhig","jjhjg","jjkig","jjkjg","jjlig","jjljg","jjmig","jjmjg","jjnig","jjnjg","jjoig","jjojg","jjpig","jjpjg","jjjjg","ajjjg","akjjg","bjjjg","bkjjg","cjjjg","ckjjg","djjjg","dkjjg","ejjjg","ekjjg","fjjjg","fkjjg","gjjjg","gkjjg","hjjjg","hkjjg","ijjjg","ikjjg","ljjjg","lkjjg","mjjjg","mkjjg","njjjg","nkjjg","ojjjg","okjjg","pjjjg","pkjjg","kkjjg","kkajg","kkakg","kkbjg","kkbkg","kkcjg","kkckg","kkdjg","kkdkg","kkejg","kkekg","kkfjg","kkfkg","kkgjg","kkgkg","kkhjg","kkhkg","kkijg","kkikg","kkljg","kklkg","kkmjg","kkmkg","kknjg","kknkg","kkojg","kkokg","kkpjg","kkpkg","kkkkg","ggggx","gggxx","ggxxx","gxxxx","xxxxx","xxxxy","xxxyy","xxyyy","xyyyy","yyyyy","yyyyw","yyyww","yywww","ywwww","wwwww","wwvww","wvvww","vvvww","vvvwz","avvwz","aavwz","aaawz","aaaaz"};
    string st = "aaaaa";
    string en = "ggggg";
    auto sol = s.findLadders(st,en,wl);
    for (auto s:sol){
        for (auto w:s){
            cout<<w<<' ';
        }
        cout<<endl;
    }
    return 0;
}

