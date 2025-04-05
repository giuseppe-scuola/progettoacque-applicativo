void CancellaPrompt(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned int Scelta;

    //Loop per l'input
    while (!InputValido)
    {
        //Output per l'utente
        Stampa(Array, IndiceVuoto);
        cout << "Inserisci il record da cancellare: ";
        InputValido = InputInt(Scelta);

        //Gestione input dell'utente
        if (!InputValido)
        {
            //Pulizia e output per l'utente
            PulisciSchermo;
            cout << "Il valore inserito non è valido!" << endl;
        }
    }

    //Cancellazione dell'elemento dall'array
    Cancella(Array, IndiceVuoto, Scelta);

    //Pulizia schermo e output per l'utente
    PulisciSchermo;
    cout << "Il record è stato cancellato." << endl;
}

void Cancella(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto, unsigned int DaRimuovere)
{
    //Loop per la rimozione
    while (DaRimuovere < IndiceVuoto - 1)
    {
        Array[DaRimuovere] = Array[DaRimuovere + 1];
        DaRimuovere++;
    }

    //Diminuzione contatore dell'array
    IndiceVuoto--;
}
