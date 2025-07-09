#include "funciones.h"
#include <cstdlib>
#include "rlutil.h"
#include <ctime>
#include <string>
#include <vector>
#include <limits>

using namespace std;

void LineaHorizontal(int inicioX, int finX, int posicionY, string esquinaIzq = "*", string esquinaDer = "*")
{
    rlutil::locate(inicioX, posicionY);
    cout << esquinaIzq;

    for (int i = inicioX + 1; i < finX; i++)
    {
        cout << "-";
    }
    cout << esquinaDer;
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

//funcion tirar dados pasar caras por parametro.
int tirarDado(int CarasDados)
{
    return rand() % CarasDados + 1;
}

void MostrarValorDados(int dados[], int &stock){
    cout << "Valor de dados: ";
    for (int i = 0; i < stock; i++)
    {
        cout << "| " << dados[i] << " ";
    }
    cout << "|\n";
    cout << endl;
}

void MostrarStockJugadores(int dados[],int &numeroObjetivo, int &stock)
{
 // Tirar los dados disponibles segun (stock se recibe desde jugar)
    for (int i = 0; i < stock; i++)
    {
        dados[i] = tirarDado(6);
    }
    cout << "Dados stock:    ";
    for (int i = 0; i < stock; i++)
    {
        cout << "| " << i + 1 << " ";
    }
    cout << "|\n";
    // Para alinear con "Dados stock: "
    cout << "               ";
    for (int i = 0; i < stock; i++) {
    cout << "----";
    }
    cout << " [" << numeroObjetivo << "] <- NUMERO OBJETIVO" << endl;

    cout << "Valor de dados: ";
    for (int i = 0; i < stock; i++)
    {
        cout << "| " << dados[i] << " ";
    }
    cout << "|\n";
    cout << endl;
}

void Reglas(){
    rlutil::locate(20,1);
    cout << "|REGLAS Pagina 1/2|" << endl;
    rlutil::locate(20,2);
    cout << "> ¨COMO SE JUEGA? <" << endl;
    cout << "- Debes saber que el juego consiste de tres rondas" << endl;
    cout << "- Se inicia tirando dos dados de seis caras, el que saque el dado con mayor valor empieza la ronda" << endl;
    cout << "- Una vez iniciada la ronda tendras un stock de 6 dados, con sus respectivas caras estas se generaran aleatoriamente"<< endl << endl;
    rlutil::locate(1,8);
    cout << "Un ejemplo rapido" << endl;
    rlutil::locate(20,7);
    cout << "|1|2|3|4|5|6| <---- Dados stock" << endl;
    rlutil::locate(20,8);
    cout << "-------------" << endl;
    rlutil::locate(20,9);
    cout << "|4|1|4|3|1|6| <---- Valor de cada dado :)"<< endl << endl;

    cout << "- Cada ronda debes intentar deshacerte de tus dados llegando al Numero objetivo" << endl << endl;

    rlutil::locate(15,13);
    cout << "> ¨QUE ES EL NUMERO OBJETIVO? <" << endl;
    cout << "- El Numero Objetivo es la suma de dos dados de doce caras." << endl;
    cout << "- El Numero Objetivo es al que debes llegar con tus dados stock :)" << endl;
    cout << "- Mientras mas dados uses mas dados pasaras al contrincante y mas puntos ganaras" << endl;

    rlutil::locate(1,21);
    cout << "Otro ejemplo" << endl;
    rlutil::locate(14,18);
    cout << "Se tiran los dados de 12 caras" << endl;
    rlutil::locate(12,19);
    cout << "Dado uno: 6 + Dado dos: 9 que la suma de 6 + 9 da como resultado: 15" << endl << endl;

    rlutil::locate(20,20);
    cout << "|1|2|3|4|5|6|              <---- Dados stock" << endl;
    rlutil::locate(20,21);
    cout << "------------- Objetivo: 15 <---- NUMERO OBJETIVO " << endl;
    rlutil::locate(20,22);
    cout << "|4|1|4|3|1|6|              <---- Valor de cada dado :)"<< endl << endl;

    cout << "- Los dados objetivos (de 12 caras) son comunes para ambos jugadores" << endl;
    cout << "- El jugador debe intentar igualar este numero con la suma de algunos dados de su stock" << endl;
    cout << "- Si te llegas a equivocar al elegir algun dado en tu stock, no te preocupes podras volver a intentarlo" << endl << endl;
    rlutil::locate(12,28);
    cout << "Preciona cualquier tecla para pasar a la pagina dos." << endl;
    rlutil::anykey();
    rlutil::cls();

    cout << "> ­PERO TEN CUIDADO! <" << endl;
    cout << "- Si te pasas del numero objetivo, seras penalizado con un dado extra sacado del stock de tu rival" << endl;
    cout << "- Si tu contrincante te pasa todos tus dados, ­perderas automaticamente! sea la ronda que sea" << endl;
    cout << endl;
    cout << "- ENTONCES TUS OBJETIVOS SERAN:" << endl;
    cout << "- Pasar la mayor cantidad de dados a tu rival" << endl;
    cout << "- Intentar llegar al numero objetivo" << endl;
    cout << "- Obtener m s puntos que tu contrincante pasadas las 3 rondas" << endl;
    cout << endl;
    cout << "> ¨GANASTE? <" << endl;
    cout << "- Si ganaste y obtienes un puntaje alto seras galardonado en estadisticas \n  Felicidades pero ten en cuenta que alguien mas puede robar tu puesto" << endl;
    cout << "- Cuando el juego termine se declarara el ganador al que tuvo mas puntos o se quedo sin dados :)" << endl;
    cout << "- Si ganaste sacandote todos los dados del stock tendras 10.000 puntos mas los que venias acumulando" << endl;
    cout << endl;
    rlutil::locate(9,16);
    cout << "Bueno jugador o jugadora, ya te he explicado todo lo que tenias que saber ­A JUGAR!" << endl;
    rlutil::locate(24,18);
    cout << " > Preciona cualquier tecla para volver al menu <" << endl;
    rlutil::anykey();

}
void Creditos()
{
    Cuadro(27,6,67,17);
    rlutil::locate(42,4);
    cout << "|Materia|";
    rlutil::locate(33,5);
    cout << "|------Programacion 1------|";
    rlutil::locate(31,7);
    cout << "Juego inventado por: Angel Simon";
    rlutil::locate(38,9);
    cout << "Juego codeado por: " << endl;
    rlutil::locate(30,10);
    cout <<"Martin Daniel Guerre¤o LEGAJO: 33305" << endl;
    rlutil::locate(33,11);
    cout <<"Mauro Sinopoli LEGAJO: 31747" << endl;
    rlutil::locate(33,12);
    cout <<"Agustin Salto LEGAJO: 26201" << endl;
    rlutil::locate(29,13);
    cout <<"Leonardo Julian Sanchez LEGAJO: 31926" << endl;
    rlutil::locate(36,15);
    cout << "Creditos adicionales:";
    rlutil::locate(31,16);
    cout << "Libreria rlutil 2010 Tapio Vierros" << endl;
    rlutil::locate(26,19);
    cout << "Presione cualquier tecla para volver al menu" << endl;
    rlutil::anykey();
}

void Estadisticas(int puntosMax,string jugadorMax)
{

    if (jugadorMax == "" && puntosMax == 0) {
        rlutil::locate(49,13);
        cout << "No has jugado" << endl;
        rlutil::locate(30,13);
        cout << "No has jugado" << endl;
    }
    else{
        rlutil::locate(49,13);
        cout << "Jugador: " << jugadorMax << endl;
        rlutil::locate(30,13);
        cout << "Puntos: " << puntosMax << endl;
        }

    rlutil::locate(30,11);
    cout << "Puntos maximos";
    rlutil::locate(48,11);
    cout << "Nombre de jugador";

    rlutil::locate(29,9);
    cout << "|---------- ESTADISTICAS ----------|";
    LineaVertical(46,10,14);
    cout << endl << endl << endl;
    rlutil::locate(28,12);
    cout << "---------------------------------------";
    rlutil::locate(29,16);
    cout << "Presiona cualquier tecla para volver al menu" << endl;
    rlutil::anykey();
};
void menu()
{
    int puntosMax = 0;
    string jugadorMax = "";
    string jugador1="";
    string jugador2="";
    int opciones = 10, PosicionY = -3;
    rlutil::hidecursor();
    do
    {
        rlutil::cls();
        Cuadro(25,8,48,14);
        rlutil::locate(29,2);
        cout << "BIENVENIDOS A...\n"
             "    _______   ____________  _______    ______  ___    ____  ____  _____\n"
             "   / ____/ | / / ____/ __ \\/ ____/  | / / __ \\/   |  / __ \\/ __ \\/ ___/ \n"
             "  / __/ /  |/ / /_  / /_/ / __/ /   |/ / / / / /| | / / / / / / /\\__ \\ \n"
             " / /___/ /|  / __/ / _, _/ /___/ /|  / / _/ / ___ |/ /_/ / /_/ /___/ /\n"
             "/_____/_/ |_/_/   /_/ |_/_____/_/ |_/_____/_/  |_/_____/\\____//_____/\n" << endl;

        rlutil::locate(30,9);
        cout << "1 - JUGAR "<< endl;
        rlutil::locate(30,10);
        cout << "2 - REGLAS " << endl;
        rlutil::locate(30,11);
        cout << "3 - ESTADISTICAS "<< endl;
        rlutil::locate(30,12);
        cout << "4 - CREDITOS "<< endl;
        rlutil::locate(30,13);
        cout << "0 - SALIR " << endl;

        rlutil::locate(19,15);
        cout << "Presiona las flechitas para moverte";
        rlutil::locate(23,17);
        cout << "Presiona Enter para aceptar";
        rlutil::locate(28,12 + PosicionY);

        cout << (char)175 << endl;

        int tecla = rlutil::getkey();
        switch(tecla)
        {
        case 14:
            PosicionY--;
            if(PosicionY < -3)
            {
                PosicionY = -3;
            }
            break;
        /// Puede moverse 3 casillas a partir del -3 (-2,-1,0,1)
        case 15: /// Abajo
            PosicionY++;
            if(PosicionY > 1)
            {
                PosicionY = 1;
            }
            break;
        case 1: /// Enter
        {
            switch(PosicionY)
            {
            case -3:{
            string jugador1, jugador2;
            PedirNombresJugadores(puntosMax, jugadorMax, jugador1, jugador2);
            break;
            }
            case -2:

                rlutil::cls();
                Reglas();

                break;
            case -1:
                rlutil::cls();
                Cuadro(27,10,67 + jugadorMax.length(),14);
                Estadisticas(puntosMax,jugadorMax);
                break;
            case 0:
                rlutil::cls();
                Creditos();
                break;
            case 1: /// Salir
            {
                int opcionSalir = 0;
                bool confirmando = true;

                while(confirmando)
                {
                    rlutil::cls();
                    /// AnchoIzquierdo /Parte de Arriba/ Ancho Derecho /Parte de abajo
                    Cuadro(27,10,54,18);
                    rlutil::locate(30, 12);
                    cout << "¨Desea salir del juego?" << endl;

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
                            cout << "Gracias por jugar ­Volveremos a encontrarnos!" << endl << endl << endl << endl << endl;
                            rlutil::locate(28,15);
                            cout << "Presione cualquier tecla para salir del juego";
                            rlutil::anykey();
                            rlutil::cls();
                            opciones = 0;
                        }
                        else
                        {
                            opciones = 10;
                        }
                        confirmando = false;
                        break;
                            }
                        }
                    }
                }
            }
        }
    }while(opciones != 0);
}


//pedirmos nombre por cin y se los pasamos a quienEmpiezaRonda()
void PedirNombresJugadores(int &puntosMax,string &jugadorMax,string &jugador1, string &jugador2)
{
    rlutil::cls();

    rlutil::locate(30,12);
    cout << "Ingrese su nombre jugador/a 1: ";
    if (cin.peek() == '\n') cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, jugador1);
    rlutil::cls();

    rlutil::locate(30, 12);
    cout << "Ingrese su nombre jugador/a 2: ";
    getline(cin, jugador2);


    rlutil::cls();
    QuienEmpiezaRonda(jugador1,jugador2,puntosMax,jugadorMax);
}

// Realiza el sorteo de quien empieza.
void QuienEmpiezaRonda(string jugador1, string jugador2,int &puntosMax,string &jugadorMax)
{
    int dado1;
    int dado2;
    string ganador;

    rlutil::locate(16,2);
    cout << "[SIMULACION] " << jugador1 <<  " tira su dado a la mesa y su valor fue... " << endl;
    dado1 = tirarDado(6);
    rlutil::locate(26,4);
    cout << " El dado ha mostrado la cara: " << dado1 << endl;
    rlutil::locate(16,6);
    cout << "[SIMULACION] " << jugador2 << " tira su dado a la mesa y su valor fue... " << endl;
    dado2 = tirarDado(6);
    rlutil::locate(26,8);
    cout << " El dado ha mostrado la cara: " << dado2 << endl;


    while (dado1 == dado2)
    {
        rlutil::locate(33,10);
        cout << "­FUE UN EMPATE!" << endl;
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



// funcion jugar se encarga de los stocks de dados y puntaje,le pasa a turnojugador parametros de referencia nombre,stock,puntos,usados,dadoscontrincante.
void jugar(string jugador1, string jugador2,int &puntosMax,string &jugadorMax)
{
    // cantidad de rondas iniciales
    const int RONDAS = 3;

    // stocks de dados de jugadores
    int dadosStockJ1 = 6;
    int dadosStockJ2 = 6;
    // puntos de jugadores
    int puntosJ1 = 0;
    int puntosJ2 = 0;

    // ciclo de rondas iniciado dentro se suman puntos y se suman o descuentan dados.
    for (int ronda = 1; ronda <= RONDAS; ronda++)
    {
        cout << "\n                 ======= RONDA " << ronda << " =======\n";

        // Turno Jugador 1
        int CantidadUsadosJ1 = 0;
        // pasamos por parametros informacion.
        turnoJugador(jugador1, dadosStockJ1, puntosJ1, CantidadUsadosJ1, dadosStockJ2);

        // chequeo de dados usados y suma o resta de los mismos.
        if (CantidadUsadosJ1 > 0)
        {
            dadosStockJ1 -= CantidadUsadosJ1;
            dadosStockJ2 += CantidadUsadosJ1;
            cout << jugador1 << " pasa " << CantidadUsadosJ1 << " dado(s) a " << jugador2 << ".\n";

            // Detecta si el jugador 1 se quedâ”œÃ­ sin dados
            if (dadosStockJ1 == 0)
            {
                cout << jugador1 << " se quedo sin dados y gana el juego anticipadamente.\n";
                break;
            }
        }
        cout << endl;
        cout << "Presiona cualquier tecla para pasar a la siguiente ronda";
        cout << endl;
        rlutil::anykey();
        cout << "\n======= Puntajes =======\n";
        cout << jugador1 << ": " << puntosJ1 << " puntos | Dados: " << dadosStockJ1 << endl;
        cout << jugador2 << ": " << puntosJ2 << " puntos | Dados: " << dadosStockJ2 << endl;
        cout << "========================";
        cout << endl;

        // Turno Jugador 2
        int CantidadUsadosJ2 = 0;
        turnoJugador(jugador2, dadosStockJ2, puntosJ2, CantidadUsadosJ2, dadosStockJ1);

        // chequeo de dados usados - suma o resta de los mismos.
        if (CantidadUsadosJ2 > 0)
        {
            dadosStockJ2 -= CantidadUsadosJ2;
            dadosStockJ1 += CantidadUsadosJ2;
            cout << jugador2 << " pasa " << CantidadUsadosJ2 << " dado(s) a " << jugador1 << ".\n";

            // Detecta si el jugador 2 se quedo sin dados
            if (dadosStockJ2 == 0)
            {
                cout << jugador2 << " se quedo sin dados y gana el juego anticipadamente.\n";
                break;
            }
        }
        cout << endl;
        cout << "Presiona cualquier tecla para pasar a la siguiente  y ultima ronda";
        cout << endl;
        rlutil::anykey();
        cout << "\n======= Puntajes =======\n";
        cout << jugador1 << ": " << puntosJ1 << " puntos | Dados: " << dadosStockJ1 << endl;
        cout << jugador2 << ": " << puntosJ2 << " puntos | Dados: " << dadosStockJ2 << endl;
        cout << "========================";
        cout << endl;

    }
    // Resultado final al salir del ciclo
    cout << "\n======= JUEGO TERMINADO =======\n";
    cout << jugador1 << ": " << puntosJ1 << " puntos | Dados: " << dadosStockJ1 << endl;
    cout << jugador2 << ": " << puntosJ2 << " puntos | Dados: " << dadosStockJ2 << endl;

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
        cout << "                                SE DECLARO: Ganador: " << jugador2 << " \n";
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
        cout << "                                SE DECLARO: Empate!\n" << endl;
        cout << "                                GRACIAS POR JUGAR :D";

    }
    cout << endl << endl;
    cout << "                   -----------------------------------------------"<< endl;;
    cout << "                  | Presiona cualquier tecla para volver al menu |" << endl;
    cout << "                   -----------------------------------------------" << endl;
    cout << endl;
    rlutil::anykey();
}


//recibimos por parametro las referencias a ser modificadas entre rondas.

void turnoJugador(string nombre, int &stock, int &puntos, int &dadosUsados, int &stockDadosContrincante)
{
    // maximo de dados que un jugador puede tener
    int const MAXIMOSDADOS = 12;
    int numeroObjetivo;
    // Vector inicializado en 12 posiciones.
    int dados[MAXIMOSDADOS];
    // Vector booleanos para marcar dados ya utilizados.
    bool usados[MAXIMOSDADOS]={};

    for(int i = 0; i < MAXIMOSDADOS -1; i++){
        dados[i] = false;
    }

    // Inicia en 0 los dados utilizados.
    dadosUsados = 0;

    // Tirar dados
    int dado1 = tirarDado(12);
    int dado2 = tirarDado(12);
    // resultado de dados
    numeroObjetivo = dado1 + dado2;

    cout << "                    Turno de: " << nombre << endl;
    cout << "[SIMULACION] " << nombre << " tira los dos dados de 12 caras.."<< endl;
    cout << endl;
    cout << "       El primer dado ha mostra la cara: " << dado1 << endl;
    cout << "       El segundo dado ha mostra la cara: " << dado2 << endl;
    cout << endl;
    cout << "La suma de los dos dados es: [" << numeroObjetivo <<"] <- NUMERO OBJETIVO"<< endl;
    cout << endl;

    MostrarStockJugadores(dados,numeroObjetivo,stock);

    // inicializacion de suma y dados usados

    int sumaSeleccionada = 0;
    int cantidadUsados = 0;

    // inicializacion del ciclo de eleccion de dados, (mientras que suma sea menor a objetivo)

    while (sumaSeleccionada < numeroObjetivo)
    {
        // Usuario ingresa numero para eleccion.
        cout << "Elegi el numero de dado stock (0 para rendirte en la ronda y pasar turno): ";
        int dadosElegidos;
        cin >> dadosElegidos;

          if(cin.fail()){
            cout << "Elegiste un valor incorrecto, ingresa un numero por favor."<< endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // verificamos la eleccion si es igual a 0,si es asi penaliza con un dado que se resta del oponente.
        if (dadosElegidos == 0)
        {
            cout << endl;
            cout << "Te rendiste. Pierdes tu turno y te han penalizado con un dado del contrincante.\n";

            if (stockDadosContrincante > 1)
            {
                stockDadosContrincante--;
                stock++;
            }
            else
            {
                cout << "Tienes suerte! tu contrincante no puede pasarte dados porque no tiene mas de uno" << endl;
            }

            break;
        }
        else if (dadosElegidos < 1 || dadosElegidos > stock)
        {
            cout << endl;
            cout << "Elegiste una opcion incorrecta. Pierdes tu turno y te han penalizado con un dado del contrincante.\n" << endl;


            if (stockDadosContrincante > 1)
            {
                stockDadosContrincante--;
                stock++;
            }
            else
            {
                cout << "Tienes suerte! tu contrincante no puede pasarte dados porque no tiene mas de uno" << endl;
            }
            break;
        }
        else if (usados[dadosElegidos - 1])
        {
            cout << "Ese dado ya fue usado. Elegido otro." << endl;
            continue;
        }

        usados[dadosElegidos - 1] = true;

        sumaSeleccionada += dados[dadosElegidos - 1];

        // mostramos por pantalla los dados elegidos su valor y ademas la suma de los mismos.

        cout << "Elegiste el dado [" << dadosElegidos << "] con valor " << dados[dadosElegidos - 1] << endl;;
        cout << endl;
        cout << "[Tu suma es] = " << sumaSeleccionada << endl;


        cantidadUsados++;


        if (cantidadUsados == stock && sumaSeleccionada == numeroObjetivo)
        {
            cout << "Felicitaciones! Utilizaste todos tus dados, ganaste automtomaticamente y sumaste 10.000 puntos!\n" << endl;
            puntos += 10000;
            cout << "Tu puntaje es: [" << puntos << "]" << endl;
            dadosUsados = cantidadUsados;
            break;
        }

        // Verifica si suma se paso del objetivo y penaliza.
        if (sumaSeleccionada > numeroObjetivo)
        {
            cout << "Te has pasado del objetivo! La suma dio " << sumaSeleccionada << "\n";
            if (stockDadosContrincante > 1)
            {
                stockDadosContrincante--;
                stock++;
            }
            cout << "Como tu suma fue incorrecta y te han penalizado con un dado del contrincante :( . \n";
            break;
        }

        // Verificamos si la suma es igual a objetivo.
        if (sumaSeleccionada == numeroObjetivo)
        {
            cout << "Tirada exitosa ! Objetivo alcanzado con " << cantidadUsados << " dados!\n";
            int puntosGanados = cantidadUsados * sumaSeleccionada;
            puntos += puntosGanados;
            dadosUsados = cantidadUsados;
            cout << "Ganaste " << puntosGanados << " puntos." << endl;
            break;
        }
    }
}
