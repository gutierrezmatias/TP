
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
Model/Activo.h
Model/Estado.cpp
Model/Estado.h
Model/Formacion.cpp
Model/Formacion.h
Model/Formacion33.cpp
Model/Formacion33.h
Model/Formacion312.cpp
Model/Formacion312.h
Model/Formacion321.cpp
Model/Formacion321.h
Model/Inactivo.cpp
Model/Inactivo.h
Model/LTexture.cpp
Model/LTexture.h
Model/Model.cpp
Model/Model.h
Model/Model_Equipo.cpp
Model/Model_Equipo.h
Model/Model_Jugador.cpp
Model/Model_Jugador.h
Model/Model_Pelota.cpp
Model/Model_Pelota.h
Controller/AumentarVelocidadX.cpp
Controller/AumentarVelocidadX.h
Controller/AumentarVelocidadY.cpp
Controller/AumentarVelocidadY.h
Controller/CambiarJugador.cpp
Controller/CambiarJugador.h
Controller/Command.cpp
Controller/Command.h
Controller/Controller.cpp
Controller/Controller.h
Controller/Controller_Jugador.cpp
Controller/Controller_Jugador.h
Controller/DesminuirVelocidadY.cpp
Controller/DesminuirVelocidadY.h
Controller/DisminuirVelocidadX.cpp
Controller/DisminuirVelocidadX.h
Controller/DisminuirVelocidadY.cpp
Controller/DisminuirVelocidadY.h
Controller/StopJugador.cpp
Controller/StopJugador.h 
View/ViewModel.cpp
View/ViewModel.h
View/Entity.cpp
View/Entity.h
View/Event.cpp
View/Event.h
View/Observer.cpp
View/Observer.h
View/View.cpp
View/View.h
View/View_Cancha.cpp
View/View_Cancha.h
View/View_Jugador.cpp
View/View_Jugador.h
View/ViewModel.cpp
View/ViewModel.h
View/View_Pelota.cpp
View/View_Pelota.h
View/View_Seleccionado.cpp
View/View_Seleccionado.h
Utils/IObserver.h
Utils/Util_Common.cpp
Utils/Util_Common.h
Utils/Util_Configuracion.cpp
Utils/Util_Configuracion.h
Utils/Util_Logger.cpp
Utils/Util_Logger.h
Utils/Util_LoggerObserver.cpp
Utils/Util_LoggerObserver.h
Utils/Util_LoggerSubject.cpp
Utils/Util_LoggerSubject.h
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
