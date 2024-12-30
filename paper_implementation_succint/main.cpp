#include<bits/stdc++.h>
//#include"dataStructure1.cpp"
//#include"dataStructure2.cpp"
#include"succintDataStructure1.cpp"
#include <sys/resource.h>
using namespace std;

long get_mem_usage()
{
    struct rusage usage;
    int ret;
    ret = getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss; // in KB
}


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
    cout<<"playing succint\n";
    int init = (float)get_mem_usage();
    cout<<(float)get_mem_usage()<<"\n";

    update(1);
    update(2);
    update(1);
    cout<<query(1,2).second<<"\n"<<flush;
    cout<<query(1,3).second<<"\n"<<flush;

    cout<<(float)get_mem_usage()<<"\n";
    for (int i=1 ;i<=10000000; i++)
    {
        //cout<<i<<"\n";
        update(i%100);
        if (i%10000==0)
        {
            cout<<i<<" appended \n";
            cout<<query(1, i).second<<" result: \n";
            cout<<((float)get_mem_usage()-init)/((float)i)<<"\n";
        }
    }
    cout<<query(1,10000000).second<<"\n"<<flush;


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
