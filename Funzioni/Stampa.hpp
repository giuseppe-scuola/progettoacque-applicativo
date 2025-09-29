void StampaArray(record Array[LunghezzaDatabase], unsigned long IndiceVuoto)
{
    //Dichiarazione variabili
    unsigned long ContatoreArray = 0, ContatoreDati = 0;

    //Loop per la stampa
    while (ContatoreArray < IndiceVuoto)
    {
        //Stampa dei metadati
        cout << "\033[1m[RECORD NUMERO " << ContatoreArray + 1 << "]\033[22m" << endl;
        cout << "Luogo di raccolta: " << Array[ContatoreArray].Luogo << " (" << Array[ContatoreArray].Latitudine << ", " << Array[ContatoreArray].Longitudine << ");" << endl << endl;
        
        //Stampa dei dati
        while (ContatoreDati < Array[ContatoreArray].NumeroSpecie)
        {
            cout << "\033[4m<<BATTERIO No." << ContatoreDati + 1 << ">>\033[24m" << endl;
            cout << "Nome: " << Array[ContatoreArray].Dati[ContatoreDati].NomeBatterio << endl;
            cout << "Tipologia: " << Array[ContatoreArray].Dati[ContatoreDati].Tipologia << endl;
            cout << "Concentrazione: " << Array[ContatoreArray].Dati[ContatoreDati].Concentrazione << endl;
            cout << endl;
            ContatoreDati++;
        }
        ContatoreDati = 0;
        ContatoreArray++;
        cout << endl << endl;
    }
}

void StampaRecord(record Array[LunghezzaDatabase], unsigned long RecordDaStampare)
{
    //Dichiarazione variabili
    unsigned long Contatore = 0;

    //Stampa dei metadati
    cout << "\033[1m[RECORD NUMERO " << RecordDaStampare + 1 << "]\033[22m" << endl;
    cout << "Luogo di raccolta: " << Array[RecordDaStampare].Luogo << " (" << Array[RecordDaStampare].Latitudine << ", " << Array[RecordDaStampare].Longitudine << ");" << endl << endl;
        
    //Stampa dei dati
    while (Contatore < Array[RecordDaStampare].NumeroSpecie)
    {
        cout << "\033[4m<<BATTERIO No." << Contatore + 1 << ">>\033[24m" << endl;
        cout << "Nome: " << Array[RecordDaStampare].Dati[Contatore].NomeBatterio << endl;
        cout << "Tipologia: " << Array[RecordDaStampare].Dati[Contatore].Tipologia << endl;
        cout << "Concentrazione: " << Array[RecordDaStampare].Dati[Contatore].Concentrazione << endl;
        cout << endl;
        Contatore++;
    }
    cout << endl << endl;;
}

void NewStampaArray(record Array[LunghezzaDatabase], unsigned long IndiceVuoto)
{
    //Dichiarazione variabili
    unsigned long LunghezzaRiga, LunghezzaLuogo = 5, LunghezzaBatterio = 8, LunghezzaConcentrazione = 14, ContatoreArray = 0, ContatoreDati = 0;

    //Calcolo della lunghezza delle colonne
    while (ContatoreArray < IndiceVuoto)
    {
        LunghezzaLuogo = max((unsigned long) Array[ContatoreArray].Luogo.length(), LunghezzaLuogo);
        while (ContatoreDati < Array[ContatoreArray].NumeroSpecie)
        {
            LunghezzaBatterio = max((unsigned long) Array[ContatoreArray].Dati[ContatoreDati].NomeBatterio.length(), LunghezzaBatterio);
            LunghezzaConcentrazione = max((unsigned long) to_string(Array[ContatoreArray].Dati[ContatoreDati].Concentrazione).length(), LunghezzaConcentrazione);
            ContatoreDati++;
        }
        ContatoreDati = 0;
        ContatoreArray++;
    }
    ContatoreArray = 0;

    //Calcolo della lunghezza della riga
    LunghezzaRiga = LunghezzaLuogo + LunghezzaBatterio + LunghezzaConcentrazione;

    //Stampa delle sezioni della tabella
    cout << "+";
    while (ContatoreArray < LunghezzaRiga)
    {
        cout << "-";
        ContatoreArray++;
    }
    ContatoreArray = 0;
    cout << "+" << endl;

    cout << "|" << setw(LunghezzaLuogo) << "Luogo" << setw(0) << "|" << setw(LunghezzaBatterio) << "Batterio" << setw(0) << "|" << setw(LunghezzaConcentrazione) << "Concentrazione" << setw(0) << "|" << endl;

    cout << "+";
    while (ContatoreArray < LunghezzaRiga)
    {
        cout << "-";
        ContatoreArray++;
    }
    ContatoreArray = 0;
    cout << "+" << endl;

    //Stampa dei dati
    while (ContatoreArray < IndiceVuoto)
    {
        while (ContatoreDati < Array[ContatoreArray].NumeroSpecie)
        {
            cout << "|" << setw(LunghezzaLuogo) << Array[ContatoreArray].Luogo << setw(0) << "|" << setw(LunghezzaBatterio) << Array[ContatoreArray].Dati[ContatoreDati].NomeBatterio << setw(0) << "|" << setw(LunghezzaConcentrazione) << Array[ContatoreArray].Dati[ContatoreDati].Concentrazione << setw(0) << "|" << endl;
            ContatoreDati++;
        }
        ContatoreDati = 0;
        ContatoreArray++;
    }
    ContatoreArray = 0;

    //Fine tabella
    cout << "+";
    while (ContatoreArray < LunghezzaRiga)
    {
        cout << "-";
        ContatoreArray++;
    }
    ContatoreArray = 0;
    cout << "+" << endl << endl << endl;
}