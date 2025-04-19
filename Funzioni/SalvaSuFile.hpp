void SalvaSuFilePrompt(record Array[LunghezzaDatabase], unsigned int IndiceVuoto)
{
    //Dichiarazione variabili
    bool FileInvalido = true;
    string NomeFile;
    ofstream FileOutput;

    //Input con verifica
    while (FileInvalido)
    {
        //Output per l'utente
        wcout << "Inserisci il nome del file (* per sovrascivere database, ? per annullare salvataggio): ";
        getline(cin, NomeFile);

        //Controllo per caratteri speciali o non permessi
        if ((NomeFile.find('\\') != string::npos) || (NomeFile.find('%') != string::npos) || (NomeFile.find(':') != string::npos) || (NomeFile.find('|') != string::npos) || (NomeFile.find('"') != string::npos) || (NomeFile.find('<') != string::npos) || (NomeFile.find('>') != string::npos))
        {
            wcout << "Il nome del file non e' valido!" << endl;
        }
        else if (NomeFile.find('*') != string::npos)
        {
            FileInvalido = false;
            FileOutput.open("Batteri.csv");
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
    system("cls");
    if (NomeFile.find('?') != string::npos)
    {
        wcout << "Il file non e' stato salvato." << endl;
    }
    else
    {
        wcout << "Il file e' stato salvato." << endl;
    }
}

void SalvaSuFile(record Array[LunghezzaDatabase], unsigned int IndiceVuoto, ofstream &FileOutput)
{
    //Dichiarazione variabili
    unsigned int ContatoreArray = 0, ContatoreDati = 0;

    //Scrittura su file
    while (ContatoreArray < IndiceVuoto)
    {
        //Sezione inziale del file
        FileOutput << Array[ContatoreArray].Luogo << ';' << Array[ContatoreArray].Longitudine << ';' << Array[ContatoreArray].Latitudine << ';' << Array[ContatoreArray].NumeroSpecie << ';';

        //Scrittura batteri
        while (ContatoreDati < Array[ContatoreArray].NumeroSpecie)
        {
            FileOutput << Array[ContatoreArray].Dati[ContatoreDati].NomeBatterio << ';' << Array[ContatoreArray].Dati[ContatoreDati].Tipologia << ';' << Array[ContatoreArray].Dati[ContatoreDati].Concentrazione << ';';
            ContatoreDati++;
        };
        ContatoreDati = 0;
        ContatoreArray++;

        //Fine riga
        FileOutput << endl;
    }
}