# List of contents
1. Binary search tree(BST)
# Build library from source
## On Linux/Unix
1. Clone the repo
```
git clone https://github.com/Naakinn/BinTrees
```
2. Specify your own installation paths in `CMakeLists.txt`, or use default ones(skip this step)
```
set(CMAKE_INSTALL_PREFIX <where-place-library-directory-and-header-directory>)
...
install(
    TARGETS bintrees
    LIBRARY DESTINATION <library-directory> # Placed in  CMAKE_INSTALL_PREFIX  directory
    PUBLIC_HEADER DESTINATION <header-directory> # Placed in  CMAKE_INSTALL_PREFIX  directory
)
```
3. Build the library
```
cmake -B_builds/shared -DBUILD_SHARED_LIBS=ON
sudo cmake --build _builds/shared --target install
```
# Or install library from releases 
1. Downloand `tar.gz` archive
2. Extract archive
```
tar -xvzf <archive-name>
```
