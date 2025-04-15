void CancellaPrompt(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned int Scelta = 0;

    //Loop per l'input
    while (!InputValido)
    {
        //Output per l'utente
        Stampa(Array, IndiceVuoto);
        cout << "Inserisci il record da cancellare: ";
        InputValido = InputInt(Scelta);

        //Test per verificare che il numero sia corretto
        if ((Scelta - 1 < 0) || (IndiceVuoto <= Scelta - 1))
        {
            InputValido = false;
        }

        //Gestione input dell'utente
        if (!InputValido)
        {
            //Pulizia e output per l'utente
            system("cls");
            cout << "Il valore inserito non e' valido!" << endl;
        }
    }

    //Cancellazione dell'elemento dall'array
    Cancella(Array, IndiceVuoto, Scelta);

    //Pulizia schermo e output per l'utente
    system("cls");
    cout << "Il record e' stato cancellato." << endl;
}

void Cancella(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto, unsigned int DaRimuovere)
{
    //Dichiarazione variabili
    unsigned int ContatoreDati = 0;

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