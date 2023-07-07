# CMakeList.txt: Cpp2Py 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

set(CORE "src/core")
set(DEP	 "src/dep")
set(MOD  "src/modules")

project ("Cpp2Py_Build")

# pybind11
add_subdirectory("${DEP}/pybind")

# module
pybind11_add_module (
    TestModule 
    "${MOD}/Test.cpp"
    "${MOD}/Test.h"
)

target_include_directories (
    TestModule 
    PRIVATE "${MOD}"
)

# 将源代码添加到此项目的可执行文件。
add_executable (
    Cpp2Py 
    "${CORE}/Cpp2Py.cpp" 
    "${CORE}/Cpp2Py.h"
)

target_include_directories (
    Cpp2Py 
    PRIVATE ${CORE}
    PRIVATE ${MOD}
)

target_link_libraries(
    Cpp2Py
    PRIVATE pybind11::embed
)

# TODO: 如有需要，请添加测试并安装目标。
