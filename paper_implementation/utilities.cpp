#include<bits/stdc++.h>
using namespace std;


int logLowerBound(long long x){
  return 8*sizeof(x) - __builtin_clzll(x);
}

int logUpperBound(long long x){
  int log2Lower = logLowerBound(x);
  if( (1ll<<log2Lower) >=x  ){
    return log2Lower;
  }
  else{
    return log2Lower+1;
  }
}
