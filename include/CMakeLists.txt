add_library(dynqueue INTERFACE)

target_include_directories(
  dynqueue
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
