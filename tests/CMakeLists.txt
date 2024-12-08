include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

# Arquivos-fonte para testes
set(
    SOURCES
    ProductTest.cpp
    OrderTest.cpp
    CatalogTest.cpp
    IntegrationTest.cpp
)

# Executável de testes
add_executable(store_tests ${SOURCES})
target_include_directories(store_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_link_libraries(
    store_tests
    PRIVATE
    ${PROJECT_NAME}_lib
    spdlog::spdlog
    gtest
    gtest_main
)

# Registra os testes
add_test(NAME store_tests COMMAND store_tests)
