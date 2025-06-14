#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string>
using namespace std;

void menu();
void PedirNombresJugadores();
void QuienEmpiezaRonda(string jugador1, string jugador2);
void turnoJugador(string nombre, int& stock, int& puntos, int& dadosUsados,int& stockContrincante);
void jugar(string jugador1, string jugador2);
int tirarDado(int CarasDados);
void estadisticas(); // falta hacer
void mostrarCreditos(); // falta agregar al codigo
bool confirmarSalida(); // falta agregar al codigo
void actualizarEstadisticas(string jugador, int puntaje); // falta hacer

// Funciones de del rlutil estas se declaran?
void LineaHorizontal(int inicioX, int finX, int posicionY, char esquinaIzq, char esquinaDer);
void LineaVertical(int posicionX, int inicioY, int finY);
void Cuadro(int inicioX, int inicioY, int finX, int finY);

#endif
