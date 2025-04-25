void StampaArray(record Array[LunghezzaDatabase], unsigned int IndiceVuoto)
{
    //Dichiarazione variabili
    unsigned int ContatoreArray = 0, ContatoreDati = 0;

    //Loop per la stampa
    while (ContatoreArray < IndiceVuoto)
    {
        //Stampa dei metadati
        cout << "[RECORD NUMERO " << ContatoreArray + 1 << "]" << endl;
        cout << "Luogo di raccolta: " << Array[ContatoreArray].Luogo << " (" << Array[ContatoreArray].Longitudine << ", " << Array[ContatoreArray].Latitudine << ");" << endl;
        
        //Stampa dei dati
        while (ContatoreDati < Array[ContatoreArray].NumeroSpecie)
        {
            cout << "<<BATTERIO No." << ContatoreDati + 1 << ">>" << endl;
            cout << "Nome: " << Array[ContatoreArray].Dati[ContatoreDati].NomeBatterio << endl;
            cout << "Tipologia: " << Array[ContatoreArray].Dati[ContatoreDati].Tipologia << endl;
            cout << "Concentrazione: " << Array[ContatoreArray].Dati[ContatoreDati].Concentrazione << endl;
            ContatoreDati++;
        }
        ContatoreDati = 0;
        ContatoreArray++;
        cout << endl;
    }
}

void StampaRecord(record Array[LunghezzaDatabase], unsigned int RecordDaStampare)
{
    //Dichiarazione variabili
    unsigned int Contatore = 0;

    //Stampa dei metadati
    cout << "[RECORD NUMERO " << RecordDaStampare + 1 << "]" << endl;
    cout << "Luogo di raccolta: " << Array[RecordDaStampare].Luogo << " (" << Array[RecordDaStampare].Longitudine << ", " << Array[RecordDaStampare].Latitudine << ");" << endl;
        
    //Stampa dei dati
    while (Contatore < Array[RecordDaStampare].NumeroSpecie)
    {
        cout << "<<BATTERIO No." << Contatore + 1 << ">>" << endl;
        cout << "Nome: " << Array[RecordDaStampare].Dati[Contatore].NomeBatterio << endl;
        cout << "Tipologia: " << Array[RecordDaStampare].Dati[Contatore].Tipologia << endl;
        cout << "Concentrazione: " << Array[RecordDaStampare].Dati[Contatore].Concentrazione << endl;
        Contatore++;
    }
    cout << endl;
}