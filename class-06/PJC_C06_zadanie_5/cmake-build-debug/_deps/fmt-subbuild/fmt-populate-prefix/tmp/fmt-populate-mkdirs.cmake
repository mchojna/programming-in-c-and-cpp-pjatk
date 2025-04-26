# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C06/PJC_C06_zadanie_5/cmake-build-debug/_deps/fmt-src"
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C06/PJC_C06_zadanie_5/cmake-build-debug/_deps/fmt-build"
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C06/PJC_C06_zadanie_5/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix"
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C06/PJC_C06_zadanie_5/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix/tmp"
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C06/PJC_C06_zadanie_5/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp"
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C06/PJC_C06_zadanie_5/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix/src"
  "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C06/PJC_C06_zadanie_5/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C06/PJC_C06_zadanie_5/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/mchojna/Documents/Studia/Inzynierka/Programowanie w jezykach C i C++/PJC_C06/PJC_C06_zadanie_5/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
