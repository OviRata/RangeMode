#include<bits/stdc++.h>
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int logLowerBound(long long x){
  return 8*sizeof(x) - __builtin_clzll(x)-1;
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
