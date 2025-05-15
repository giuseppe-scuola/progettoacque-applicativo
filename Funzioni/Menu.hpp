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
        cout << "\033[1m[0]\033[22m Salvare ed uscire…" << endl; 
        cout << "\033[1m[1]\033[22m Inserire uno o più record…" << endl;
        cout << "\033[1m[2]\033[22m Mostrare tutti i record a schermo…" << endl;
        cout << "\033[1m[3]\033[22m Modificare un record…" << endl;
        cout << "\033[1m[4]\033[22m Cancellare un record…" << endl;
        cout << "\033[1m[5]\033[22m Cercare un record…" << endl;
        cout << "\033[1m[6]\033[22m Generare un grafico…" << endl;
        cout << "Scegli una di queste opzioni: ";
        InputValido = InputLong(Scelta);

        //Pulizia schermo
        system("cls");

        //Verifica dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido!" << endl;
        }
        else if (6 < Scelta)
        {
            InputValido = false;
            cout << "Questa opzione non esiste!" << endl;
        }
    }

    //Restituzione del valore
    return Scelta;
}
