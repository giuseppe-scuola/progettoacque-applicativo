void Inserimento(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto)
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned long Scelta;

    //Richiesta del tipo di modifica
    while (!InputValido)
    {
        //Output per l'utente
        cout << "Che tipo di inserimento vuoi fare?" << endl;
        cout << "[1] Singolo…" << endl;
        cout << "[2] Massivo…" << endl;
        cout << "Scegli una di queste opzioni: ";
        InputValido = InputLong(Scelta);

        //Pulizia schermo
        system("cls");

        //Controllo per validità dell'input
        if ((!InputValido) || (Scelta < 1) || (2 < Scelta))
        {
            cout << "Il valore inserito non è valido!" << endl;
        }
    }

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
            cout << "\033[31mErrore: valore di scelta non valido, non verrà inserito niente.\033[0m" << endl;
            break;
    }
}

void InserimentoSingolo(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto)
{
    //Dichiarazione variabili
    bool InputValido = false, Interruzione = false;

    //Inserimento del luogo
    Array[IndiceVuoto] = SceltaLuogo(Array, IndiceVuoto);

    //Inserimento dei batteri
    while ((Array[IndiceVuoto].NumeroSpecie < SpeciePerRecord) && (!Interruzione))
    {
        //Inserimento del nome
        cout << "<<BATTERIO No." << Array[IndiceVuoto].NumeroSpecie + 1 << ">> Inserisci il nome del batterio \033[36m(\033[3m?\033[23m per terminare l'inserimento)\033[0m: ";
        getline(cin, Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio);

        //Controllo per caratteri speciali
        if (Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio.find('?') != string::npos)
        {
            Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio = "";
            Interruzione = true;
            system("cls");
        }
        else
        {
            //Inserimento della tipologia
            cout << "<<BATTERIO No." << Array[IndiceVuoto].NumeroSpecie + 1 << ">> Inserisci la tipologia del batterio: ";
            getline(cin, Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Tipologia);

            //Inserimento della concentrazione
            while (!InputValido)
            {
                //Output per l'utente
                cout << "<<BATTERIO No." << Array[IndiceVuoto].NumeroSpecie + 1 << ">> Inserisci la concentrazione del batterio: ";
                InputValido = InputLong(Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione);

                //Pulizia schermo
                system("cls");

                //Verifica dell'input
                if (!InputValido)
                {
                    cout << "Il valore inserito non è valido!" << endl;
                }
            }
            InputValido = false;

            //Aumento contatore
            Array[IndiceVuoto].NumeroSpecie++;
        }
    }

    //Aumento contatore
    IndiceVuoto++;

    //Output per l'utente
    cout << "Il record No." << IndiceVuoto << " è stato aggiunto." << endl;
}

void InserimentoMassivo(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto)
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned long DaInserire, Contatore = 0;

    //Richiesta del numero di record da inserire
    while (!InputValido)
    {
        //Output per l'utente
        cout << "Inserisci il numero di record che vuoi inserire: ";
        InputValido = InputLong(DaInserire);

        //Pulizia schermo
        system("cls");

        //Gestione dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido!" << endl;
        }
        else if (64 < DaInserire + IndiceVuoto)
        {
            InputValido = false;
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

        //Pulizia schermo
        system("cls");

        //Aumento contatore
        Contatore++;
    }
}
