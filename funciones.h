#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string>
using namespace std;

void menu();
void PedirNombresJugadores(int &puntosMax,string &jugadorMax);
void QuienEmpiezaRonda(string jugador1, string jugador2,int &puntosMax,string &jugadorMax);
void turnoJugador(string nombre, int& stock, int& puntos, int& dadosUsados,int& stockContrincante);
void jugar(string jugador1, string jugador2,int &puntosMax,string &jugadorMax);
int tirarDado(int CarasDados);
void estadisticas(); // falta hacer
void Creditos(); //Agregar debe mostrar los apellidos, nombres y legajos de los integrantes del equipo. Así como también el nombre del equipo.
bool confirmarSalida(); //poner como se llama la funcio nrealmente.
void actualizarEstadisticas(string jugador, int puntaje); // falta hacer

// Funciones de del rlutil estas se declaran?
void LineaHorizontal(int inicioX, int finX, int posicionY, char esquinaIzq, char esquinaDer);
void LineaVertical(int posicionX, int inicioY, int finY);
void Cuadro(int inicioX, int inicioY, int finX, int finY);

#endif
