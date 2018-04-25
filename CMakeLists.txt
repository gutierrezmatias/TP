
cmake_minimum_required(VERSION 3.1)

project (taller CXX)
include_directories(Model) 

include_directories(View)  

include_directories(Controller)   

include_directories(Utils)  

include_directories(Images)  

include_directories(Configs)  

add_executable(taller main.cpp 

Model/Activo.cpp

Model/Estado.cpp

Model/Formacion.cpp

Model/Formacion33.cpp

Model/Formacion312.cpp

Model/Formacion321.cpp

Model/Inactivo.cpp

Model/LTexture.cpp

Model/Model.cpp

Model/Model_Equipo.cpp

Model/Model_Jugador.cpp

Model/Model_Pelota.cpp

Controller/AumentarVelocidadX.cpp

Controller/AumentarVelocidadY.cpp

Controller/CambiarJugador.cpp

Controller/Command.cpp

Controller/Controller.cpp

Controller/Controller_Jugador.cpp

Controller/DesminuirVelocidadY.cpp

Controller/DisminuirVelocidadX.cpp

Controller/DisminuirVelocidadY.cpp

View/ViewModel.cpp

View/Entity.cpp

View/Event.cpp

View/Observer.cpp

View/View.cpp

View/View_Cancha.cpp

View/View_Jugador.cpp

View/ViewModel.cpp

View/View_Pelota.cpp

View/View_Seleccionado.cpp

Utils/Util_Common.cpp

Utils/Util_Configuracion.cpp

Utils/Util_Logger.cpp

Utils/Util_LoggerObserver.cpp

Utils/Util_LoggerSubject.cpp

Utils/Util_Parser.cpp


    )

set_property(TARGET taller PROPERTY CXX_STANDARD 11)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(YAML-CPP REQUIRED yaml-cpp)

INCLUDE_DIRECTORIES(${PROJECT_NAME} ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${YAML-CPP_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES}  ${YAML-CPP_LIBRARIES} Util_Parser
)
