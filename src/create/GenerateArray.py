import os


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

def getdims(dim):
    ret = "dims[0] = c_n1;"
    for k in range(1, dim):
        ret = ret + " dims[" + str(k) + "] = c_n" + str(k+1) + ";"
    return ret


os.system("cp ArrayBegin.h Array1.h")
arrayFile = open("Array1.h", "a")
for dim in range(1,11):
    dimString = str(dim)
    os.system("cp ArrayTemplate.h ArrayTemplate1.h")
    os.system("sed -i 's/__DIM/" + str(dim) + "/' ArrayTemplate1.h")
    # Need to replace __DIM twice in a line
    os.system("sed -i 's/__DIM/" + str(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__PARAMS1/" + params1(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__MULT/" + mult(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__CHECK1/" + check1(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__EQUALS/" + equals(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__PARAMS2/" + params2(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__CHECK2/" + check2(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__INDEX/" + index(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__PRIVATE/" + private(dim) + "/' ArrayTemplate1.h")
    os.system("sed -i 's/__GETDIMS/" + getdims(dim) + "/' ArrayTemplate1.h")
    os.system("cat ArrayTemplate1.h >> Array1.h")
arrayFile.close()


os.system("cat ArrayEnd.h >> Array1.h")
os.system("rm ArrayTemplate1.h")
os.system("mv Array1.h ../Array.h")




