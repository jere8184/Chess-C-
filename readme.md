mkdir build
cd build
conan install ../conan/ --settings arch=x86
cmake ..
cmake --build .
