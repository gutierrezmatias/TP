#include "Model.h"
#include "ViewModel.h"
#define CANTJUGADORES 7


Model::Model()
{
    this->jugadores = new Jugador[CANTJUGADORES]();
    this->nroJugadorActivo = 4;
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
   // try
  //  {
        NotifyMessage("Iniciamos: addCommand", "Model.cpp");
        //hay que tirar una excepcion
        if(command == nullptr) return;
        this->commandsToApply.push_back(command);
        NotifyMessage("Terminamos: addCommand", "Model.cpp");
  /*  }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Model.cpp");
        NotifyError(re.what(), "Model.cpp");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Model.cpp");
        NotifyError(ex.what(), "Model.cpp");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Model.cpp");
    }*/
}

void Model::cambiarJugadorActivo()
{
 //   try
  //  {
        NotifyMessage("Iniciamos: cambiarJugadorActivo", "Model.cpp");

        while (!((this->jugadores[(this->nroJugadorActivo + 1) % CANTJUGADORES]).collide(this->camara )))
        {
            NotifyMessage("Colision 2", "Model.cpp");
            (this->jugadores[(this->nroJugadorActivo)]).desactivar();
            this->nroJugadorActivo = (this->nroJugadorActivo + 1) % CANTJUGADORES;
        }
        (this->jugadores[(this->nroJugadorActivo)]).desactivar();

        NotifyMessage("Desactive el jugador actual", "Model.cpp");
        this->nroJugadorActivo = (this->nroJugadorActivo + 1) % CANTJUGADORES;
        (this->jugadores[(this->nroJugadorActivo)]).activar();
        NotifyMessage("Active otro jugador", "Model.cpp");

        NotifyMessage("Terminamos: cambiarJugadorActivo", "Model.cpp");
    /*}
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Model.cpp");
        NotifyError(re.what(), "Model.cpp");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Model.cpp");
        NotifyError(ex.what(), "Model.cpp");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Model.cpp");
    }*/
}

void Model::update()
{
 //   try
   // {
        NotifyMessage("Iniciamos: update", "Model.cpp");
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
        this->pelota.move();
        NotifyMessage("Terminamos: update", "Model.cpp");
   /* }
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "Model.cpp");
        NotifyError(re.what(), "Model.cpp");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "Model.cpp");
        NotifyError(ex.what(), "Model.cpp");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "Model.cpp");
    }*/
}

void Model::setCamara(SDL_Rect * camara)
{
    NotifyMessage("Iniciamos: setCamara", "Model.cpp");
    this->camara = camara;
    NotifyMessage("Terminamos: setCamara", "Model.cpp");
}

void Model::setFormacion(Formacion* formacion)
{
    NotifyMessage("Iniciamos: setFormacion", "Model.cpp");
    formacion->setPosicionInicial(this->jugadores);
    NotifyMessage("Terminamos: setFormacion", "Model.cpp");

}

void Model::setCasaca(std::string casacaName)
{
 //   try
   // {
        NotifyMessage("Iniciamos: setCasaca", "Model.cpp");
        char c1[100];
        for(unsigned i = 0; i<casacaName.size(); i++)
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
        NotifyMessage("Terminamos: setCasaca", "Model.cpp");
    /*}
    catch(const std::runtime_error& re)
    {
        NotifyError("Error en Runtime: ", "CONTROLLER");
        NotifyError(re.what(), "CONTROLLER");
    }
    catch(const std::exception& ex)
    {
        NotifyError("Ha ocurrido un error: ", "CONTROLLER");
        NotifyError(ex.what(), "CONTROLLER");
    }
    catch(...)
    {
        NotifyError("Error desconocido que no se ha podido especificar.", "CONTROLLER");
    }*/
}
