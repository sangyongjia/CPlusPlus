#ifndef SINGLETON_H
#define SINGLETON_H
//template <typename T>
#include<stddef.h>
#include<iostream>
#include<mutex>
using namespace std;
namespace test
{
//std::mutex g_mutex;
template <typename T>
class Singleton
{
public:
    static T* get()
    {

        if(0==__sync_val_compare_and_swap(&m_flag_,0,1))
        {
            //g_mutex.lock();
            if(m_instance_==NULL)
            {
            //std::cout<<"get"<<std::endl;
                m_instance_=new T();
                std::cout<<"ptra:"<<m_instance_<<std::endl;
            }
            //g_mutex.unlock();
        }
        std::cout<<"already-1:"<<m_instance_<<std::endl;
        return m_instance_;
    }

private:
    Singleton(){}
    static int m_flag_;
    static T* m_instance_;
};
template<typename T>
T* Singleton<T>::m_instance_=NULL;
template<typename T>
int Singleton<T>::m_flag_=0;
}
#endif
