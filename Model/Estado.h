#ifndef ESTADO_H
#define ESTADO_H

#define VELOCIDAD_NORMAL 3
#define VELOCIDAD_ACELERADA 6

class Estado
{
public:
    Estado();
    virtual ~Estado();
    //Position accessors
    int getPosX();
    int getPosY();
    //Position accessors
    int getVelX();
    int getVelY();

    void setPosX(int PosX);
    void setPosY(int PosY);

    void setPosInitX(int posX);
    void setPosInitY(int posY);
    void copiarEstado(Estado* estado);
    void disminuirVelocidadX();
    void disminuirVelocidadY();
    void aumentarVelocidadX();
    void aumentarVelocidadY();
    void detenerVelocidad();

    virtual void move() = 0;

    virtual bool estaActivo() = 0;

    virtual void acelerar() = 0;

    void desacelerar();
    //virtual void stop() = 0;

protected:
    //The X and Y offsets of the dot
    int mPosX, mPosY;
    int posInitX, posInitY;
    //The velocity of the dot
    int mVelX, mVelY;
    int aceleracion;

private:
};

#endif // ESTADO_H
