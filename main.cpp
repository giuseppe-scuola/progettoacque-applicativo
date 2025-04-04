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


struct record;
struct batterio;

#include "Funzioni/intestazioni.hpp"


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

void ApriFile(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto, std::ifstream &FileInput)
{}

int Menu()
{
    int Choose;
    std::cout<<"inserisci:"<<std::endl;
    std::cout<<"1- per fare l'inserimento"<<std::endl;
    std::cout<<"2- per stampare"<<std::endl;
    std::cout<<"3- per fare una modifica"<<std::endl;
    std::cout<<"4- per cancellare"<<std::endl;
    std::cout<<"5- per fare la ricerca"<<std::endl;
    std::cout<<"6- per realizzare il grafico"<<std::endl;
    std::cout<<"0- per uscire e salvare sul file"<<std::endl;
    std::cin>>Choose;
    return(Choose);
}

bool InputInt(unsigned int &Valore)
{
    //Dichiarazione variabili
    bool Convertibile;
    std::string Temp;

    //Input dalla console
    std::getline(std::cin, Temp);

    //Controllo per caratteri non numerici
    try
    {
        Valore = std::stoul(Temp);
        Convertibile = true;
    }
    catch (...)
    {
        Convertibile = false;
    }

    //Risultato della funzione
    return Convertibile;
}

void Inserimento(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    int Scelta;

    //scelta tra inserimento massivo o singolo
    std::cout<<"Che tipo di inserimento vuoi fare?"<<std::endl;
    std::cout<<"1)Singolo"<<std::endl;
    std::cout<<"2)Massivo"<<std::endl;
    std::cin>>Scelta;

    switch(Scelta){

        case 1: PulisciSchermo;
                std::cout<<"Hai scelto l'inserimento singolo"<<std::endl;
                std::cout<<std::endl;

                std::cout<<"Qual è il nome del luogo?"<<std::endl;
                Nome_Luogo(Array, IndiceVuoto);

                PulisciSchermo;
                std::cout<<"Inserisci il numero della specie: ";
                std::cin>>Array[IndiceVuoto].NumeroSpecie;
                std::cout<<std::endl;

                for(int k=0, k<SpeciePerRecord, k++){
                    std::cout<<"Inserisci il nome del "<<k+1<<"° batterio: "<<std::endl;
                    std::cin>>Array[IndiceVuoto].NomeBatterio;
                    std::cout<<"Inserisci la concentrazione"<<std::endl;
                    std::cin>>Array[IndiceVuoto].Concentrazione;
                }

        break;
        case 2: PulisciSchermo;
                int Num_Massivi;
                std::cout<<"Hai scelto l'inserimento massivo"<<std::endl;
                std::cout<<std::endl;

                std::cout<<"Quanti dati vuoi inserire? ";
                std::cin>>Num_Massivi;
                for(int i=0; i<Num_Massivi; i++)
                {
                    std::cout<<"Qual è il nome del "<<i+1"° luogo?"<<std::endl;
                    Nome_Luogo(Array, IndiceVuoto);
                    PulisciSchermo;
                    std::cout<<"Inserisci il numero della specie: ";
                    std::cin>>Array[IndiceVuoto].NumeroSpecie;
                    std::cout<<std::endl;
                    for(int j=0; j<SpeciePerRecord; j++){
                        std::cout<<"Inserisci il nome del "<<j+1<<"° batterio: "<<std::endl;
                        std::cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio;
                        std::cout<<"Inserisci la concentrazione"<<std::endl;
                        std::cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione;
                    }
                }
        break;
        default: std::cout<<"Opzione non valida."<<std::endl;
        break;
    }
    IndiceVuoto++;
    return;
}

bool InputDouble(double &Valore)
{
    //Dichiarazione variabili
    bool Convertibile;
    std::string Temp;

    //Input dalla console
    std::getline(std::cin, Temp);

    //Controllo per caratteri non numerici
    try
    {
        Valore = std::stod(Temp);
        Convertibile = true;
    }
    catch (...)
    {
        Convertibile = false;
    }

    //Risultato della funzione
    return Convertibile;
}

void Stampa(record Array[LunghezzaDatabase], unsigned int IndiceVuoto)
{
    int conta=0;
    while(conta<=IndiceVuoto){
        std::cout<<Array[IndiceVuoto].Latitudine<<"|"<<Array[IndiceVuoto].Longitudine<<<<"|"<<Array[IndiceVuoto].NumeroSpecie<<'\t';
        for(int k=0; k<8; k++){
            std::cout<<Array[IndiceVuoto].Dati[k].NomeBatterio;
            std::cout<<Array[IndiceVuoto].Dati[k].Concentrazione;
        }
        conta++;
        std::cout<<std::endl;
    }
    return;
}

void Modifica(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{}

void CancellaPrompt(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{}

void Cancella(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto, unsigned int DaRimuovere)
{}

void Ricerca(record Array[LunghezzaDatabase], unsigned int IndiceVuoto)
{}

void Grafico(record Array[LunghezzaDatabase], unsigned int IndiceVuoto)
{
    #if defined(_WIN32) || defined(_WIN64)
    //Codice qui
    #else
    std::cout << "Funzione non supportata su questo sistema operativo..." << std::endl;
    #endif
}

void Nome_Luogo(record Vector[LunghezzaDatabase], unsigned int Indice)
{
    int Scelta;
    std::cout<<"1)Campana"<<std::endl;
    std::cout<<"2)Grotte Di Stiffe"<<std::endl;
    std::cout<<"3)Vetoio"<<std::endl;
    std::cout<<"4)Barete"<<std::endl;
    std::cout<<"5)Stazione dell’Aquila"<<std::endl;
    std::cout<<"6)Sassa"<<std::endl;
    std::cout<<"7)Pizzoli"<<std::endl;
    std::cin>>Scelta;

    switch(Scelta){
        case 1: Vector[Indice].Luogo="Campana";
                Vector[Indice].Latitudine="42° 14' 48.829'' N";
                Vector[Indice].Longitudine="13° 34' 4.494'' E";
        break;
        case 2: Vector[Indice].Luogo="Grotte Di Stiffe";
                Vector[Indice].Latitudine="42° 15' 15.012'' N";
                Vector[Indice].Longitudine="13° 32' 28.183'' E";
        break;
        case 3: Vector[Indice].Luogo="Vetoio";
                Vector[Indice].Latitudine="42° 21′ 09.4'' N";
                Vector[Indice].Longitudine="13° 22′ 40.36'' E";
        break;
        case 4: Vector[Indice].Luogo="Barete";
                Vector[Indice].Latitudine="42° 26' 57.156'' N ";
                Vector[Indice].Longitudine="13° 16' 50.102'' E ";
        break;
        case 5: Vector[Indice].Luogo="Stazione dell’Aquila";
                Vector[Indice].Latitudine="42° 21' 3.924'' N;
                Vector[Indice].Longitudine="13° 23' 5.69'' E ";
        break;
        case 6: Vector[Indice].Luogo="Sassa";
                Vector[Indice].Latitudine="42° 21′ 07.44'' N";
                Vector[Indice].Longitudine="13° 17′ 57.42'' E";
        break;
        case 7: Vector[Indice].Luogo="Pizzoli";
                Vector[Indice].Latitudine="42° 26' 9.762'' N";
                Vector[Indice].Longitudine="13° 18' 4.378'' E ";
        break;
    }
}

void SalvaSuFilePrompt(record Array[LunghezzaDatabase], unsigned int IndiceVuoto)
{
    //Dichiarazione variabili
    bool FileInvalido = true;
    std::string NomeFile;
    std::ofstream FileOutput;

    //Input con verifica
    while (FileInvalido)
    {
        //Output per l'utente
        std::cout << "Inserisci il nome del file (* per sovrascivere database, ? per annullare salvataggio): ";
        std::getline(std::cin, NomeFile);

        //Controllo per caratteri speciali o non permessi
        if ((NomeFile.find('\\') != std::string::npos) || (NomeFile.find('%') != std::string::npos) || (NomeFile.find(':') != std::string::npos) || (NomeFile.find('|') != std::string::npos) || (NomeFile.find('"') != std::string::npos) || (NomeFile.find('<') != std::string::npos) || (NomeFile.find('>') != std::string::npos))
        {
            std::cout << "Il nome del file non è valido!" << std::endl;
        }
        else if (NomeFile.find('?') != std::string::npos)
        {
            FileInvalido = false;
        }
        else if (NomeFile.find('*') != std::string::npos)
        {
            FileInvalido = false;
            FileOutput.open("Database.csv");
            SalvaSuFile(Array, IndiceVuoto, FileOutput);
            FileOutput.close();
        }
        else
        {
            FileInvalido = false;
            FileOutput.open(NomeFile);
            SalvaSuFile(Array, IndiceVuoto, FileOutput);
            FileOutput.close();
        }
    }

    //Pulizia schermo e prompt di fine programma
    PulisciSchermo;
    std::cout << "Il file è stato salvato." << std::endl;
}

void SalvaSuFile(record Array[LunghezzaDatabase], unsigned int IndiceVuoto, std::ofstream &FileOutput)
{
    //Dichiarazione variabili
    unsigned int Contatore = 0, ContatoreSpecie = 0;

    //Scrittura su file
    while (Contatore < IndiceVuoto)
    {
        //Sezione inziale del file
        FileOutput << Array[Contatore].Luogo << ';' << Array[Contatore].Longitudine << ';' << Array[Contatore].Latitudine << ';' << Array[Contatore].NumeroSpecie << ';';

        //Scrittura batteri
        while (ContatoreSpecie < Array[Contatore].NumeroSpecie)
        {
            FileOutput << Array[Contatore].Dati[Contatore].NomeBatterio << ';' << Array[Contatore].Dati[Contatore].Concentrazione << ';';
            ContatoreSpecie++;
        };
        ContatoreSpecie = 0;
        Contatore++;

        //Fine riga
        FileOutput << std::endl;
    }
}
