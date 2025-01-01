#include<bits/stdc++.h>
#include"utilities.cpp"
#include"basicArraysDataStructure.cpp"
#include <sdsl/bit_vectors.hpp>
using namespace std;
using namespace sdsl;


int s;
vector<int> L={0}, R={0};

vector<int> tau={0};


vector<bit_vector*> deltaBitVectors;
vector<bit_vector*> yBitVectors;
vector< rank_support_v<1>* > deltaRankSupport;
vector< rank_support_v<1>* > yRankSupport;
vector< bit_vector::select_1_type* > ySelectSupport;

int w = 64, sqrtW=8;

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
  return make_pair(x,f);
}

int getSmallBlockOfPosition(int i){
  int l = 0, r = R.size()-1;
  while(l<r){
    int mid = (l+r)>>1;
    if(R[mid]>=i){
      r=mid;
    }
    else{
      l=mid+1;
    }
  }
  return l;
}


int getBigBlockOfPosition(long long i){
  long long l = 0, r = n;
  while(l<r){
    long long mid = (l+r)>>1;
    if( mid*(mid+1)/2>=i ){
      r=mid;
    }
    else{
      l=mid+1;
    }
  }
  return l;
}

int size(int beta){
  return R[beta]-L[beta]+1;
}


int getLast1(int beta1, int beta2){
  return (*(ySelectSupport[beta2]))( (*(yRankSupport[beta2]))(beta2-beta1+1+1) );
}

pair<int, int> query(int i, int j){
    if( j-i+1<=65 ){
        return NaiveQueryDataStructure1(i, j);
    }
  int beta1 = getSmallBlockOfPosition(i)+1;
  int beta2 = getSmallBlockOfPosition(j)-1;
  int f = 0;
  int x = -1;
  if(beta2>=beta1){
    int p_last = getLast1(beta1, beta2);
    int bs = beta2-p_last+1;
    f = (( *(deltaRankSupport[beta2]) )(beta2-beta1+2)) * size(beta2);

    for(int k = R[bs]; k>=L[bs]; k--){
      int p = Q_1[k];
      int e = B[k];
      while(p+f <= (((int)Q[e].size())-1) &&  Q[e][p+f]<=R[beta2] ){
        x=e;
        f=f+1;
      }
    }

  }

  for(int k = min(j,R[beta1-1]); k>=i; k--){
    int p = Q_1[k];
    int e = B[k];
    while (p+f <= ( (int)(Q[e].size())-1 ) && Q[e][p+f]<=j  )
    {
      x=e;
      f=f+1;
    }
  }

  for(int k=max(R[beta2]+1, i); k<=j; k++ ){
    int p = Q_1[k];
    int e = B[k];
    while ( p>=f+1 && Q[e][p-f]>=i )
    {
      x=e;
      f=f+1;
    }
  }

  return {C[x],f};
}

void updateDataStructure(){
  if( n==1 || n > R[getSmallBlockOfPosition(n-1)] ){
    int b = getBigBlockOfPosition(n);
    L.push_back(n);
    R.push_back( min( b*(b+1)/2, n + ((int)ceil( float(b) / float(sqrtW) )) - 1 ) );
    tau.push_back(0);

    yBitVectors.push_back( new bit_vector(s+1) );
    deltaBitVectors.push_back( new bit_vector(s+1) );

    for(int beta = s; beta>=1; beta--){
      if(tau[beta]>tau[beta+1]){
        (*yBitVectors.back())[s-beta+1]='1';
        if( tau[beta]-tau[beta+1]>=size(s) ){
          (*deltaBitVectors.back())[s-beta+1]='1';
        }
      }
    }
    
    s=s+1;

    yRankSupport.push_back( new rank_support_v<1>(yBitVectors.back()) );
    ySelectSupport.push_back( new bit_vector::select_1_type(yBitVectors.back()) );

    deltaRankSupport.push_back( new rank_support_v<1>(deltaBitVectors.back()) );
  }

  int p = Q_1[n];
  int e = B[n];
  for(int beta = s; beta>=1; beta--){
    int f = tau[beta];
    if( p>=f+1 && ( Q[e][p-f]>=L[beta] ) ){
      tau[beta]=f+1;
    }
  }


}

void update(int x){
  updateArrays(x);
  updateDataStructure();
}