cmake_minimum_required(VERSION 3.0.0)
project(nanovg VERSION 0.1.0)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# global settings 
add_compile_definitions(NANOVG_GLEW)
add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
add_compile_definitions(DEMO_MSAA) 
add_compile_definitions(NANOVG_EXAMPLE_FOLDER="../../example/")  # path for fonts and images
set(NANOVG_GLES OFF) 

add_library(nanovg src/nanovg.c src/nanovg.h)
target_include_directories(nanovg PUBLIC src)  


add_executable(example_fbo example/example_fbo.c  example/demo.c  example/perf.c )
target_link_libraries(example_fbo nanovg  ${CONAN_LIBS})

add_executable(example_gl2 example/example_gl2.c  example/demo.c  example/perf.c )
target_link_libraries(example_gl2 nanovg  ${CONAN_LIBS})

add_executable(example_gl3 example/example_gl3.c  example/demo.c  example/perf.c )
target_link_libraries(example_gl3 nanovg  ${CONAN_LIBS})

if(NANOVG_GLES)
    add_executable(example_gles2 example/example_gles2.c  example/demo.c  example/perf.c )
    target_link_libraries(example_gles2 nanovg ${CONAN_LIBS})

    add_executable(example_gles3 example/example_gles3.c  example/demo.c  example/perf.c )
    target_link_libraries(example_gles3 nanovg ${CONAN_LIBS})
endif()

