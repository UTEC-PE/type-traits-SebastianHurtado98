cmake_minimum_required(VERSION 3.12)
project(type_traits_develop)

set(CMAKE_CXX_STANDARD 14)

add_executable(type_traits_develop main.cpp dlist.h slist.h iterator.h node.h)