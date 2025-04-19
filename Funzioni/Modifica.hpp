void Modifica(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    int Scelta, i, batteri;
    bool ris=false;
    StampaArray(Array, IndiceVuoto);
    wcout<<"Quale record vuoi modificare?(inserisci il numero del record) ";
    cin>>i;
    system("cls");
    wcout<<"Che tipo di modifica vuoi fare?"<<endl;
    wcout<<"1)Del luogo;"<<endl;
    wcout<<"2)Dei Batteri;"<<endl;
    cin>>Scelta;
    switch(Scelta)
    {
        case 1: system("cls");
                NomeLuogo(Array, IndiceVuoto);
        break;
        case 2: system("cls");
                for(int j=0; j<SpeciePerRecord; j++){
                    int mod;
                    wcout<<"Vuoi modificare il "<<j+1<<"° batterio?"<<endl;
                    wcout<<"1)Si"<<endl;
                    wcout<<"2)No"<<endl;
                    cin>>mod;
                    if(mod==1){
                        wcout<<"Inserisci il nome del "<<j+1<<"° batterio: "<<endl;
                        cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio;
                        wcout<<"Inserisci la concentrazione"<<endl;
                        cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione;
                        ris=InputDouble(Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione);
                        if(ris==false){
                            wcout<<"Inserimento non valido."<<endl;
                        }
                    }
                }
        break;
    }
}