void Inserimento(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned int Scelta;

    //Output per l'utente
    while (!InputValido)
    {
        cout << "Che tipo di inserimento vuoi fare?" << endl;
        cout << "[1] Singolo..." << endl;
        cout << "[2] Massivo..." << endl;
        cout << "Scegli una di queste opzioni: ";
        InputValido = InputInt(Scelta);

        //Controllo per validità dell'input
        if ((!InputValido) || (Scelta < 1) || (2 < Scelta))
        {
            cout << "Il valore inserito non è valido!" << endl;
        }
    }
    system("cls");

    //Gestione dell'input
    switch (Scelta)
    {
        case 1:
            InserimentoSingolo(Array, IndiceVuoto);
            break;
        case 2:
            InserimentoMassivo(Array, IndiceVuoto);
            break;
        default:
            cout << "Errore: valore di scelta non valido, non verrà inserito niente." << endl;
            break;
    }
}

void InserimentoSingolo(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    //Dichiarazione variabili
    unsigned int Contatore = 0;
}

void InserimentoMassivo(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{}