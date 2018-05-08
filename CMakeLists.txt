project(xxLib)
cmake_minimum_required(VERSION 2.8)

## this is required
#SET(CMAKE_SYSTEM_NAME Linux)

## specify the cross compiler
#SET(CMAKE_C_COMPILER   /opt/arm/usr/bin/ppc_74xx-gcc)
#SET(CMAKE_CXX_COMPILER /opt/arm/usr/bin/ppc_74xx-g++)

## where is the target environment
#SET(CMAKE_FIND_ROOT_PATH  /opt/arm/ppc_74xx /home/rickk/arm_inst)

## search for programs in the build host directories (not necessary)
#SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
## for libraries and headers in the target directories
#SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

## configure Boost and Qt
#SET(QT_QMAKE_EXECUTABLE /opt/qt-embedded/qmake)
#SET(BOOST_ROOT /opt/boost_arm)


SET(CMAKE_BUILD_TYPE "Debug")

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib-debug)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin-debug)
else()
    SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib-release)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin-release)
endif()


aux_source_directory(./Common SOURCE_FILES)
aux_source_directory(./Exception SOURCE_FILES)


INCLUDE_DIRECTORIES(./Algorithm
                     ./Array
                     ./Graph
                     ./List
                     ./Queue
                     ./Smartpointer
                     ./Stack
                     ./String
                     ./Tree
                     ./Common
                     ./Exception
                    )


set(CXX_FLAGS
 -g
 -Wall
 -Wextra
 -Werror
 -Wconversion
 -Wno-unused-parameter
 -Wold-style-cast
 -Woverloaded-virtual
 -Wpointer-arith
 -Wshadow
 -Wwrite-strings
 -march=native
 -MMD
 -rdynamic
 -D_GLIBCXX_USE_CXX11_ABI=0
 )

if(CMAKE_BUILD_BITS EQUAL 32)
  list(APPEND CXX_FLAGS "-m32")
endif()
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")

add_library(xxlib ${SOURCE_FILES})

add_subdirectory(test)
