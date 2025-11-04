# Software for Hypernuclear experiment in Hall C

cmake_minimum_required(VERSION 3.5)

project(HYPlib LANGUAGES CXX)

# Podd
if(NOT TARGET Podd::HallA)
  if(DEFINED ENV{ANALYZER})
    set(CMAKE_PREFIX_PATH "$ENV{ANALYZER}" "${CMAKE_PREFIX_PATH}")
  endif()

  find_package(Podd 1.7 REQUIRED)
endif()
include(PoddCMakeEnv)

set_diagnostic_flags(WALL WEXTRA)

add_subdirectory(src)
