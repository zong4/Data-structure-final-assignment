#include<iostream>
using namespace std;


#ifdef __cplusplus
extern "C" {
#endif

    class arraylist
    {
        public:
            int size;
            int *array;
        public:
            arraylist()
            {
                size=0;
                array=NULL;
            }
            arraylist(int s)
            {
                size=s;
                array=new int[size];
            }
            void insert(int loc,int num)
            {
                array[loc-1]=num;
            }
            friend arraylist init();
    };
    arraylist arr(6);
    int inse()
    {
        arr.insert(1,3);
        return arr.array[0];
    }
    int hello()
    {
        return 1;
    }

#ifdef __cplusplus
}  // end extern "C"
#endif