set(APP_DIR store)
set(UTILS_DIR utils)

# Arquivos-fonte compartilhados
set(
    SOURCES
    ${APP_DIR}/entity/Entity.cpp
    ${APP_DIR}/entity/Product.cpp
    ${APP_DIR}/entity/Order.cpp
    ${APP_DIR}/service/Catalog.cpp
    ${APP_DIR}/view/View.cpp
    ${APP_DIR}/AppController.cpp
    ${UTILS_DIR}/Input.cpp
)

# Biblioteca compartilhada
add_library(${PROJECT_NAME}_lib STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Executável
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib spdlog::spdlog)
