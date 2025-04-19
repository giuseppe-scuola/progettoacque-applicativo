void StampaArray(record Array[LunghezzaDatabase], unsigned int IndiceVuoto)
{
    //Dichiarazione variabili
    unsigned int ContatoreArray = 0, ContatoreDati = 0;

    //Loop per la stampa
    while (ContatoreArray < IndiceVuoto)
    {
        //Stampa dei metadati
        wcout << "[RECORD NUMERO " << ContatoreArray + 1 << "]" << endl;
        wcout << "Luogo di raccolta: " << Array[ContatoreArray].Luogo.c_str() << " (" << Array[ContatoreArray].Longitudine.c_str() << ", " << Array[ContatoreArray].Latitudine.c_str() << ");" << endl;
        
        //Stampa dei dati
        while (ContatoreDati < Array[ContatoreArray].NumeroSpecie)
        {
            wcout << "Concentrazione batterio No." << ContatoreDati + 1 << " (" << Array[ContatoreArray].Dati[ContatoreDati].NomeBatterio.c_str() << "): " << Array[ContatoreArray].Dati[ContatoreDati].Concentrazione << endl;
            ContatoreDati++;
        }
        ContatoreDati = 0;
        ContatoreArray++;
        wcout << endl;
    }
}

void StampaRecord(record Array[LunghezzaDatabase], unsigned int IndiceDaStampare)
{
    //Dichiarazione variabili
    unsigned int Contatore = 0;

    //Stampa dei metadati
    wcout << "[RECORD NUMERO " << IndiceDaStampare + 1 << "]" << endl;
    wcout << "Luogo di raccolta: " << Array[IndiceDaStampare].Luogo.c_str() << " (" << Array[IndiceDaStampare].Longitudine.c_str() << ", " << Array[IndiceDaStampare].Latitudine.c_str() << ");" << endl;
        
    //Stampa dei dati
    while (Contatore < Array[IndiceDaStampare].NumeroSpecie)
    {
        wcout << "Concentrazione batterio No." << Contatore + 1 << " (" << Array[IndiceDaStampare].Dati[Contatore].NomeBatterio.c_str() << "): " << Array[IndiceDaStampare].Dati[Contatore].Concentrazione << endl;
        Contatore++;
    }
    wcout << endl;
}