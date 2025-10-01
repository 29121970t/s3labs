BASEDIR=$(dirname "$0")

for arg in $@
do
    if [ "$arg" = "-g" ]; then
        args+="-DCMAKE_BUILD_TYPE=DEBUG"
    fi
    if [ "$arg" = "-t" ]; then
        args+="-DBUILD_TESTS=ON "
    fi
    if [ "$arg" = "-w" ]; then
        mkdir $BASEDIR/buildW
        cmake $args -DCMAKE_TOOLCHAIN_FILE=./cmake/TWin.cmake -S $BASEDIR -B $BASEDIR/buildW -G Ninja
        cmake --build $BASEDIR/buildW --parallel 16
    fi
done
mkdir $BASEDIR/build
cmake $args -DCMAKE_BUILD_TYPE=DEBUG -S $BASEDIR -B $BASEDIR/build -G Ninja
cmake --build $BASEDIR/build -j 16
