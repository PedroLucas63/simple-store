cmake_minimum_required(VERSION 3.15.0)
project(store VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Definição das pastas
set(SOURCE_DIR src)
set(TESTS_DIR tests)

# Adição das bibliotecas compartilhadas:
find_package(spdlog REQUIRED)

# Subdiretórios
add_subdirectory(${SOURCE_DIR})
enable_testing()
add_subdirectory(${TESTS_DIR})
