BASEDIR=$(dirname "$0")
mkdir $BASEDIR/build
cmake -DCMAKE_BUILD_TYPE=DEBUG -S $BASEDIR -B $BASEDIR/build
make -C $BASEDIR/build
