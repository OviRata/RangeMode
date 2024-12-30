#include<bits/stdc++.h>
#include"utilities.cpp"
#include"naive.cpp"
using namespace std;

ifstream finData("clean_data/tickets.txt");
void checkQueriesFile(){

  for(int i=1; i<=10000000; i++){
    int x;
    finData>>x;
    updateArrays(x);
    if(i%10000==0){
      cout<<"appended "<<i<<" elements\n";
    }
  }

  ifstream fin("queryResults.out");
  int i, j, x, f;
  int cnt = 1;
  while(fin>>i){
     if( cnt%100==0 ){
       cout<<"queries processed: "<<cnt<<"\n";
     }
     fin>>j>>x>>f;
     auto pr = naiveQuery(i,j);
     int naiveF = pr.second;
     int X = pr.first;
     if( f != naiveF ){
       cout<<"wrong answer: "<<i<<" "<<j<<"\n expected: "<<f<<" "<<x<<" \n found: "<<naiveF<<" "<<X<<"\n";
     }
     cnt++;
  }


  fin.close();
}


int main(){

  checkQueriesFile();

  return 0;
}