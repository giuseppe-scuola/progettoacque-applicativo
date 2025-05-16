void Grafico(record Array[LunghezzaDatabase], unsigned long IndiceVuoto)
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned long Scelta, Lunghezza, Contatore = 0, ContatoreStampa = 0, Maggiore = 0;
    CONSOLE_SCREEN_BUFFER_INFO Informazioni;
    HANDLE StandardOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(StandardOutput, &Informazioni);

    //Scelta del record
    while (!InputValido)
    {
        //Output per l'utente
        StampaArray(Array, IndiceVuoto);
        cout << "Scegli il record per il quale disegnare il grafico: ";
        InputValido = InputLong(Scelta);

        //Pulizia schermo
        system("cls");

        //Verifica dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido!" << endl << endl;
        }
        else if ((Scelta - 1 < 0) || (IndiceVuoto <= Scelta - 1))
        {
            InputValido = false;
            cout << "Il numero inserito non corrisponde a un record esistente" << endl << endl;
        }
        else if (Array[Scelta - 1].NumeroSpecie == 0)
        {
            InputValido = false;
            cout << "Il record scelto non contiene batteri!" << endl << endl;
        }
        else
        {
            Scelta--;
        }
    }

    //Calcolo del valore maggiore
    while (Contatore < Array[Scelta].NumeroSpecie)
    {
        if (Maggiore < Array[Scelta].Dati[Contatore].Concentrazione)
        {
            Maggiore = Array[Scelta].Dati[Contatore].Concentrazione;
        }
        Contatore++;
    }
    Contatore = 0;

    //Stampa del grafico
    while (Contatore < Array[Scelta].NumeroSpecie)
    {
        //Stampa del batterio
        cout << "Concentrazione del batterio " << Array[Scelta].Dati[Contatore].NomeBatterio << " (" << Array[Scelta].Dati[Contatore].Tipologia << "):" << endl;

        //Calcolo della lunghezza della barra
        Lunghezza = floor((double (Array[Scelta].Dati[Contatore].Concentrazione) / double (Maggiore)) * double (Informazioni.dwSize.X));

        //Colorazione dell'output
        cout << "\033[34m";
        //Stampa della barra
        while (ContatoreStampa < Lunghezza)
        {
            /*
            if (ContatoreStampa <= Informazioni.dwSize.X / 4)
            {
                cout << "\033[32m";
            }
            else if (ContatoreStampa <= Informazioni.dwSize.X / 2)
            {
                cout << "\033[33m";
            }
            else if (ContatoreStampa <= Informazioni.dwSize.X / 4 * 3)
            {
                cout << "\033[31m";
            }
            else
            {
                cout << "\033[35m";
            }
            */
            cout << "#";
            ContatoreStampa++;
        }
        ContatoreStampa = 0;
        cout << "\033[0m" << endl << endl;

        //Aumento contatore
        Contatore++;
    }
}