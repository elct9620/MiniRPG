###
# Game Source
#### Compile Options

set(MiniRPG_SRCS Game.cpp)

add_executable(${PROJECT_NAME} ${MiniRPG_SRCS})

find_package(SDL2 REQUIRED)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
