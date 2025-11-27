cmake_minimum_required(VERSION 3.10)
project(matrix_lab)

# Основная программа
add_executable(sample_utmatrix samples/sample_matrix.cpp)

# Тесты + gtest в одном исполняемом файле
add_executable(test_utmatrix 
    test/test_main.cpp 
    test/test_tmatrix.cpp 
    test/test_tvector.cpp
    gtest/gtest-all.cc  # добавляем gtest напрямую
)

# Подключаем заголовки
target_include_directories(sample_utmatrix PRIVATE include)
target_include_directories(test_utmatrix PRIVATE include gtest)