#include<bits/stdc++.h>
#include"dataStructure1.cpp"
#include"queryWriteout.cpp"
using namespace std;


ifstream finData("clean_data/tickets.txt");
ifstream finQueries("queries.out");

int main(){


  DataStructure1();
  for(int i=1; i<=5000000; i++){
    int x;
    finData>>x;
    //cout<<x<<" found\n";
    update(x);
    if(i%10000==0){
      cout<<"appended "<<i<<" elements\n";
		/*
      int sumDelta = 0;
      int sumY = 0;
		int sumF = 0;
      for(int j=1; j<=T; j++){
        for(int k = 1; k<lambdaDataStructuresArray[j].delta.size(); k++){sumDelta+=((int)lambdaDataStructuresArray[j].delta[k].arrayMasks.size()); }
        for(int k = 1; k<lambdaDataStructuresArray[j].y.size(); k++){sumY+=((int)lambdaDataStructuresArray[j].y[k].arrayMasks.size()); }
		cout<<" for "<<j << " : \n t_lambda="<<lambdaDataStructuresArray[j].t_lambda<<"\n s_lambda="<<lambdaDataStructuresArray[j].s_lambda<< " \n F: "<<lambdaDataStructuresArray[j].F.size()<<"\n";
    	sumF += (int)lambdaDataStructuresArray[j].F.size();
	}
      cout<<"sum delta: "<<sumDelta<<"\n";
      cout<<"sum Y: "<<sumY<<"\n";
      cout<<"sum F: "<<sumF<<"\n";
      cout<<"ratio: "<<(float)sumDelta/(float)n<<"\n";
		*/
	}

  }

  int i, j;
  int cnt = 1;
  while(finQueries>>i){
    finQueries>>j;
    auto pr = query(i,j);
    queryWriteout(i,j, pr.first, pr.second);
    cout<<"done query "<<cnt<<"\n";
    cnt++;
  }
  auto pr =query( 141542 , 142127);
  cout<<pr.first<<" "<<pr.second<<"\n";

  pr =query( 48619 , 50133 );
  cout<<pr.first<<" "<<pr.second<<"\n";

  cout<<"first right block "<<(142126/32+1)<<"\n";

  int f = 0;
  int lastF=0;
  int lastBlock = 0;
  string s="0";
  for(int i=141542; i<=142127 && true; i++){
    int x = B[i];
    int p = Q_1[i];
    if( p>=f+1 && Q[x][p-f]>=141542 ){
      f++;
    }
    int block = (i-1)/32+1;
    if( f>lastF ){
      s[ ((int)s.length())-1 ]='1';
    }
    if( f-lastF>=32 ){
      s[ ((int)s.length())-1 ]='1';
    }
    if( (i)/32>(i-1)/32 ){
      lastF = f;
      lastBlock = block;
      s.push_back('0');
    }
  }

  cout<<s<<"\n";

  auto bb = BinaryStringGetLast1(s);
  cout<<bb.getLast1(17)<<"\n";
  cout<<bb.arrayMasks.back()<<"\n";
  int msk = 0;
  int k = 0;
  cout<< ( (int) (msk & ( ( (1<<(k+1))-1 ) ) ) ) <<"-\n";
  cout<<bb.getLast1(18)<<"\n";
  cout<<bb.getLast1(16)<<"\n";

  return 0;
}