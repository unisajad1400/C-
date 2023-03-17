cmake_minimum_required(VERSION 3.0)
project(my_project)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Add the include directories for OpenSSL
include_directories(${OPENSSL_INCLUDE_DIR})

# Add the executable
add_executable(my_app main.cpp)

# Link against OpenSSL libraries
target_link_libraries(my_app ${OPENSSL_LIBRARIES})
