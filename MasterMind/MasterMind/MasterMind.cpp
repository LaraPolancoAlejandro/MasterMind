/*Este programa tiene la finalidad de simular el juego "MasterMind" en su dificultad mas baja y
otra dificultad que es como me gustaria que fuera el juego que nos mandaron a hacer.

Creado por Alejandro Lara ID:1106231
*/

#include <iostream> //Permite ejecutar "cout" y "cin"
#include <vector> // usada para el numero random
#include <random> //permite generar numeros random de 0 a un maximo//
#include <conio.h> //permite ejecutar el _getch()
#include <string> //me permite utilizar el getline en my try catch
#include <windows.h> // me permite colorear las letras y fondo del programa

using namespace std;

bool decisionprofe;
string Decision;
bool aux2;
int i=0;
int  g= 0;
int colori;
int Code[4] = {};
bool aux = true;
int SecretCode[4] = {};
string VolverJugarS;
bool VolverJugar = false;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int Codeinicio = 0;

bool SC1 = false, SC2 = false, SC3 = false, SC4 = false;



// Bienvenida e Inicio del Juego
void Color(int color) //funcion para dar colores a las letras
{
    SetConsoleTextAttribute(h, color);
}
void inicio() //menu inicial
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // variable que se utiliza para dar color

    cout << "\n BIENVENIDO MASTERMIND\n"<< endl;

    cout << " Adivina el \"SecretCode\"\n" << endl;
    
    
    
    cout << "| ?| ? | ? | ? | \n\n" << endl;;
    


    
    cout << " Como jugar:\n\n"; //instrucciones
    cout << " Debes ingresar un numero del 1 al 6 en cada casilla y fijarte en lo siguiente." << endl;
    Color(4); cout << " C"; Color(7); cout << " Significa \"Caliente\" lo que quiere decir que acertaste la posicion del numero." << endl;
    Color(6); cout << " T"; Color(7); cout << " Significa \"Tibio\" lo que quiere decir que el numero esta entre los que buscas pero no en la posicion correcta." << endl;
    Color(1); cout << " F"; Color(7); cout << " Significa \"Frio\" lo que quiere decir que el numero que escogiste no esta entre los que buscas." << endl;
    cout << "\n";
}
void Difficulty()
{
    cin.exceptions(istream::failbit);
    do {
        try 
        {
            inicio();
            cout << " Vas a jugar en facil o dificil [F/D]: ";
            cin >> Decision;
            aux2 = true;

            while (Decision != "F" && Decision != "D" && Decision != "f" && Decision != "d")
            {
                Color(4); cout << endl << " Solo exiten 2 dificultades facil o dificil " << endl << endl; Color(7);

                cout << " Vas a jugar en facil o dificil [F/D]: ";
                cin >> Decision;
            }
        }
        //capta si hubo algun error y pide intorducir datos validos
        catch (exception fail) {
            aux2 = false;
            Color(4); cout << endl << " Solo existen 2 dificultades [F/D]: " << endl << endl; Color(7);
            _getch();
            cin.clear();
            string tmp;
            getline(cin, tmp);
        }
    } while (aux2 == false);

    if (Decision == "F" || Decision == "f")
    {
        decisionprofe = false;
    }
    else
    {
        decisionprofe = true;
    }
}
void IntentoCounter()
{
    switch (i+1)
    {
    case 1:
        colori = 2;
        break;
    case 2:
        colori = 2;
        break;
    case 3:
        colori = 8;
        break;
    case 4:
        colori = 8;
        break;
    case 5:
        colori = 7;
        break;
    case 6:
        colori = 7;
        break;
    case 7:
        colori = 6;
        break;
    case 8:
        colori = 6;
        break;
    case 9:
        colori = 4;
        break;
    case 10:
        colori = 4;
        break;
    }
    cout << " Estas en el intento "; Color(colori); cout << i+1; Color(7); cout << "/"; Color(4); cout << "10"; Color(5); cout << endl << endl;
    Color(7);
}
void Getinput()
{
    for (size_t f = 0; f < 4; f++) //toma el input del usuario y lo almacena
    {
        cin.exceptions(istream::failbit);
        do {
            try {
                cout << " ingrese el valor de la casilla #" << f + 1 << ": ";
                cin >> Code[f];
                aux = true;
                while (Code[f] < 1 ^ Code[f] > 6)
                {
                    Color(4); cout << endl << " Solo estan permitidos valores entre el 1 y el 6" << endl << endl; Color(7);
                    cout << " ingrese el valor de la casilla #" << f + 1 << ": ";
                    cin >> Code[f];
                }
            }
            //capta si hubo algun error y pide introducir datos validos
            catch (exception fail) {
                aux = false;
                Color(4); cout << endl << " Solo estan permitidos valores entre el 1 y el 6" << endl << endl; Color(7);
                _getch();
                cin.clear();
                string tmp;
                getline(cin, tmp);
            }
        } while (aux == false);
    }
}
void Validator()
{
    for ( g = 0; g < 4; g++) //indica si las opciones introducidas existen, no existen y si estan en la posicion correcta.
    {
        bool exists = find(SecretCode, SecretCode + 4, Code[g]) != SecretCode + 4;

        if (exists)//verifica si existe
        {
            if (SecretCode[g] == Code[g]) //posicion correcta
            {
                switch (g)
                {
                case 1:
                    SC1 = true;
                    break;
                case 2:
                    SC1 = true;
                    break;
                case 3:
                    SC1 = true;
                    break;
                case 4:
                    SC1 = true;
                    break;
                default:
                    break;
                }
                cout << "  Casilla #" << g + 1 << ": " << Code[g];
                Color(4);
                cout << " C" << endl;
                Color(7);
            }
            if (SecretCode[g] != Code[g]) //existe pero no esta en el arreglo
            {
                cout << "  Casilla #" << g + 1 << ": " << Code[g];
                Color(6);
                cout << " T" << endl;
                Color(7);
            }

        }
        else {
            cout << "  Casilla #" << g + 1 << ": " << Code[g]; //no existe en el arreglo
            Color(1);
            cout << " F" << endl;
            Color(7);
        }

    }
}
void WinValidator()
{
    while (SecretCode[0] == Code[0] && SecretCode[1] == Code[1] && SecretCode[2] == Code[2] && SecretCode[3] == Code[3]) //verifica que todos los numeros esten en la posicion correcta
    {
        system("cls");
        inicio();
        cout << " Felicidades, ganaste\n" << endl;
        cout << " presiona \"R\" para volver a jugar: ";
        cin >> VolverJugarS;
        if (VolverJugarS == "R" || VolverJugarS == "r")
        {
            system("cls");
            Code[1] = SecretCode[2];
            VolverJugar = true;
            i = 10;
            system("cls");
        }
        else
        {
            exit(EXIT_SUCCESS);
        }
    }
}
void Intentosout()
{
    if (i == 10)
    {
        cout << " Mejor suerte en esta proxima "; Color(4); cout << 10; Color(7); cout << "/"; Color(4); cout << "10"; Color(7); cout << " presiona \"R\" para reiniciar la partida: "; //indica cuando ya no te quedan intentos
        cin >> VolverJugarS;
    }
}
void Replay()
{
    if (VolverJugarS == "R" || VolverJugarS == "r")
    {
        VolverJugar = true;
        system("cls");
    }
    else
    {
        exit(EXIT_SUCCESS);
    }
}
void juego()
{
    Difficulty();
    system("cls");
    //para saber cual codigo correr basado en la opinion del profesor
    if (decisionprofe == true)
    {
        do
        {
            vector<int> SecretCode1 = { 1, 2, 3, 4, 5, 6 }; //Arreglo que contiene los numeros enteros para que posteriormente se mezclan y se elijan 4 de ellos.
            random_device rd; //generador los numeros que puse en el arreglo
            mt19937 g(rd()); //genera la secuencia a partir de lo que le manda el random_device

            shuffle(SecretCode1.begin(), SecretCode1.end(), g); //se mezclan los numeros del 1 al 6

            for (size_t i = 0; i < 4; i++) //se toman solo 4 numeros de los 6 y se introducen en el "SecretCode"
            {
                SecretCode[i] = SecretCode1[i];
            }
            // numero de intentos a iterar
            for (i = 0; i < 10; i++)
            {
                inicio(); //variables solo esteticas
                IntentoCounter();
                Getinput();
                system("cls"); //limpia consola
                inicio();
                cout << " Estas en el intento "; Color(colori); cout << i+1; Color(7); cout << "/"; Color(4); cout << "10"; Color(5); cout << endl << endl;
                Color(7);
                Validator();
                cout << " " << endl << endl;
                _getch(); //espera alguna entrada del usuario.
                system("cls");
                WinValidator();

            }
            inicio();
            Intentosout();
            Replay();
            
        } while (VolverJugar == true);
    }

    if (decisionprofe == false)
    {
        do
        {
            inicio();          
            vector<int> SecretCode1 = { 1, 2, 3, 4, 5, 6 };
            random_device rd;
            mt19937 g(rd());

            shuffle(SecretCode1.begin(), SecretCode1.end(), g);

            for (size_t i = 0; i < 4; i++)
            {
                SecretCode[i] = SecretCode1[i];
            }

            // numero de intentos a iterar

            for (i = 0; i < 10; i++)
            {
                IntentoCounter();
                Getinput();
                cout << endl << endl;
                Validator();
                cout << " " << endl << endl;
                WinValidator();
            }
            system("cls");
            inicio();
            Intentosout();
            Replay();
        } while (VolverJugar == true);
    }
}
int main()
{
    inicio();
    cout << " Presionar cualquier tecla para iniciar a jugar\n" << endl;
    _getch();
    system("cls");
    juego();
    return 0;
}