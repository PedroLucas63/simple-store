cmake_minimum_required(VERSION 3.15.0)
project(store VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_DIR src)
set(APP_DIR ${SOURCE_DIR}/store)

set(
   SOURCES 
   ${SOURCE_DIR}/main.cpp
   ${APP_DIR}/entity/Entity.cpp
   ${APP_DIR}/entity/Product.cpp
   ${APP_DIR}/entity/Order.cpp
   ${APP_DIR}/service/Catalog.cpp
   ${APP_DIR}/view/View.cpp
   ${APP_DIR}/AppController.cpp
)
set(
   HEADERS 
   ${APP_DIR}/entity/Entity.hpp
   ${APP_DIR}/entity/Product.hpp
   ${APP_DIR}/entity/Order.hpp
   ${APP_DIR}/service/Catalog.hpp
   ${APP_DIR}/view/View.hpp
   ${APP_DIR}/AppController.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})