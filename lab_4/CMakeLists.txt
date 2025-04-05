cmake_minimum_required(VERSION 3.20)
project(lab_4)

set(CMAKE_CXX_STANDARD 20)

# Создаем исполняемый файл, добавляем functions.cpp
add_executable(lab_4 main.cpp functions.cpp)

# Указываем путь к заголовочным файлам
target_include_directories(lab_4 PRIVATE ${CMAKE_SOURCE_DIR})

# Импортируем DLL как внешнюю библиотеку
add_library(InputCheck SHARED IMPORTED)

# Указываем пути к DLL и LIB с правильными именами для MinGW
set_target_properties(InputCheck PROPERTIES
        IMPORTED_LOCATION "${CMAKE_BINARY_DIR}/libinputCheck.dll"
        IMPORTED_IMPLIB "${CMAKE_BINARY_DIR}/libinputCheck.dll.a"
)

# Линкуем библиотеку
target_link_libraries(lab_4 PRIVATE InputCheck)