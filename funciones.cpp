
#include "funciones.h"
#include <cstdlib>
#include "rlutil.h"
#include <ctime>
#include <string>

using namespace std;

int dados6 = 6;
int dados12 = 12;

void LineaHorizontal(int inicioX, int finX, int posicionY, char esquinaIzq, char esquinaDer)
{

    rlutil::locate(inicioX, posicionY);
    cout << esquinaIzq; /// É

    for (int i = inicioX + 1; i < finX; i++)
    {
        cout << "Í";
    }
    cout<< esquinaDer; /// »
}

void LineaVertical(int posicionX, int inicioY, int finY)  /// Dibuja una linea en vertical en Y
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
    LineaHorizontal(inicioX, finX, finY,    'È', '¼');

    LineaVertical(inicioX, inicioY, finY);
    LineaVertical(finX, inicioY, finY);
}

void menu()
{
    int opciones = 9, PosicionY;

    rlutil::hidecursor(); /// Oculta el cursor de la pantalla
    Cuadro(25,11,48,16);
    do
    {
        rlutil::cls();

        ///    X  Y   X  Y
        Cuadro(25,11,48,16);
        /*
        X1 = IZQ
        Y1 = ARRIBA
        X2 = DER
        Y2 = ABAJO
        */
        rlutil::locate(29,5); /// Ubica en pantalla los couts (x, y)
        cout << "­BIENVENIDOS A...\n"
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
        cout << "  "; /// Esto es para ir borrando la flecha de selecci¢n mediante

        cout << (char)175 << endl; /// Muestra el CHAR de 175 (ASCII)

        int tecla = rlutil::getkey(); /// devuelve un entero que representa la letra que presiono en el teclado

        switch(tecla)
        {
        /// ¨Por qu‚ 0?, por que no quiero que vaya m s de arriba (0 = JUGAR)
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
                PedirNombresJugadores();
                break;
            case 3:
                /// SALIR
                opciones = 0;
                rlutil::cls();
                Cuadro(25,3,55,5);
                /*
                X1 = IZQ
                Y1 = ARRIBA
                X2 = DER (Si sumo se agranda, si resto se resta :D)
                Y2 = ABAJO
                */
                rlutil::locate(30,4);
                cout << "Hasta la vista, baby" << endl;
            }
            break;
        }
        rlutil::locate(26, 12 + PosicionY);
        cout << (char)175 << endl;

        }
    }
    while(opciones != 0);
}



int tirarDado(int CarasDados)
{
    return rand() % CarasDados + 1;
}


void PedirNombresJugadores()
{
    string jugador1;
    string jugador2;

    rlutil::cls();
    rlutil::locate(30,12);
    cout << "Ingrese su nombre jugador/a 1: ";
    cin >> jugador1;
    rlutil::cls();
    rlutil::locate(30,12);
    cout << "Ingrese su nombre jugador/a 2: ";
    cin >> jugador2;
    rlutil::cls();
    QuienEmpiezaRonda(jugador1,jugador2);
    system("pause");


}

// VER EN CASO QUE EMPATE SE VEAN LOS NUEVOS RESULTADOS.
void QuienEmpiezaRonda(string jugador1, string jugador2)
{

    int dado1;
    int dado2;
    string ganador;

    rlutil::locate(30,2);
    cout << jugador1 << " tira su dado.. " << endl;
    dado1 = tirarDado(dados6);
    rlutil::locate(30,3);
    cout << "El dado de "<< jugador1 << " es: " << dado1 << endl;
    rlutil::locate(30,4);
    cout << jugador2 << " tira su dado.. " << endl;
    dado2 = tirarDado(dados6);
    rlutil::locate(30,5);
    cout << "El dado de "<< jugador2 << " es: " << dado2 << endl;


    while (dado1 == dado2)
    {
        rlutil::locate(30,6);
        cout << "Empate. Vuelven a   tirar los dados.\n";

        dado1 = tirarDado(dados6);
        dado2 = tirarDado(dados6);

        rlutil::locate(30,7);
        cout << jugador1 << " saco: " << dado1 << endl;
        rlutil::locate(30,8);
        cout << jugador2 << " saco: " << dado2 << endl;
    }

    if (dado1 > dado2)
    {
        rlutil::locate(30,7);
        cout << " Empieza: " << jugador1 << endl;
        ganador = jugador1;
    }
    else
    {
        rlutil::locate(30,7);
        cout << " Empieza: " << jugador2 << endl;
        ganador = jugador2;
    }
        jugar(jugador1,jugador2,ganador);

}


void jugar(string jugador1,string jugador2,string ganador)
{

        cout << jugador1 << " jugador1: " << endl;
        cout << jugador2 << " jugador2: " << endl;
        cout << ganador  << " ganador: "  << endl;

}







