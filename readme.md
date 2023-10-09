python -m venv ./venv
.\venv\Scripts\activate
pip install conan
mkdir build
cd build
conan install ../conan/ --build=missing -s build_type=Debug
cmake ..
cmake --build .
