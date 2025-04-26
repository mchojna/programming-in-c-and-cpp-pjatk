# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C10/PJC_C10_zadanie_1/cmake-build-debug/_deps/sfml-src"
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C10/PJC_C10_zadanie_1/cmake-build-debug/_deps/sfml-build"
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C10/PJC_C10_zadanie_1/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix"
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C10/PJC_C10_zadanie_1/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C10/PJC_C10_zadanie_1/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C10/PJC_C10_zadanie_1/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C10/PJC_C10_zadanie_1/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C10/PJC_C10_zadanie_1/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C10/PJC_C10_zadanie_1/cmake-build-debug/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
