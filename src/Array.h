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


////////////////////////////////////////////////////////////////////////////////
//                          Array1
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class Array1 final : public ArrayBase<T>
{
public:
    explicit
    Array1(size_t n1, 
           T *data = NULL) : ArrayBase<T>(n1, data)
    {
        if (n1 < 1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        
        c_n1 = n1;
    }
    
    Array1(const ArrayBase<T> &that) = delete;
    Array1<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator()(const size_t n1) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (n1 >= c_n1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return this->c_data[n1];
    }
    
private:
    size_t c_n1;
};


////////////////////////////////////////////////////////////////////////////////
//                          Array2
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class Array2 final : public ArrayBase<T>
{
public:
    explicit
    Array2(size_t n1,
           size_t n2, 
           T *data = NULL) : ArrayBase<T>(n1 * n2, data)
    {
        if (n1 < 1 || n2 < 1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        
        c_n1 = n1;
        c_n2 = n2;
    }
    
    Array2(const ArrayBase<T> &that) = delete;
    Array2<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator()(const size_t n1, 
                  const size_t n2) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (n1 >= c_n1 || n2 >= c_n2) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return this->c_data[n2 + c_n2 * n1];
    }
    
private:
    size_t c_n1, c_n2;
};


////////////////////////////////////////////////////////////////////////////////
//                          Array3
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class Array3 final : public ArrayBase<T>
{
public:
    explicit
    Array3(size_t n1,
           size_t n2, 
           size_t n3, 
           T *data = NULL) : ArrayBase<T>(n1 * n2 * n3, data)
    {
        if (n1 < 1 || n2 < 1 || n3 < 1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        
        c_n1 = n1;
        c_n2 = n2;
        c_n3 = n3;
    }
    
    Array3(const ArrayBase<T> &that) = delete;
    Array3<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator()(const size_t n1, 
                  const size_t n2, 
                  const size_t n3) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (n1 >= c_n1 || n2 >= c_n2 || n3 >= c_n3) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return this->c_data[n3 + c_n3 * (n2 + c_n2 * n1)];
    }
    
private:
    size_t c_n1, c_n2, c_n3;
};

} // End namespace

#endif



