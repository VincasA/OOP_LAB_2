cmake_minimum_required(VERSION 3.10)
project(Projektas VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_COMPILER g++)

set(SOURCES Funkcijos.cpp)
set(HEADERS Funkcijos.h Funkcijos_impl.h Studentas.h)

add_executable(main main.cpp ${SOURCS} ${HEADERS})
add_executable(main_vector main_vector.cpp ${SOURCS} ${HEADERS})
add_executable(main_deque main_deque.cpp ${SOURCS} ${HEADERS})
add_executable(main_list main_list.cpp ${SOURCS} ${HEADERS})

add_custom_target(clean
    COMMAND ${CMAKE_COMMAND} -E remove
    main
    main_vector
    main_deque
    main_list    
)