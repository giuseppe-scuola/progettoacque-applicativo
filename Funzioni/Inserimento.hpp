void Inserimento(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    int Scelta;

    //scelta tra inserimento massivo o singolo
    wcout<<"Che tipo di inserimento vuoi fare?"<<endl;
    wcout<<"1)Singolo"<<endl;
    wcout<<"2)Massivo"<<endl;
    cin>>Scelta;
    bool ris=false;

    switch(Scelta){

        case 1: system("cls");
                wcout<<"Hai scelto l'inserimento singolo"<<endl;
                wcout<<endl;
                wcout<<"Qual e' il nome del luogo?"<<endl;
                NomeLuogo(Array, IndiceVuoto);
                wcout<<endl;
                for(int i=0; i<SpeciePerRecord; i++){
                    wcout<<"Inserisci il nome del "<<i+1<<"° batterio: "<<endl;
                    cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio;
                    for(int k=0; k<SpeciePerRecord; k++){
                        while(ris==false){
                            wcout<<"Inserisci la concentrazione"<<endl;
                            cin>>Array[IndiceVuoto].Dati[k].Concentrazione;
                            ris=InputDouble(Array[IndiceVuoto].Dati[k].Concentrazione);
                            if(ris==false){
                                wcout<<"Inserimento non valido."<<endl;
                            }
                        }
                    }
                }
        break;
        case 2: system("cls");
                int NumMassivi;
                wcout<<"Hai scelto l'inserimento massivo"<<endl;
                wcout<<endl;

                wcout<<"Quanti dati vuoi inserire? ";
                cin>>NumMassivi;
                for(int i=0; i<NumMassivi; i++)
                {
                    wcout<<"Qual e' il nome del "<<i+1<<"° luogo?"<<endl;
                    NomeLuogo(Array, IndiceVuoto);
                    for(int j=0; j<SpeciePerRecord; j++){
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
        default: wcout<<"Opzione non valida."<<endl;
        break;
    }
    IndiceVuoto++;
}