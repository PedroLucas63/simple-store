cmake_minimum_required(VERSION 3.15.0)
project(store VERSION 1.0.0 LANGUAGES C CXX)

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

# Arquivos-fonte compartilhados
set(
   SOURCES 
   ${APP_DIR}/entity/Entity.cpp
   ${APP_DIR}/entity/Product.cpp
   ${APP_DIR}/entity/Order.cpp
   ${APP_DIR}/service/Catalog.cpp
   ${APP_DIR}/view/View.cpp
   ${SOURCE_DIR}/utils/Input.cpp
   ${APP_DIR}/AppController.cpp
)

# Cabeçalhos compartilhados
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

# Biblioteca compartilhada
add_library(store_lib ${SOURCES} ${HEADERS})

# Linkar a biblioteca com spdlog
target_link_libraries(store_lib PRIVATE spdlog::spdlog)

# Diretórios de inclusão para a biblioteca
target_include_directories(store_lib PUBLIC ${APP_DIR} ${SOURCE_DIR}/utils ${spdlog_SOURCE_DIR}/include)

# Adiciona o executável principal
add_executable(${PROJECT_NAME} ${SOURCE_DIR}/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE store_lib)

# Testes
enable_testing()

# Adiciona o executável para os testes
add_executable(store_tests
    tests/ProductTest.cpp
    tests/OrderTest.cpp
    tests/CatalogTest.cpp
    tests/IntegrationTest.cpp
)

# Linkar os testes com as bibliotecas compartilhadas
target_link_libraries(store_tests PRIVATE store_lib gtest gtest_main)

# Diretórios de inclusão para os testes
target_include_directories(store_tests PRIVATE ${spdlog_SOURCE_DIR}/include)

# Registra os testes
add_test(NAME store_tests COMMAND store_tests)
