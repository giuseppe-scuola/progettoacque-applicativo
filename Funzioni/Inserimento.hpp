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
    bool InputValido = false, Interruzione = false;

    //Inserimento del luogo
    Array[IndiceVuoto] = SceltaLuogo(Array, IndiceVuoto);

    //Pulizia schermo
    system("cls");

    //Inserimento dei batteri
    while ((Array[IndiceVuoto].NumeroSpecie < SpeciePerRecord) && (!Interruzione))
    {
        //Inserimento del nome
        cout << "<<BATTERIO No." << Array[IndiceVuoto].NumeroSpecie + 1 << ">> Inserisci il nome del batterio (? per terminare l'inserimento): ";
        getline(cin, Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio);

        //Controllo per caratteri speciali
        if (Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio.find('?') != string::npos)
        {
            Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio = "";
            Interruzione = true;
        }
        else
        {
            //Inserimento della tipologia
            cout << "<<BATTERIO No." << Array[IndiceVuoto].NumeroSpecie + 1 << ">> Inserisci la tipologia del batterio: ";
            getline(cin, Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Tipologia);

            //Inserimento della concentrazione
            while (!InputValido)
            {
                cout << "<<BATTERIO No." << Array[IndiceVuoto].NumeroSpecie + 1 << ">> Inserisci la tipologia del batterio (Per esempio " << double (rand()) / double (rand()) << "): ";
                InputValido = InputDouble(Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione);

                if (!InputValido)
                {
                    cout << "Il valore inserito non è valido!" << endl;
                }
            }

            //Pulizia schermo
            system("cls");

            //Aumento contatore
            Array[IndiceVuoto].NumeroSpecie++;
        }
    }

    //Aumento contatore
    IndiceVuoto++;
}

void InserimentoMassivo(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned int DaInserire, Contatore = 0;

    //Richiesta del numero di record da inserire
    while (!InputValido)
    {
        //Output per l'utente
        cout << "Inserisci il numero di record che vuoi inserire: ";
        InputValido = InputInt(DaInserire);

        //Gestione dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido!" << endl;
        }
        else if (64 < DaInserire + IndiceVuoto)
        {
            cout << "Il numero inserito è troppo grande!" << endl;
        }
    }

    //Loop per l'inserimento
    while (Contatore < DaInserire)
    {
        //Output per l'utente
        cout << "<<RECORD No." << Contatore + 1 << ">>" << endl;

        //Inserimento record
        InserimentoSingolo(Array, IndiceVuoto);

        //Aumento contatore
        Contatore++;
    }
}