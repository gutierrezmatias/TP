#include "Model_Jugador.h"


Jugador::Jugador()
{
    this->estado = &(this->inactivo);

    this->casaca = 1;
    this->mCollider.x = this->estado->getPosX();
    this->mCollider.y = this->estado->getPosY();
    this->mCollider.w = ANCHO_JUGADOR;
    this->mCollider.h = ALTO_JUGADOR;

}

void Jugador::setPosInitX(int posX) {
    this->estado->setPosInitX(posX);
}

void Jugador::setPosInitY(int posY) {
    this->estado->setPosInitY(posY);
}

void Jugador::move()
{
    this->estado->move();
    this->mCollider.x = this->estado->getPosX();
    this->mCollider.y = this->estado->getPosY();
}

int Jugador::getPosX()
{
    return this->estado->getPosX();
}

int Jugador::getPosY()
{
    return this->estado->getPosY();
}

void Jugador::setPosX(int PosX)
{
    this->estado->setPosX(PosX);
}

void Jugador::setPosY(int PosY)
{
    this->estado->setPosY(PosY);
}

void Jugador::setCasacaAlternativa()
{
    this->casaca = 0 ;
}


void Jugador::disminuirVelocidadX()
{
    this->estado->disminuirVelocidadX();
}

void Jugador::disminuirVelocidadY()
{
    this->estado->disminuirVelocidadY();
}

void Jugador::aumentarVelocidadX()
{
    this->estado->aumentarVelocidadX();
}

void Jugador::aumentarVelocidadY()
{
    this->estado->aumentarVelocidadY();
}

int Jugador::getVelX()
{
    return this->estado->getVelX();
}

int Jugador::getVelY()
{
    return this->estado->getVelY();
}
bool Jugador::casacaPrincipal()
{
    return this->casaca;
}

void Jugador::stop()
{
    //posiblemente este metodo desaparezca ya
    //no tenga sentido.
    //Eliminar en cuanto se pueda.
}
bool Jugador::estaActivo()
{
    return this->estado->estaActivo();
}
void Jugador::activar()
{
    this->activo.copiarEstado(this->estado);
    this->estado = &(this->activo);
}
void Jugador::desactivar()
{
    this->inactivo.copiarEstado(this->estado);
    this->estado = &(this->inactivo);
}
bool Jugador::collide(SDL_Rect * camara)
{
//The sides of the rectangles
    int leftCam, leftJugador;
    int rightCam, rightJugador;
    int topCam, topJugador;
    int bottomCam, bottomJugador;

    //Calculate the sides of rect A
    leftCam = camara->x;

    rightCam = camara->x + camara->w;

    topCam = camara->y;

    bottomCam = camara->y + camara->h;

    //Calculate the sides of rect B
    leftJugador = this->mCollider.x;
    printf("leftcam %i - ",leftCam);
    printf("leftJugador - %i\n",leftJugador);
    rightJugador = this->mCollider.x + this->mCollider.w;
    printf("rightCam %i",rightCam);
    printf("rightJugador %i\n",rightJugador);
    topJugador = this->mCollider.y;
    printf("topCam %i",topCam);
    printf("topJugador %i\n",topJugador);
    bottomJugador = this->mCollider.y + this->mCollider.h;
    printf("bottomCam %i",topCam);
    printf("bottomJugador %i\n\n\n",bottomJugador);


    //If any of the sides from A are outside of B

    if( bottomJugador <= topCam )
    {
        return false;
    }

    if( topJugador>= bottomCam )
    {
        return false;
    }

    if( leftJugador >= rightCam )
    {
        return false;
    }

    if( rightJugador <= leftCam )
    {
        return false;
    }

    return true;
}
