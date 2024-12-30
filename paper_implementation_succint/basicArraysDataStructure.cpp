#include<bits/stdc++.h>
#include"binaryStringGetLast1.cpp"
#include"binaryStringGetRank1.cpp"
using namespace std;


int n=0;
vector<int> A={0}, B={0}, Q_1={0}, C={0};
vector< vector<int> >Q={{0}};
set<pair<int,int>> D={};
int Delta=0;



void updateArrays(int x){
    int index = 0;
    auto it = D.lower_bound(make_pair(x,0) );
    if(it != D.end() && it->first == x){
        index = it->second;
    }
    else{
        Delta=Delta+1;
        D.insert(make_pair(x, Delta));
        index=Delta;
        Q.push_back({0});
        C.push_back(x);
    }
    n=n+1;
    A.push_back(x);
    B.push_back(index);
    Q[index].push_back(n);
    Q_1.push_back( ((int)(Q[index].size())) - 1 );
	//cout<<x<<" "<<A.back()<<" "<<B.back()<<" "<<Q[index].back()<<" "<<Q_1.back()<<endl;
}