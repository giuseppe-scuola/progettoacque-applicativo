void CancellaPrompt(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto)
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned long Scelta = 0;

    //Loop per l'input
    while (!InputValido)
    {
        //Output per l'utente
        StampaArray(Array, IndiceVuoto);
        cout << "Inserisci il record da cancellare: ";
        InputValido = InputLong(Scelta);

        //Pulizia schermo
        system("cls");

        //Gestione input dell'utente
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido!" << endl << endl;
        }
        else if ((Scelta - 1 < 0) || (IndiceVuoto <= Scelta - 1))
        {
            InputValido = false;
            cout << "Il numero inserito non corrisponde a un record esistente!" << endl << endl;
        }
        else
        {
            Scelta--;
        }
    }

    //Cancellazione dell'elemento dall'array
    Cancella(Array, IndiceVuoto, Scelta);

    //Output per l'utente
    cout << "Il record No." << Scelta + 1 << " è stato cancellato." << endl;
}

void Cancella(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto, unsigned long DaRimuovere)
{
    //Dichiarazione variabili
    unsigned long ContatoreDati = 0;

    //Loop per la rimozione
    while (DaRimuovere < IndiceVuoto - 1)
    {
        Array[DaRimuovere] = Array[DaRimuovere + 1];
        DaRimuovere++;
    }

    //Diminuzione contatore dell'array
    IndiceVuoto--;

    //Azzeramento record appena rimosso
    Array[IndiceVuoto].Luogo = "";
    Array[IndiceVuoto].Longitudine = "";
    Array[IndiceVuoto].Latitudine = "";
    Array[IndiceVuoto].NumeroSpecie = 0;
    while (ContatoreDati < SpeciePerRecord)
    {
        Array[IndiceVuoto].Dati[ContatoreDati].NomeBatterio = "";
        Array[IndiceVuoto].Dati[ContatoreDati].Tipologia = "";
        Array[IndiceVuoto].Dati[ContatoreDati].Concentrazione = 0;
        ContatoreDati++;
    }
}