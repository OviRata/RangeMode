#include<bits/stdc++.h>
#include"utilities.cpp"
#include"basicArraysDataStructure.cpp"
using namespace std;



int s;
vector<int> L={0, 1}, R={0, 1};

vector<int> tau={0, 0};

vector<BinaryStringGetLast1> y={BinaryStringGetLast1()};
vector<BinaryStringGetRank1> delta={BinaryStringGetRank1()};
int w = 64, sqrtW=8;

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


int getBigBlockOfPosition(int i){
  int l = 0, r = R.size()-1;
  while(l<r){
    int mid = (l+r)>>1;
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



int query(int i, int j){
  int beta1 = getSmallBlockOfPosition(i)+1;
  int beta2 = getSmallBlockOfPosition(j)-1;
  int f = 0;
  int x = -1;
  if(beta2>=beta1){
    int p_last = y[beta2].getLast1(beta2-beta1+1);
    int bs = beta2-p_last+1;
    f = (delta[beta2].getRank1(beta2-beta1+1) ) * size(beta2);

    for(int k = R[bs]; k>=L[bs]; k--){
      int p = Q_1[k];
      int e = B[k];
      while(p+f <= (((int)Q[e].size())-1) &&  Q[e][p+f]<=R[beta2] ){
        x=e;
        f=f+1;
      }
    }

  }

  for(int k = i; k<=R[beta1-1]; k++){
    int p = Q_1[k];
    int e = B[k];
    if (p+f <= ( (int)(Q[e].size())-1 ) && Q[e][p+f]<=j  )
    {
      x=e;
      f=f+1;
    }
  }

  for(int k=L[beta2+1]; k<=j; k++ ){
    int p = Q_1[k];
    int e = B[k];
    if ( p>=f+1 && Q[e][p-f]>=i )
    {
      x=e;
      f=f+1;
    }
  }

  return f;
}

void updateDataStructure(int x){
  if( n > R[getSmallBlockOfPosition(n-1)] ){
    int b = getBigBlockOfPosition(n);
    L.push_back(n);
    R.push_back( min( b*(b+1)/2, n + ((int)ceil( float(b) / float(sqrtW) )) - 1 ) );
    tau.push_back(0);

    string deltaString = "";
    string yString = "";

    for(int beta = s; beta>=1; beta--){
      if(tau[beta]>tau[beta+1]){
        yString.push_back('1');
        if( tau[beta]-tau[beta-1]>=size(s) ){
          deltaString.push_back('1');
        }
        else{
          deltaString.push_back('0');
        }
      }
      else{
        yString.push_back('0');
        deltaString.push_back('0');
      }
    }

    delta.emplace_back( deltaString );
    y.emplace_back( yString );
    s=s+1;


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
  updateDataStructure(x);
}