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


