#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

#define LunghezzaDatabase 64
#define SpeciePerRecord 8


using namespace std;


struct batterio
{
    string NomeBatterio;
    string Tipologia;
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
    //Inizializzazione programma
    srand(time(NULL));
    SetConsoleOutputCP(65001);
    cout << "Benvenuto nell'applicativo per il progetto delle acque!\nNumero massimo di record: " << LunghezzaDatabase << "\nNumero di specie per record: " << SpeciePerRecord << endl;

    //Dichiarazione variabili
    bool Modificato = false, Termina = false;
    unsigned int Scelta, IndiceDatabase = 0, Contatore = 0;
    ifstream FileDatabase;
    record Database[LunghezzaDatabase];
    Azzera(Database, IndiceDatabase);

    //Controllo se il file esiste
    if (GetFileAttributes("Batteri.csv") != INVALID_FILE_ATTRIBUTES)
    {
        FileDatabase.open("Batteri.csv");
        ApriFile(Database, IndiceDatabase, FileDatabase);
        FileDatabase.close();
    }
    else
    {
        cout << "Database non trovato! Verrà generato un nuovo file CSV." << endl;
    }

    //Loop infinito
    while (!Termina)
    {
        //Menù
        Scelta = Menu();

        //Pulizia schermo
        system("cls");

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
                StampaArray(Database, IndiceDatabase);
                break;
            case 3:
                Modifica(Database, IndiceDatabase);
                Modificato = true;
                break;
            case 4:
                CancellaPrompt(Database, IndiceDatabase);
                Modificato = true;
                break;
            case 5:
                RicercaPrompt(Database, IndiceDatabase);
                break;
            case 6:
                Grafico(Database, IndiceDatabase);
                break;
            default:
                cout << "Questa opzione non esiste!" << endl;
                break;
        }
    };

    //Prompt di salvataggio
    if (Modificato)
    {
        SalvaSuFilePrompt(Database, IndiceDatabase);
    }

    //Fine programma
    return 0;
}
