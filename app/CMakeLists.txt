# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
set(distribution_DIR ${CMAKE_SOURCE_DIR}/libs)
set(CPP_DIR "src/main/cpp")
#定义全局路径
file(GLOB CPP_FILES "${CPP_DIR}/testjni/*.cpp")
add_library( # Sets the name of the library.
             ffmpeg_jni

#https://blog.csdn.net/quwei3930921/article/details/78820991
             # Sets the library as a shared library.
             SHARED
             # 资源文件，可以多个，
             # 资源路径是相对路径，相对于本CMakeLists.txt所在目录
             # Provides a relative path to your source file(s).
             ${CPP_DIR}/ffmpegdecode/ffmpeg_decode.cpp
            # ${CPP_DIR}/testjni/native-lib.cpp 可以写成下面的形式
             ${CPP_FILES}
             ${CPP_DIR}/addmusic/add_music.cpp
             #两个filter冲突
             ${CPP_DIR}/avfilter2/avfilter2.cpp
             ${CPP_DIR}/ffmpegfilter/ffmpeg_filter.cpp
             ${CPP_DIR}/testjni/CppBean.cpp
             ${CPP_DIR}/opensles/FFmpegMusic.cpp
             ${CPP_DIR}/ffmpeg_player/video_player.cpp
             ${CPP_DIR}/video_play/FFmpegMusic.cpp
             ${CPP_DIR}/video_play/FFmpegVideo.cpp
             ${CPP_DIR}/video_play/video_play.cpp
             ${CPP_DIR}/opensles/opensles.cpp
             )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable. # android系统每个类型的库会存放一个特定的位置，而log库存放在log-lib中
              log-lib
               # android系统在c环境下打log到logcat的库
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )



add_library( avutil-55
             SHARED
             IMPORTED )
set_target_properties( avutil-55
                       PROPERTIES IMPORTED_LOCATION
                        ${CMAKE_SOURCE_DIR}/libs/armeabi-v7a/libavutil-55.so )

add_library( swresample-2
             SHARED
             IMPORTED )
set_target_properties( swresample-2
                       PROPERTIES IMPORTED_LOCATION
                        ${CMAKE_SOURCE_DIR}/libs/armeabi-v7a/libswresample-2.so )
add_library( avcodec-57
             SHARED
             IMPORTED )
set_target_properties( avcodec-57
                       PROPERTIES IMPORTED_LOCATION
                        ${CMAKE_SOURCE_DIR}/libs/armeabi-v7a/libavcodec-57.so )
add_library( avfilter-6
             SHARED
             IMPORTED)
set_target_properties( avfilter-6
                       PROPERTIES IMPORTED_LOCATION
                        ${CMAKE_SOURCE_DIR}/libs/armeabi-v7a/libavfilter-6.so )
add_library( swscale-4
             SHARED
             IMPORTED)
set_target_properties( swscale-4
                       PROPERTIES IMPORTED_LOCATION
                        ${CMAKE_SOURCE_DIR}/libs/armeabi-v7a/libswscale-4.so )
add_library( avdevice-57
             SHARED
             IMPORTED)
set_target_properties( avdevice-57
                       PROPERTIES IMPORTED_LOCATION
                        ${CMAKE_SOURCE_DIR}/libs/armeabi-v7a/libavdevice-57.so )
add_library( avformat-57
             SHARED
             IMPORTED)
set_target_properties( avformat-57
                       PROPERTIES IMPORTED_LOCATION
                       ${CMAKE_SOURCE_DIR}/libs/armeabi-v7a/libavformat-57.so )

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

#影响了引入包规则
include_directories(${CMAKE_SOURCE_DIR}/libs/include)

#target_include_directories(ffmpeg_jni PRIVATE ${distribution_DIR}/include)

#include_directories(libs/include)
# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       ffmpeg_jni
                       android
                       EGL
                       z
                       OpenSLES
                       avutil-55 swresample-2 avcodec-57 avfilter-6 swscale-4 avdevice-57 avformat-57
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )