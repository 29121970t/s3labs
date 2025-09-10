BASEDIR=$(dirname "$0")
mkdir $BASEDIR/build
cmake -S $BASEDIR -B $BASEDIR/build
cmake --build $BASEDIR/build -j $(grep -c ^processor /proc/cpuinfo)
for arg in "$@"; do
    if [ "$arg" = "-w" ]; then 
        mkdir $BASEDIR/buildW
        cmake -DCMAKE_BUILD_TYPE=DEBUG -DCMAKE_TOOLCHAIN_FILE=./cmake/TWin.cmake -S $BASEDIR -B $BASEDIR/buildW
        cmake --build $BASEDIR/buildW -j $(grep -c ^processor /proc/cpuinfo)
    fi;
done

