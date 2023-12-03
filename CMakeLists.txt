cmake_minimum_required(VERSION 3.24)
project(DiaryManagement C)

set(CMAKE_C_STANDARD 11)

add_executable(DiaryManagement main.c cell.h cell.c lvl_list.c lvl_list.h
        Part2_analysis/timer.c
        Part2_analysis/timer.h Part2_analysis/get_timer_data.c)
