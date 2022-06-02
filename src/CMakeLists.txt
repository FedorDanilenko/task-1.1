add_library(my_stack_lib)

target_sources(my_stack_lib
    PRIVATE
        stack.cxx
    PUBLIC
        stack.h
)

target_include_directories(my_stack_lib
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
