cmake_minimum_required(VERSION 3.16)

project(Switcher)
set(SRC_FILES
main.cpp
publisher.cpp
)
set(CMAKE_PREFIX_PATH "/usr/lib/aarch64-linux-gnu/")
find_library(PAHO_MQTT_CPP_LIB NAMES paho-mqttpp3 PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)
find_library(PAHO_MQTT_C_LIB NAMES paho-mqtt3as PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)
find_library(WIRINGPI_LIB NAMES wiringPi PATHS /usr/lib /usr/local/lib NO_DEFAULT_PATH)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
include_directories(publisher)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME}  ${PAHO_MQTT_CPP_LIB} ${WIRINGPI_LIB} ${PAHO_MQTT_C_LIB} pthread ssl crypto)
