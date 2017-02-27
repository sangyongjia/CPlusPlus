#include"./Singleton.h"
#include<iostream>
#include<thread>
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
int main()
{
    //Me* p[10]={NULL};
    //Me* p=test::Singleton<Me>::get();
    //p->Say();

    //thread t(hello);
    //t.join();

    thread first(&test::Singleton<Me>::get);
    thread second(&test::Singleton<Me>::get);
    thread third(&test::Singleton<Me>::get);

    first.join();
    second.join();
    third.join();
    //thread t(hello);
    //t.join();
    /*
    for(int i=0;i<10;i++)
    {
        p[i]=test::Singleton<Me>::get();
        std::cout<<p[i]<<std::endl;
    }
    for(int j=0;j<10;j++)
    {
        if(p[j]==NULL)
            std::cout<<"NULL ptr"<<std::endl;
        else
            p[j]->Say();
    }
    */
    return 0;
}
            
