cmake_minimum_required(VERSION 3.24)
project(game1)

set(CMAKE_CXX_STANDARD 17)

include_directories(D:/SFML/include)

add_executable(game1 sc/main.cpp headers/engine.h sc/engine.cpp States/State.cpp States/State.h States/GameState.cpp States/GameState.h States/GameState.h Entities/Entity.cpp Entities/Entity.h Entities/Bullets.cpp Entities/Bullets.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(game1 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()