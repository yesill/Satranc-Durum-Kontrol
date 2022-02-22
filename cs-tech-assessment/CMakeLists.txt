cmake_minimum_required(VERSION 3.21)
project(cs_tech_assessment)

set(CMAKE_CXX_STANDARD 14)

add_executable(cs_tech_assessment main.cpp Taslar/Tas.cpp Taslar/Tas.h Konum.cpp Konum.h Taslar/Piyon.cpp Taslar/Piyon.h Taslar/At.cpp Taslar/At.h Taslar/Fil.cpp Taslar/Fil.h Taslar/Kale.cpp Taslar/Kale.h Taslar/Vezir.cpp Taslar/Vezir.h Taslar/Sah.cpp Taslar/Sah.h Tahta.cpp Tahta.h IO.cpp IO.h)
