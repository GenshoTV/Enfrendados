
#include "funciones.h"
#include <cstdlib>
#include "rlutil.h"
#include <ctime>
#include <string>
#include <vector>

using namespace std;

void LineaHorizontal(int inicioX, int finX, int posicionY, char esquinaIzq, char esquinaDer)
{

    rlutil::locate(inicioX, posicionY);
    cout << esquinaIzq; /// É

    for (int i = inicioX + 1; i < finX; i++)
    {
        cout << "Í";
    }
    cout << esquinaDer; /// »
}

void LineaVertical(int posicionX, int inicioY, int finY) /// Dibuja una linea en vertical en Y
{

    for (int i = inicioY + 1; i < finY; i++)
    {
        rlutil::locate(posicionX, i);
        cout << "º";
    }
}

void Cuadro(int inicioX, int inicioY, int finX, int finY)
{
    LineaHorizontal(inicioX, finX, inicioY, 'É', '»');
    LineaHorizontal(inicioX, finX, finY, 'È', '¼');

    LineaVertical(inicioX, inicioY, finY);
    LineaVertical(finX, inicioY, finY);
}

void menu()
{
    int opciones = 9, PosicionY;

    rlutil::hidecursor(); /// Oculta el cursor de la pantalla
    Cuadro(25, 11, 48, 16);
    do
    {
        rlutil::cls();

        ///    X  Y   X  Y
        Cuadro(25, 11, 48, 16);
        /*
        X1 = IZQ
        Y1 = ARRIBA
        X2 = DER
        Y2 = ABAJO
        */
        rlutil::locate(29, 5); /// Ubica en pantalla los couts (x, y)
        cout << "­BIENVENIDOS A...\n"
             "    _______   ____________  _______    ______  ___    ____  ____  _____\n"
             "   / ____/ | / / ____/ __ \\/ ____/  | / / __ \\/   |  / __ \\/ __ \\/ ___/ \n"
             "  / __/ /  |/ / /_  / /_/ / __/ /   |/ / / / / /| | / / / / / / /\\__  \\ \n"
             " / /___/ /|  / __/ / _, _/ /___/ /|  / / _/ / ___  |//_/ / /_/ /___/ /\n"
             "/_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/ _/  |_/_____/\____//_____/\n"
             << endl;

        rlutil::locate(30, 12);
        cout << "1 - JUGAR " << endl; /// 0
        rlutil::locate(30, 13);
        cout << "2 - ESTADISTICAS " << endl; /// 1
        rlutil::locate(30, 14);
        cout << "3 - CREDITOS " << endl; /// 2
        rlutil::locate(30, 15);
        cout << "0 - SALIR " << endl; /// 3

        ////////////// X   Y
        rlutil::locate(19, 17);
        cout << "Presiona las flechitas para moverte";
        rlutil::locate(23, 19);
        cout << "Presiona Enter para aceptar";
        /// Cursor
        rlutil::locate(26, 12 + PosicionY);
        cout << "  "; /// Esto es para ir borrando la flecha de selecci¢n mediante

        cout << (char)175 << endl; /// Muestra el CHAR de 175 (ASCII)

        int tecla = rlutil::getkey(); /// devuelve un entero que representa la letra que presiono en el teclado

        switch (tecla)
        {
        /// ¨Por qu‚ 0?, por que no quiero que vaya m s de arriba (0 = JUGAR)
        case 14: /// Arriba
            PosicionY--;
            if (PosicionY < 0)
            {
                PosicionY = 0;
            }
            break;
        /// Puede moverse 3 casillas a partir del 0 (0,1,2,3)
        case 15: /// Abajo
            PosicionY++;
            if (PosicionY > 3)
            {
                PosicionY = 3;
            }
            break;
        case 1: /// Enter
        {
            switch (PosicionY)
            {
            case 0:
                PedirNombresJugadores();
                break;
            case 3:

                /// SALIR
                opciones = 0;
                rlutil::cls();
                Cuadro(25, 3, 55, 5);
                /*
                X1 = IZQ
                Y1 = ARRIBA
                X2 = DER (Si sumo se agranda, si resto se resta :D)
                Y2 = ABAJO
                */
                rlutil::locate(30, 4);
                cout << "Hasta la vista, baby" << endl;
            }
            break;
        }
        rlutil::locate(26, 12 + PosicionY);
        cout << (char)175 << endl;
        }
    }
    while (opciones != 0);
}

//funcion tirar dados pasar caras por parametro.
int tirarDado(int CarasDados)

{
    return rand() % CarasDados + 1;
}


//pedirmos nombre por cin y se los pasamos a quienEmpiezaRonda()
void PedirNombresJugadores()
{
    string jugador1;
    string jugador2;

    rlutil::cls();
    rlutil::locate(30, 12);
    cout << "Ingrese su nombre jugador/a 1: ";
    cin >> jugador1;
    rlutil::cls();
    rlutil::locate(30, 12);
    cout << "Ingrese su nombre jugador/a 2: ";
    cin >> jugador2;
    rlutil::cls();
    QuienEmpiezaRonda(jugador1, jugador2);
    system("pause");
}

// VER EN CASO QUE EMPATE SE VEAN LOS NUEVOS RESULTADOS.
void QuienEmpiezaRonda(string jugador1, string jugador2)
{

    int dado1;
    int dado2;
    string ganador;

    rlutil::locate(30, 2);
    cout << jugador1 << " tira su dado..🎲 " << endl;
    dado1 = tirarDado(6);
    rlutil::locate(30, 3);
    cout << "El dado de " << jugador1 << " es: " << dado1 << endl;
    rlutil::locate(30, 4);
    cout << jugador2 << " tira su dado..🎲 " << endl;
    dado2 = tirarDado(6);
    rlutil::locate(30, 5);
    cout << "El dado de " << jugador2 << " es: " << dado2 << endl;
    //mientras que dado1 sea igual a dado2 el ciclo continua.
    while (dado1 == dado2)
    {
        rlutil::cls(); // Limpia pantalla para evitar textos superpuestos
        rlutil::locate(30, 6);
        cout << "Empate. Vuelven a tirar los dados 🎲.\n";

        dado1 = tirarDado(6);
        dado2 = tirarDado(6);
        system("pause");

        rlutil::locate(30, 7);
        cout << jugador1 << " saco: " << dado1 << endl;
        rlutil::locate(30, 8);
        cout << jugador2 << " saco: " << dado2 << endl;

    }
    //comparamos dado ganador y enviamos el ganador por parametro a jugar
    if (dado1 > dado2)
    {
        rlutil::locate(30, 7);
        cout << " Empieza: " << jugador1 << endl;
        ganador = jugador1;
        jugar(jugador1, jugador2);
    }
    else
    {
        rlutil::locate(30, 7);
        cout << " Empieza: " << jugador2 << endl;
        ganador = jugador2;
        jugar(jugador2, jugador1);
    }

}
//recibimos por parametro las referencias a ser modificadas entre rondas.

void turnoJugador(string nombre, int &stock, int &puntos, int &dadosUsados, int &stockDadosContrincante)
{
    // maximo de dados que un jugador puede tener
    int maximosDados = 12;
    int objetivo;
    // Vector inicializado en 12 posiciones
    vector<int> dados(maximosDados);
    // Para marcar dados ya utilizados
    vector<bool> usados(maximosDados, false);
    // Inicia en 0 los dados utilizados.
    dadosUsados = 0;

    // Tirar dados objetivo
    int dado1 = tirarDado(12);
    int dado2 = tirarDado(12);
    // resultado de dados objetivo
    objetivo = dado1 + dado2;

    cout << "\nTurno de: " << nombre << endl;
    cout << "Dados objetivos 🎲: " << dado1 << " + " << dado2 << " = " << objetivo << endl;

    // Tirar los dados disponibles según (stock se recibe desde jugar)
    for (int i = 0; i < stock; i++)
    {
        dados[i] = tirarDado(6);
    }

    // Mostrar dados con índices
    cout << "Tus dados: " << endl;

    for (int i = 0; i < stock; i++)
    {
        cout << "N#" << i + 1 << "🎲"
             "Cara "
             << dados[i] << " " << endl;
    }
    cout << endl;

    // inicializacion de suma y dados usados
    int suma = 0;
    int cantidadUsados = 0;

    // inicializacion del ciclo de eleccion de dados, (mientras que suma sea menor a objetivo)
    while (suma < objetivo)
    {
        // Usuario ingresa numero para eleccion.
        cout << "Elegí el número de dado a usar (0 para rendirte): ";
        int eleccion;
        cin >> eleccion;

        // verificamos la eleccion si es igual a 0,si es asi penaliza con un dado que se resta del oponente.
        if (eleccion == 0)
        {
            cout << "Te rendiste. Pierdes tu turno y te han penalizado con un dado.\n";
            if (stockDadosContrincante > 1) // Verifica que reste solo si tiene más de 1 dado
            {
                stockDadosContrincante--; // Resta dados del contrincante
                stock++;                  // Suma dados a usuario del turno
            }
            else
            {
                cout << "Tienes suerte! tu companero no puede pasarte dados porque no tiene mas de uno";
            }

            break; // sale del ciclo para darle lugar al oponente.
        }
        else if (eleccion < 1 || eleccion > stock) // Verifica si la eleccion es menor a 1 o mayor al stock de dados , y penaliza por mala eleccion.
        {
            cout << "Elegiste una opción incorrecta. Pierdes tu turno y te han penalizado con un dado.\n";
           if (stockDadosContrincante > 1) // Verifica que reste solo si tiene más de 1 dado
            {
                stockDadosContrincante--; // Resta dados del contrincante
                stock++;                  // Suma dados a usuario del turno
            }
            else
            {
                cout << "Tienes suerte! tu companero no puede pasarte dados porque no tiene mas de uno";
            }
            break;
        }
        else if (usados[eleccion - 1]) // verifica si la eleccion ya fue usada
        {
            cout << "Ese dado ya fue usado. Elegí otro." << endl;
            continue;
        }

        usados[eleccion - 1] = true; // marca el dado como usado

        // va sumando las elecciones
        suma += dados[eleccion - 1];
        // mostramos por pantalla los dados elegidos su valor y ademas la suma de los mismos.
        cout << "Elegiste el dado [" << eleccion << "] con valor " << dados[eleccion - 1] << endl;
        cout << "Tu suma es " << suma << endl;
        // acumulamos los dados usados.
        cantidadUsados++;

        // Si usó todos los dados Y alcanzó el objetivo → premio de 10.000 puntos
        if (cantidadUsados == stock && suma == objetivo)
        {
            cout << "¡Felicitaciones! ¡Utilizaste todos tus dados, ganaste automáticamente y sumaste 10.000 puntos!" << endl;
            puntos += 10000;
            dadosUsados = cantidadUsados; // se pasan todos los dados usados al rival
            cout << "¡Tu puntaje es: [" << puntos << "]" << endl;
            break;
        }

        // Verifica si suma se paso del objetivo y penaliza.
        if (suma > objetivo)
        {
            cout << "¡Te has pasado del objetivo! La suma dio " << suma << "\n";
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
            cout << "¡Objetivo alcanzado con " << cantidadUsados << " dados!\n";
            int puntosGanados = cantidadUsados * suma; // multiplica los dados usados por la suma dando el total de puntos ganados
            puntos += puntosGanados;                   // pasa por referencia los puntosganados y los suma para jugar()
            dadosUsados = cantidadUsados;              // pasa por referencia los dados usados para jugar()
            cout << "Ganaste " << puntosGanados << " puntos." << endl;
            break;
        }
    }
}


// funcion jugar se encarga de los stocks de dados y puntaje,le pasa a turnojugador por parametros de referencia stock,puntos,usados,objetivo.
void jugar(string jugador1, string jugador2)
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
        system("pause");
        cout << "\n======= RONDA " << ronda << " =======\n";

        // Turno Jugador 1
        int usadosJ1 = 0;
        // pasamos por parametros informacion.
        turnoJugador(jugador1, stockJ1, puntosJ1, usadosJ1, stockJ2);
        system("pause");

        // chequeo de dados usados y suma o resta de los mismos.
        if (usadosJ1 > 0)
        {
            stockJ1 -= usadosJ1;
            stockJ2 += usadosJ1;
            cout << jugador1 << " pasa " << usadosJ1 << " dado(s) a " << jugador2 << ".\n";

            // Detecta si el jugador 1 se quedó sin dados
            if (stockJ1 == 0)
            {
                cout << jugador1 << " se quedó sin dados y gana el juego anticipadamente.\n";
                break;
            }
        }

        cout << "\nPuntajes:\n";
        cout << jugador1 << ": " << puntosJ1 << " puntos | Dados: " << stockJ1 << endl;
        cout << jugador2 << ": " << puntosJ2 << " puntos | Dados: " << stockJ2 << endl;

        // Turno Jugador 2
        int usadosJ2 = 0;
        turnoJugador(jugador2, stockJ2, puntosJ2, usadosJ2, stockJ1);
        system("pause");

        // chequeo de dados usados - suma o resta de los mismos.
        if (usadosJ2 > 0)
        {
            stockJ2 -= usadosJ2;
            stockJ1 += usadosJ2;
            cout << jugador2 << " pasa " << usadosJ2 << " dado(s) a " << jugador1 << ".\n";

            // Detecta si el jugador 2 se quedó sin dados
            if (stockJ2 == 0)
            {
                cout << jugador2 << " se quedó sin dados y gana el juego anticipadamente.\n";
                break;
            }
        }

        cout << "\nPuntajes:\n";
        cout << jugador1 << ": " << puntosJ1 << " puntos | Dados: " << stockJ1 << endl;
        cout << jugador2 << ": " << puntosJ2 << " puntos | Dados: " << stockJ2 << endl;
    }

    // Resultado final al salir del ciclo
    cout << "\n======= JUEGO TERMINADO =======\n";
    cout << jugador1 << ": " << puntosJ1 << " puntos | Dados: " << stockJ1 << endl;
    cout << jugador2 << ": " << puntosJ2 << " puntos | Dados: " << stockJ2 << endl;

    if (puntosJ1 > puntosJ2)
        cout << "Ganador: " << jugador1 << " \n";
    else if (puntosJ2 > puntosJ1)
        cout << "Ganador: " << jugador2 << " \n";
    else
        cout << "¡Empate!\n";
}
