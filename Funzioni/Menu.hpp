int Menu()
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned int Scelta;

    while (!InputValido)
    {
        //Output per l'utente
        cout << "Scegli uno tra i seguenti numeri;" << endl;
        cout << "[0] Salva ed esci..." << endl; 
        cout << "[1] per fare l'inserimento" << endl;
        cout << "[2] per stampare" << endl;
        cout << "[3] per fare una modifica" << endl;
        cout << "[4] per cancellare" << endl;
        cout << "[5] Cerca un record..." << endl;
        cout << "[6] Genera un grafico..." << endl;
        cout << "Inserisci un numero: ";
        InputValido = InputInt(Scelta);

        //Gestione dell'input
        if (!InputDouble)
        {
            //Pulizia schermo e output per l'utente
            PulisciSchermo;
            cout << "Il valore inserito non è valido." << endl;
        }
    }

    //Restituzione del valore
    return Scelta;
}
