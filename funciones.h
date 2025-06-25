#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>

void menu();
void PedirNombresJugadores(int &puntosMax,std::string &jugadorMax);
void QuienEmpiezaRonda(std::string jugador1, std::string jugador2,int &puntosMax,std::string &jugadorMax);
void turnoJugador(std::string nombre, int& stock, int& puntos, int& dadosUsados,int& stockContrincante);
void jugar(std::string jugador1, std::string jugador2,int &puntosMax,std::string &jugadorMax);
int tirarDado(int CarasDados);
void Estadisticas(int &puntosMax,std::string &jugadorMax);
void Creditos();

#endif
