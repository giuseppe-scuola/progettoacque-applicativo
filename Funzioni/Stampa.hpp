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
            cout << "<<BATTERIO No." << ContatoreDati + 1 << ">>" << endl;
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
        cout << "<<BATTERIO No." << Contatore + 1 << ">>" << endl;
        cout << "Nome: " << Array[RecordDaStampare].Dati[Contatore].NomeBatterio << endl;
        cout << "Tipologia: " << Array[RecordDaStampare].Dati[Contatore].Tipologia << endl;
        cout << "Concentrazione: " << Array[RecordDaStampare].Dati[Contatore].Concentrazione << endl;
        cout << endl;
        Contatore++;
    }
    cout << endl << endl;;
}