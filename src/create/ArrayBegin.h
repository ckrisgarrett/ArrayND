#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <cstddef>
#include <cstdio>

namespace CKG_Utils {


////////////////////////////////////////////////////////////////////////////////
//                          ArrayBase
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class ArrayBase
{
public:
    ~ArrayBase()
    {
        if (c_ownData && c_data != NULL)
            delete[] c_data;
    }
    
    ArrayBase(const ArrayBase<T> &that) = delete;
    ArrayBase<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator[](const size_t n) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (n >= c_n) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return c_data[n];
    }
    
protected:
    explicit
    ArrayBase(const size_t n, T *data = NULL)
    {
        c_n = n;
        if (data == NULL) {
            c_ownData = true;
            c_data = new T[n];
        }
        else {
            c_ownData = false;
            c_data = data;
        }
    }
    
    size_t c_n;
    bool c_ownData;
    T *c_data;
};



