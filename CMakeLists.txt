cmake_minimum_required(VERSION 3.12)
project(hangman_game C)

set(CMAKE_C_STANDARD 99)

add_library(hangman_game main.c main.h)