#ifndef MODEL_JUGADOR_H_
#define MODEL_JUGADOR_H_
#include <SDL2/SDL.h>
#include "LTexture.h"
#include "Estado.h"
#include "Activo.h"
#include "Inactivo.h"
#include "Model_Pelota.h"

class Jugador
{
public:
    //The dimensions of the dot
    static const int ANCHO_JUGADOR = 62;
    static const int ALTO_JUGADOR = 62;
    //Maximum axis velocity of the dot
    static const int VELOCIDAD_JUGADOR = 3;

    //Initializes the variables
    Jugador();

    //Moves the dot
    void move();

    //Position accessors
    int getPosX();
    int getPosY();
    //Position accessors
    int getVelX();
    int getVelY();
    void recuperaPelota(Pelota* pelota);
    void patearPelota(Pelota* pelota );
    void setPosX(int PosX);
    void setPosY(int PosY);

    void setPosInitX(int posX);
    void setPosInitY(int posY);


    void disminuirVelocidadX();
    void disminuirVelocidadY();
    void aumentarVelocidadX();
    void aumentarVelocidadY();
    bool estaActivo();
    void detenerVelocidad();

    void activar();
    void desactivar();

    void setCasacaAlternativa();
    bool casacaPrincipal();
    bool collide(SDL_Rect * camara);
    void acelerar();
    void desacelerar();
    double getDireccion();
     bool checkCollisionPelota(SDL_Rect *pelota);
    void updateDirection();
    void setCasacaSprite(std::string casacaName);
    std::string getCasacaSprite();
    int getAceleracion();
    void poseePelota();
    void noPoseePelota();
    bool getPosesion();
private:
    SDL_Rect mCollider;
    int casaca;
    std::string casacaSprite;
    Estado* estado;
    Activo activo;
    Inactivo inactivo;
    double direccion;
    bool conPelota;
    Pelota * pelota;
};

#endif
