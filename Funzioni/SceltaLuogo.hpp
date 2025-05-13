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
        cout << "[0] Posto e coordinate a scelta (WIP);" << endl;
        cout << "[1] Fiume Raio;" << endl;
        cout << "[2] Pizzoli;" << endl;
        cout << "[3] Sorgente del fiume Vera;" << endl;
        cout << "[4] Fiume Vera;" << endl;
        cout << "[5] Fiume Aterno prima delle Grotte di Stiffe;" << endl;
        cout << "[6] Fiume Aterno dopo le Grotte di Stiffe;" << endl;
        cout << "[7] Ingresso delle Grotte di Stiffe;" << endl;
        cout << "[8] Profondità delle Grotte di Stiffe;" << endl;
        cout << "[9] Valle San Giuliano;" << endl;
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
            cout << "Inserisci il nome del luogo: ";
            getline(cin, ValoreDiRitorno.Luogo);
            cout << "Inserisci il valore di latitudine (Per esempio " << rand() % 90 << "° " << rand() % 60 << "' " << rand() % 60 << "'' " << ((rand() % 2 == 1) ? "N" : "S") << "): ";
            getline(cin, ValoreDiRitorno.Latitudine);
            cout << "Inserisci il valore di longitudine (Per esempio " << rand() % 180 << "° " << rand() % 60 << "' " << rand() % 60 << "'' " << ((rand() % 2 == 1) ? "E" : "W") << "): ";
            getline(cin, ValoreDiRitorno.Longitudine);
            break;
        case 1:
            ValoreDiRitorno.Luogo = "Fiume Raio";
            ValoreDiRitorno.Latitudine = "42° 21' 30.5'' N";
            ValoreDiRitorno.Longitudine = "13° 19' 32.8'' E";
            break;
        case 2:
            ValoreDiRitorno.Luogo = "Pizzoli";
            ValoreDiRitorno.Latitudine = "42° 26' 9.762'' N";
            ValoreDiRitorno.Longitudine = "13° 18' 4.378'' E";
            break;
        case 3:
            ValoreDiRitorno.Luogo = "Sorgente del fiume Vera";
            ValoreDiRitorno.Latitudine = "42° 22' 3.2'' N";
            ValoreDiRitorno.Longitudine = "13° 27' 32.1'' E";
            break;
        case 4:
            ValoreDiRitorno.Luogo = "Fiume Vera";
            ValoreDiRitorno.Latitudine = "42° 22' 6.0'' N";
            ValoreDiRitorno.Longitudine = "13° 27' 31.4'' E";
            break;
        case 5:
            ValoreDiRitorno.Luogo = "Fiume Aterno prima delle Grotte di Stiffe";
            ValoreDiRitorno.Latitudine = "//";
            ValoreDiRitorno.Longitudine = "//";
            break;
        case 6:
            ValoreDiRitorno.Luogo = "Fiume Aterno dopo le Grotte di Stiffe";
            ValoreDiRitorno.Latitudine = "//";
            ValoreDiRitorno.Longitudine = "//";
            break;
        case 7:
            ValoreDiRitorno.Luogo = "Ingresso delle Grotte di Stiffe";
            ValoreDiRitorno.Latitudine = "//";
            ValoreDiRitorno.Longitudine = "//";
            break;
        case 8:
            ValoreDiRitorno.Luogo = "Profondità delle Grotte di Stiffe";
            ValoreDiRitorno.Latitudine = "//";
            ValoreDiRitorno.Longitudine = "//";
            break;
        case 9:
            ValoreDiRitorno.Luogo = "Valle San Giuliano";
            ValoreDiRitorno.Latitudine = "//";
            ValoreDiRitorno.Longitudine = "//";
            break;
        default:
            cout << "Errore: valore inserito non valido, il luogo e le sue coordinate non verranno aggiunto al record." << endl;
            break;
    }

    //Ritorno del valore del luogo
    return ValoreDiRitorno;
}
