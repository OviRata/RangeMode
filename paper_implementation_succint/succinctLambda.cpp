#include<bits/stdc++.h>
#include"basicArraysDataStructure.cpp"
#include <sdsl/bit_vectors.hpp>
using namespace std;
using namespace sdsl;

const float Ratio = 2.00;


class LambdaDataStructure{
  public:


    int lambda=0;
    vector<bit_vector*> deltaBitVectors;
    vector<bit_vector*> yBitVectors;
    vector< rank_support_v<1>* > deltaRankSupport;
    vector< rank_support_v<1>* > yRankSupport;
    vector< bit_vector::select_1_type* > ySelectSupport;

    vector<int> F;

    int s_lambda;
    int t_lambda;
    int f_size_limit;

    LambdaDataStructure(int lambda){
      t_lambda = max(1,(int)(sqrtl(1ll<<lambda)*Ratio) );
      f_size_limit = max(1, (int)((1ll<<lambda)/t_lambda))+1;
      s_lambda=0;
      this->lambda=lambda;
      deltaBitVectors.push_back( nullptr );
      yBitVectors.push_back( nullptr );
      for(int i=0; i<yBitVectors.size(); i++){
        yRankSupport.push_back( nullptr );
        ySelectSupport.push_back( nullptr );
      }
      for(int i=0; i<deltaBitVectors.size(); i++){
        deltaRankSupport.push_back( nullptr );
      }
      this->F={0};
    }


    LambdaDataStructure(vector<bit_vector*> deltaBitVector, vector<bit_vector*> yBitVector, vector<int> F, int lambda){
    
      this->lambda=lambda;

      this->deltaBitVectors={};
      this->yBitVectors={};
      for(int i=0; i<yBitVector.size(); i++)
      {
        this->yBitVectors.push_back( yBitVector[i] );
      }
      for(int i=0; i<deltaBitVector.size(); i++)
      {
        this->deltaBitVectors.push_back( deltaBitVector[i]  );
      }

      for(int i=0; i<yBitVectors.size(); i++){
        yRankSupport.push_back( new rank_support_v<1>( yBitVector[i] ) );
        ySelectSupport.push_back( new bit_vector::select_1_type(yBitVector[i]) );
      }
      for(int i=0; i<deltaBitVectors.size(); i++){
        deltaRankSupport.emplace_back( new rank_support_v<1>(deltaBitVector[i]) );
      }

      this->F=F;
      this->s_lambda = ((int)F.size())-1;      
      t_lambda = max(1,(int)(sqrtl(1ll<<lambda)*Ratio) );
      f_size_limit = max(1, (int)((1ll<<lambda)/t_lambda))+1;
      //cout<<(this->yBitVectors).size()<<"sz\n";
      
    }


    void update(){



      if( (n % t_lambda)==1 || t_lambda==1 ){
        s_lambda++;
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

      for(int b = max(s_lambda-f_size_limit+1, 1); b<=s_lambda; b++ ){
        int k = b-max(s_lambda-f_size_limit+1, 1)+1;
        int f = F[k];
        int p = Q_1.back();
        int x = B.back();
        if( p >= f+1 && Q[x][p-f]>=( (b-1)*t_lambda + 1 ) ){
          f=f+1;
        }
        F[k]=f;
      }
          /*
          if(lambda==6){
          cout<<A[n]<<"- B\n";
          cout<<"F: \n";
          for(int i=0; i<F.size(); i++){
            cout<<F[i]<<" ";
          }
          cout<<"-F\n";
          }
          */

      if( n%t_lambda==0 ){
        
        yBitVectors.push_back( new bit_vector( (int) F.size() ) );
        deltaBitVectors.push_back( new bit_vector( (int) F.size() ) );

        (*(yBitVectors.back()) )[1] = F.back()>0;
        (* (deltaBitVectors.back()) )[1] = F.back()>=t_lambda;

        for(int i=2; i<((int)F.size())-1; i++){
           (* (yBitVectors.back()) )[i] = (F[ F.size()-i ]>F[ F.size()-i+1 ]);
           (* (deltaBitVectors.back()) )[i] = ((F[ F.size()-i ]-F[ F.size()-i+1 ])>=t_lambda);
        }

        yRankSupport.push_back( new rank_support_v<1>( yBitVectors.back() ) );
        deltaRankSupport.push_back( new rank_support_v<1>( deltaBitVectors.back() ) );

        ySelectSupport.push_back( new bit_vector::select_1_type(yBitVectors.back()) );
        
        if(lambda==6){
          if( (*yBitVectors.back())[1]!=1 ){
         cout<<n<<" n--\n";
         cout<<f_size_limit<<" fsizelimit\n";
         cout<<F.size()<<" fsize\n";
         cout<<( *(yBitVectors.back()) ).size()<<" size of last in ybitvectors\n "; 
         cout<<( *(deltaBitVectors.back()) ).size()<<" size of last in ybitvectors\n ";
          for(int i=0; i<F.size(); i++){
            cout<<(*yBitVectors.back())[i]<<" ";
          }
          cout<<"-F\n";
        }
        }
        

      }





    }

    [[nodiscard]] int getBlockOfPosition(const int i) const
    {
      return (i-1) / t_lambda + 1;
    }

    int getLast1inY(int b1, int b2){
      //cout<<"b1="<<b1<<" b2="<<b2<<" "<<"\n";
      //cout<<yRankSupport.size()<<"\n";
      //cout<<(*yBitVectors[b2]).size()<<"\n";
      
      /*
      for(int i=0; i<(*yBitVectors[b2]).size(); i++){
        cout<<(*(yRankSupport[b2]))(i)<<" ";
      }
      */

      //cout<<"\n";
      //cout<<(*(yRankSupport[b2]))(b2-b1+1+1)<<"\n";
      //cout<<ySelectSupport.size()<<"\n";
      return (*(ySelectSupport[b2]))( (*(yRankSupport[b2]))(b2-b1+1+1) );
    }

    pair<int, int> query(const int i, const int j){
      const int b1 = getBlockOfPosition(i)+1;
      const int b2 = getBlockOfPosition(j)-1;
      int f = 0;
      int x = -1;
      //cout<<b1<<" "<<b2<<"-\n";
      if (b2>=b1)
      {

        //cout<<p_last<<" p_last "<< bs<<" bs "<<" f "<<f<< " t_lambda "<< t_lambda<<" s_lambda "<<s_lambda<< "\n";
        const int p_last = getLast1inY(b1, b2);


        //cout<<p_last<<" p_last "<< bs<<" bs "<<" f "<<f<< " t_lambda "<< t_lambda<<" s_lambda "<<s_lambda<< "\n";

        const int bs = b2-p_last+1;


        //cout<<p_last<<" p_last "<< bs<<" bs "<<" f "<<f<< " t_lambda "<< t_lambda<<" s_lambda "<<s_lambda<< "\n";
        f = t_lambda* ( (*(deltaRankSupport[b2]))(b2-b1+1+1) );

        //cout<<p_last<<" p_last "<< bs<<" bs "<<" f "<<f<< " t_lambda "<< t_lambda<<" s_lambda "<<s_lambda<< "\n";

        for (int k = (bs)*t_lambda; k>(bs-1)*t_lambda; k-- )
        {
          const int p = Q_1[k];
          const int e = B[k];
          //if( e==26 ){cout<<"26 found\n";}
          while ( p+f<Q[e].size() && ( Q[e][p+f]<=(b2)*t_lambda) )
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

      return { C[x] ,f};
    }


};
