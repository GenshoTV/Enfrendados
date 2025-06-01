#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string>
using namespace std;


void menu();
void jugar(string jugador1,string jugador2,string ganador);
int tirarDado(int CarasDados);
void rondas();
void PedirNombresJugadores();
void QuienEmpiezaRonda(string ganador1 , string ganador2);


#endif // FUNCIONES_H_INCLUDED
