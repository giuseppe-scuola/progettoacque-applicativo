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
            cout << "Concentrazione batterio No." << ContatoreDati + 1 << " (" << Array[ContatoreArray].Dati[ContatoreDati].NomeBatterio << "): " << Array[ContatoreArray].Dati[ContatoreDati].Concentrazione << endl;
            ContatoreDati++;
        }
        ContatoreDati = 0;
        ContatoreArray++;
        cout << endl;
    }
}

void StampaRecord(record Array[LunghezzaDatabase], unsigned int IndiceDaStampare)
{
    //Dichiarazione variabili
    unsigned int Contatore = 0;

    //Stampa dei metadati
    cout << "[RECORD NUMERO " << IndiceDaStampare + 1 << "]" << endl;
    cout << "Luogo di raccolta: " << Array[IndiceDaStampare].Luogo << " (" << Array[IndiceDaStampare].Longitudine << ", " << Array[IndiceDaStampare].Latitudine << ");" << endl;
        
    //Stampa dei dati
    while (Contatore < Array[IndiceDaStampare].NumeroSpecie)
    {
        cout << "Concentrazione batterio No." << Contatore + 1 << " (" << Array[IndiceDaStampare].Dati[Contatore].NomeBatterio << "): " << Array[IndiceDaStampare].Dati[Contatore].Concentrazione << endl;
        Contatore++;
    }
    cout << endl;
}