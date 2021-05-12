set(SOURCE_LIB
max_sum_in_matrix_library.cpp
max_sum_in_matrix_library.hpp
)

add_library(${PRO}_lib STATIC ${SOURCE_LIB})

target_include_directories(${PRO}_lib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCE_LIB})

set_property(TARGET ${PRO}_lib PROPERTY FOLDER "max_sum_matrix_lib")

add_subdirectory(tests)