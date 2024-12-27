#include<bits/stdc++.h>
using namespace std;

class GetLast1LookUpTable{
    public:
    static const int sz = 16;
    vector<vector<int>>lookUp;
    GetLast1LookUpTable(){
        lookUp.assign( 1<<sz, vector<int>(sz+2,0) );
        for(int msk=0; msk<(1<<sz); msk++){
            //lookUp[i]=sizeof(unsigned short int)-__builtin_clz(msk);
            for(int i=0; i<sz; i++){
                if( (int) (msk & ( ( (1<<(i+1))-1 ) ) ) >0 ){
                    lookUp[msk][i+1]=32-__builtin_clz( (int) (msk & ( ( (1<<(i+1))-1 ) ) )  );
                }
                else{
                    lookUp[msk][i+1]=0;
                }
                //cout<<lookUp[msk][i+1]<<endl;
            }
        }
    }

    int get(int msk, int i)
    {
        return lookUp[msk][i];
    }

};

GetLast1LookUpTable getLastLookUp = GetLast1LookUpTable();;