#include<bits/stdc++.h>
#include"getRank1LookUpTable.cpp"
using namespace std;



class BinaryStringGetRank1
{
    public:
    int n;

    vector<int> smallArrayIndexes;

    vector<int> arrayMasks;


    explicit BinaryStringGetRank1(){
        smallArrayIndexes={0};
        arrayMasks={0};
        n=0;
    }

    BinaryStringGetRank1( string binaryString ){
        smallArrayIndexes={0};
        arrayMasks={0};
        n=0;

        for(int i=0;i<binaryString.length();i++){
          short int b = (int)(binaryString[i]-'0');
          this->append(b);
        }

    }

    int getRank1(int i){
        int sz = 16;
        int numberOfBlock = ((i-1)/sz)+1;

        int j = i-(numberOfBlock-1)*sz;
        if(numberOfBlock<=1){
            //cout << std::bitset<8>( arrayMasks[ numberOfBlock ])<<endl<<flush;
            //cout<<j<<endl<<flush;
          return getRankLookUp.get( arrayMasks[ numberOfBlock ] , j);
        }
        return  getRankLookUp.get( arrayMasks[ numberOfBlock ] , j) + smallArrayIndexes[numberOfBlock-1];
    }

    int lastBlockValue(){
      int sz = 16;
        int cntlast = getRankLookUp.get( arrayMasks.back() , sz);
        if( smallArrayIndexes.size()>0 ){
           return (cntlast + smallArrayIndexes.back() );
        }
        else{
          return ( cntlast );
        }
    }

    void append(unsigned short int b){
        n++;
        int sz = 16;
        int numberOfBlock = (n-1)/sz+1;
        int j = n-(numberOfBlock-1)*sz;

        if(n%sz==1){
            arrayMasks.push_back( (unsigned short int) b );
        }
        else{
            arrayMasks[ arrayMasks.size()-1 ]|=( 1<<(j-1) )*b;
            if( n%sz == 0 ){
                smallArrayIndexes.push_back( lastBlockValue() );
            }
        }
    }


    void setLast(unsigned short int b){
        int sz = 16;
        int numberOfBlock = (n-1)/sz+1;
        int j = n-(numberOfBlock-1)*sz;
        if( b!=((unsigned short int)((arrayMasks.back()&( 1<<(j-1) ))>0)) ){
            arrayMasks[ arrayMasks.size()-1 ]^=( 1<<(j-1) );
            if( n%sz==0 ){
                smallArrayIndexes[ ((int)smallArrayIndexes.size())-1 ]=lastBlockValue();
            }
        }
    }



};