# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.


set(pathOpenCv /Users/parkheejin/Downloads/OpenCV-android-sdk)
set(pathProject /Users/parkheejin/MyTest/OpenCVBasic)


cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

include_directories(${pathOpenCv}/sdk/native/jni/include)

add_library( lib_opencv SHARED IMPORTED )
set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${pathProject}/app/src/main/JniLibs/${ANDROID_ABI}/libopencv_java3.so)


#와일드 문자를 이용하여 여러개의 파일을 불러올 수 도 있음
# *.cpp 또는 *.h
file(GLOB Library_SOURCES  src/main/cpp/module.cpp)
file(GLOB Library_HEADER   src/main/cpp/module.h)

#공유 라이브러리 생성
add_library(imported-lib SHARED ${Library_SOURCES} ${Library_HEADERS})
set_target_properties(imported-lib PROPERTIES LINKER_LANGUAGE CXX)

add_library( native-lib SHARED src/main/cpp/native-lib.cpp )

#미리 빌드된 라이브러리를 찾습니다.
find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )


# 타겟 라이브러리를 생성하기 위해 필요한 라이브러리를 명시합니다.
target_link_libraries(  imported-lib    #타겟 라이브러리
                        lib_opencv)     #필요한 라이브러리

target_link_libraries(  native-lib      #타겟 라이브러리
                        ${log-lib}      #필요한 라이브러리 3개
                        imported-lib
                        lib_opencv )
