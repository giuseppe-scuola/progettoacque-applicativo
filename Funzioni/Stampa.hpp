void Stampa(record Array[LunghezzaDatabase], unsigned int IndiceVuoto)
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