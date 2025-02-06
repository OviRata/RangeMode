#include<bits/stdc++.h>
#include"succintDataStructure2.cpp"
#include <sys/resource.h>
using namespace std;


int kFromLog[10]={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

pair<int, int> generateQuery(int n, int logk) {
  int k = kFromLog[logk];
  int a = (rng()%(n-1) )+1;
  int b = min( a + ((int)ceil( (float)(n-a)/(float)k)), n) ;
  return make_pair(a, b);
}



pair<int, int> generateQueryForLength(int n, int l){
  if(l>=n)return {1, n};

  int a = rng()%(n-l+1)+1;
  int b = a+l-1;
  return {a,b};
}

long get_mem_usage()
{
  struct rusage usage;
  int ret;
  ret = getrusage(RUSAGE_SELF, &usage);
  return usage.ru_maxrss; // in KB
}

void checkResultCorrectnessNaively(int i, int j, pair<int, int> result){
      /*
        Use this function to check if the result is correct for the query (i,j), by using the naive algorithm.
      */
      auto resultNaive = NaiveQueryDataStructure1(i,j);
      if(result.second!=resultNaive.second){
        cout<<result.first<<" " <<result.second<<" query-\n";
        cout<<resultNaive.first<<" " <<resultNaive.second<<" queryNaive-\n";
        cout<<"wa: "<<i<<" "<<j<<"\n";
      }
}



string dataset = "ddos_tcp" ;

ifstream finData( "clean_data/" + dataset + ".txt" );

int main(){

  auto start = chrono::high_resolution_clock::now();
  for(int i=1; i<=10000000; i++){
    int x;
    finData>>x;
    
    update(x);
  }

  auto end = chrono::high_resolution_clock::now();

  long long time = chrono::duration_cast<chrono::microseconds>(end - start).count();
  cout<<"Building time: "<<time<<" microseconds "<<" = "<< ( (double)time/(double)(1000000*60) )<<" minutes \n";

  cout<<"Total memory usage: "<<get_mem_usage()<<" KB\n";
  cout<<"Average memory usage per symbol: "<<((float)get_mem_usage()*1024*8)/((float)n)<<" Bits\n";


    int cnt = 100000;
  for(int k=0; k<=6; k++){
    long long totalTime = 0;
    for(int q=1; q<=cnt; q++){
      auto pr = generateQuery(n, k);
      int i = pr.first, j=pr.second;


      auto start = chrono::high_resolution_clock::now();

      auto result = query(i,j);
      auto end = chrono::high_resolution_clock::now();

      long long currentDuration = std::chrono::duration_cast<std::chrono::nanoseconds>( end - start ).count();
      totalTime += currentDuration;
    }
    cout<<"for log k="<<kFromLog[k]<<" :"<<((float)totalTime)/(float)cnt<<"\n";
  }


  for(int l=1; l<=1000000; l*=10){
    long long totalTime = 0;
    for(int q=1; q<=cnt; q++){
      auto pr = generateQueryForLength(n, l);
      int i = pr.first, j=pr.second;


      auto start = chrono::high_resolution_clock::now();


      auto result = query(i,j);

      auto end = chrono::high_resolution_clock::now();

      long long currentDuration = std::chrono::duration_cast<std::chrono::nanoseconds>( end - start ).count();
      totalTime += currentDuration;
    }
    cout<<"for length="<<l<<" :"<<((float)totalTime)/(float)cnt<<"\n";
  }



  for(int logL=0, l=1; l<n; logL++, l*=2 ){
    long long totalTime = 0;
    for(int q=1; q<=cnt; q++){
      auto pr = generateQueryForLength(n, l);
      int i = pr.first, j=pr.second;


      auto start = chrono::high_resolution_clock::now();


      auto result = query(i,j);

      auto end = chrono::high_resolution_clock::now();

      long long currentDuration = std::chrono::duration_cast<std::chrono::nanoseconds>( end - start ).count();
      totalTime += currentDuration;
    }
    cout<<"for log_2 (length)="<<logL<<" :"<<((float)totalTime)/(float)cnt<<"\n";
  }


  return 0;
}