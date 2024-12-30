#include<bits/stdc++.h>
using namespace std;

class GetRank1LookUpTable{
  public:
    static const int sz = 16;
    vector<vector<int>> lookUp;
    GetRank1LookUpTable(){
        lookUp.assign( 1<<sz, vector<int>(sz+2,0) );
        for(int msk=1; msk< (int)(1<<sz); msk++){
            for(int i=0; i<sz; i++){
              //cout<<msk<<" "<<i<<endl<<flush;
              lookUp[msk][i+1]=__builtin_popcount( ( (1<<(i+1))-1) & msk );
            }
        }
    }

    int get(int msk, int i) const {
        return lookUp[msk][i];
    }
};

GetRank1LookUpTable getRankLookUp = GetRank1LookUpTable();