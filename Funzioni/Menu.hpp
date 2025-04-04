int Menu()
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned int Scelta;

    while (!InputValido)
    {
        //Output per l'utente
        std::cout << "Scegli uno tra i seguenti numeri;" << std::endl;
        std::cout << "[0] Salva ed esci..." << std::endl; 
        std::cout << "[1] per fare l'inserimento" << std::endl;
        std::cout << "[2] per stampare" << std::endl;
        std::cout << "[3] per fare una modifica" << std::endl;
        std::cout << "[4] per cancellare" << std::endl;
        std::cout << "[5] Cerca un record..." << std::endl;
        std::cout << "[6] Genera un grafico..." << std::endl;
        std::cout << "Inserisci un numero: ";
        InputValido = InputInt(Scelta);

        //Gestione dell'input
        if (!InputDouble)
        {
            //Pulizia schermo e output per l'utente
            PulisciSchermo;
            std::cout << "Il valore inserito non è valido." << std::endl;
        }
    }

    //Restituzione del valore
    return Scelta;
}
