#include <iostream>
#include <fstream>
#include <sstream>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define PulisciSchermo system("cls")
#else
#define PulisciSchermo system("clear")
#endif

#define LunghezzaDatabase 64
#define SpeciePerRecord 8


using namespace std;


struct batterio
{
    string NomeBatterio;
    double Concentrazione;
};

struct record
{
    string Luogo;
    string Longitudine;
    string Latitudine;
    unsigned int NumeroSpecie;
    batterio Dati[SpeciePerRecord];
};


#include "Funzioni/intestazioni.hpp"


int main()
{
    //Dichiarazione variabili
    bool Modificato = false, Termina = false;
    unsigned int IndiceDatabase = 0, Contatore = 0;
    int Scelta = -1;
    record Database[LunghezzaDatabase];

    //Inizializzazione programma
    setlocale(LC_ALL, "italian");
    cout << "Benvenuto nell'applicativo per il progetto delle acque!\nNumero massimo di record: " << LunghezzaDatabase << "\nNumero di specie per record: " << SpeciePerRecord << endl;
    ifstream FileDatabase("Batteri.csv");

    //Controllo se il file esiste
    if (FileDatabase.good())
    {
        ApriFile(Database, IndiceDatabase, FileDatabase);
    }
    else
    {
        cout << "Database non trovato! Verrà generato un nuovo file CSV." << endl;
    }
    FileDatabase.close();

    //Loop infinito
    while ((Contatore < LunghezzaDatabase) && (Termina != true))
    {
        //Menù
        Scelta = Menu();

        //Pulizia schermo
        PulisciSchermo;

        //Gestione input dell'utente
        switch (Scelta)
        {
            case 0:
                Termina = true;
                SalvaSuFilePrompt(Database, IndiceDatabase);
                break;
            case 1:
                PulisciSchermo;
                Inserimento(Database, IndiceDatabase);
                break;
            case 2:
                PulisciSchermo;
                Stampa(Database, IndiceDatabase);
                break;
            case 3:
                PulisciSchermo;
                Modifica(Database, IndiceDatabase);
                break;
            case 4:
                PulisciSchermo;
                CancellaPrompt(Database, IndiceDatabase);
                break;
            case 5:
                PulisciSchermo;
                Ricerca(Database, IndiceDatabase);
                break;
            case 6:
                Grafico(Database, IndiceDatabase);
                break;
            default:
                cout << "Questa opzione non esiste!" << endl;
                break;
        }
    };

    //Fine programma
    return 0;
}
