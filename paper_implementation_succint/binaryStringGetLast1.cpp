#include<bits/stdc++.h>
#include"getLast1LookUpTable.cpp"
using namespace std;




class BinaryStringGetLast1
{
    public:
    int n;

    vector<int> smallArrayIndexes;

    vector<int> arrayMasks;

    BinaryStringGetLast1(){
        smallArrayIndexes={0};
        arrayMasks={0};
        n=0;
    }

    BinaryStringGetLast1(string binaryString ){
        smallArrayIndexes={0};
        arrayMasks={0};
        n=0;

        for(int i=0;i<binaryString.length();i++){
          unsigned short int b = (int)(binaryString[i]-'0');
          this->append(b);
        }

    }

    int getLast1(int i) const;


    int lastBlockValue(){
      int sz = 16;
      int numberOfBlock = (n-1)/sz+1;
      int j = n-(numberOfBlock-1)*sz;
      int lastlast = getLastLookUp.get( arrayMasks.back() , sz);
            if( lastlast>0 ){
               return ( (numberOfBlock-1) * sz + lastlast );
            }
            else{
                if( smallArrayIndexes.size()>1 ){
                    return ( smallArrayIndexes.back() );
                }
                else{
                    return (0);
                }
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
            arrayMasks[ ((int)arrayMasks.size())-1 ]|=( 1<<(j-1) )*b;
        }
        
        if( n%sz==0 ){            
            smallArrayIndexes.push_back( lastBlockValue() );
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


int BinaryStringGetLast1:: getLast1(int i) const
{
    int sz = 16;
    int numberOfBlock = ((i-1)/sz)+1;

    int j = i-(numberOfBlock-1)*sz;
    //cout<<j<<" "<<getLastLookUp.get( 0, j)<<" last1\n";
    if( getLastLookUp.get( arrayMasks[ numberOfBlock ] , j)>0 ){
        return (numberOfBlock-1)*sz + getLastLookUp.get( arrayMasks[ numberOfBlock ] , j );
    }

    if( numberOfBlock>1 ){
        return smallArrayIndexes[numberOfBlock-1];
    }

    return -1;
}