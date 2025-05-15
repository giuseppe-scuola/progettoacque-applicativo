void ApriFile(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto, ifstream &FileInput)
{
    //Dichiarazione variabili
    unsigned long ContatoreRiga = 0, ContatoreDati = 0;
    string RigaFile, Temp;
    stringstream RigaFileStream;

    //Copia delle informazioni del file all'interno dell'array
    while ((!FileInput.eof()) && (IndiceVuoto < LunghezzaDatabase))
    {
        //Lettura del file
        getline(FileInput, RigaFile);
        RigaFileStream.str(RigaFile);
        ContatoreRiga++;

        //Ignora la riga in caso sia l'ultima
        if (RigaFile == "")
        {
            continue;
        }

        //Estrazione del luogo dalla riga
        getline(RigaFileStream, Array[IndiceVuoto].Luogo, ';');

        //Estrazione della latitudine dalla riga
        getline(RigaFileStream, Array[IndiceVuoto].Latitudine, ';');

        //Estrazione della longitudine dalla riga
        getline(RigaFileStream, Array[IndiceVuoto].Longitudine, ';');

        //Estrazione del numero di specie presenti nel record dalla riga
        getline(RigaFileStream, Temp, ';');
        try
        {
            Array[IndiceVuoto].NumeroSpecie = stoul(Temp);
            if (SpeciePerRecord <= Array[IndiceVuoto].NumeroSpecie)
            {
                Array[IndiceVuoto].NumeroSpecie = SpeciePerRecord - 1;
                cout << "\033[33;4m<<Riga del database No." << ContatoreRiga << ">>\033[24m Avviso: troppe specie nel singolo record dichiarate, verrano considerate solo le prime " << SpeciePerRecord << ".\033[0m" << endl;
            }
        }
        catch (...)
        {
            cout << "\033[31;4m<<Riga del database No." << ContatoreRiga << ">>\033[24m Errore: valore del numero di specie invalido, questa riga verrà ignorata.\033[0m" << endl;
            continue;
        }

        //Estrazione dei dati delle singole specie dalla riga
        while (ContatoreDati < Array[IndiceVuoto].NumeroSpecie)
        {
            getline(RigaFileStream, Array[IndiceVuoto].Dati[ContatoreDati].NomeBatterio, ';');
            getline(RigaFileStream, Array[IndiceVuoto].Dati[ContatoreDati].Tipologia, ';');
            getline(RigaFileStream, Temp, ';');
            try
            {
                Array[IndiceVuoto].Dati[ContatoreDati].Concentrazione = stod(Temp);
            }
            catch (...)
            {
                cout << "\033[31;4m<<Riga del database No." << ContatoreRiga << ">>\033[24m Errore: valore della concentrazione invalido, la specie \"" << Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio << "\" verrà ignorata.\033[0m" << endl;
                Array[IndiceVuoto].NumeroSpecie--;
                continue;
            }
            ContatoreDati++;
        }
        ContatoreDati = 0;

        //Spostamento dell'indice al prossimo elemento
        IndiceVuoto++;
    }

    //Controllo per verificare che il file non sia troppo lungo
    if (!FileInput.eof())
    {
        cout << "\033[33mAvviso: ci sono troppi record all'interno del file, verrano considerati solo i primi " << LunghezzaDatabase << ".\033[0m" << endl;
    }
}