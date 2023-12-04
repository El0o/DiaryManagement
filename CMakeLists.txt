cmake_minimum_required(VERSION 3.24)
project(DiaryManagement C)

set(CMAKE_C_STANDARD 11)

add_executable(DiaryManagement main.c Part_1-2/cell.h Part_1-2/cell.c Part_1-2/lvl_list.c Part_1-2/lvl_list.h
        Part_1-2/timer.c
        Part_1-2/timer.h Part_1-2/copy_main_2.c
        Part_3/appointment.c
        Part_3/appointment.h
        Part_3/contact.c
        Part_3/contact.h
        Part_1-2/copy_main_1.c
        Part_3/copy_main_3.c
        tools.c tools.h
        Part_3/copy_main_3.c
        Part_3/contact_list.c
        Part_3/contact_list.h)
