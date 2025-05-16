record SceltaLuogo(record Array[LunghezzaDatabase], unsigned long IndiceVuoto)
{
    //Dichiarazione variabili
    bool InputValido = false;
    unsigned long Scelta;
    record ValoreDiRitorno = Array[IndiceVuoto];

    //Output per l'utente
    while (!InputValido)
    {
        cout << "Quale luogo vuoi selezionare?" << endl;
        cout << "\033[1m[0]\033[22m Posto e coordinate a scelta…" << endl;
        cout << "\033[1m[1]\033[22m \033[3mSassa (Raio)\033[23m;" << endl;
        cout << "\033[1m[2]\033[22m \033[3mCavallari (Aterno)\033[23m;" << endl;
        cout << "\033[1m[3]\033[22m \033[3mTempera - Sorgenti (Vera)\033[23m;" << endl;
        cout << "\033[1m[4]\033[22m \033[3mTempera (Vera)\033[23m;" << endl;
        cout << "\033[1m[5]\033[22m \033[3mVilla S. Angelo (Aterno)\033[23m;" << endl;
        cout << "\033[1m[6]\033[22m \033[3mGrotte di Stiffe - profondità (Aterno)\033[23m;" << endl;
        cout << "\033[1m[7]\033[22m \033[3mGrotte di Stiffe - ingresso (Aterno)\033[23m;" << endl;
        cout << "\033[1m[8]\033[22m \033[3mCampana (Aterno)\033[23m;" << endl;
        cout << "\033[1m[9]\033[22m \033[3mValle di S. Giuliano (Torrente Vallone di S. Giuliano)\033[23m;" << endl;
        cout << "Scegli una di queste opzioni: ";
        InputValido = InputLong(Scelta);

        //Pulizia schermo
        system("cls");

        //Verifica dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido!" << endl;
        }
        else if (9 < Scelta)
        {
            InputValido = false;
            cout << "Questa opzione non esiste!" << endl;
        }
    }

    //Gestione dell'input
    switch (Scelta)
    {
        case 0:
            ValoreDiRitorno = LuogoCustom(Array[IndiceVuoto]);
            break;
        case 1:
            ValoreDiRitorno.Luogo = "Sassa (Raio)";
            ValoreDiRitorno.Latitudine = "42.357370";
            ValoreDiRitorno.Longitudine = "13.294650";
            break;
        case 2:
            ValoreDiRitorno.Luogo = "Cavallari (Aterno)";
            ValoreDiRitorno.Latitudine = "42.416403";
            ValoreDiRitorno.Longitudine = "13.301220";
            break;
        case 3:
            ValoreDiRitorno.Luogo = "Tempera - Sorgenti (Vera)";
            ValoreDiRitorno.Latitudine = "42.372180";
            ValoreDiRitorno.Longitudine = "13.458370";
            break;
        case 4:
            ValoreDiRitorno.Luogo = "Tempera (Vera)";
            ValoreDiRitorno.Latitudine = "42.371120";
            ValoreDiRitorno.Longitudine = "13.458140";
            break;
        case 5:
            ValoreDiRitorno.Luogo = "Villa S. Angelo (Aterno)";
            ValoreDiRitorno.Latitudine = "42.255040";
            ValoreDiRitorno.Longitudine = "13.554260";
            break;
        case 6:
            ValoreDiRitorno.Luogo = "Grotte di Stiffe - profondità (Aterno)";
            ValoreDiRitorno.Latitudine = "42.254480";
            ValoreDiRitorno.Longitudine = "13.546100";
            break;
        case 7:
            ValoreDiRitorno.Luogo = "Grotte di Stiffe - ingresso (Aterno)";
            ValoreDiRitorno.Latitudine = "42.256030";
            ValoreDiRitorno.Longitudine = "13.546110";
            break;
        case 8:
            ValoreDiRitorno.Luogo = "Campana (Aterno)";
            ValoreDiRitorno.Latitudine = "42.248000";
            ValoreDiRitorno.Longitudine = "13.567260";
            break;
        case 9:
            ValoreDiRitorno.Luogo = "Valle di S. Giuliano (Torrente Vallone di S. Giuliano)";
            ValoreDiRitorno.Latitudine = "42.383420";
            ValoreDiRitorno.Longitudine = "13.399520";
            break;
        default:
            cout << "\033[31mErrore: valore inserito non valido, il luogo e le sue coordinate non verranno aggiunto al record.\033[0m" << endl;
            break;
    }

    //Ritorno del valore del luogo
    return ValoreDiRitorno;
}

record LuogoCustom(record Base)
{
    //Dichiarazione variabili
    bool InputValido = false, Max = false;
    unsigned long TempGradi, TempPrimi, TempSecondi, TempMeta;
    record ValoreDiRitorno = Base;

    //Richiesta del nome
    while (!InputValido)
    {
        //Output per l'utente
        cout << "Inserisci il nome del luogo di raccolta: ";
        getline(cin, ValoreDiRitorno.Luogo);

        //Pulizia schermo
        system("cls");

        //Verifica dell'input
        if (ValoreDiRitorno.Luogo.find(';') != string::npos)
        {
            cout << "Non puoi inserire punti e virgola nel nome del luogo!" << endl;
        }
        else
        {
            InputValido = true;
        }
    }
    InputValido = false;

    //Richiesta dei gradi della latitudine
    while (!InputValido)
    {
        //Output per l'utente
        cout << "Inserisci i gradi della latitudine \033[36m(Un esempio di questa notazione è \033[3;4m" << rand() % 90 << "\033[24m° " << rand() % 60 << "' " << rand() % 60 << "'' " << ((rand() % 2 == 1) ? "N" : "S") << "\033[23m)\033[0m: ";
        InputValido = InputLong(TempGradi);

        //Pulizia dello schermo
        system("cls");

        //Verifica dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido" << endl;
        }
        else if (90 < TempGradi)
        {
            InputValido = false;
            cout << "La latitudine deve essere compresa tra 0 e 90 gradi!" << endl;;
        }
        else if (TempGradi == 90)
        {
            Max = true;
        }
    }
    InputValido = false;

    //Richiesta dei primi della latitudine
    while ((!InputValido) && (!Max))
    {
        //Output per l'utente
        cout << "Inserisci i primi della latitudine \033[36m(Un esempio di questa notazione è \033[3m" << rand() % 90 << "° \033[4m" << rand() % 60 << "\033[24m' " << rand() % 60 << "'' " << ((rand() % 2 == 1) ? "N" : "S") << "\033[23m)\033[0m: ";
        InputValido = InputLong(TempPrimi);

        //Pulizia dello schermo
        system("cls");

        //Verifica dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido" << endl;
        }
        else if (60 < TempPrimi)
        {
            InputValido = false;
            cout << "I primi devono essere compresi tra 0 e 60!" << endl;;
        }
        else if (TempPrimi == 60)
        {
            TempGradi++;
            TempPrimi = 0;
        }
    }
    InputValido = false;
    if (Max == true)
    {
        TempPrimi = 0;
    }

    //Richiesta dei secondi della latitudine
    while ((!InputValido) && (!Max))
    {
        //Output per l'utente
        cout << "Inserisci i secondi della latitudine \033[36m(Un esempio di questa notazione è \033[3m" << rand() % 90 << "° " << rand() % 60 << "' \033[4m" << rand() % 60 << "\033[24m'' " << ((rand() % 2 == 1) ? "N" : "S") << "\033[23m)\033[0m: ";
        InputValido = InputLong(TempSecondi);

        //Pulizia dello schermo
        system("cls");

        //Verifica dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido" << endl;
        }
        else if (60 < TempSecondi)
        {
            InputValido = false;
            cout << "I secondi devono essere compresi tra 0 e 60!" << endl;;
        }
        else if (TempSecondi == 60)
        {
            TempPrimi++;
            TempSecondi = 0;
            if (TempPrimi == 60)
            {
                TempGradi++;
                TempPrimi = 0;
            }
        }
    }
    InputValido = false;
    if (Max == true)
    {
        TempSecondi = 0;
    }
    Max = false;

    //Richiesta dell'emisfero
    while (!InputValido)
    {
        //Output per l'utente
        cout << "In quale emisfero sono state fatte le misurazioni?" << endl;
        cout << "\033[1m[1]\033[22m Nord (N)" << endl;
        cout << "\033[1m[2]\033[22m Sud (S)" << endl;
        cout << "Scegli una di queste opzioni: ";
        InputValido = InputLong(TempMeta);

        //Pulizia dello schermo
        system("cls");

        //Verifica dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido!" << endl;
        }
        else if ((TempMeta < 0) && (2 < TempMeta))
        {
            InputValido = false;
            cout << "Questa opzione non esiste!" << endl;
        }
    }
    InputValido = false;

    //Assegnazione del valore di latitudine
    ValoreDiRitorno.Latitudine = to_string(TempGradi) + "° " + to_string(TempPrimi) + "' " + to_string(TempSecondi) + "'' ";
    if (TempMeta % 2 == 1)
    {
        ValoreDiRitorno.Latitudine = ValoreDiRitorno.Latitudine + "N";
    }
    else
    {
        ValoreDiRitorno.Latitudine = ValoreDiRitorno.Latitudine + "S";
    }

    //Richiesta dei gradi della longitudine
    while (!InputValido)
    {
        //Output per l'utente
        cout << "Inserisci i gradi della longitudine \033[36m(Un esempio di questa notazione è \033[3;4m" << rand() % 180 << "\033[24m° " << rand() % 60 << "' " << rand() % 60 << "'' " << ((rand() % 2 == 1) ? "E" : "W") << "\033[23m)\033[0m: ";
        InputValido = InputLong(TempGradi);

        //Pulizia dello schermo
        system("cls");

        //Verifica dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido" << endl;
        }
        else if (180 < TempGradi)
        {
            InputValido = false;
            cout << "La longitudine deve essere compresa tra 0 e 180 gradi!" << endl;;
        }
        else if (TempGradi == 180)
        {
            Max = true;
        }
    }
    InputValido = false;

    //Richiesta dei primi della longitudine
    while ((!InputValido) && (!Max))
    {
        //Output per l'utente
        cout << "Inserisci i primi della longitudine \033[36m(Un esempio di questa notazione è \033[3m" << rand() % 180 << "° \033[4m" << rand() % 60 << "\033[24m' " << rand() % 60 << "'' " << ((rand() % 2 == 1) ? "E" : "W") << "\033[23m)\033[0m: ";
        InputValido = InputLong(TempPrimi);

        //Pulizia dello schermo
        system("cls");

        //Verifica dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido" << endl;
        }
        else if (60 < TempPrimi)
        {
            InputValido = false;
            cout << "I primi devono essere compresi tra 0 e 60!" << endl;;
        }
        else if (TempPrimi == 60)
        {
            TempGradi++;
            TempPrimi = 0;
        }
    }
    InputValido = false;
    if (Max == true)
    {
        TempPrimi = 0;
    }

    //Richiesta dei secondi della longitudine
    while ((!InputValido) && (!Max))
    {
        //Output per l'utente
        cout << "Inserisci i secondi della longitudine \033[36m(Un esempio di questa notazione è \033[3m" << rand() % 180 << "° " << rand() % 60 << "' \033[4m" << rand() % 60 << "\033[24m'' " << ((rand() % 2 == 1) ? "E" : "W") << "\033[23m)\033[0m: ";
        InputValido = InputLong(TempSecondi);

        //Pulizia dello schermo
        system("cls");

        //Verifica dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido" << endl;
        }
        else if (60 < TempSecondi)
        {
            InputValido = false;
            cout << "I secondi devono essere compresi tra 0 e 60!" << endl;;
        }
        else if (TempSecondi == 60)
        {
            TempPrimi++;
            TempSecondi = 0;
            if (TempPrimi == 60)
            {
                TempGradi++;
                TempPrimi = 0;
            }
        }
    }
    InputValido = false;
    if (Max == true)
    {
        TempSecondi = 0;
    }

    //Richiesta della metà del pianeta rispetto a Greenwich
    while (!InputValido)
    {
        //Output per l'utente
        cout << "In quale metà del pianeta rispetto a Greenwich sono state fatte le misurazioni?" << endl;
        cout << "\033[1m[1]\033[22m Est (E)" << endl;
        cout << "\033[1m[2]\033[22m Ovest (W)" << endl;
        cout << "Scegli una di queste opzioni: ";
        InputValido = InputLong(TempMeta);

        //Pulizia dello schermo
        system("cls");

        //Verifica dell'input
        if (!InputValido)
        {
            cout << "Il valore inserito non è valido!" << endl;
        }
        else if ((TempMeta < 0) && (2 < TempMeta))
        {
            InputValido = false;
            cout << "Questa opzione non esiste!" << endl;
        }
    }

    //Assegnazione del valore di latitudine
    ValoreDiRitorno.Longitudine = to_string(TempGradi) + "° " + to_string(TempPrimi) + "' " + to_string(TempSecondi) + "'' ";
    if (TempMeta % 2 == 1)
    {
        ValoreDiRitorno.Longitudine = ValoreDiRitorno.Longitudine + "E";
    }
    else
    {
        ValoreDiRitorno.Longitudine = ValoreDiRitorno.Longitudine + "W";
    }

    //Ritorno dei valori al programma
    return ValoreDiRitorno;
}