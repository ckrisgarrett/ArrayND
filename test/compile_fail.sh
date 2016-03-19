SRC="-I../src"
CFLAGS="-Wall --std=c++11"

echo " "
echo "*************************************************************************"
echo "    Should see compile fail because no copy constructor is allowed."
echo "*************************************************************************"
echo " "
g++ $CFLAGS $SRC MainCompileFail1.cpp -o test2.x


echo " "
echo "*************************************************************************"
echo "    Should see compile fail because operator= is not allowed."
echo "*************************************************************************"
echo " "
g++ $CFLAGS $SRC MainCompileFail2.cpp -o test3.x
