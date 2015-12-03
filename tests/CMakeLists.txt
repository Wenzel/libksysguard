include_directories(${CMAKE_SOURCE_DIR}/processcore/)

add_executable(list_process list_process.cpp)

target_link_libraries(list_process processcore)
