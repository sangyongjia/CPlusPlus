#include<assert.h>
#include<cstddef>
#include<iostream>
void *memcpy(void* dst,const void *src,size_t num)
{   
    assert((dst!=NULL)&&(src!=NULL));
    size_t word_num = num/sizeof(long);
    size_t slice = num%sizeof(long);
    if((src<dst)&&((char*)src+num > (char*)dst))//对应于情况3
    {   
        if(word_num>0)                              //要拷贝的空间大于等于一个long的情况！
        {   
            long *psrc = (long*)((char*)src+num-sizeof(long));
            long *pdst = (long*)((char*)dst+num-sizeof(long));
            while(word_num--)
                *pdst-- = *psrc--;
            while(slice--)
                *((char*)pdst--) = *((char*)psrc--);
        }
        else                                        //要拷贝的空间小于一个long的情况！
        {   
            char *psrc = (char*)src+num-1;
            char *pdst = (char*)dst+num-1;
            while(slice--)
                *((char*)pdst--) = *((char*)psrc--);
        }
    }
    else                                        //对应于情况1,2,4
    {   
        long *pdst = (long*)dst;
        long *psrc = (long*)src;
        while(word_num--)
            *pdst++ = *psrc++;
        while(slice--)
            *((char*)pdst++) = *((char*)psrc++);
    }
    return dst;
}

int main()
{
    char src[101]="1234567890";
    char dst[101];
    memcpy(dst,src,10);
    for(int i=0;i<101;i++)
    {
        std::cout<<src[i]<<" ";
    }
}
