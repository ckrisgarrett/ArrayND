import os


#def arrayString(dim):
#    classname = "Array" + str(dim)
#    
#    
#    # Header
#    string = \
#    "////////////////////////////////////////////////////////////////////////////////\n"
#    string = string + \
#    "//                          " + classname + "\n"
#    string = string + \
#    "////////////////////////////////////////////////////////////////////////////////\n"
#    
#    
#    # Class beginning
#    string = string + \
#    "template<typename T>\n" \
#    "class " + classname + " final : public ArrayBase<T>\n" \
#    "{\n" \
#    "public:\n"
#    
#    
#    # Constructor
#    string = string + \
#    "    explicit\n" \
#    "    " + classname + "(size_t n1,\n"
#    for k in range(2, dim+1):
#        string = string + \
#        "           size_t n" + k + ",\n"
#    string = string + \
#    "           T *data = NULL) : ArrayBase<T>(n1 * n2 * n3, data)\n" \
#    "    {\n" \
#    "        if (n1 < 1 || n2 < 1 || n3 < 1) {\n" \
#    "            printf(\"Array out of bounds error\n\");\n" \
#    "            throw -1;\n" \
#    "        }\n" \
#    "        \n" \
#    "        c_n1 = n1;\n" \
#    "        c_n2 = n2;\n" \
#    "        c_n3 = n3;\n" \
#    "    }\n" \
#    "    \n" \
#    "    Array3(const ArrayBase<T> &that) = delete;\n" \
#    "    Array3<T>& operator=(const ArrayBase<T> &that) = delete;\n" \
#    "    \n" \
#    "    inline\n" \
#    "    T& operator()(const size_t n1, \n" \
#    "                  const size_t n2, \n" \
#    "                  const size_t n3) const\n" \
#    "    {\n" \
#    "        #ifdef CKG_UTILS_ARRAY_CHECK_BOUNDS\n" \
#    "        if (n1 >= c_n1 || n2 >= c_n2 || n3 >= c_n3) {\n" \
#    "            printf(\"Array out of bounds error\n\");\n" \
#    "            throw -1;\n" \
#    "        }\n" \
#    "        #endif\n" \
#    "        return this->c_data[n3 + c_n3 * (n2 + c_n2 * n1)];\n" \
#    "    }\n" \
#    "    \n" \
#    "private:\n" \
#    "    size_t c_n1, c_n2, c_n3;\n" \
#    "};\n\n\n"
#    return string

def params1(dim):
    ret = "size_t n1"
    for k in range(2, dim+1):
        ret = ret + ", size_t n" + str(k)
    return ret

def mult(dim):
    ret = "n1"
    for k in range(2, dim+1):
        ret = ret + " * n" + str(k)
    return ret

def check1(dim):
    ret = "n1 < 1"
    for k in range(2, dim+1):
        ret = ret + " || n" + str(k) + " < 1"
    return ret

def equals(dim):
    ret = "c_n1 = n1;"
    for k in range(2, dim+1):
        ret = ret + "  c_n" + str(k) + " = n" + str(k) + ";"
    return ret

def params2(dim):
    ret = "const size_t n1"
    for k in range(2, dim+1):
        ret = ret + ", const size_t n" + str(k)
    return ret

def check2(dim):
    ret = "n1 >= c_n1"
    for k in range(2, dim+1):
        ret = ret + " || n" + str(k) + " >= c_n" + str(k)
    return ret

def index(dim):
    numParen = 0
    ret = ""
    for k in range(dim,1,-1):
        ret = ret + "n" + str(k) + " + c_n" + str(k) + " * ("
        numParen = numParen + 1 
    ret = ret + "n1"
    for k in range(0, numParen):
        ret = ret + ")"
    return ret

def private(dim):
    ret = "size_t c_n1"
    for k in range(2, dim+1):
        ret = ret + ", c_n" + str(k)
    ret = ret + ";"
    return ret


os.system("cp ArrayBegin.h Array_new.h")
arrayFile = open("Array_new.h", "a")
for dim in range(1,11):
    dimString = str(dim)
    os.system("cp ArrayTemplate.h ArrayTemplate1.h")
    os.system("sed -i 's/__DIM/" + str(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__PARAMS1/" + params1(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__MULT/" + mult(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__CHECK1/" + check1(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__EQUALS/" + equals(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__PARAMS2/" + params2(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__CHECK2/" + check2(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__INDEX/" + index(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__PRIVATE/" + private(dim) + "/' ArrayTemplate1.h")
    os.system("cat ArrayTemplate1.h >> Array_new.h")
    #arrayFile.write(arrayString(dim))
arrayFile.close()
os.system("cat ArrayEnd.h >> Array_new.h")




