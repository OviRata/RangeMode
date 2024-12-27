#include<bits/stdc++.h>
#include"dataStructure1.cpp"
//#include"dataStructure2.cpp"
using namespace std;



int main(){
    /*
    GetRank1LookUpTable* lookUpRank = new GetRank1LookUpTable();
    cout<<"first lookup done\n"<<flush;
    GetLast1LookUpTable* lookUpLast = new GetLast1LookUpTable();
    cout<<"second lookup done\n"<<flush;

    BinaryStringGetRank1* binaryStringGetRank1 = new BinaryStringGetRank1(lookUpRank);
    BinaryStringGetLast1* binaryStringGetLast1 = new BinaryStringGetLast1(lookUpLast);

    binaryStringGetRank1 -> append(0);
    binaryStringGetRank1 -> append(0);
    cout<<binaryStringGetRank1 -> getRank1(2)<<endl;
    binaryStringGetRank1 -> append(1);
    cout<<binaryStringGetRank1 -> getRank1(3)<<endl;
    binaryStringGetRank1 -> append(1);
    cout<<binaryStringGetRank1 -> getRank1(3)<<endl;
    cout<<binaryStringGetRank1 -> getRank1(4)<<endl;
    binaryStringGetRank1 -> append(0);
    binaryStringGetRank1 -> append(1);
    binaryStringGetRank1 -> append(0);
    binaryStringGetRank1 -> append(1);

    binaryStringGetRank1 -> append(0);
    binaryStringGetRank1 -> append(1);
    binaryStringGetRank1 -> append(0);
    binaryStringGetRank1 -> append(1);

    binaryStringGetRank1 -> append(0);
    binaryStringGetRank1 -> append(1);
    binaryStringGetRank1 -> append(0);
    binaryStringGetRank1 -> append(1);

    binaryStringGetRank1 -> append(0);
    binaryStringGetRank1 -> append(1);
    binaryStringGetRank1 -> append(0);
    binaryStringGetRank1 -> append(1);

    cout<<binaryStringGetRank1 -> getRank1(17)<<endl;

    cout<<"done rank."<<endl<<flush;

    binaryStringGetLast1 -> append(0);
    binaryStringGetLast1 -> append(0);
    binaryStringGetLast1 -> append(1);
    binaryStringGetLast1 -> append(0);
    binaryStringGetLast1 -> append(0);

    cout<<binaryStringGetLast1 -> getLast1(5)<<endl;

    binaryStringGetLast1 -> append(0);
    binaryStringGetLast1 -> append(0);
    binaryStringGetLast1 -> append(0);
    binaryStringGetLast1 -> append(0);
    binaryStringGetLast1 -> append(0);
    cout<<binaryStringGetLast1 -> getLast1(10)<<endl;

    binaryStringGetLast1 -> append(0);
    binaryStringGetLast1 -> append(0);
    binaryStringGetLast1 -> append(1);
    binaryStringGetLast1 -> append(0);
    binaryStringGetLast1 -> append(0);
    cout<<binaryStringGetLast1 -> getLast1(15)<<endl;

    binaryStringGetLast1 -> append(0);
    binaryStringGetLast1 -> append(0);
    binaryStringGetLast1 -> append(1);
    binaryStringGetLast1 -> append(0);
    binaryStringGetLast1 -> append(0);

    cout<<binaryStringGetLast1 -> getLast1(17)<<endl;

    cout<<binaryStringGetLast1 -> getLast1(20)<<endl;

    cout<<"done last."<<endl<<flush;
    */



    auto start = std::chrono::high_resolution_clock::now();
    DataStructure1();

    // operation to be timed ...

    update(1);
    update(2);
    update(1);
    cout<<query(1,2)<<"\n"<<flush;
    cout<<query(1,3)<<"\n"<<flush;
    for (int i=1 ;i<=5000000; i++)
    {
        update(i%100);
    }
    cout<<query(1,5000000)<<"\n"<<flush;


    auto finish = std::chrono::high_resolution_clock::now();

    cout<<(chrono::duration_cast<chrono::milliseconds>(
              finish-start)
              .count() )<<"\n"<<flush;


    /*
    auto start = std::chrono::high_resolution_clock::now();

    // operation to be timed ...

    update(1);
    update(2);
    update(1);
    cout<<query(1,2)<<"\n"<<flush;
    cout<<query(1,3)<<"\n"<<flush;
    for (int i=1 ;i<=1000000; i++)
    {
        update(i%100);
    }
    cout<<query(1,1000000)<<"\n"<<flush;


    auto finish = std::chrono::high_resolution_clock::now();

    cout<<(chrono::duration_cast<chrono::milliseconds>(
              finish-start)
              .count() )<<"\n"<<flush;

    */
    return 0;
}
