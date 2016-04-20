###
# Libs
###

include(ExternalProject)

ExternalProject_Add(
  project_mruby
  #GIT_REPOSITORY git@github.com:mruby/mruby.git
  #GIT_TAG 1.2.0
  GIT_SUBMODULES mruby
  SOURCE_DIR ${PROJECT_SOURCE_DIR}/lib/mruby
  INSTALL_DIR ${PROJECT_SOURCE_DIR}/lib/mruby/build/host/lib
  BUILD_IN_SOURCE 1
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ./minirake
  INSTALL_COMMAND ""
)

ExternalProject_Get_Property(project_mruby SOURCE_DIR)

set_directory_properties(PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
  ${SOURCE_DIR}/build)
