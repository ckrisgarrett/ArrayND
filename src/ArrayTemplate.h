////////////////////////////////////////////////////////////////////////////////
//                          Array__DIM
////////////////////////////////////////////////////////////////////////////////
template<typename T>
class Array__DIM final : public ArrayBase<T>
{
public:
    explicit
    Array__DIM(
        __PARAMS1, 
        T *data = NULL) 
        : ArrayBase<T>(__MULT, data)
    {
        if (__CHECK1) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        
        __EQUALS
    }
    
    Array__DIM(const ArrayBase<T> &that) = delete;
    Array__DIM<T>& operator=(const ArrayBase<T> &that) = delete;
    
    inline
    T& operator()(__PARAMS2) const
    {
        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS
        if (__CHECK2) {
            printf("Array out of bounds error\n");
            throw -1;
        }
        #endif
        return this->c_data[__INDEX];
    }
    
private:
    __PRIVATE
};


