void Grafico(record Array[LunghezzaDatabase], unsigned long IndiceVuoto)
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned long Scelta, Contatore = 0, ContatoreStampa = 0;
    unsigned long Maggiore = 0;
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

        //Stampa della barra
        while (ContatoreStampa < floor((Array[Scelta].Dati[Contatore].Concentrazione / Maggiore) * Informazioni.dwSize.X))
        {
            cout << "#";
            ContatoreStampa++;
        }
        ContatoreStampa = 0;
        cout << endl << endl;

        //Aumento contatore
        Contatore++;
    }
}