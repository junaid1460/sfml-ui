cmake_minimum_required(VERSION 3.0.2)

add_custom_command(
  OUTPUT src/lexer.cpp
  COMMAND ${FLEX_EXECUTABLE} 
  lex -o src/lexer.cpp src/lexer.l
  DEPENDS src/lexer.l
)


add_custom_command(
  OUTPUT src/parser.cpp
  COMMAND ${BISON_EXECUTABLE} 
  bison -d -o src/parser.cpp src/parser.y
  
  DEPENDS src/parser.y
)


add_custom_target(project_files ALL
    DEPENDS src/lexer.cpp src/parser.cpp)



project(transpiler)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
add_library(parser SHARED src/parser.cpp )

add_executable(out src/main.cpp)
target_link_libraries(out parser)
add_definitions("-std=c++14")