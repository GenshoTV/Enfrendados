
#include "funciones.h"
#include <cstdlib>
#include "rlutil.h"
#include <ctime>
#include <string>
#include <vector>

using namespace std;

void LineaHorizontal(int inicioX, int finX, int posicionY, string esquinaIzq = "*", string esquinaDer = "*")
{

    rlutil::locate(inicioX, posicionY);
    cout << esquinaIzq; /// *

    for (int i = inicioX + 1; i < finX; i++)
    {
        cout << "-";
    }
    cout << esquinaDer; /// *
}

void LineaVertical(int posicionX, int inicioY, int finY) /// Dibuja una linea en vertical en Y
{

    for (int i = inicioY + 1; i < finY; i++)
    {
        rlutil::locate(posicionX, i);
        cout << "|";
    }
}

void Cuadro(int inicioX, int inicioY, int finX, int finY)
{
    LineaHorizontal(inicioX, finX, inicioY);
    LineaHorizontal(inicioX, finX, finY);

    LineaVertical(inicioX, inicioY, finY);
    LineaVertical(finX, inicioY, finY);
}

void Creditos()
{
    rlutil::locate(38,11);
    cout << "Juego hecho por: " << endl;
    rlutil::locate(30,13);
    cout <<"Martin Daniel Guerre§o LEGAJO: 33305" << endl;
    rlutil::locate(33,14);
    cout <<"Mauro Sinopoli LEGAJO: 31747" << endl;
    rlutil::locate(33,15);
    cout <<"Agustin Salto LEGAJO: 26201" << endl;
    rlutil::locate(29,16);
    cout <<"Leonardo Julian Sanchez LEGAJO: 31926" << endl;
}



void estadisticas(int &puntosMax,string &jugadorMax)
{
    rlutil::locate(30,11);
    cout << "Puntos m†ximos";
    rlutil::locate(48,11);
    cout << "Nombre de jugador";

    rlutil::locate(30,13);
    cout <<" Puntaje: " << puntosMax;
    rlutil::locate(49,13);
    cout <<" Jugador: " << jugadorMax;

    rlutil::locate(29,9);
    cout << "|---------- ESTADISTICAS ----------|";
    LineaVertical(46,10,14);
    cout << endl << endl << endl;
    rlutil::locate(28,12);
    cout << "---------------------------------------";
    rlutil::locate(29,16);
    cout << "Presiona cualquier tecla para continuar" << endl;
    rlutil::anykey();


};



void menu()
{
    int puntosMax;
    string jugadorMax;


    int opciones = 10, PosicionY;

    rlutil::hidecursor(); /// Oculta el cursor de la pantalla
    do
    {
        rlutil::cls();
        Cuadro(25,11,48,16);
        rlutil::locate(29,5); /// Ubica en pantalla los couts (x, y)
        cout << "≠BIENVENIDOS A...\n"
             "    _______   ____________  _______    ______  ___    ____  ____  _____\n"
             "   / ____/ | / / ____/ __ \\/ ____/  | / / __ \\/   |  / __ \\/ __ \\/ ___/ \n"
             "  / __/ /  |/ / /_  / /_/ / __/ /   |/ / / / / /| | / / / / / / /\\__  \\ \n"
             " / /___/ /|  / __/ / _, _/ /___/ /|  / / _/ / ___  |//_/ / /_/ /___/ /\n"
             "/_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/ _/  |_/_____/\____//_____/\n" << endl;


        rlutil::locate(30,12);
        cout << "1 - JUGAR "<< endl; /// 0
        rlutil::locate(30,13);
        cout << "2 - ESTADISTICAS "<< endl; /// 1
        rlutil::locate(30,14);
        cout << "3 - CREDITOS "<< endl; ///2
        rlutil::locate(30,15);
        cout << "0 - SALIR " << endl; ///3


        ////////////// X   Y
        rlutil::locate(19,17);
        cout << "Presiona las flechitas para moverte";
        rlutil::locate(23,19);
        cout << "Presiona Enter para aceptar";
        /// Cursor
        rlutil::locate(26,12 + PosicionY);
        cout << "  ";

        cout << (char)175 << endl;

        int tecla = rlutil::getkey();
        switch(tecla)
        {
        /// ®Por quÇ?, por que no quiero que vaya m†s de arriba (0 = JUGAR(TOPE))
        case 14: /// Arriba
            PosicionY--;
            if(PosicionY < 0)
            {
                PosicionY = 0;
            }
            break;
        /// Puede moverse 3 casillas a partir del 0 (0,1,2,3)
        case 15: /// Abajo
            PosicionY++;
            if(PosicionY > 3)
            {
                PosicionY = 3;
            }
            break;
        case 1: /// Enter
        {
            switch(PosicionY)
            {
            case 0:
                PedirNombresJugadores(puntosMax,jugadorMax);
                break;
            case 1:
                rlutil::cls();
                Cuadro(27,10,67,14);
                estadisticas(puntosMax,jugadorMax);
                break;
            case 2:
                rlutil::cls();
                Cuadro(27,10,67,17);
                Creditos();
                rlutil::locate(26,19);
                cout << "Presione cualquier tecla para volver al men£" << endl;
                rlutil::anykey();
                break;
            case 3: /// Salir
            {
                int opcionSalir = 0;
                bool confirmando = true;

                while(confirmando)
                {
                    rlutil::cls();
                    /// X1 Y1 X2 Y2
                    Cuadro(27,10,54,18);
                    rlutil::locate(30, 12);
                    cout << "®Desea salir del juego?" << endl;

                    rlutil::locate(33, 13);
                    if (opcionSalir == 0)
                    {
                        cout << " " << (char)175 << " Si  =   No " << endl;
                    }
                    else
                    {
                        cout << "   Si  = " << (char)175 << " No" << endl;
                    }
                    rlutil::locate(36,14);
                    cout << "<-- | -->" << endl;
                    rlutil::locate(30,15);
                    cout << "Presiona las flechitas" << endl;
                    rlutil::locate(33,16);
                    cout << "para seleccionar";
                    int teclaSalir = rlutil::getkey();

                    switch(teclaSalir)
                    {
                    case 16: /// Flecha izquierda
                        opcionSalir = 0;
                        break;
                    case 17: /// Flecha derecha
                        opcionSalir = 1;
                        break;
                    case 1:
                        if (opcionSalir == 0)
                        {
                            rlutil::cls();
                            Cuadro(25,9,75,11);
                            rlutil::locate(28,10);
                            cout << "Gracias por jugar ≠Volveremos a encontrarnos!" << endl << endl << endl << endl << endl;
                            rlutil::locate(28,15);
                            cout << "Presione cualquier tecla para salir del juego";
                            rlutil::anykey();
                            opciones = 0; /// salir del juego
                        }
                        else
                        {
                            opciones = 10; /// seguir en el men√∫
                        }
                        confirmando = false;
                        break;
                    }
                }
            }
            }
        }
        rlutil::locate(26, 12 + PosicionY);
        cout << (char)175 << endl;
        rlutil::cls();

        }
    }
    while(opciones != 0);
}


//funcion tirar dados pasar caras por parametro.
int tirarDado(int CarasDados)

{
    return rand() % CarasDados + 1;
}


//pedirmos nombre por cin y se los pasamos a quienEmpiezaRonda()
void PedirNombresJugadores(int &puntosMax,string &jugadorMax)
{
    string jugador1;
    string jugador2;

    rlutil::cls();
    rlutil::locate(30,12);
    cout << "Ingrese su nombre jugador/a 1: ";
    cin >> jugador1;
    rlutil::cls();
    rlutil::locate(30, 12);
    cout << "Ingrese su nombre jugador/a 2: ";
    cin >> jugador2;
    rlutil::cls();
    QuienEmpiezaRonda(jugador1,jugador2,puntosMax,jugadorMax);
}

// Realiza el sorteo de quien empieza.
void QuienEmpiezaRonda(string jugador1, string jugador2,int &puntosMax,string &jugadorMax)
{
    int dado1;
    int dado2;
    string ganador;

    rlutil::locate(30,2);
    cout << jugador1 << " tira su dado... " << endl;
    dado1 = tirarDado(6);
    rlutil::locate(30,4);
    cout << "El dado de "<< jugador1 << " es: " << dado1 << endl;
    rlutil::locate(30,6);
    cout << jugador2 << " tira su dado... " << endl;
    dado2 = tirarDado(6);
    rlutil::locate(30,8);
    cout << "El dado de "<< jugador2 << " es: " << dado2 << endl;


    while (dado1 == dado2)
    {
        rlutil::locate(33,10);
        cout << "≠FUE UN EMPATE!" << endl;
        rlutil::locate(19,13);
        cout << "Presiona cualquier para volver a tirar los dados" << endl;
        rlutil::anykey();
        rlutil::cls();

        dado1 = tirarDado(6);
        dado2 = tirarDado(6);

        rlutil::locate(26,4);
        cout << jugador1 << " vuelve a tirar los dados..." << endl;
        rlutil::locate(34,5);
        cout << "El dado es: " << dado1 << endl;
        rlutil::locate(26,7);
        cout << jugador2 << " vuelve a tirar los dados..." << endl;
        rlutil::locate(34,8);
        cout << "El dado es: " << dado2 << endl;
    }

    if (dado1 > dado2)
    {
        rlutil::locate(33,10);
        cout << "Empieza: " << jugador1 << endl;
        ganador = jugador1;
        rlutil::locate(19,12);
        cout << "Presione cualquier tecla para iniciar la ronda";
        rlutil::anykey();
        rlutil::cls();
        jugar(jugador1, jugador2,puntosMax,jugadorMax);
    }
    else
    {
        rlutil::locate(33,10);
        cout << "Empieza: " << jugador2 << endl;
        ganador = jugador2;
        rlutil::locate(19,12);
        cout << "Presione cualquier tecla para iniciar la ronda";
        rlutil::anykey();
        rlutil::cls();
        jugar(jugador2,jugador1,puntosMax,jugadorMax);
    }
}
//recibimos por parametro las referencias a ser modificadas entre rondas.

void turnoJugador(string nombre, int &stock, int &puntos, int &dadosUsados, int &stockDadosContrincante)
{
    // maximo de dados que un jugador puede tener
    int maximosDados = 12;
    int objetivo;
    // Vector inicializado en 12 posiciones.
    int dados[maximosDados];
    // Vector booleanos para marcar dados ya utilizados.
    bool usados[maximosDados]= {false};
    // Inicia en 0 los dados utilizados.
    dadosUsados = 0;

    // Tirar dados objetivo
    int dado1 = tirarDado(12);
    int dado2 = tirarDado(12);
    // resultado de dados objetivo
    objetivo = dado1 + dado2;

    cout << "\nTurno de: " << nombre << endl;
    cout << "Dados objetivos: " << dado1 << " + " << dado2 << " = " << objetivo << endl;

    // Tirar los dados disponibles seg£n (stock se recibe desde jugar)
    for (int i = 0; i < stock; i++)
    {
        dados[i] = tirarDado(6);
    }
    cout << "Dados a usar:   ";
    for (int i = 0; i < stock; i++)
    {
        cout << "| " << i + 1 << " ";
    }
    cout << "|\n";
    cout << "                --------------------------" << " Objetivo a llegar: " << objetivo << endl;
    cout << "Valor de dados: ";
    for (int i = 0; i < stock; i++)
    {
        cout << "| " << dados[i] << " ";
    }
    cout << "|\n";
    cout << endl;

    // inicializacion de suma y dados usados
    int suma = 0;
    int cantidadUsados = 0;

    // inicializacion del ciclo de eleccion de dados, (mientras que suma sea menor a objetivo)
    while (suma < objetivo)
    {
        // Usuario ingresa numero para eleccion.
        cout << "Eleg° el numero de dado a usar (0 para rendirte): ";
        int eleccion;
        cin >> eleccion;

        // verificamos la eleccion si es igual a 0,si es asi penaliza con un dado que se resta del oponente.
        if (eleccion == 0)
        {
            cout << endl;
            cout << "Te rendiste. Pierdes tu turno y te han penalizado con un dado.\n";

            if (stockDadosContrincante > 1) // Verifica que reste solo si tiene m√°s de 1 dado
            {
                stockDadosContrincante--; // Resta dados del contrincante
                stock++;                  // Suma dados a usuario del turno
            }
            else
            {
                cout << "Tienes suerte! tu companero no puede pasarte dados porque no tiene mas de uno" << endl;
            }

            break; // sale del ciclo para darle lugar al oponente.
        }
        else if (eleccion < 1 || eleccion > stock) // Verifica si la eleccion es menor a 1 o mayor al stock de dados , y penaliza por mala eleccion.
        {
            cout << endl;
            cout << "Elegiste una opci¢n incorrecta. Pierdes tu turno y te han penalizado con un dado.\n" << endl;

            if (stockDadosContrincante > 1) // Verifica que reste solo si tiene m√°s de 1 dado
            {
                stockDadosContrincante--; // Resta dados del contrincante
                stock++;                  // Suma dados a usuario del turno
            }
            else
            {
                cout << "Tienes suerte! tu companero no puede pasarte dados porque no tiene mas de uno" << endl;
            }
            break;
        }
        else if (usados[eleccion - 1]) // verifica si la eleccion ya fue usada
        {
            cout << "Ese dado ya fue usado. Eleg° otro." << endl;
            continue;
        }

        usados[eleccion - 1] = true; // marca el dado como usado

        // va sumando las elecciones
        suma += dados[eleccion - 1];
        // mostramos por pantalla los dados elegidos su valor y ademas la suma de los mismos.
        cout << "Elegiste el dado [" << eleccion << "] con valor " << dados[eleccion - 1] << endl;;
            cout << endl;
        cout << "[Tu suma es] = " << suma << endl;
        // acumulamos los dados usados.
        cantidadUsados++;
        // Si us¢ todos los dados Y alcanz¢ el objetivo d† el premio de 10.000 puntos
        if (cantidadUsados == stock && suma == objetivo)
        {
            cout << "≠Felicitaciones! Utilizaste todos tus dados, ganaste autom†ticamente y sumaste 10.000 puntos!\n" << endl;
            puntos += 10000;
            dadosUsados = cantidadUsados; // se pasan todos los dados usados al rival
            cout << "≠Tu puntaje es: [" << puntos << "]" << endl;
            break;
        }
        // Verifica si suma se paso del objetivo y penaliza.
        if (suma > objetivo)
        {
            cout << "≠Te has pasado del objetivo! La suma dio " << suma << "\n";
            if (stockDadosContrincante > 1)
            {
                stockDadosContrincante--; // Se le quita un dado al contrincante
                stock++;                  // Se le da al jugador actual
            }
            cout << "Tu suma fue incorrecta y te han penalizado con un dado.\n";
            break;
        }
        // Verificamos si la suma es igual a objetivo.
        if (suma == objetivo)
        {
            cout << "≠Objetivo alcanzado con " << cantidadUsados << " dados!\n";
            int puntosGanados = cantidadUsados * suma; // multiplica los dados usados por la suma dando el total de puntos ganados
            puntos += puntosGanados;                   // pasa por referencia los puntosganados y los suma para jugar()
            dadosUsados = cantidadUsados;              // pasa por referencia los dados usados para jugar()
            cout << "Ganaste " << puntosGanados << " puntos." << endl;
            break;
        }
    }
}
// funcion jugar se encarga de los stocks de dados y puntaje,le pasa a turnojugador por parametros de referencia stock,puntos,usados,objetivo.
void jugar(string jugador1, string jugador2,int &puntosMax,string &jugadorMax)
{
    // cantidad de rondas iniciales
    const int rondas = 3;

    // stocks de dados de jugadores
    int stockJ1 = 6;
    int stockJ2 = 6;
    // puntos de jugadores
    int puntosJ1 = 0;
    int puntosJ2 = 0;

    // ciclo de rondas iniciado dentro se suman puntos y se suman o descuentan dados.
    for (int ronda = 1; ronda <= rondas; ronda++)
    {
        cout << "\n                 ======= RONDA " << ronda << " =======\n";

        // Turno Jugador 1
        int usadosJ1 = 0;
        // pasamos por parametros informacion.
        turnoJugador(jugador1, stockJ1, puntosJ1, usadosJ1, stockJ2);

        // chequeo de dados usados y suma o resta de los mismos.
        if (usadosJ1 > 0)
        {
            stockJ1 -= usadosJ1;
            stockJ2 += usadosJ1;
            cout << jugador1 << " pasa " << usadosJ1 << " dado(s) a " << jugador2 << ".\n";

            // Detecta si el jugador 1 se qued√≥ sin dados
            if (stockJ1 == 0)
            {
                cout << jugador1 << " se qued¢ sin dados y gana el juego anticipadamente.\n";
                break;
            }
        }
        cout << endl;
        cout << "Presiona cualquier tecla para continuar";
        cout << endl;
        rlutil::anykey();
        cout << "\n======= Puntajes =======\n";
        cout << jugador1 << ": " << puntosJ1 << " puntos | Dados: " << stockJ1 << endl;
        cout << jugador2 << ": " << puntosJ2 << " puntos | Dados: " << stockJ2 << endl;
        cout << "========================";
        cout << endl;

        // Turno Jugador 2
        int usadosJ2 = 0;
        turnoJugador(jugador2, stockJ2, puntosJ2, usadosJ2, stockJ1);

        // chequeo de dados usados - suma o resta de los mismos.
        if (usadosJ2 > 0)
        {
            stockJ2 -= usadosJ2;
            stockJ1 += usadosJ2;
            cout << jugador2 << " pasa " << usadosJ2 << " dado(s) a " << jugador1 << ".\n";

            // Detecta si el jugador 2 se qued√≥ sin dados
            if (stockJ2 == 0)
            {
                cout << jugador2 << " se qued¢ sin dados y gana el juego anticipadamente.\n";
                break;
            }
        }
        cout << endl;
        cout << "Presiona cualquier tecla para continuar";
        cout << endl;        rlutil::anykey();
        cout << "\n======= Puntajes =======\n";
        cout << jugador1 << ": " << puntosJ1 << " puntos | Dados: " << stockJ1 << endl;
        cout << jugador2 << ": " << puntosJ2 << " puntos | Dados: " << stockJ2 << endl;
        cout << "========================";
        cout << endl;

    }
    // Resultado final al salir del ciclo
    cout << "\n======= JUEGO TERMINADO =======\n";
    cout << jugador1 << ": " << puntosJ1 << " puntos | Dados: " << stockJ1 << endl;
    cout << jugador2 << ": " << puntosJ2 << " puntos | Dados: " << stockJ2 << endl;

    if (puntosJ1 > puntosJ2)
    {
        cout << "Ganador: " << jugador1 << " \n";
        if(puntosJ1 > puntosMax)
        {
            puntosMax = puntosJ1;
            jugadorMax = jugador1;
        }
    }
    else if (puntosJ2 > puntosJ1)
    {
        cout << "                                SE DECLARO:Ganador: " << jugador2 << " \n";
        cout << "                                GRACIAS POR JUGAR :D";
        if(puntosJ2 > puntosMax)
        {
            puntosMax = puntosJ2;
            jugadorMax = jugador2;
        }
    }
    else
    {
        cout << endl;
        cout << "                                SE DECLARO: ≠Empate!\n" << endl;
        cout << "                                GRACIAS POR JUGAR :D";

    }
        cout << endl << endl;
        cout << "                   -----------------------------------------------"<< endl;;
        cout << "                  | Presiona cualquier tecla para volver al men£ |" << endl;
        cout << "                   -----------------------------------------------" << endl;
        cout << endl;
        rlutil::anykey();
}



