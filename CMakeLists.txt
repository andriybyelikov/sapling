cmake_minimum_required(VERSION 3.10)

project(
  sapling
  VERSION 0.1.0
  HOMEPAGE_URL "https://github.com/andriybyelikov/sapling"
  LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

file(
  GLOB_RECURSE SOURCES
  RELATIVE ${CMAKE_SOURCE_DIR}
  "src/*.c")

add_executable(sapling-bin ${SOURCES})
target_include_directories(sapling-bin PRIVATE include src)
target_link_libraries(sapling-bin sapling m)

include(GNUInstallDirs)
set_target_properties(sapling-bin PROPERTIES OUTPUT_NAME sapling)
install(TARGETS sapling-bin RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

if (UNIX AND NOT APPLE)
  install(FILES ${CMAKE_SOURCE_DIR}/sapling.1 DESTINATION share/man/man1)
endif()
