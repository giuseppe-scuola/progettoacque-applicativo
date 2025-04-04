#include <iostream>
#include <iomanip>
#include <fstream>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define PulisciSchermo system("cls")
#else
#define PulisciSchermo system("clear")
#endif

#define LunghezzaDatabase 64
#define SpeciePerRecord 8


struct batterio
{
    std::string NomeBatterio;
    double Concentrazione;
};

struct record
{
    std::string Luogo;
    std::string Longitudine;
    std::string Latitudine;
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
    std::cout << "Benvenuto nell'applicativo per il progetto delle acque!\nNumero massimo di record: " << LunghezzaDatabase << "\nNumero di specie per record: " << SpeciePerRecord << std::endl;
    std::ifstream FileDatabase("Batteri.csv");
    ApriFile(Database, IndiceDatabase, FileDatabase);
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
                std::cout << "Questa opzione non esiste!" << std::endl;
                break;
        }
    };

    //Fine programma
    return 0;
}
