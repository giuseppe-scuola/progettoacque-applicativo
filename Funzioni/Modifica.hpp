void Modifica(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    int Scelta, i, batteri;
    bool ris=false;
    StampaArray(Array, IndiceVuoto);
    cout<<"Quale record vuoi modificare?(inserisci il numero del record) ";
    cin>>i;
    system("cls");
    cout<<"Che tipo di modifica vuoi fare?"<<endl;
    cout<<"1)Del luogo;"<<endl;
    cout<<"2)Dei Batteri;"<<endl;
    cin>>Scelta;
    switch(Scelta)
    {
        case 1: system("cls");
                NomeLuogo(Array, IndiceVuoto);
        break;
        case 2: system("cls");
                for(int j=0; j<SpeciePerRecord; j++){
                    int mod;
                    cout<<"Vuoi modificare il "<<j+1<<"° batterio?"<<endl;
                    cout<<"1)Si"<<endl;
                    cout<<"2)No"<<endl;
                    cin>>mod;
                    if(mod==1){
                        cout<<"Inserisci il nome del "<<j+1<<"° batterio: "<<endl;
                        cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio;
                        cout<<"Inserisci la concentrazione"<<endl;
                        cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione;
                        ris=InputDouble(Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione);
                        if(ris==false){
                            cout<<"Inserimento non valido."<<endl;
                        }
                    }
                }
        break;
    }
}