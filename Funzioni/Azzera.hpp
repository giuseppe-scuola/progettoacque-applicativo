void Azzera(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    //Dichiarazione variabili
    unsigned int ContatoreArray = 0, ContatoreSpecie = 0;

    //Azzeramento del database
    while (ContatoreArray < LunghezzaDatabase)
    {
        Array[ContatoreArray].Luogo = "";
        Array[ContatoreArray].Longitudine = "";
        Array[ContatoreArray].Latitudine = "";
        Array[ContatoreArray].NumeroSpecie = 0;
        while (ContatoreSpecie < SpeciePerRecord)
        {
            Array[ContatoreArray].Dati[ContatoreSpecie].NomeBatterio = "";
            Array[ContatoreArray].Dati[ContatoreSpecie].Concentrazione = 0;
            ContatoreSpecie++;
        }
        ContatoreSpecie = 0;
        ContatoreArray++;
    }

    //Spostamento dell'indice all'inizio del database
    IndiceVuoto = 0;
}