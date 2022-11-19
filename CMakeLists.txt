cmake_minimum_required(VERSION 3.23)
project(Program_File)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Program_File
        OlderClasses/Admin.h
        OlderClasses/Customer.h
        Main.cpp
        OlderClasses/User.h Class/Staff.h Class/Date.h Class/Student.h Class/Course.h Class/Programme.h Utility/Utility.h Utility/StudentUtil.h Utility/StaffUtil.h Utility/AdminUtil.h)
