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
