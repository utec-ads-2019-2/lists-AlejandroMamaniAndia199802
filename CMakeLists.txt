cmake_minimum_required(VERSION 3.13.4)
project(lists-AlejandroMamaniAndia199802)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)



add_executable(lists-AlejandroMamaniAndia199802 mocker.h mocker.cpp forward.h iterator.h linked.h list.h node.h main.cpp tester.cpp tester.h)