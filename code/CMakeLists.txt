cmake_minimum_required(VERSION 3.13)
project(toy_compiler)
include(CheckCXXCompilerFlag)

set(CMAKE_CXX_STANDARD 17)

find_package(LLVM REQUIRED CONFIG)

check_cxx_compiler_flag("-std=c++17" COMPILER_SUPPORTS_CXX17)
check_cxx_compiler_flag("-std=c++2a" COMPILER_SUPPORTS_CXX20)

message(STATUS "[INFO] Detected C/C++ Compiler: ${CMAKE_CXX_COMPILER}")
if(COMPILER_SUPPORTS_CXX20)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++2a")
    message(STATUS "[INFO] Your compiler is supported C++2a")
elseif(COMPILER_SUPPORTS_CXX17)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++17")
    message(STATUS "[INFO] Your compiler is supported C++17")
else()
    message(ERROR "[ERR!] Detected compiler has no C++17 or newer support.")
endif()

message(STATUS "[INFO] Found LLVM: LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "[INFO] Using LLVMConfig.cmake in: ${LLVM_DIR}")

set(LLVM_INCLUDE_PATH ${LLVM_INCLUDE_DIRS})
if(${LLVM_PACKAGE_VERSION} STREQUAL "7.0.1")
    add_definitions(-DLLVM_7)
    message(STATUS "[WARN] Macro 'LLVM_7' has been added to project")
    message(STATUS "[WARN] Because of Windows filesystem is incompatible with WSL, override default path")
    set(LLVM_INCLUDE_PATH /usr/include/llvm-7/;/usr/include/llvm-c-7/)
    message(STATUS "[INFO] Using 'llvm-7' as llvm include path")
else()
    message(STATUS "[INFO] Using default llvm include path")
    message(STATUS "[INFO] If you use WSL in Windows, then specify include path manually to avoid path error")
    message(STATUS "[INFO] Manually access '${LLVM_INCLUDE_DIRS}', and parse the link as include directories")
endif()

message(STATUS "[INFO] LLVM include path: ${LLVM_INCLUDE_PATH}")

aux_source_directory(${PROJECT_SOURCE_DIR}/src SOURCE_DIRS)
set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
file(GLOB HEADER_DIRS "${INCLUDE_PATH}/*.h")

include_directories(${LLVM_INCLUDE_PATH} ${INCLUDE_PATH})
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs support core irreader interpreter)
get_property(dirs DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)

add_executable(toy_compiler main.cpp ${SOURCE_DIRS} ${HEADER_DIRS})
target_link_libraries(toy_compiler ${llvm_libs})
