#include <bits/stdc++.h>
#include "src/solutionTemplate.hpp"
#include "src/solutionTemplate.cpp"

using namespace std;
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


void Solution::part1() {
    vector<ll> seeds;
    //cout<<p1.size()<<' '<<p1[0].size();


    for (int i = 1;i<(int)p1[0].size();i++){
        seeds.push_back(stoll(p1[0][i]));
    }
    vector<bool> processed(seeds.size(),false);

    for (int r = 3;r<p1.size();r++) {
        auto row = p1[r];
        if (row.size()<3){
            r=r+1;
            processed.resize(0,false);
            processed.resize(seeds.size(),false);
            continue;
        }
        ll dest = stoll(row[0]);
        ll src = stoll(row[1]);
        ll range = stoll(row[2]);
        
        for (int i = 0 ;i< seeds.size();i++){
            ll seed = seeds[i]; 
            if (processed[i] == false && src <= seed && seed <=src+range-1){

                seeds[i] = dest + (seed-src);
                //cout<<"Seed: "<<seed<<" "<<seeds[i];
                processed[i] = true;
            }
            else{
                seeds[i] = seed;
            }
          //  cout<<seed<<' ';
        }
        //cout<<endl;

    }
    ll res =  *min_element(seeds.begin(),seeds.end());
    cout<<"Part 1: "<< res<<endl;
}

struct seedRange{
    ll startingSeed;
    ll range;
    
    seedRange(ll ss,ll r) {
        this->startingSeed = ss;
        this->range = r;
    }
};

ll intersectingSeedRanges(seedRange a, seedRange b){
    ll al = a.startingSeed;
    ll bl = b.startingSeed;
    ll ar = a.startingSeed+a.range-1;
    ll br = b.startingSeed+b.range-1;

    ll res =  min(ar,br) - max(al,bl)+1;
    return max((ll)0,res);
}



void Solution::part2() {
    list<seedRange> seeds;
    list<seedRange> newSeeds;

    for (int i = 2;i<p2[0].size();i+=2){
        seeds.push_back(seedRange(stoll(p2[0][i-1]),stoll(p2[0][i])));
    }


    for (int r = 1;r<p2.size();r++) {
        auto row = p2[r];

        if (row.size()<3){
            r=r+1;
           // cout<<"stage end: ";
            
            seeds.splice(seeds.end(),newSeeds);
            for (auto s : seeds){
            cout<<"{"<<s.startingSeed<<' '<<s.range<<'}'<<' ';
            }
            cout<<endl;
            continue;
        }

        ll dest = stoll(row[0]);
        ll src = stoll(row[1]);
        ll range = stoll(row[2]);
        //cout<<dest<<' '<<src<<' '<<range<<endl;
        

        


        seedRange transformer = seedRange(src,range);
        

        auto it = seeds.begin();
        
        while (it != seeds.end()){
            auto& seed = *it;
           // cout<< seed.startingSeed<<' ';

            ll area = intersectingSeedRanges(transformer,seed);
            if (area == 0) {
                it = next(it);  // Move to the next element
                continue;
            }

            int lRange = transformer.startingSeed - seed.startingSeed ;
            int rRange = seed.startingSeed+seed.range - (transformer.startingSeed+transformer.range); 

            if (lRange > 0){
                seeds.push_back(seedRange(seed.startingSeed,lRange));// non transformed
            }
            if (rRange > 0){
                seeds.push_back(seedRange(transformer.startingSeed+transformer.range,rRange)); // non transformed
            }

            
            ll newPos = dest + max(seed.startingSeed - transformer.startingSeed,(ll)0);
            ll newRange = area;
                
            newSeeds.push_back(seedRange(newPos,newRange));
            
            it = seeds.erase(it);
        }
        //cout<<"To process: ";
      //  for (auto s : seeds){
       //     cout<<"{"<<s.startingSeed<<' '<<s.range<<'}'<<' ';
      //  }

     //   cout<<endl<<"To next phase: ";
   //     for (auto s : newSeeds){
     //      cout<<"{"<<s.startingSeed<<' '<<s.range<<'}'<<' ';
     //   }
      //  cout<<endl;
    }
    for (seedRange s : seeds){
        newSeeds.push_back(s);
    }
    ll res = (ll)INT_MAX;
    for (auto s : newSeeds){
       res = min(s.startingSeed,res);
    }
    std::cout<<"Part 2: "<< res<<endl; 
}

int main(void){
    auto precomp = std::chrono::high_resolution_clock::now();

   // cout<<intersectingSeedRanges(seedRange(0,4),seedRange(1,5))<<endl;
    //cout<<intersectingSeedRanges(seedRange(0,3),seedRange(1,2))<<endl;

    Solution s("5.2023.1", Solution::readType::spaced);

    auto start = std::chrono::high_resolution_clock::now();
    auto readin = std::chrono::duration_cast<std::chrono::microseconds>(start - precomp);
    cout << "--------------Read time: " << readin.count() / 1e3 << " milliseconds------------------" << endl;
   
    start = std::chrono::high_resolution_clock::now();

    s.part1();
    auto p1finish = std::chrono::high_resolution_clock::now();
    s.part2();
    auto stop = std::chrono::high_resolution_clock::now();

    auto p1duration = std::chrono::duration_cast<std::chrono::microseconds>(p1finish - start);
    auto p2duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - p1finish);
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    auto totalduration = std::chrono::duration_cast<std::chrono::microseconds>(stop - precomp);
    cout << "Part 1 Execution Time: " << p1duration.count() / 1e3 << " milliseconds" << endl;
    cout << "Part 2 Execution Time: " << p2duration.count() / 1e3 << " milliseconds" << endl;
    cout << "Execution Time: " << duration.count() / 1e3 << " milliseconds" << endl;
    cout << "Total Time: " << totalduration.count() / 1e3 << " milliseconds" << endl;

    return 0;
}