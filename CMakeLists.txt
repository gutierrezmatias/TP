
cmake_minimum_required(VERSION 3.1)

project (taller CXX)
include_directories(Model) 
include_directories(View)  
include_directories(Controller)   
include_directories(Utils)  
include_directories(Images)   

file(GLOB SOURCES "Model/*.cpp" "View/*.cpp" "Controller/*.cpp" "Utils/*.cpp") 
##add_library(taller SHARED ${SOURCES})
add_executable(taller ${SOURCES})

set_property(TARGET taller PROPERTY CXX_STANDARD 11)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(YAML-CPP REQUIRED yaml-cpp)

INCLUDE_DIRECTORIES(${PROJECT_NAME} ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${YAML-CPP_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES}  ${YAML-CPP_LIBRARIES})
