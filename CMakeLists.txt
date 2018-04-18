
cmake_minimum_required(VERSION 3.1)

project (taller CXX)
include_directories(Model)
include_directories(View)
include_directories(Controller)
include_directories(Utils)
include_directories(Images)
include_directories(Configs)

add_executable(taller main.cpp 
  Model/Model.cpp
  Model/Model.h
  Controller/Command.cpp
  Controller/Command.h
  View/ViewModel.cpp
  View/ViewModel.h
  Utils/Util_Common.cpp
  Utils/Util_Common.h
  Utils/Util_LoggerObserver.cpp
  Utils/Util_LoggerObserver.h
  Utils/Util_LoggerSubject.cpp
  Utils/Util_LoggerSubject.h
  Utils/Util_Configuracion.cpp
  Utils/Util_Configuracion.h
  Utils/Util_Parser.cpp
  Utils/Util_Parser.h
    )

set_property(TARGET taller PROPERTY CXX_STANDARD 11)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(YAML-CPP REQUIRED yaml-cpp)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${YAML-CPP_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES}  ${YAML-CPP_LIBRARIES})
