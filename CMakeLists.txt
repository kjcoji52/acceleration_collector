# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "C:/Users/kjkjk/Documents/Pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(acceleration_collector C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(acceleration_collector acceleration_collector.c )

pico_set_program_name(acceleration_collector "acceleration_collector")
pico_set_program_version(acceleration_collector "0.1")

pico_enable_stdio_uart(acceleration_collector 0)
pico_enable_stdio_usb(acceleration_collector 1)

# Add the standard library to the build
target_link_libraries(acceleration_collector pico_stdlib)

# Add any user requested libraries
target_link_libraries(acceleration_collector
        hardware_i2c
        hardware_pio
        )

target_sources(acceleration_collector
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/mma8451_i2c.c
  ${CMAKE_CURRENT_LIST_DIR}/mma8451_i2c.h
  ${CMAKE_CURRENT_LIST_DIR}/bootsel_button.c
  ${CMAKE_CURRENT_LIST_DIR}/bootsel_button.h
)


pico_add_extra_outputs(acceleration_collector)

