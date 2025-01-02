#include<bits/stdc++.h>
#include"succintDataStructure1.cpp"
#include"queryWriteout.cpp"
using namespace std;


ifstream finData("clean_data/reviews.txt");
ifstream finQueries("queries.out");

int main(){


  DataStructure1();
  for(int i=1; i<=10000000; i++){
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

    auto pr = query(9996861 , 9996893);
    cout<<pr.first<<" "<<pr.second<<"\n";
  

  int i, j;
  int cnt = 1;
  while(finQueries>>i){
    finQueries>>j;
    cout<<i<<" "<<j<<"-\n";
    auto pr = query(i,j);
    cout<<"answer: "<<pr.first<<" "<<pr.second<<"\n";
    queryWriteout(i,j, pr.first, pr.second);
    cout<<"done query "<<cnt<<"\n";
    cnt++;
  }
    


  return 0;
}