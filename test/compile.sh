SRC="-I../src"
CFLAGS="-Wall --std=c++11"
TEST_SRC="test1.cpp"


# Compile normal tests
g++ $CFLAGS $SRC Main.cpp $TEST_SRC -o test.x
