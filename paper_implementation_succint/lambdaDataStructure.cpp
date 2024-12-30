#include<bits/stdc++.h>
#include"basicArraysDataStructure.cpp"
using namespace std;


const float Ratio = 2.00 ;

class LambdaDataStructure{
  public:
    int lambda=0;
    vector<BinaryStringGetRank1> delta;
    vector<BinaryStringGetLast1> y;
    vector<int> F;

    int s_lambda;
    int t_lambda;
  int f_size_limit;

    LambdaDataStructure(int lambda){
      t_lambda = max(1,(int)((float)sqrtl(1ll<<lambda)*Ratio) );
      f_size_limit = max(1ll, (long long )((1ll<<lambda)/t_lambda) )+1;
      s_lambda=0;
      this->lambda=lambda;
      delta.emplace_back();
      y.emplace_back();
      this->F={0};
    }

    LambdaDataStructure(vector<BinaryStringGetRank1> delta, vector<BinaryStringGetLast1> y, vector<int> F, int lambda){
      this->lambda=lambda;
      for (auto bs:delta)
      {
        this->delta.push_back(bs);
      }
      for (auto bs:y)
      {
        this->y.push_back(bs);
      }
      this->F=F;
      this->s_lambda = ((int)F.size())-1;
      t_lambda = max(1,(int)((float)sqrtl(1ll<<lambda)*Ratio) );
      f_size_limit = max(1ll, (long long )((1ll<<lambda)/t_lambda) )+1;
    }


    void update(){
      int st = max(s_lambda-f_size_limit+1, 1);
      if( (n % t_lambda)==1 || t_lambda==1 ){
        delta.emplace_back();
        y.emplace_back();
        this->s_lambda=s_lambda+1;
        for(int b = max(s_lambda-f_size_limit+1, 1); b<=s_lambda; b++ ){
          y[b].append(0);
          delta[b].append(0);
        }

        if( (((int)F.size())-1)==f_size_limit ){
           for(int i = 1 ; i<f_size_limit ; i++){
             F[i]=F[i+1];
           }
           F[f_size_limit]=0;
        }
        else{
          F.push_back(0);
        }

      }

      for(int b = st; b<=s_lambda; b++ ){
        int k = b-st+1;
        int f = F[k];
        int p = Q_1.back();
        int x = B.back();
        if( p > f && Q[x][p-f]>( (b-1)*t_lambda ) ){
          f=f+1;
          y[b].setLast(1);
          if( f%t_lambda==0 ){
            delta[b].setLast(1);
          }
        }
        F[k]=f;
      }


    }

    [[nodiscard]] int getBlockOfPosition(const int i) const
    {
      return (i-1) / t_lambda + 1;
    }

    pair<int, int> query(const int i, const int j){
      const int b1 = getBlockOfPosition(i)+1;
      const int b2 = getBlockOfPosition(j)-1;
      int f = 0;
      int x = -1;
      if (b2>=b1)
      {
        const int p_last = y[b1].getLast1( b2-b1+1 );

        const int bs = b1+p_last-1;
        f = t_lambda*delta[b1].getRank1(b2-b1+1);

        //cout<<p_last<<" p_last "<< bs<<" bs "<<" f "<<f<< " t_lambda "<< t_lambda<<" s_lambda "<<s_lambda<< "\n";

        for (int k = (bs-1)*t_lambda+1; k<=bs*t_lambda; k++ )
        {
          const int p = Q_1[k];
          const int e = B[k];
          //if( e==26 ){cout<<"26 found\n";}
          while ( p>=f+1 && ( Q[e][p-f]>=(b1-1)*t_lambda+1 ) )
          {
            x=e;
            f=f+1;
          }
        }
      }

      for (int k=min(j,(b1-1)*t_lambda); k>=i; k--)
      {
        int p = Q_1[k];
        int e = B[k];
        while (p+f <= ( (int)(Q[e].size())-1 ) && Q[e][p+f]<=j  )
        {
          x=e;
          f=f+1;
        }
      }

      for (int k=max(b2*t_lambda+1, i); k<=j; k++ )
      {
        int p = Q_1[k];
        int e = B[k];
        while ( p>=f+1 && Q[e][p-f]>=i )
        {
          x=e;
          f=f+1;
        }
      }

      return {x,f};
    }


};
