#include "Hilo.h"

//Constructor de Hilo
Hilo::Hilo()
{
    period = 0;
    stopped = false;
}

//Destructor de Hilo
Hilo::~Hilo()
{}

//Metodo que llama el metodo tick, el que ejecuta el hilo
void Hilo::run(std::function<void()> tick)
{
    while(true){
        while(!stopped){
            tick();
        }
    }
}

//Metodo que inicia el contador
void Hilo::start(){
    stopped = false;
}

//Metodo que para el contador
void Hilo::pause(){
    stopped = true;    
}

//Metodo que pone el periodo actual del contador
void Hilo::setPeriod(int millis){
    period=millis;
}

