int Menu()
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned int Scelta;

    while (!InputValido)
    {
        //Output per l'utente
        cout << "Scegli una tra le seguenti opzioni;" << endl;
        cout << "[0] Salva ed esci..." << endl; 
        cout << "[1] Inserisci uno o piu' record..." << endl;
        cout << "[2] Mostra tutti i record a schermo..." << endl;
        cout << "[3] Modifica un record..." << endl;
        cout << "[4] Cancella un record..." << endl;
        cout << "[5] Cerca un record..." << endl;
        cout << "[6] Genera un grafico..." << endl;
        cout << "Inserisci un numero: ";
        InputValido = InputInt(Scelta);

        //Gestione dell'input
        if (!InputValido)
        {
            //Pulizia schermo e output per l'utente
            system("cls");
            cout << "Il valore inserito non e' valido!" << endl;
        }
    }

    //Restituzione del valore
    return Scelta;
}
