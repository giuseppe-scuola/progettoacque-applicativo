void RicercaPrompt(record Array[LunghezzaDatabase], unsigned long IndiceVuoto)
{
    unsigned long Scelta = 0;
    string Luogo;
    string Batt;
    unsigned long Val;
    unsigned long SceltaConcentrazione;
    unsigned long Val1, Val2;
    string Tipo;
    bool InputValido = false;

    cout<<"[1]Ricerca per Luogo..."<<endl;
    cout<<"[2]Ricerca per Batterio..."<<endl;
    cout<<"[3]Ricerca per Concentrazione..."<<endl;
    cout<<"[4]Ricerca per Tipologia..."<<endl;
    cout<<endl;
    cout<<"Inserisci che tipo di ricerca vuoi fare: ";
    InputLong(Scelta);
    switch (Scelta)
    {
        case 1: system("cls");
                cout<<"Hai selezionato la ricerca per luogo."<<endl;
                cout<<"Inserisci il luogo che vuoi ricercare: ";
                getline(cin, Luogo);
                RicercaLuogo(Array, IndiceVuoto, Luogo);
        break;
        case 2: system("cls");
                cout<<"Hai selezionato la ricerca per batterio."<<endl;
                cout<<"Inserisci il Batterio che vuoi ricercare: ";
                getline(cin, Batt);
                RicercaBatterio(Array, IndiceVuoto, Batt);
        break;
        case 3: system("cls");
                cout<<"Hai selezionato la ricerca per concentrazione."<<endl;
                cout<<"Come vuoi basare la ricerca?"<<endl;
                cout<<"[1]Concentrazione minore del valore inserito..."<<endl;
                cout<<"[2]Concentrazione maggiore del valore inserito..."<<endl;
                cout<<"[3]Concentrazione compresa tra due valori inseriti..."<<endl;
                cin>>SceltaConcentrazione;
                switch (SceltaConcentrazione)
                {
                case 1:
                        while (!InputValido){
                            system("cls");
                            cout<<"Hai selezionato la ricerca per concentrazione minore di un valore inserito"<<endl;
                            cout<<"Inserisci il valore: ";
                            InputValido = InputLong(Val);
                        }
                        ConcentrazioneMinore(Array, IndiceVuoto, Val);
                break;
                case 2: while (!InputValido){
                            system("cls");
                            cout<<"Hai selezionato la ricerca per concentrazione maggiore di un valore inserito"<<endl;
                            cout<<"Inserisci il valore: ";
                            InputValido = InputLong(Val);
                        }
                        ConcentrazioneMaggiore(Array, IndiceVuoto, Val);
                break;
                case 3:
                        while (!InputValido){
                            system("cls");
                            cout<<"Hai selezionato la ricerca per concentrazione compresa tra due valori"<<endl;
                            cout<<"Inserisci il valore 1: ";
                            InputValido = InputLong(Val1);
                        }
                        InputValido=false;
                        while(!InputValido){
                            cout<<"Inserisci il valore 2: ";
                            InputValido = InputLong(Val2);
                        }
                        if(Val1<Val2){
                                ConcentrazioneCompresa(Array, IndiceVuoto, Val1, Val2);
                        }
                        else{
                                ConcentrazioneCompresa(Array, IndiceVuoto, Val2, Val1);
                        }
                break;
                default: cout<<"Inserimento non valido."<<endl;
                break;
                }
        break;
        case 4: system("cls");
                cout<<"Hai selezionato la ricerca per tipologia di batterio."<<endl;
                cout<<"Inserisci il la Tipologia che vuoi ricercare: ";
                getline(cin, Tipo);
                RicercaTipo(Array, IndiceVuoto, Tipo);
        break;
        default: cout<<"Inserimento non valido."<<endl;
        break;
    }
}

void RicercaLuogo(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, string Localita)
{
    int Conta=0;
    for(int i=0; i<LunghezzaDatabase; i++){
        if(Array[i].Luogo.find(Localita) != string::npos){
            StampaRecord(Array, i);
            Conta++;
        }
    }
    if(Conta==0){
        cout<<"Il luogo ricercato non corrisponde a nessun risultato."<<endl;
    }
        else{
        cout<<Conta<<" è il numero di risultati ottenuti."<<endl;
    }
}

void RicercaBatterio(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, string BatterioRicerca)
{
    int Conta = 0;
    for (int i = 0; i < IndiceVuoto; i++) {
        for (int j = 0; j < Array[i].NumeroSpecie; j++) {
            if (Array[i].Dati[j].NomeBatterio.find(BatterioRicerca) != string::npos) {
                StampaRecord(Array, i);
                Conta++;
                break;
            }
        }
    }
    if(Conta==0){
        cout<<"Il batterio ricercato non corrisponde a nessun risultato."<<endl;
    }
    else{
        cout<<Conta<<" è il numero di risultati ottenuti."<<endl;
    }
}

void ConcentrazioneMinore(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, unsigned long Valore)
{
    int Conta = 0;
    for (int i = 0; i < IndiceVuoto; i++) {
        for (int j = 0; j < SpeciePerRecord; j++) {
            if (Array[i].Dati[j].Concentrazione < Valore) {
                StampaRecord(Array, i);
                Conta++;
                break;
            }
        }
    }
    if(Conta==0){
        cout<<"Non è stato ritrovato alcun batterio con una concentrazione minnore di "<<Valore<<"."<<endl;
    }
    else{
        cout<<Conta<<" è il numero di risultati ottenuti."<<endl;
    }
}

void ConcentrazioneMaggiore(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, unsigned long Valore)
{
    int Conta = 0;
    for (int i = 0; i < IndiceVuoto; i++) {
        for (int j = 0; j < Array[i].NumeroSpecie; j++) {
            if (Array[i].Dati[j].Concentrazione > Valore) {
                StampaRecord(Array, i);
                Conta++;
                break;
            }
        }
    }
    if(Conta==0){
        cout<<"Non è stato ritrovato alcun batterio con una concentrazione maggiore di "<<Valore<<endl;
    }
    else{
        cout<<Conta<<" è il numero di risultati ottenuti"<<endl;
    }
}

void ConcentrazioneCompresa(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, unsigned long Valore1, unsigned long Valore2)
{
    int Conta = 0;
    for (int i = 0; i < IndiceVuoto; i++) {
        for (int j = 0; j < Array[i].NumeroSpecie; j++) {
            if (Array[i].Dati[j].Concentrazione >= Valore1 &&
                Array[i].Dati[j].Concentrazione <= Valore2) {
                StampaRecord(Array, i);
                Conta++;
                break;
            }
        }
    }
    if(Conta==0){
        cout<<"Non è stato ritrovato alcun batterio con una concentrazione compresa tra "<<Valore1<<" e "<<Valore2<<"."<<endl;
    }
    else{
        cout<<Conta<<" è il numero di risultati ottenuti."<<endl;
    }
}

void RicercaTipo(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, string Tipo)
{
    int Conta = 0;
    for (int i = 0; i < IndiceVuoto; i++) {
        for (int j = 0; j < Array[i].NumeroSpecie; j++) {
            if (Array[i].Dati[j].Tipologia.find(Tipo) != string::npos) {
                StampaRecord(Array, i);
                Conta++;
                break;
            }
        }
    }
    if(Conta==0){
        cout<<"Il batterio ricercato non corrisponde a nessun risultato."<<endl;
    }
    else{
        cout<<Conta<<" è il numero di risultati ottenuti."<<endl;
    }
}
