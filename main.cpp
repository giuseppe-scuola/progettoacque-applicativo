#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>

#define LunghezzaDatabase 64
#define SpeciePerRecord 8


using namespace std;


struct batterio
{
    string NomeBatterio;
    string Tipologia;
    unsigned long Concentrazione;
};

struct record
{
    string Luogo;
    string Longitudine;
    string Latitudine;
    unsigned long NumeroSpecie;
    batterio Dati[SpeciePerRecord];
};


#include "Funzioni/intestazioni.hpp"


int main()
{
    //Inizializzazione programma
    SetConsoleOutputCP(65001);
    CONSOLE_SCREEN_BUFFER_INFO Informazioni;
    HANDLE StandardOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleMode(StandardOutput, ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    srand(time(NULL));
    system("cls");
    cout << "Benvenuto nell'applicativo per il progetto delle acque!\nNumero massimo di record: " << LunghezzaDatabase << "\nNumero di specie per record: " << SpeciePerRecord << endl;

    //Dichiarazione variabili
    bool Modificato = false, Termina = false;
    unsigned long Scelta, IndiceDatabase = 0, Contatore = 0;
    ifstream FileDatabase;
    record Database[LunghezzaDatabase];
    Azzera(Database, IndiceDatabase);

    //Controllo se il file esiste
    if (GetFileAttributes("Database.csv") != INVALID_FILE_ATTRIBUTES)
    {
        FileDatabase.open("Database.csv");
        ApriFile(Database, IndiceDatabase, FileDatabase);
        FileDatabase.close();
    }
    else
    {
        cout << "\033[33mAvviso: database non trovato! Verrà generato un nuovo file CSV.\033[0m" << endl;
    }

    //Loop infinito
    while (!Termina)
    {
        //Menù
        Scelta = Menu();

        //Gestione input dell'utente
        switch (Scelta)
        {
            case 0:
                Termina = true;
                break;
            case 1:
                if (IndiceDatabase < LunghezzaDatabase)
                {
                    Inserimento(Database, IndiceDatabase);
                    Modificato = true;
                }
                else
                {
                    cout << "Non è possibile inserire più elementi, hai raggiunto la capacità massima!" << endl;
                }
                break;
            case 2:
                if (IndiceDatabase == 0)
                {
                    cout << "Il database è vuoto." << endl;
                }
                else
                {
                    StampaArray(Database, IndiceDatabase);
                }
                break;
            case 3:
                if (IndiceDatabase == 0)
                {
                    cout << "Non ci sono record da modificare." << endl;
                }
                else
                {
                    Modifica(Database, IndiceDatabase);
                    Modificato = true;
                }
                break;
            case 4:
                if (IndiceDatabase == 0)
                {
                    cout << "Non ci sono record da cancellare." << endl;
                }
                else
                {
                    CancellaPrompt(Database, IndiceDatabase);
                    Modificato = true;
                }
                break;
            case 5:
                if (IndiceDatabase == 0)
                {
                    cout << "Non ci sono record tra i quali cercare." << endl;
                }
                else
                {
                    RicercaPrompt(Database, IndiceDatabase);
                }
                break;
            case 6:
                if (IndiceDatabase == 0)
                {
                    cout << "Non ci sono record per i quali sia possibile disegnare un grafico." << endl;
                }
                else
                {
                    Grafico(Database, IndiceDatabase);
                }
                break;
            default:
                cout << "\033[31mErrore: opzione non valida.\033[0m" << endl;
                break;
        }
    };

    //Pulizia schermo
    system("cls");

    //Prompt di salvataggio
    if (Modificato)
    {
        if (IndiceDatabase == 0)
        {
            cout << "Non c'è nulla da salvare nel database." << endl;
        }
        else
        {
            cout << "Ecco tutti i dati che verranno salvati:" << endl;
            StampaArray(Database, IndiceDatabase);
        }
        SalvaSuFilePrompt(Database, IndiceDatabase);
    }

    //Fine programma
    return 0;
}