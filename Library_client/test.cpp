#include<iostream>

#ifdef __cplusplus
extern "C" {
#endif

    using namespace std;

    int plus(int a,int b)
    {
        return a+b;
    }

    int decline(int a,int b)
    {
        return a-b;
    }

#ifdef __cplusplus
}  // end extern "C"
#endif