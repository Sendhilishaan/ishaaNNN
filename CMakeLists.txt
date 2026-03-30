cmake_minimum_required(VERSION 3.18)
project(ishaan_nn CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- scalar ---
add_library(scalar STATIC
    src/scalar/scalar.cpp
)
target_include_directories(scalar PUBLIC src/scalar)

# --- vector ---
add_library(vector STATIC
    src/vector/vector.cpp
)
target_include_directories(vector PUBLIC src/vector)
target_link_libraries(vector PUBLIC scalar)

# --- matrix ---
add_library(matrix STATIC
    src/matrix/matrix.cpp
)
target_include_directories(matrix PUBLIC src/matrix)

# --- tensor ---
add_library(tensor STATIC
    src/tensor/tensor.cpp
)
target_include_directories(tensor PUBLIC src/tensor)

# --- nn ---
add_library(nn STATIC
    src/nn/linear.cpp
    src/nn/activations.cpp
    src/nn/loss.cpp
    src/nn/network.cpp
)
target_include_directories(nn PUBLIC src/nn src/tensor)
target_link_libraries(nn PUBLIC tensor)

# --- demo ---
add_executable(ishaan_nn src/main.cpp)
target_link_libraries(ishaan_nn PRIVATE nn tensor matrix vector scalar)
target_include_directories(ishaan_nn PRIVATE src)

# --- tests ---
add_executable(test_scalar tests/test_scalar.cpp)
target_link_libraries(test_scalar PRIVATE scalar)
target_include_directories(test_scalar PRIVATE src/scalar)

add_executable(test_vector tests/test_vector.cpp)
target_link_libraries(test_vector PRIVATE vector scalar)
target_include_directories(test_vector PRIVATE src/vector src/scalar)

add_executable(test_matrix tests/test_matrix.cpp)
target_link_libraries(test_matrix PRIVATE matrix)
target_include_directories(test_matrix PRIVATE src/matrix)

add_executable(test_tensor tests/test_tensor.cpp)
target_link_libraries(test_tensor PRIVATE tensor)
target_include_directories(test_tensor PRIVATE src/tensor)

add_executable(test_nn tests/test_nn.cpp)
target_link_libraries(test_nn PRIVATE nn tensor matrix vector scalar)
target_include_directories(test_nn PRIVATE src)
