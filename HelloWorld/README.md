# Welcome
Get started with C++ with CMake.

## Usage
```
rm -rf cmake-build-debug
./build.sh
./start.sh
```

## Application
Provide REST API.
http://pistache.io/


## Build
Build project with link, deps.

### CMake
https://cmake.org/examples/

* Dependency ExternalProject_Add

```
ExternalProject_Add(
    Library1
    GIT_REPOSITORY https://git@gitlab.yourdomain.com/repo/library_1.git
    GIT_TAG tag_S.33.91
    HTTP_USERNAME ciserv
    HTTP_PASSWORD Obfusc@t3M3
    CMAKE_ARGS
        -DBUILD_EXAMPLES:BOOL=OFF
        -DBUILD_TESTS:BOOL=OFF
        -DBUILD_DOCS:BOOL=OFF
)
target_link_libraries(MyTarget PRIVATE Library1)
```

## Package Module



