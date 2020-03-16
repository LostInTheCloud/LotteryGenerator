cmake_minimum_required(VERSION 3.15)
project(LotteryGenerator C)

set(CMAKE_C_STANDARD 99)

add_executable(EuroJackpot eurojackpot.c lottolib.c)
target_link_libraries(EuroJackpot sodium)

add_executable(6aus49 6aus49.c lottolib.c)
target_link_libraries(6aus49 sodium)

add_executable(EuroMillion euromillion.c lottolib.c)
target_link_libraries(EuroMillion sodium)