#include"./Singleton.h"
#include<iostream>
#include<thread>

#include<sys/time.h>
using namespace std;

class Me
{
public:
    void Say()
    {
        std::cout<<"Hello Word"<<std::endl;
    }
};
void hello()
{
    while(true)
    {
        cout<<"he"<<endl;
    }
}
#define N 10000
int main()
{
    //Me* p[10]={NULL};
    //Me* p=test::Singleton<Me>::get();
    //p->Say();

    //thread t(hello);
    //t.join();
    struct timeval start,end;
    gettimeofday(&start,NULL);
    thread pool[N];
    for(int i=0;i<N;i++)
    {
        pool[i]=thread(&test::Singleton<Me>::get);
    }
    for(int i=0;i<N;i++)
    {
        pool[i].join();
       }
    gettimeofday(&end,NULL);
    std::cout<<std::endl;
    std::cout<<"total time:"<<double((end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec))<<std::endl; 
    return 0;
}
