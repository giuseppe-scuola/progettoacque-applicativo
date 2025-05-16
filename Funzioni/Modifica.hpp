void Modifica(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto)
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned long SceltaRecord, SceltaModifica;

    //Scelta del record
    while (!InputValido)
    {
        //Output dell'utente
        StampaArray(Array, IndiceVuoto);
        cout << "Scegli uno dei record da modificare: ";
        InputValido = InputLong(SceltaRecord);

        //Pulizia schermo
        system("cls");

        //Verifica dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido!" << endl << endl;
        }
        else if ((SceltaRecord - 1 < 0) || (IndiceVuoto <= SceltaRecord - 1))
        {
            InputValido = false;
            cout << "Il numero inserito non corrisponde a un record esistente!" << endl << endl;
        }
        else
        {
            SceltaRecord--;
        }
    }
    InputValido = false;

    //Scelta del tipo di modifica
    while (!InputValido)
    {
        //Output per l'utente
        cout << "Che cosa vuoi modificare?" << endl;
        cout << "\033[1m[1]\033[22m Il luogo…" << endl;
        cout << "\033[1m[2]\033[22m I dati di un batterio…" << endl;
        cout << "Scegli una di queste opzioni: ";
        InputValido = InputLong(SceltaModifica);

        //Pulizia schermo
        system("cls");

        //Verifica dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido!" << endl;
        }
        else if ((SceltaModifica < 1) || (2 < SceltaModifica))
        {
            InputValido = false;
            cout << "Questa opzione non esiste!" << endl;
        }
    }

    //Gestione dell'input
    switch (SceltaModifica)
    {
        case 1:
            Array[SceltaRecord] = SceltaLuogo(Array, SceltaRecord);
            system("cls");
            break;
        case 2:
            ModificaBatteri(Array[SceltaRecord]);
            system("cls");
            break;
        default:
            cout << "\033[31mErrore: valore di scelta non valido, il record non verrà modificato.\033[0m" << endl;
            break;
    }

    //Output per l'utente
    cout << "\033[32mIl record No." << SceltaRecord + 1 << " è stato modificato.\033[0m" << endl;
}

void ModificaBatteri(record &DaModificare)
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned long SceltaModifica, SceltaBatterio, SceltaCampo, Contatore = 0;

    //Verifica della disponibiltà di certe funzionalità
    if (DaModificare.NumeroSpecie == 0)
    {
        //Scelta della modalità di modifica
        while (!InputValido)
        {
            //Output per l'utente
            cout << "Come vuoi modificare questo record?" << endl;
            cout << "\033[1m[1]\033[22m Aggiungi un batterio…" << endl;
            cout << "Scegli una di queste opzioni: ";
            InputValido = InputLong(SceltaModifica);

            //Pulizia schermo
            system("cls");

            //Verifica dell'input
            if (!InputValido)
            {
                cout << "Il valore inserito non è valido!" << endl;
            }
            else if ((SceltaModifica < 1) || (1 < SceltaModifica))
            {
                InputValido = false;
                cout << "Questa opzione non esiste!" << endl;
            }
        }
    }
    else
    {
        //Scelta della modalità di modifica
        while (!InputValido)
        {
            //Output per l'utente
            cout << "Come vuoi modificare questo record?" << endl;
            cout << "\033[1m[1]\033[22m Aggiungi un batterio…" << endl;
            cout << "\033[1m[2]\033[22m Modifica un batterio…" << endl;
            cout << "\033[1m[3]\033[22m Elimina un batterio…" << endl;
            cout << "Scegli una di queste opzioni: ";
            InputValido = InputLong(SceltaModifica);

            //Pulizia schermo
            system("cls");

            //Verifica dell'input
            if (!InputValido)
            {
                cout << "Il valore inserito non è valido!" << endl;
            }
            else if ((SceltaModifica < 1) || (3 < SceltaModifica))
            {
                InputValido = false;
                cout << "Questa opzione non esiste!" << endl;
            }
        }
    }
    InputValido = false;

    //Gestione della scelta della modalità
    switch (SceltaModifica)
    {
        case 1:
            //Inserimento del nome del batterio
            while (!InputValido)
            {
                //Output per l'utente
                cout << "Inserisci il nome del batterio: ";
                getline(cin, DaModificare.Dati[DaModificare.NumeroSpecie].NomeBatterio);

                //Pulizia schermo
                system("cls");

                //Verifica dell'input
                if (DaModificare.Dati[DaModificare.NumeroSpecie].NomeBatterio.find(';') != string::npos)
                {
                    cout << "Non puoi inserire punti e virgola nel nome del batterio!" << endl;
                }
                else
                {
                    InputValido = true;
                }
            }
            InputValido = false;

            //Inserimento della tipologia del batterio
            while (!InputValido)
            {
                //Output per l'utente
                cout << "Inserisci la tipologia del batterio: ";
                getline(cin, DaModificare.Dati[DaModificare.NumeroSpecie].Tipologia);

                //Pulizia schermo
                system("cls");

                //Verifica dell'input
                if (DaModificare.Dati[DaModificare.NumeroSpecie].Tipologia.find(';') != string::npos)
                {
                    cout << "Non puoi inserire punti e virgola nella tipologia del batterio!" << endl;
                }
                else
                {
                    InputValido = true;
                }
            }
            InputValido = false;

            //Inserimento della concentrazione del batterio
            while (!InputValido)
            {
                cout << "Inserisci la concentrazione del batterio: ";
                InputValido = InputLong(DaModificare.Dati[DaModificare.NumeroSpecie].Concentrazione);

                if (!InputValido)
                {
                    cout << "Il valore inserito non è valido!" << endl;
                }
            }

            //Pulizia schermo
            system("cls");

            //Aumento contatore
            DaModificare.NumeroSpecie++;
            break;
        case 2:
            //Scelta del batterio da modificare
            while (!InputValido)
            {
                //Output per l'utente
                cout << "Quale batterio vuoi modificare?" << endl;
                cout << "\033[1m[0]\033[22m Tutti i batteri;" << endl;
                
                //Stampa di tutti i batteri
                while (Contatore < DaModificare.NumeroSpecie)
                {
                    cout << "\033[1m[" << Contatore + 1 << "]\033[22m " << DaModificare.Dati[Contatore].NomeBatterio << " (tipologia: " << DaModificare.Dati[Contatore].Tipologia << ", concentrazione: " << DaModificare.Dati[Contatore].Concentrazione << ");" << endl;
                    Contatore++;
                }
                Contatore = 0;

                //Richiesta dell'input
                cout << "Scegli una di queste opzioni: ";
                InputValido = InputLong(SceltaBatterio);

                //Pulizia schermo
                system("cls");

                //Verifica dell'input
                if (!InputValido)
                {
                    cout << "Il valore inserito non è valido!" << endl;
                }
                else if (DaModificare.NumeroSpecie < SceltaBatterio)
                {
                    InputValido = false;
                    cout << "Questa opzione non esiste!" << endl;
                }
            }
            InputValido = false;

            //Scelta del campo da modificare
            while (!InputValido)
            {
                cout << "Quale campo vuoi modificare?" << endl;
                cout << "\033[1m[1]\033[22m Il nome;" << endl;
                cout << "\033[1m[2]\033[22m La tipologia;" << endl;
                cout << "\033[1m[3]\033[22m La concentrazione;" << endl;
                cout << "Scegli una di queste opzioni: ";
                InputValido = InputLong(SceltaCampo);

                //Pulizia schermo
                system("cls");

                //Verifica dell'input
                if (!InputValido)
                {
                    cout << "Il valore inserito non è valido!" << endl;
                }
                else if ((SceltaCampo < 1) || (3 < SceltaCampo))
                {
                    InputValido = false;
                    cout << "Questa opzione non esiste!" << endl;
                }
            }
            InputValido = false;

            //Gestione della scelta del batterio
            if (SceltaBatterio == 0)
            {
                //Gestione della scelta del campo
                switch (SceltaCampo)
                {
                    case 1:
                        //Inserimento del nome
                        while (!InputValido)
                        {
                            //Output per l'utente
                            cout << "Inserisci il nuovo nome: ";
                            getline(cin, DaModificare.Dati[0].NomeBatterio);

                            //Pulizia schermo
                            system("cls");

                            //Verifica dell'input
                            if (DaModificare.Dati[0].NomeBatterio.find(';') != string::npos)
                            {
                                cout << "Non puoi inserire punti e virgola nel nome del batterio!" << endl;
                            }
                            else
                            {
                                InputValido = true;
                            }
                        }
                        InputValido = false;

                        //Loop per rimpiazzare tutti i nomi nel record
                        while (Contatore < DaModificare.NumeroSpecie)
                        {
                            DaModificare.Dati[Contatore].NomeBatterio = DaModificare.Dati[0].NomeBatterio;
                            Contatore++;
                        }
                        break;
                    case 2:
                        //Inserimento della tipologia
                        while (!InputValido)
                        {
                            //Output per l'utente
                            cout << "Inserisci la nuova tipologia: ";
                            getline(cin, DaModificare.Dati[0].Tipologia);

                            //Pulizia schermo
                            system("cls");

                            //Verifica dell'input
                            if (DaModificare.Dati[0].Tipologia.find(';') != string::npos)
                            {
                                cout << "Non puoi inserire punti e virgola nella tipologia del batterio!" << endl;
                            }
                            else
                            {
                                InputValido = true;
                            }
                        }
                        InputValido = false;

                        //Loop per rimpiazzare tutte le tipologie nel record
                        while (Contatore < DaModificare.NumeroSpecie)
                        {
                            DaModificare.Dati[Contatore].Tipologia = DaModificare.Dati[0].Tipologia;
                            Contatore++;
                        }
                        break;
                    case 3:
                        //Inserimento del nome
                        while (!InputValido)
                        {
                            //Output per l'utente
                            cout << "Inserisci la nuova concentrazione: ";
                            InputValido = InputLong(DaModificare.Dati[0].Concentrazione);

                            //Verifica dell'input
                            if (!InputValido)
                            {
                                cout << "Il valore inserito non è valido!" << endl;
                            }
                        }

                        //Loop per rimpiazzare tutte le tipologie nel record
                        while (Contatore < DaModificare.NumeroSpecie)
                        {
                            DaModificare.Dati[Contatore].Concentrazione = DaModificare.Dati[0].Concentrazione;
                            Contatore++;
                        }
                        break;
                    default:
                        cout << "\033[31mErrore: valore del campo invalido, il record non verrà modificato.\033[0m" << endl;
                        break;
                }
            }
            else
            {
                //Diminuzione contatore
                SceltaBatterio--;

                //Gestione della scelta del campo
                switch (SceltaCampo)
                {
                    case 1:
                        //Inserimento del nome
                        while (!InputValido)
                        {
                            //Output per l'utente
                            cout << "Inserisci il nuovo nome: ";
                            getline(cin, DaModificare.Dati[SceltaBatterio].NomeBatterio);

                            //Pulizia schermo
                            system("cls");

                            //Verifica dell'input
                            if (DaModificare.Dati[SceltaBatterio].NomeBatterio.find(';') != string::npos)
                            {
                                cout << "Non puoi inserire punti e virgole nel nome del batterio!" << endl;
                            }
                            else
                            {
                                InputValido = true;
                            }
                        }
                        InputValido = false;
                        break;
                    case 2:
                        //Inserimento della tipologia
                        while (!InputValido)
                        {
                            //Output per l'utente
                            cout << "Inserisci la nuova tipologia: ";
                            getline(cin, DaModificare.Dati[SceltaBatterio].Tipologia);

                            //Pulizia schermo
                            system("cls");

                            //Verifica dell'input
                            if (DaModificare.Dati[SceltaBatterio].Tipologia.find(';') != string::npos)
                            {
                                cout << "Non puoi inserire punti e virgole nel nome del batterio!" << endl;
                            }
                            else
                            {
                                InputValido = true;
                            }
                        }
                        InputValido = false;
                        break;
                    case 3:
                        //Inserimento della concentrazione
                        while (!InputValido)
                        {
                            //Output per l'utente
                            cout << "Inserisci la nuova concentrazione: ";
                            InputValido = InputLong(DaModificare.Dati[SceltaBatterio].Concentrazione);

                            //Verifica dell'input
                            if (!InputValido)
                            {
                                cout << "Il valore inserito non è valido!" << endl;
                            }
                        }
                        break;
                    default:
                        cout << "\033[31mErrore: valore del campo invalido, il record non verrà modificato.\033[0m" << endl;
                        break;
                }
            }
            break;
        case 3:
            //Scelta del batterio da eliminare
            while (!InputValido)
            {
                //Output per l'utente
                cout << "Quale batterio vuoi eliminare?" << endl;
                cout << "\033[1m[0]\033[22m Tutti i batteri;" << endl;
                
                //Stampa di tutti i batteri
                while (Contatore < DaModificare.NumeroSpecie)
                {
                    cout << "\033[1m[" << Contatore + 1 << "]\033[22m " << DaModificare.Dati[Contatore].NomeBatterio << " (tipologia: " << DaModificare.Dati[Contatore].Tipologia << ", concentrazione: " << DaModificare.Dati[Contatore].Concentrazione << ");" << endl;
                    Contatore++;
                }
                Contatore = 0;

                //Richiesta dell'input
                cout << "Scegli una di queste opzioni: ";
                InputValido = InputLong(SceltaBatterio);

                //Pulizia schermo
                system("cls");

                //Verifica dell'input
                if (!InputValido)
                {
                    cout << "Il valore inserito non è valido!" << endl;
                }
                else if (DaModificare.NumeroSpecie < SceltaBatterio)
                {
                    InputValido = false;
                    cout << "Questa opzione non esiste!" << endl;
                }
            }
            InputValido = false;

            //Gestione della scelta del batterio
            if (SceltaBatterio == 0)
            {
                //Loop per la rimozione dei batteri
                while (Contatore < DaModificare.NumeroSpecie)
                {
                    DaModificare.Dati[Contatore].NomeBatterio = "";
                    DaModificare.Dati[Contatore].Tipologia = "";
                    DaModificare.Dati[Contatore].Concentrazione = 0;
                    Contatore++;
                }
                DaModificare.NumeroSpecie = 0;
            }
            else
            {
                //Diminuzione del contatore
                SceltaBatterio--;

                //Rimozione del patterio
                while (SceltaBatterio < DaModificare.NumeroSpecie - 1)
                {
                    DaModificare.Dati[SceltaBatterio] = DaModificare.Dati[SceltaBatterio + 1];
                    SceltaBatterio++;
                }

                //Diminuzione contatore dell'array
                DaModificare.NumeroSpecie--;

                //Azzeramento record appena rimosso
                DaModificare.Dati[DaModificare.NumeroSpecie].NomeBatterio = "";
                DaModificare.Dati[DaModificare.NumeroSpecie].Tipologia = "";
                DaModificare.Dati[DaModificare.NumeroSpecie].Concentrazione = 0;
            }
    }
}