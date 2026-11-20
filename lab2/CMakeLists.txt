cmake_minimum_required(VERSION 3.20)
project(Oceanarium LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
include(FetchContent)

set(OCEANARIUM_SOURCES
    Oceanarium/MarineAnimals.cpp
    Oceanarium/AquariumSystems.cpp
    Oceanarium/AnimalCare.cpp
    Oceanarium/StaffManagement.cpp
    Oceanarium/VisitorManagement.cpp
    Oceanarium/OperationsFinance.cpp
)

add_library(OceanariumCore STATIC ${OCEANARIUM_SOURCES})
target_include_directories(OceanariumCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Oceanarium")

add_executable(OceanariumApp Oceanarium/Oceanarium.cpp)
target_link_libraries(OceanariumApp PRIVATE OceanariumCore)

if(BUILD_TESTING)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    FetchContent_MakeAvailable(googletest)

    add_executable(OceanariumTests
        OceanariumTests/test.cpp
    )
    target_include_directories(OceanariumTests PRIVATE OceanariumTests)
    target_link_libraries(OceanariumTests PRIVATE OceanariumCore GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(OceanariumTests)
endif()
