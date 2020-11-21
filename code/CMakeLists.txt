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

aux_source_directory(${PROJECT_SOURCE_DIR}/src SOURCE_DIRS)
set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
file(GLOB HEADER_DIRS "${INCLUDE_PATH}/*.h")

include_directories(${LLVM_INCLUDE_DIRS} ${INCLUDE_PATH})
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs support core irreader interpreter)

add_executable(toy_compiler main.cpp ${SOURCE_DIRS} ${HEADER_DIRS})
target_link_libraries(toy_compiler ${llvm_libs})
