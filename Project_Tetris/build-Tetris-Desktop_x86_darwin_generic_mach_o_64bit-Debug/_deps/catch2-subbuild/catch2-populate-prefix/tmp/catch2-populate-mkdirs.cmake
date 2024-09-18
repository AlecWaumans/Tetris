# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/alecwaumans/Desktop/tetris-master/Project_Tetris/build-Tetris-Desktop_x86_darwin_generic_mach_o_64bit-Debug/_deps/catch2-src"
  "/Users/alecwaumans/Desktop/tetris-master/Project_Tetris/build-Tetris-Desktop_x86_darwin_generic_mach_o_64bit-Debug/_deps/catch2-build"
  "/Users/alecwaumans/Desktop/tetris-master/Project_Tetris/build-Tetris-Desktop_x86_darwin_generic_mach_o_64bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix"
  "/Users/alecwaumans/Desktop/tetris-master/Project_Tetris/build-Tetris-Desktop_x86_darwin_generic_mach_o_64bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/tmp"
  "/Users/alecwaumans/Desktop/tetris-master/Project_Tetris/build-Tetris-Desktop_x86_darwin_generic_mach_o_64bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
  "/Users/alecwaumans/Desktop/tetris-master/Project_Tetris/build-Tetris-Desktop_x86_darwin_generic_mach_o_64bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src"
  "/Users/alecwaumans/Desktop/tetris-master/Project_Tetris/build-Tetris-Desktop_x86_darwin_generic_mach_o_64bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/alecwaumans/Desktop/tetris-master/Project_Tetris/build-Tetris-Desktop_x86_darwin_generic_mach_o_64bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/alecwaumans/Desktop/tetris-master/Project_Tetris/build-Tetris-Desktop_x86_darwin_generic_mach_o_64bit-Debug/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
