void RicercaPrompt(record Array[LunghezzaDatabase], unsigned long IndiceVuoto)
{
    bool InputValido = false;
    unsigned long Val, Val1, Val2, SceltaConcentrazione, Scelta;
    string Luogo, Batt, Tipo;

    while (!InputValido)
    {
        cout << "Quale tipo di ricerca vuoi fare?" << endl;
        cout << "\033[1m[1]\033[22m Ricerca per Luogo…" << endl;
        cout << "\033[1m[2]\033[22m Ricerca per Batterio…" << endl;
        cout << "\033[1m[3]\033[22m Ricerca per Concentrazione…" << endl;
        cout << "\033[1m[4]\033[22m Ricerca per Tipologia…" << endl;
        cout << "Scegli una di queste opzioni: ";
        InputValido = InputLong(Scelta);

        system("cls");

        if (!InputValido)
        {
            cout << "Il valore inserito non è valido!" << endl;
        }
    }

    InputValido = false;
    switch (Scelta)
    {
        case 1:
            cout << "Hai selezionato la ricerca per luogo;" << endl;
            cout << "Inserisci il luogo che vuoi ricercare: ";
            getline(cin, Luogo);
            system("cls");
            RicercaLuogo(Array, IndiceVuoto, Luogo);
            break;
        case 2:
            cout << "Hai selezionato la ricerca per batteri;." << endl;
            cout << "Inserisci il batterio che vuoi ricercare: ";
            getline(cin, Batt);
            system("cls");
            RicercaBatterio(Array, IndiceVuoto, Batt);
            break;
        case 3:
            while (!InputValido)
            {
                cout << "Hai selezionato la ricerca per concentrazion;." << endl;
                cout << "Come vuoi basare la ricerca?" << endl;
                cout << "\033[1m[1]\033[22m Concentrazione minore del valore inserito…" << endl;
                cout << "\033[1m[2]\033[22m Concentrazione maggiore del valore inserito…" << endl;
                cout << "\033[1m[3]\033[22m Concentrazione compresa tra due valori inseriti…" << endl;
                cout << "Scegli una di queste opzioni: ";
                InputLong(SceltaConcentrazione);
                system("cls");
                if (!InputValido)
                {
                    cout << "Il valore inserito non è valido!" << endl;
                }
            }
            InputValido = false;
            switch (SceltaConcentrazione)
            {
                case 1:
                    while (!InputValido)
                    {
                        cout << "Hai selezionato la ricerca per concentrazione minore di un valore inserito;" << endl;
                        cout << "Inserisci il valore: ";
                        InputValido = InputLong(Val);
                        system("cls");
                        if (!InputValido)
                        {
                            cout << "Il valore inserito non è valido!" << endl;
                        }
                    }
                    ConcentrazioneMinore(Array, IndiceVuoto, Val);
                    break;
                case 2:
                    while (!InputValido)
                    {
                        cout << "Hai selezionato la ricerca per concentrazione maggiore di un valore inserito;" << endl;
                        cout << "Inserisci il valore: ";
                        InputValido = InputLong(Val);
                        system("cls");
                        if (!InputValido)
                        {
                            cout << "Il valore inserito non è valido!" << endl;
                        }
                    }
                    ConcentrazioneMaggiore(Array, IndiceVuoto, Val);
                    break;
                case 3:
                    while (!InputValido)
                    {
                        cout << "Hai selezionato la ricerca per concentrazione compresa tra due valori;" << endl;
                        cout << "Inserisci il valore 1: ";
                        InputValido = InputLong(Val1);
                        system("cls");
                        if (!InputValido)
                        {
                            cout << "Il valore inserito non è valido!" << endl;
                        }
                    }
                    InputValido = false;
                    while(!InputValido)
                    {
                        cout << "Inserisci il valore 2: ";
                        InputValido = InputLong(Val2);
                        system("cls");
                        if (!InputValido)
                        {
                            cout << "Il valore inserito non è valido!" << endl;
                        }
                    }
                    if(Val1<Val2)
                    {
                        ConcentrazioneCompresa(Array, IndiceVuoto, Val1, Val2);
                    }
                    else
                    {
                        ConcentrazioneCompresa(Array, IndiceVuoto, Val2, Val1);
                    }
                    break;
                default:
                    cout << "Inserimento non valido." << endl;
                    break;
            }
            break;
        case 4:
            cout << "Hai selezionato la ricerca per tipologia di batterio;" << endl;
            cout << "Inserisci la tipologia che vuoi ricercare: ";
            getline(cin, Tipo);
            system("cls");
            RicercaTipo(Array, IndiceVuoto, Tipo);
            break;
        default:
            cout << "\033[31mErrore: valore non valido, ricerca fallita.\033[0m" << endl;
            break;
    }
}

void RicercaLuogo(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, string Localita)
{
    int Conta = 0;
    for(int i = 0; i < LunghezzaDatabase; i++)
    {
        if(Array[i].Luogo.find(Localita) != string::npos)
        {
            StampaRecord(Array, i);
            Conta++;
        }
    }
    if(Conta==0)
    {
        cout << "Il luogo ricercato non corrisponde a nessun risultato." << endl;
    }
    else
    {
        cout << "\033[32mSono stati ottenuti \033[3m" << Conta << "\033[23m risultati.\033[0m" << endl;
    }
}

void RicercaBatterio(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, string BatterioRicerca)
{
    int Conta = 0;
    for (int i = 0; i < IndiceVuoto; i++)
    {
        for (int j = 0; j < Array[i].NumeroSpecie; j++)
        {
            if (Array[i].Dati[j].NomeBatterio.find(BatterioRicerca) != string::npos)
            {
                StampaRecord(Array, i);
                Conta++;
                break;
            }
        }
    }
    if(Conta==0)
    {
        cout << "Il batterio ricercato non corrisponde a nessun risultato." << endl;
    }
    else
    {
        cout << "\033[32mSono stati ottenuti \033[3m" << Conta << "\033[23m risultati.\033[0m" << endl;
    }
}

void ConcentrazioneMinore(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, unsigned long Valore)
{
    int Conta = 0;
    for (int i = 0; i < IndiceVuoto; i++)
    {
        for (int j = 0; j < SpeciePerRecord; j++)
        {
            if (Array[i].Dati[j].Concentrazione < Valore)
            {
                StampaRecord(Array, i);
                Conta++;
                break;
            }
        }
    }
    if(Conta==0)
    {
        cout << "Non è stato ritrovato alcun batterio con una concentrazione minore di " << Valore << "." << endl;
    }
    else
    {
        cout << "\033[32mSono stati ottenuti \033[3m" << Conta << "\033[23m risultati.\033[0m" << endl;
    }
}

void ConcentrazioneMaggiore(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, unsigned long Valore)
{
    int Conta = 0;
    for (int i = 0; i < IndiceVuoto; i++)
    {
        for (int j = 0; j < Array[i].NumeroSpecie; j++)
        {
            if (Array[i].Dati[j].Concentrazione > Valore)
            {
                StampaRecord(Array, i);
                Conta++;
                break;
            }
        }
    }
    if(Conta==0)
    {
        cout << "Non è stato ritrovato alcun batterio con una concentrazione maggiore di " << Valore << endl;
    }
    else
    {
        cout << "\033[32mSono stati ottenuti \033[3m" << Conta << "\033[23m risultati.\033[0m" << endl;
    }
}

void ConcentrazioneCompresa(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, unsigned long Valore1, unsigned long Valore2)
{
    int Conta = 0;
    for (int i = 0; i < IndiceVuoto; i++)
    {
        for (int j = 0; j < Array[i].NumeroSpecie; j++)
        {
            if (Array[i].Dati[j].Concentrazione >= Valore1 && Array[i].Dati[j].Concentrazione <= Valore2)
            {
                StampaRecord(Array, i);
                Conta++;
                break;
            }
        }
    }
    if(Conta==0)
    {
        cout << "Non è stato ritrovato alcun batterio con una concentrazione compresa tra \033[3m" << Valore1 << "\033[23m e \033[3m" << Valore2 << "\033[23m." << endl;
    }
    else
    {
        cout << "\033[32mSono stati ottenuti \033[3m" << Conta << "\033[23m risultati.\033[0m" << endl;
    }
}

void RicercaTipo(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, string Tipo)
{
    int Conta = 0;
    for (int i = 0; i < IndiceVuoto; i++)
    {
        for (int j = 0; j < Array[i].NumeroSpecie; j++)
        {
            if (Array[i].Dati[j].Tipologia.find(Tipo) != string::npos)
            {
                StampaRecord(Array, i);
                Conta++;
                break;
            }
        }
    }
    if(Conta==0)
    {
        cout << "Il batterio ricercato non corrisponde a nessun risultato." << endl;
    }
    else
    {
        cout << "\033[32mSono stati ottenuti \033[3m" << Conta << "\033[23m risultati.\033[0m" << endl;
    }
}