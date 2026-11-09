cmake_minimum_required(VERSION 4.4)

project(abelix)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



set(SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gl.c 
)
set(LIBS 
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw3dll.lib
)

#find_package(glfw3 REQUIRED)
add_executable(abelix ${SRC})

target_include_directories(abelix PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(abelix 
    ${LIBS}
    opengl32.lib
)
add_custom_command(TARGET abelix POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw3.dll
        $<TARGET_FILE_DIR:abelix>
)
