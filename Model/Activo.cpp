#include "Activo.h"

#define ANCHO_JUGADOR 62
#define ALTO_JUGADOR 62
//dimension del nivel
#define ANCHO_NIVEL 2048
#define ALTO_NIVEL 1318

Activo::Activo()
{
    //ctor
}

Activo::~Activo()
{
    //dtor
}

void Activo::move() {
    this->mPosX += this->mVelX * aceleracion;
    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + ANCHO_JUGADOR >= ANCHO_NIVEL) )
    {
        //Move back
        mPosX -= mVelX*aceleracion;
    }

    //Move the dot up or down
    mPosY += mVelY * aceleracion;
    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + ALTO_JUGADOR >= ALTO_NIVEL ) )
    {
        //Move back
        mPosY -= mVelY*aceleracion;
    }

}
bool Activo::estaActivo() {
    return true;
}

void Activo::acelerar() {
    this->aceleracion = VELOCIDAD_ACELERACION;
}
