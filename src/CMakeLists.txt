###
# Game Source
#### Compile Options

include(ExternalProject)

set(MiniRPG_SRCS Game.cpp)

add_executable(${PROJECT_NAME} ${MiniRPG_SRCS})

# Add SDL dependent
find_package(SDL2 REQUIRED)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

# Add mruby dependent
ExternalProject_Get_Property(project_mruby INSTALL_DIR)
ExternalProject_Get_Property(project_mruby SOURCE_DIR)
add_library(mruby STATIC IMPORTED)
set_property(TARGET mruby PROPERTY IMPORTED_LOCATION ${INSTALL_DIR}/libmruby.a)
add_dependencies(mruby project_mruby)

add_library(mruby_core STATIC IMPORTED)
set_property(TARGET mruby_core PROPERTY IMPORTED_LOCATION ${INSTALL_DIR}/libmruby_core.a)
add_dependencies(mruby_core project_mruby)

include_directories(${SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} mruby mruby_core)

# Run Game
add_custom_target(run
  COMMAND ${PROJECT_NAME}
  DEPENDS ${PROJECT_NAME}
  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
