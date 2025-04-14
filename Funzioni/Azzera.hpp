void Azzera(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    //Dichiarazione variabili
    unsigned int ContatoreArray = 0, ContatoreDati = 0;

    //Azzeramento del database
    while (ContatoreArray < LunghezzaDatabase)
    {
        Array[ContatoreArray].Luogo = "";
        Array[ContatoreArray].Longitudine = "";
        Array[ContatoreArray].Latitudine = "";
        Array[ContatoreArray].NumeroSpecie = 0;
        while (ContatoreDati < SpeciePerRecord)
        {
            Array[ContatoreArray].Dati[ContatoreDati].NomeBatterio = "";
            Array[ContatoreArray].Dati[ContatoreDati].Concentrazione = 0;
            ContatoreDati++;
        }
        ContatoreDati = 0;
        ContatoreArray++;
    }

    //Spostamento dell'indice all'inizio del database
    IndiceVuoto = 0;
}