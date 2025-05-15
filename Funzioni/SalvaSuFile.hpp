void SalvaSuFilePrompt(record Array[LunghezzaDatabase], unsigned long IndiceVuoto)
{
    //Dichiarazione variabili
    bool FileInvalido = true;
    string NomeFile;
    ofstream FileOutput;

    //Input con verifica
    while (FileInvalido)
    {
        //Output per l'utente
        cout << "Inserisci il nome del file \033[36m(\033[3m*\033[23m per sovrascivere database, \033[3m?\033[23m per uscire senza)\033[0m: ";
        getline(cin, NomeFile);

        //Controllo per caratteri speciali o non permessi
        if ((NomeFile.find('\\') != string::npos) || (NomeFile.find('%') != string::npos) || (NomeFile.find(':') != string::npos) || (NomeFile.find('|') != string::npos) || (NomeFile.find('"') != string::npos) || (NomeFile.find('<') != string::npos) || (NomeFile.find('>') != string::npos))
        {
            cout << "Il nome del file non è valido!" << endl;
        }
        else if (NomeFile.find('*') != string::npos)
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
    system("cls");
    if (NomeFile.find('?') != string::npos)
    {
        cout << "\033[32mIl file non è stato salvato.\033[0m" << endl;
    }
    else
    {
        cout << "\033[32mIl file è stato salvato.\033[0m" << endl;
    }
}

void SalvaSuFile(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, ofstream &FileOutput)
{
    //Dichiarazione variabili
    unsigned long ContatoreArray = 0, ContatoreDati = 0;

    //Scrittura su file
    while (ContatoreArray < IndiceVuoto)
    {
        //Sezione inziale del file
        FileOutput << Array[ContatoreArray].Luogo << ';' << Array[ContatoreArray].Latitudine << ';' << Array[ContatoreArray].Longitudine << ';' << Array[ContatoreArray].NumeroSpecie << ';';

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