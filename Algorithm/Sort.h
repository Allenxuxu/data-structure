#ifndef SORT_H
#define SORT_H

#include "Object.h"
namespace XXLib
{
class Sort : public Object
{
private:
    Sort();
    Sort(const Sort&);
    Sort& operator = (const Sort&);

    template <typename T>
    static void Swap(T& a,T& b)
    {
        T tmp(a);
        a = b;
        b = tmp;
    }
    template <typename T>
    static void Merge(T src[], T helper[],int begin,int mid, int end, bool min2max)
    {
        int i = begin;
        int j = mid+1;
        int k = begin;  //辅助空间起始位置

        while((  i <= mid  ) && (j <= end))
        {
            if( (min2max) ? (src[i] < src[j] ): (src[i] > src[j]))
            {
                helper[k++] = src[i++];
            }
            else
            {
                helper[k++] = src[j++];
            }
        }

        while (i <= mid)
        {
            helper[k++] = src[i++];
        }

        while(j <= end)
        {
            helper[k++] = src[j++];
        }

        for(i=begin; i<= end; i++)
        {
            src[i] = helper[i];
        }

    }

    template <typename T>
    static void Merge(T src[], T helper[], int begin,int end, bool min2max = true)
    {
        if (begin < end)
        {
            int mid = (begin + end) / 2;
            Merge(src, helper, begin, mid, min2max);
            Merge(src, helper, mid+1, end, min2max);

            Merge(src, helper, begin, mid, end, min2max);

        }
    }

    template <typename T>
    static int  Partition(T array[], int begin, int end, bool min2max)
    {
        T pv = array[begin];
        while(begin < end)
        {
            while( (begin < end)&&( min2max ?  ( pv <  array[end]) : (pv > array[end])) )
            {
                end--;
            }

            Swap(array[begin], array[end]);

            while( (begin < end)&& (min2max ? (pv >= array[begin]) : ( pv <= array[begin]) ))
            {
                begin++;
            }

            Swap( array[begin],array[end]);
        }

        array[begin] = pv;
        return begin;
    }

    template <typename T>
    static void Quick(T array[], int begin,int end, bool min2max)
    {
        if( begin < end)
        {
            int pivot = Partition(array,begin ,end, min2max);
            Quick(array, begin,        pivot-1, min2max);
            Quick(array, pivot+1, end,   min2max);
        }
    }

public:
    template <typename T>       //O(n^2)
    static void Select(T array[] , int len, bool min2max=true )
    {
        for(int i = 0; i < len; i++)
        {
            int min = i;
            for(int j = i+1; j < len; j++)
            {
                if ( min2max ? ( array[min] > array[j] ) : ( array[min] < array[j] ))
                {
                    min = j;
                }
            }
            if( min != i )
                Swap(array[min],array[i]);
        }
    }

    template <typename T>       //O(n^2)
    static void Insert(T array[], int len, bool min2max =true)
    {
        for( int i =1; i < len; i++)
        {
            int k =i;               //k 为当前位置
            T tmp = array[i];
            for( int j = i-1; (j >=0)  && (min2max ? ( tmp < array[j] ) : ( tmp > array[j] )) ; j--)
            {
                array[j+1] = array[j];              //后移
                k=j;
            }
            if( k != i )
                array[k] = tmp;
        }
    }

    template <typename T>    //O(n^2)
    static void Bubble(T array[], int len, bool min2max = true)
    {
        bool isexchanged = false;
        for( int i=1; i<=len; i++)
        {
            for( int j=len -1; j>=i; j--)
            {
                if(min2max ? ( array[j]  <  array[j-1]) : (array[j] > array[i-1]))
                {
                    isexchanged = true;
                    Swap(array[j], array[j-1]);
                }
            }
            if (isexchanged == false)
                return;
        }
    }

    template < typename T>    //O(n^(3/2))
    static void Shell(T array[], int len , bool min2max = true)
    {
        int d = len;
        do
        {
            d = d / 3+1;

            for(int i=d; i<len; i++)   //分组后使用插入排序
            {
                int k =i;               //k 为当前位置
                T tmp = array[i];
                for( int j = i-d; (j >=0)  && (min2max ? ( tmp < array[j] ) : ( tmp > array[j] )) ; j-=d)
                {
                    array[j+d] = array[j];              //后移
                    k=j;
                }
                if( k != i )
                    array[k] = tmp;
            }
        }while( d > 1);
    }

    template <typename T>       //O(n*logn)
    static void Merge(T array[], int len, bool min2max = true)
    {
        T* helper  = new  T[len];

        if(helper != NULL)
            Merge(array, helper,0,len-1,min2max);

        delete[] helper;
    }

    template < typename T>      //O(n*logn)
    static void Quick (T array[], int len, bool min2max =true)
    {
       Quick(array,0, len-1, min2max);
    }
};

template <typename T>
class Proxy
{
    T* m_proxy;
public:
    T& originalObj() const
    {
        return *m_proxy;
    }

    bool operator < (const Proxy& obj)
    {
        return  originalObj() < obj.originalObj();
    }
    bool operator <= (const Proxy& obj)
    {
        return  originalObj() <= obj.originalObj();
    }
    bool operator > (const Proxy& obj)
    {
        return  originalObj() > obj.originalObj();
    }
    bool operator >= (const Proxy& obj)
    {
        return  originalObj() >= obj.originalObj();
    }

    T& operator = ( T& obj)
    {
        m_proxy = &obj;
        return obj;
    }
};


//Test t[10000];
//Proxy<Test> pt[10000];
//int main(void)
//{
//    clock_t begin =0;
//    clock_t end = 0;

//    for(int i=0 ; i< 10000; i++)
//    {
//        t[i] = i;
//        pt[i] = t[i];
//    }

//    begin = clock();
//    Sort::Merge (pt,10000,false);
//    end = clock();

//    cout <<"time  " <<  (end - begin);

//    return 0;
//}

}
#endif // SORT_H
