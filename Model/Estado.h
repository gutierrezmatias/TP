#ifndef ESTADO_H
#define ESTADO_H


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

    virtual void move() = 0;

    virtual bool estaActivo() = 0;
    //virtual void stop() = 0;

protected:
    //The X and Y offsets of the dot
    int mPosX, mPosY;
    int posInitX, posInitY;
    //The velocity of the dot
    int mVelX, mVelY;

private:
};

#endif // ESTADO_H
