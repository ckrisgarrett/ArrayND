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
    Array1(
        size_t n1, 
        T *data = NULL) 
        : ArrayBase<T>(n1, data)
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
    Array2(
        size_t n1, size_t n2, 
        T *data = NULL) 
        : ArrayBase<T>(n1 * n2, data)
    {
        if (n1 < 1 || n2 < 1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        
        c_n1 = n1;  c_n2 = n2;
    }
    
    Array2(const ArrayBase<T> &that) = delete;
    Array2<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator()(const size_t n1, const size_t n2) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (n1 >= c_n1 || n2 >= c_n2) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return this->c_data[n2 + c_n2 * (n1)];
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
    Array3(
        size_t n1, size_t n2, size_t n3, 
        T *data = NULL) 
        : ArrayBase<T>(n1 * n2 * n3, data)
    {
        if (n1 < 1 || n2 < 1 || n3 < 1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        
        c_n1 = n1;  c_n2 = n2;  c_n3 = n3;
    }
    
    Array3(const ArrayBase<T> &that) = delete;
    Array3<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator()(const size_t n1, const size_t n2, const size_t n3) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (n1 >= c_n1 || n2 >= c_n2 || n3 >= c_n3) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return this->c_data[n3 + c_n3 * (n2 + c_n2 * (n1))];
    }
    
private:
    size_t c_n1, c_n2, c_n3;
};


////////////////////////////////////////////////////////////////////////////////
//                          Array4
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class Array4 final : public ArrayBase<T>
{
public:
    explicit
    Array4(
        size_t n1, size_t n2, size_t n3, size_t n4, 
        T *data = NULL) 
        : ArrayBase<T>(n1 * n2 * n3 * n4, data)
    {
        if (n1 < 1 || n2 < 1 || n3 < 1 || n4 < 1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        
        c_n1 = n1;  c_n2 = n2;  c_n3 = n3;  c_n4 = n4;
    }
    
    Array4(const ArrayBase<T> &that) = delete;
    Array4<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator()(const size_t n1, const size_t n2, const size_t n3, const size_t n4) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (n1 >= c_n1 || n2 >= c_n2 || n3 >= c_n3 || n4 >= c_n4) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return this->c_data[n4 + c_n4 * (n3 + c_n3 * (n2 + c_n2 * (n1)))];
    }
    
private:
    size_t c_n1, c_n2, c_n3, c_n4;
};


////////////////////////////////////////////////////////////////////////////////
//                          Array5
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class Array5 final : public ArrayBase<T>
{
public:
    explicit
    Array5(
        size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, 
        T *data = NULL) 
        : ArrayBase<T>(n1 * n2 * n3 * n4 * n5, data)
    {
        if (n1 < 1 || n2 < 1 || n3 < 1 || n4 < 1 || n5 < 1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        
        c_n1 = n1;  c_n2 = n2;  c_n3 = n3;  c_n4 = n4;  c_n5 = n5;
    }
    
    Array5(const ArrayBase<T> &that) = delete;
    Array5<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator()(const size_t n1, const size_t n2, const size_t n3, const size_t n4, const size_t n5) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (n1 >= c_n1 || n2 >= c_n2 || n3 >= c_n3 || n4 >= c_n4 || n5 >= c_n5) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return this->c_data[n5 + c_n5 * (n4 + c_n4 * (n3 + c_n3 * (n2 + c_n2 * (n1))))];
    }
    
private:
    size_t c_n1, c_n2, c_n3, c_n4, c_n5;
};


////////////////////////////////////////////////////////////////////////////////
//                          Array6
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class Array6 final : public ArrayBase<T>
{
public:
    explicit
    Array6(
        size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, 
        T *data = NULL) 
        : ArrayBase<T>(n1 * n2 * n3 * n4 * n5 * n6, data)
    {
        if (n1 < 1 || n2 < 1 || n3 < 1 || n4 < 1 || n5 < 1 || n6 < 1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        
        c_n1 = n1;  c_n2 = n2;  c_n3 = n3;  c_n4 = n4;  c_n5 = n5;  c_n6 = n6;
    }
    
    Array6(const ArrayBase<T> &that) = delete;
    Array6<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator()(const size_t n1, const size_t n2, const size_t n3, const size_t n4, const size_t n5, const size_t n6) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (n1 >= c_n1 || n2 >= c_n2 || n3 >= c_n3 || n4 >= c_n4 || n5 >= c_n5 || n6 >= c_n6) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return this->c_data[n6 + c_n6 * (n5 + c_n5 * (n4 + c_n4 * (n3 + c_n3 * (n2 + c_n2 * (n1)))))];
    }
    
private:
    size_t c_n1, c_n2, c_n3, c_n4, c_n5, c_n6;
};


////////////////////////////////////////////////////////////////////////////////
//                          Array7
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class Array7 final : public ArrayBase<T>
{
public:
    explicit
    Array7(
        size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, 
        T *data = NULL) 
        : ArrayBase<T>(n1 * n2 * n3 * n4 * n5 * n6 * n7, data)
    {
        if (n1 < 1 || n2 < 1 || n3 < 1 || n4 < 1 || n5 < 1 || n6 < 1 || n7 < 1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        
        c_n1 = n1;  c_n2 = n2;  c_n3 = n3;  c_n4 = n4;  c_n5 = n5;  c_n6 = n6;  c_n7 = n7;
    }
    
    Array7(const ArrayBase<T> &that) = delete;
    Array7<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator()(const size_t n1, const size_t n2, const size_t n3, const size_t n4, const size_t n5, const size_t n6, const size_t n7) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (n1 >= c_n1 || n2 >= c_n2 || n3 >= c_n3 || n4 >= c_n4 || n5 >= c_n5 || n6 >= c_n6 || n7 >= c_n7) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return this->c_data[n7 + c_n7 * (n6 + c_n6 * (n5 + c_n5 * (n4 + c_n4 * (n3 + c_n3 * (n2 + c_n2 * (n1))))))];
    }
    
private:
    size_t c_n1, c_n2, c_n3, c_n4, c_n5, c_n6, c_n7;
};


////////////////////////////////////////////////////////////////////////////////
//                          Array8
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class Array8 final : public ArrayBase<T>
{
public:
    explicit
    Array8(
        size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, 
        T *data = NULL) 
        : ArrayBase<T>(n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8, data)
    {
        if (n1 < 1 || n2 < 1 || n3 < 1 || n4 < 1 || n5 < 1 || n6 < 1 || n7 < 1 || n8 < 1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        
        c_n1 = n1;  c_n2 = n2;  c_n3 = n3;  c_n4 = n4;  c_n5 = n5;  c_n6 = n6;  c_n7 = n7;  c_n8 = n8;
    }
    
    Array8(const ArrayBase<T> &that) = delete;
    Array8<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator()(const size_t n1, const size_t n2, const size_t n3, const size_t n4, const size_t n5, const size_t n6, const size_t n7, const size_t n8) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (n1 >= c_n1 || n2 >= c_n2 || n3 >= c_n3 || n4 >= c_n4 || n5 >= c_n5 || n6 >= c_n6 || n7 >= c_n7 || n8 >= c_n8) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return this->c_data[n8 + c_n8 * (n7 + c_n7 * (n6 + c_n6 * (n5 + c_n5 * (n4 + c_n4 * (n3 + c_n3 * (n2 + c_n2 * (n1)))))))];
    }
    
private:
    size_t c_n1, c_n2, c_n3, c_n4, c_n5, c_n6, c_n7, c_n8;
};


////////////////////////////////////////////////////////////////////////////////
//                          Array9
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class Array9 final : public ArrayBase<T>
{
public:
    explicit
    Array9(
        size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9, 
        T *data = NULL) 
        : ArrayBase<T>(n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9, data)
    {
        if (n1 < 1 || n2 < 1 || n3 < 1 || n4 < 1 || n5 < 1 || n6 < 1 || n7 < 1 || n8 < 1 || n9 < 1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        
        c_n1 = n1;  c_n2 = n2;  c_n3 = n3;  c_n4 = n4;  c_n5 = n5;  c_n6 = n6;  c_n7 = n7;  c_n8 = n8;  c_n9 = n9;
    }
    
    Array9(const ArrayBase<T> &that) = delete;
    Array9<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator()(const size_t n1, const size_t n2, const size_t n3, const size_t n4, const size_t n5, const size_t n6, const size_t n7, const size_t n8, const size_t n9) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (n1 >= c_n1 || n2 >= c_n2 || n3 >= c_n3 || n4 >= c_n4 || n5 >= c_n5 || n6 >= c_n6 || n7 >= c_n7 || n8 >= c_n8 || n9 >= c_n9) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return this->c_data[n9 + c_n9 * (n8 + c_n8 * (n7 + c_n7 * (n6 + c_n6 * (n5 + c_n5 * (n4 + c_n4 * (n3 + c_n3 * (n2 + c_n2 * (n1))))))))];
    }
    
private:
    size_t c_n1, c_n2, c_n3, c_n4, c_n5, c_n6, c_n7, c_n8, c_n9;
};


////////////////////////////////////////////////////////////////////////////////
//                          Array10
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class Array10 final : public ArrayBase<T>
{
public:
    explicit
    Array10(
        size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6, size_t n7, size_t n8, size_t n9, size_t n10, 
        T *data = NULL) 
        : ArrayBase<T>(n1 * n2 * n3 * n4 * n5 * n6 * n7 * n8 * n9 * n10, data)
    {
        if (n1 < 1 || n2 < 1 || n3 < 1 || n4 < 1 || n5 < 1 || n6 < 1 || n7 < 1 || n8 < 1 || n9 < 1 || n10 < 1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        
        c_n1 = n1;  c_n2 = n2;  c_n3 = n3;  c_n4 = n4;  c_n5 = n5;  c_n6 = n6;  c_n7 = n7;  c_n8 = n8;  c_n9 = n9;  c_n10 = n10;
    }
    
    Array10(const ArrayBase<T> &that) = delete;
    Array10<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator()(const size_t n1, const size_t n2, const size_t n3, const size_t n4, const size_t n5, const size_t n6, const size_t n7, const size_t n8, const size_t n9, const size_t n10) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (n1 >= c_n1 || n2 >= c_n2 || n3 >= c_n3 || n4 >= c_n4 || n5 >= c_n5 || n6 >= c_n6 || n7 >= c_n7 || n8 >= c_n8 || n9 >= c_n9 || n10 >= c_n10) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return this->c_data[n10 + c_n10 * (n9 + c_n9 * (n8 + c_n8 * (n7 + c_n7 * (n6 + c_n6 * (n5 + c_n5 * (n4 + c_n4 * (n3 + c_n3 * (n2 + c_n2 * (n1)))))))))];
    }
    
private:
    size_t c_n1, c_n2, c_n3, c_n4, c_n5, c_n6, c_n7, c_n8, c_n9, c_n10;
};


} // End namespace

#endif



