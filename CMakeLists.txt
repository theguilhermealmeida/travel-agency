cmake_minimum_required(VERSION 3.10)
project(delivery-scheduler)

set(CMAKE_CXX_STANDARD 11)

set(CREATE_EXE TRUE)

set(SOURCE_FILES
        src/Agency/Agency.cpp
        src/Agency/Agency.h

        src/App/App.cpp
        src/App/App.h
        src/App/InitialState.cpp
        src/App/InitialState.h
        src/App/State.cpp
        src/App/State.h
        )


set(TEST_FILES
        )

include_directories(src)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_subdirectory(tests/googletest)
    include_directories(tests/googletest/googletest/include)
    include_directories(tests/googletest/googlemock/include)

    add_executable(${CMAKE_PROJECT_NAME}_run mainTest.cpp ${TEST_FILES} ${SOURCE_FILES})

    target_link_libraries(${CMAKE_PROJECT_NAME}_run gtest gtest_main)
    message("Debug mode")
endif()

if (CMAKE_BUILD_TYPE MATCHES Release)
    add_executable(${CMAKE_PROJECT_NAME}_run main.cpp ${SOURCE_FILES})
    message("Release mode")
endif()