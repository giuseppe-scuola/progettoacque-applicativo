
void Inserimento(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    int Scelta;

    //scelta tra inserimento massivo o singolo
    cout<<"Che tipo di inserimento vuoi fare?"<<endl;
    cout<<"1)Singolo"<<endl;
    cout<<"2)Massivo"<<endl;
    cin>>Scelta;
    bool ris=false;

    switch(Scelta){

        case 1: PulisciSchermo;
                cout<<"Hai scelto l'inserimento singolo"<<endl;
                cout<<endl;
                cout<<"Qual è il nome del luogo?"<<endl;
                NomeLuogo(Array, IndiceVuoto);
                cout<<endl;
                for(int i=0; i<SpeciePerRecord; i++;){
                    cout<<"Inserisci il nome del "<<i+1"° batterio: "<<endl;
                    cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio;
                    for(int k=0; k<SpeciePerRecord; k++){
                        while(ris==false){
                            cout<<"Inserisci la concentrazione"<<endl;
                            cin>>Array[IndiceVuoto].Dati[k].Concentrazione;
                            ris=InputDouble(Array[IndiceVuoto].Dati[k].Concentrazione)
                            if(ris==false){
                                cout<<"Inserimento non valido."<<endl;
                            }
                        }
                    }
                }
        break;
        case 2: PulisciSchermo;
                int NumMassivi;
                cout<<"Hai scelto l'inserimento massivo"<<endl;
                cout<<endl;

                cout<<"Quanti dati vuoi inserire? ";
                cin>>NumMassivi;
                for(int i=0; i<NumMassivi; i++)
                {
                    cout<<"Qual è il nome del "<<i+1"° luogo?"<<endl;
                    NomeLuogo(Array, IndiceVuoto);
                    for(int j=0; j<SpeciePerRecord; j++){
                        cout<<"Inserisci il nome del "<<j+1<<"° batterio: "<<endl;
                        cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio;
                        cout<<"Inserisci la concentrazione"<<endl;
                        cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione;
                        ris=InputDouble(Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione)
                        if(ris==false){
                            cout<<"Inserimento non valido."<<endl;
                        }

                    }
                }
        break;
        default: cout<<"Opzione non valida."<<endl;
        break;
    }
    IndiceVuoto++;
    return;
}
