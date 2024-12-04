cmake_minimum_required(VERSION 3.15.0)
project(store VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_DIR src)
set(APP_DIR ${SOURCE_DIR}/store)

# Adiciona o Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)

# Adicionar spdlog
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.15.0
)

FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(spdlog)

set(
   SOURCES 
   ${SOURCE_DIR}/main.cpp
   ${APP_DIR}/entity/Entity.cpp
   ${APP_DIR}/entity/Product.cpp
   ${APP_DIR}/entity/Order.cpp
   ${APP_DIR}/service/Catalog.cpp
   ${APP_DIR}/view/View.cpp
   ${SOURCE_DIR}/utils/Input.cpp
   ${APP_DIR}/AppController.cpp
)

set(
   HEADERS 
   ${APP_DIR}/entity/Entity.hpp
   ${APP_DIR}/entity/Product.hpp
   ${APP_DIR}/entity/Order.hpp
   ${APP_DIR}/service/Catalog.hpp
   ${APP_DIR}/view/View.hpp
   ${SOURCE_DIR}/utils/Input.hpp
   ${APP_DIR}/AppController.hpp
)

# Adiciona o executável principal
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Linkar com spdlog
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

# Adiciona os testes
enable_testing()

# Testes da aplicação
add_executable(store_tests
    tests/ProductTest.cpp
    tests/OrderTest.cpp
    tests/CatalogTest.cpp
    tests/IntegrationTest.cpp
    ${APP_DIR}/entity/Entity.cpp
    ${APP_DIR}/entity/Product.cpp
    ${APP_DIR}/entity/Order.cpp
    ${APP_DIR}/service/Catalog.cpp
)

# Linkar com Google Test
target_link_libraries(store_tests gtest gtest_main)

# Incluir diretórios de cabeçalhos
target_include_directories(store_tests PUBLIC
    ${APP_DIR}/entity
    ${APP_DIR}/service
    ${APP_DIR}/view
)

# Registra os testes
add_test(NAME store_tests COMMAND store_tests)
