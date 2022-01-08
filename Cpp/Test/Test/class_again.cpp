#include<iostream>
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

    class arraylist
    {
        public:
            int size;
            int pre_size;
            int *point;
        public:
            arraylist(){size=0;pre_size=0;point=NULL;}
            arraylist(int s){size=s;pre_size=0;point=new int[size];}
            arraylist(arraylist &array)
            {
                size=array.size;
                pre_size=array.pre_size;
                point=new int[size];
                for(int i=0;i<pre_size;i++)
                {
                    point[i]=array.point[i];
                }
            }
            ~arraylist(){delete[] point;size=0;}
            int insert(int num)
            {
                point[pre_size]=num;
                pre_size++;
                return 1;
            }
    };

    arraylist arr(10);

    arraylist inse()
    {
        arr.insert(3);
        return arr;
    }

    void print(arraylist arr)
    {
        cout<<arr.point[0];
    }

#ifdef __cplusplus
}  // end extern "C"
#endif