#include<bits/stdc++.h>
#include"succintLambda.cpp"
#include"../utility/utilities.cpp"
using namespace std;
using namespace sdsl;

int T;
vector<LambdaDataStructure*> lambdaDataStructuresArray;


void DataStructure1(){
    T=15;
    lambdaDataStructuresArray={ nullptr };
    for(int i=1; i<=T; i++){
        lambdaDataStructuresArray.push_back( new LambdaDataStructure(i) );
    }
};


void updateDataStructure(){
    for(int i = 6; i <= T; i++){
        lambdaDataStructuresArray[i]->update();
    }

    if( logUpperBound(n)*2>T ){
        T+=2;
        int fullModeFrequency = lambdaDataStructuresArray.back()->F[1];
        int t_lambda_0 = max(1, (int)(sqrtl(1ll<<T)*Ratio) );

        bit_vector* sd1=new bit_vector(1);
        bit_vector* sy1=new bit_vector(1);
        if ( fullModeFrequency>0 )
        {
            (*sy1)[0]=1;
        }
        if ( fullModeFrequency>=t_lambda_0 )
        {
            (*sd1)[0]=1;
        }

        auto last = new LambdaDataStructure(
            {nullptr, sd1 },
            {nullptr, sy1 },
            {0,fullModeFrequency},
            T
            );

        int t_lambda_1 = max(1, (int)(sqrtl(1ll<<(T-1) )*Ratio) );
        bit_vector* sd2=new bit_vector(1);
        bit_vector* sy2=new bit_vector(1);
        if ( fullModeFrequency>0 )
        {
            (*sy2)[0]=1;
        }
        if ( fullModeFrequency>=t_lambda_1 )
        {
            (*sd2)[0]=1;
        }

        auto second = new LambdaDataStructure(
            {nullptr, sd2 },
            {nullptr, sy2 },
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

pair<int, int> NaiveQueryDataStructure1(int i, int j){
  int f = 0;
  int x = -1;
  for(int k=i; k<=j; k++){
    int p = Q_1[k];
    int e = B[k];
    if(  p>=f+1 && Q[e][p-f]>=i ){
      f++;
      x=e;
    }
  }
  return make_pair(C[x],f);
}

pair<int, int> query(int i, int j){
    int length = j-i+1;
    int lambda = logUpperBound(length);
    if(lambda<=5){
        return NaiveQueryDataStructure1(i, j);
    }
    return lambdaDataStructuresArray[lambda]->query(i,j);
}


