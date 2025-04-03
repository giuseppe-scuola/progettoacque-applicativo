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


void ApriFile(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto, std::ifstream &FileInput);

int Menu();
bool InputInt(unsigned int &Valore);

void Inserimento(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto);
bool InputDouble(double &Valore);

void Stampa(record Array[LunghezzaDatabase], unsigned int IndiceVuoto);

void Modifica(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto);

void CancellaPrompt(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto);
void Cancella(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto, unsigned int DaRimuovere);

void Ricerca(record Array[LunghezzaDatabase], unsigned int IndiceVuoto);

void Grafico(record Array[LunghezzaDatabase], unsigned int IndiceVuoto);

void SalvaSuFilePrompt(record Array[LunghezzaDatabase], unsigned int IndiceVuoto);
void SalvaSuFile(record Array[LunghezzaDatabase], unsigned int IndiceVuoto, std::ofstream &FileOutput);


struct batterio
{
    std::string NomeBatterio;
    double Concentrazione;
};

struct record
{
    int Luogo;
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

int Menu() //divertiti federi
{}

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
{}

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
{}

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
