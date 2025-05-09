unsigned long Menu()
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned long Scelta;

    //Loop infinito
    while (!InputValido)
    {
        //Output per l'utente
        cout << "Che cosa vuoi fare?" << endl;
        cout << "[0] Salvare ed uscire..." << endl; 
        cout << "[1] Inserire uno o più record..." << endl;
        cout << "[2] Mostrare tutti i record a schermo..." << endl;
        cout << "[3] Modificare un record..." << endl;
        cout << "[4] Cancellare un record..." << endl;
        cout << "[5] Cercare un record..." << endl;
        cout << "[6] Generare un grafico..." << endl;
        cout << "Scegli una di queste opzioni: ";
        InputValido = InputLong(Scelta);

        //Gestione dell'input
        if (!InputValido)
        {
            //Pulizia schermo e output per l'utente
            system("cls");
            cout << "Il valore inserito non è valido!" << endl;
        }
    }

    //Restituzione del valore
    return Scelta;
}