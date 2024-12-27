#include<bits/stdc++.h>
#include"basicArraysDataStructure.cpp"
using namespace std;


pair<int, int> naiveQuery(int i, int j){
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
  return make_pair(x,f);
}

