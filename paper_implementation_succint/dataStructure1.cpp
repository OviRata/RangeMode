#include<bits/stdc++.h>
#include"lambdaDataStructure.cpp"
#include"utilities.cpp"
using namespace std;



int T;
vector<LambdaDataStructure> lambdaDataStructuresArray;


void DataStructure1(){
    T=10;
    lambdaDataStructuresArray={LambdaDataStructure(1)};
    for(int i=1; i<=T; i++){
        lambdaDataStructuresArray.emplace_back(i);
    }
};


void updateDataStructure(){
    for(int i = 7; i <= T; i++){
        lambdaDataStructuresArray[i].update();
    }

    if( logUpperBound(n)*2>T ){
        T+=2;

        int fullModeFrequency = lambdaDataStructuresArray.back().F[1];
        int t_lambda_0 = max(1, (int)((float)sqrtl(1ll<<T)*Ratio) );
        string sd="0";
        string sy="0";
        if ( fullModeFrequency>0 )
        {
            sy[0]='1';
        }
        if ( fullModeFrequency>=t_lambda_0 )
        {
            sd[0]='1';
        }

        auto last = LambdaDataStructure(
            {BinaryStringGetRank1(), BinaryStringGetRank1(sd) },
            {BinaryStringGetLast1(), BinaryStringGetLast1(sy) },
            {0,fullModeFrequency},
            T
            );

        int t_lambda_1 = max(1, (int)((float)sqrtl(1ll<<(T-1))*Ratio) );
        sd="0";
        sy="0";
        if ( fullModeFrequency>0 )
        {
            sy[0]='1';
        }
        if ( fullModeFrequency>=t_lambda_1 )
        {
            sd[0]='1';
        }

        auto second = LambdaDataStructure(
            {BinaryStringGetRank1(), BinaryStringGetRank1(sd)},
            {BinaryStringGetLast1(), BinaryStringGetLast1(sy)},
            {0,fullModeFrequency},
            T-1
        );

        lambdaDataStructuresArray.push_back(second);
        lambdaDataStructuresArray.push_back(last);

    }


}

void update(int x){
    updateArrays(x);
    updateDataStructure();
}


pair<int, int> query(int i, int j){
    int length = j-i+1;
    int lambda = logUpperBound(length);
    return lambdaDataStructuresArray[lambda].query(i,j);
}
