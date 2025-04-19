void RicercaPrompt(record Array[LunghezzaDatabase], unsigned int IndiceVuoto)
{
        unsigned int Scelta = 0;
        string Luogo;
        string Batt;
        int Val;
        int SceltaConcentrazione;
        int Val1, Val2;
        string Tipo;
    wcout<<"Inserisci che tipo di ricerca vuoi fare?"<<endl;
    wcout<<"1)Ricerca per Luogo"<<endl;
    wcout<<"2)Ricerca per Batterio"<<endl;
    wcout<<"3)Ricerca per Concentrazione"<<endl;
    wcout<<"4)Ricerca per Tipologia"<<endl;
    InputInt(Scelta);
    switch (Scelta)
    {
        case 1: system("cls");
                wcout<<"Hai selezionato la ricerca per luogo."<<endl;
                wcout<<"Inserisci il luogo che vuoi ricercare: ";
                getline(cin, Luogo);
                RicercaLuogo(Array, IndiceVuoto, Luogo);
        break;
        case 2: system("cls");
                wcout<<"Hai selezionato la ricerca per batterio."<<endl;
                wcout<<"Inserisci il Batterio che vuoi ricercare: ";
                getline(cin, Batt);
                //RicercaBatterio(Array, IndiceVuoto, Batt);
        break;
        case 3: system("cls");
                wcout<<"Hai selezionato la ricerca per concentrazione."<<endl;
                wcout<<"Come vuoi basare la ricerca?"<<endl;
                wcout<<"1)Concentrazione minore del valore inserito"<<endl;
                wcout<<"2)Concentrazione maggiore del valore inserito"<<endl;
                wcout<<"3)Concentrazione compresa tra due valori inseriti."<<endl;
                cin>>SceltaConcentrazione;
                switch (SceltaConcentrazione)
                {
                case 1: system("cls");
                        wcout<<"Hai selezionato la ricerca per concentrazione minore di un valore inserito"<<endl;
                        wcout<<"Inserisci il valore: ";
                        cin>>Val;
                        //ConcentrazioneMinore(Array, IndiceVuoto, Val);
                break;
                case 2: system("cls");
                        wcout<<"Hai selezionato la ricerca per concentrazione maggiore di un valore inserito"<<endl;
                        wcout<<"Inserisci il valore: ";
                        cin>>Val;
                        //ConcentrazioneMaggiore(Array, IndiceVuoto, Val);
                break;
                case 3: system("cls");
                        wcout<<"Hai selezionato la ricerca per concentrazione compresa tra due valori"<<endl;
                        wcout<<"Inserisci il valore 1: ";
                        cin>>Val1;
                        wcout<<"Inserisci il valore 2: ";
                        cin>>Val2;
                        //ConcentrazioneCompresa(Array, IndiceVuoto, Val1, Val2);
                break;
                default: wcout<<"Inserimento non valido."<<endl;
                break;
                }
        break;
        case 4: system("cls");
                wcout<<"Hai selezionato la ricerca per tipologia di batterio."<<endl;
                wcout<<"Inserisci il la Tipologia che vuoi ricercare: ";
                getline(cin, Tipo);
                //RicercaTipo(Array, IndiceVuoto, Tipo);
        break;
        default: wcout<<"Inserimento non valido."<<endl;
        break;
    }

}

void RicercaLuogo(record Array[LunghezzaDatabase], unsigned int IndiceVuoto, string Localita)
{
    int conta=0;
    for(int i=0; i<LunghezzaDatabase; i++){
        if(Array[i].Luogo==Localita){
            StampaRecord(Array, i);
            conta++;
        }
    }
    if(conta==0){
        wcout<<"Il luogo ricercato non corrisponde a nessun risultato."<<endl;
    }
}
