#include "Model.h"
#include "ViewModel.h"
#define CANTJUGADORES 7


Model::Model()
{
    this->jugadores = new Jugador[CANTJUGADORES]();
    this->nroJugadorActivo = 0;
    this->getJugadorActivo()->activar();
}

Model::~Model()
{
    delete[] this->jugadores;
}

Pelota* Model::getPelota()
{
    return &(this->pelota);
}

Jugador* Model::getJugadorNro(int i)
{
    return &(this->jugadores[i]);
}

Jugador* Model::getJugadorActivo()
{
    return &(this->jugadores[this->nroJugadorActivo]);
}

void Model::addCommand(Command* command)
{
    NotifyMessage("INGRESAMOS EN EL METODO: addCommand", "MODEL");
    //hay que tirar una excepcion
    if(command == nullptr)
        return;
    this->commandsToApply.push_back(command);
    NotifyMessage("SALIMOS DEL METODO: addCommand", "MODEL");
}

void Model::cambiarJugadorActivo()
{
    NotifyMessage("INGRESAMOS EN EL METODO: cambiarJugadorActivo", "MODEL");
    while (!((this->jugadores[(this->nroJugadorActivo + 1) % CANTJUGADORES]).collide(this->camara )))
    {
        printf("\n\n colision 2\n\n");
        NotifyMessage("colision 2", "MODEL");
        (this->jugadores[(this->nroJugadorActivo)]).desactivar();
        this->nroJugadorActivo = (this->nroJugadorActivo + 1) % CANTJUGADORES;

    }
    (this->jugadores[(this->nroJugadorActivo)]).desactivar();

    NotifyMessage("DESACTIVE ACTUAL JUGADOR", "MODEL");
    this->nroJugadorActivo = (this->nroJugadorActivo + 1) % CANTJUGADORES;
    (this->jugadores[(this->nroJugadorActivo)]).activar();
    NotifyMessage("ACTIVE OTRO JUGADOR", "MODEL");

    NotifyMessage("SALIMOS DEL METODO: cambiarJugadorActivo", "MODEL");
}
//El detener jugadores ya esta implicito en el estado.
//Y si no, deberia estarlo.s
//void Model::detenerJugadores()
//{
//    for(int i = 0; i < CANTJUGADORES; ++i)
//    {
//        this->jugadores[i].stop();
//    }
//}

void Model::update()
{
    NotifyMessage("INGRESAMOS EN EL METODO: update", "MODEL");
    Command* command = nullptr;
    while(!this->commandsToApply.empty())
    {
        command = this->commandsToApply.front();
        command->execute();
        this->commandsToApply.pop_front();
    }
    for(int i = 0; i < CANTJUGADORES; ++i)
    {
        this->jugadores[i].move();
    }
    NotifyMessage("SALIMOS DEL EL METODO: update", "MODEL");
}

void Model::setCamara(SDL_Rect * camara)
{
    NotifyMessage("INGRESAMOS AL METODO: setCamara", "MODEL");
    this->camara = camara;
    NotifyMessage("SALIMOS DEL METODO: setCamara", "MODEL");
}

void Model::setFormacion(Formacion* formacion)
{
    NotifyMessage("INGRESAMOS AL METODO: setFormacion", "MODEL");
    formacion->setPosicionInicial(this->jugadores);
    NotifyMessage("SALIMOS DEL METODO: setFormacion", "MODEL");
}

void Model::setCasaca(std::string casacaName)
{
    char c1[100];
    for(int i = 0; i<casacaName.size(); i++)
    {
        casacaName.at(i) = toupper(casacaName.at(i));
        c1[i] = casacaName.at(i);
    }
    char c3[] = "suplente";

    if((strncasecmp(c1,c3,2))==0)
    {
        for(int i = 0; i < CANTJUGADORES; ++i)
        {
            this->jugadores[i].setCasacaAlternativa();
        }
    }
}

std::string Model::getCasaca()
{
    return this->casacaSprite;
}
