int Menu()
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned int Scelta;

    while (!InputValido)
    {
        //Output per l'utente
        wcout << "Scegli una tra le seguenti opzioni;" << endl;
        wcout << "[0] Salva ed esci..." << endl; 
        wcout << "[1] Inserisci uno o piu' record..." << endl;
        wcout << "[2] Mostra tutti i record a schermo..." << endl;
        wcout << "[3] Modifica un record..." << endl;
        wcout << "[4] Cancella un record..." << endl;
        wcout << "[5] Cerca un record..." << endl;
        wcout << "[6] Genera un grafico..." << endl;
        wcout << "Inserisci un numero: ";
        InputValido = InputInt(Scelta);

        //Gestione dell'input
        if (!InputValido)
        {
            //Pulizia schermo e output per l'utente
            system("cls");
            wcout << "Il valore inserito non e' valido!" << endl;
        }
    }

    //Restituzione del valore
    return Scelta;
}