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
        cout << "Inserisci il nome del file (* per sovrascivere database, ? per annullare salvataggio): ";
        getline(cin, NomeFile);

        //Controllo per caratteri speciali o non permessi
        if ((NomeFile.find('\\') != string::npos) || (NomeFile.find('%') != string::npos) || (NomeFile.find(':') != string::npos) || (NomeFile.find('|') != string::npos) || (NomeFile.find('"') != string::npos) || (NomeFile.find('<') != string::npos) || (NomeFile.find('>') != string::npos))
        {
            cout << "Il nome del file non e' valido!" << endl;
        }
        else if (GetFileAttributes(NomeFile) == INVALID_FILE_ATTRIBUTES)
        {
            cout << "Il nome del file non e' valido!" << endl;
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
        cout << "Il file non e' stato salvato." << endl;
    }
    else
    {
        cout << "Il file e' stato salvato." << endl;
    }
}

void SalvaSuFile(record Array[LunghezzaDatabase], unsigned int IndiceVuoto, ofstream &FileOutput)
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
        FileOutput << endl;
    }
}
