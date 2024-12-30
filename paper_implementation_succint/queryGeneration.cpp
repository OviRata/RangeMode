#include<bits/stdc++.h>
#include"utilities.cpp"
using namespace std;


int kFromLog[10]={0, 10, 100, 1000, 10000, 100000, 1000000};

pair<int, int> generateQuery(int n, int logk) {
  int k = kFromLog[logk];
  int a = (rng()%(n-1) )+1;
  int b = a + ((int)ceil( (float)(n-a)/(float)k));
  return make_pair(a, b);
}


int main(){

  ofstream fout("queries.out");
  for(int i=1; i<=5; i++){
    for(int j=1; j<=700; j++){
      pair pr = generateQuery(10000000, i);
      fout<<pr.first<<" "<<pr.second<<endl;
    }
  }
  fout.close();

  return 0;
}