cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")

project(cpp-opgl-game)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(OPENGL REQUIRED)
# set(SOIL_INCLUDE_DIR "/usr/local/include")
set(SOIL_LIBRARY "/usr/local/lib/libSOIL.a")
# set(OPENGL_INCLUDE_DIR "/usr/local/Cellar/glew/2.1.0/include")
# set(OPENGL_LIBRARY "/usr/local/Cellar/glew/2.1.0/lib/libGLEW.a")
set(GLEW_LIBRARY "/usr/local/Cellar/glew/2.1.0/lib/libGLEW.a")
set(FMOD_LINCLUDE_DIR "/Users/bhuang/FMOD/api/studio/inc")
set(FMOD_LIBRARY "/Users/bhuang/FMOD/api/studio/lib/libfmodstudio.dylib")
set(FMOD_CORE_LINCLUDE_DIR "/Users/bhuang/FMOD/api/core/inc")
set(FMOD_CORE_LIBRARY "/Users/bhuang/FMOD/api/core/lib/libfmod.dylib")

#MESSAGE(STATUS "The INCLUDE is " ${OPENGL_INCLUDE_DIR})
#MESSAGE(STATUS "The LIBRARY is " ${OPENGL_LIBRARY})

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR}
                    #${SOIL_INCLUDE_DIR} 
                    #${OPENGL_INCLUDE_DIR}
                    ${FMOD_LINCLUDE_DIR}
                    ${FMOD_CORE_LINCLUDE_DIR}
                    src)
                    
file(GLOB project_SRCS src/*.cpp) #src/*.h

add_executable(Main.exe ${project_SRCS})


target_link_libraries(Main.exe ${SDL2_LIBRARY}
                               ${SDL2_IMAGE_LIBRARY}
                               ${SDL2_TTF_LIBRARY}
                               ${OPENGL_LIBRARY}
                               ${GLEW_LIBRARY}
                               ${SOIL_LIBRARY}
                               ${FMOD_LIBRARY}
                               ${FMOD_CORE_LIBRARY}
                               )