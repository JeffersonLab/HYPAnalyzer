# Software for Hypernuclear experiment in Hall C

cmake_minimum_required(VERSION 3.5)

project(HYPlib LANGUAGES CXX)

# Podd
#find_package(Podd 1.7 REQUIRED)
#include(PoddCMakeEnv)

if(NOT TARGET hcana:HallC)
  if(DEFINED EVN{HCANA})
    set(CMAKE_PREFIX_PATH "$ENV{HCANA}" "${CMAKE_PREFIX_PATH}")
  endif()

  find_package(hcana 0.95 REQUIRED)
endif()

include(PoddCMakeEnv)

set_diagnostic_flags(WALL WEXTRA)

add_subdirectory(src)
