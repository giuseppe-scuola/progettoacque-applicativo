void Inserimento(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    int Scelta;

    //scelta tra inserimento massivo o singolo
    std::cout<<"Che tipo di inserimento vuoi fare?"<<std::endl;
    std::cout<<"1)Singolo"<<std::endl;
    std::cout<<"2)Massivo"<<std::endl;
    std::cin>>Scelta;
    bool ris=false;

    switch(Scelta){

        case 1: PulisciSchermo;
                std::cout<<"Hai scelto l'inserimento singolo"<<std::endl;
                std::cout<<std::endl;
                std::cout<<"Qual è il nome del luogo?"<<std::endl;
                NomeLuogo(Array, IndiceVuoto);
                std::cout<<std::endl;
                std::cout<<"Inserisci il nome del batterio: "<<std::endl;
                std::cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio;
                for(int k=0; k<SpeciePerRecord; k++){
                    while(ris==false){
                        std::cout<<"Inserisci la concentrazione"<<std::endl;
                        std::cin>>Array[IndiceVuoto].Dati[k].Concentrazione;
                        ris=InputDouble(Array[IndiceVuoto].Dati[k].Concentrazione)
                        if(ris==false){
                            std::cout<<"Inserimento non valido."<<std::endl;
                        }
                    }
                }
        break;
        case 2: PulisciSchermo;
                int NumMassivi;
                std::cout<<"Hai scelto l'inserimento massivo"<<std::endl;
                std::cout<<std::endl;

                std::cout<<"Quanti dati vuoi inserire? ";
                std::cin>>NumMassivi;
                for(int i=0; i<NumMassivi; i++)
                {
                    std::cout<<"Qual è il nome del "<<i+1"° luogo?"<<std::endl;
                    NomeLuogo(Array, IndiceVuoto);
                    for(int j=0; j<SpeciePerRecord; j++){
                        std::cout<<"Inserisci il nome del "<<j+1<<"° batterio: "<<std::endl;
                        std::cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio;
                        std::cout<<"Inserisci la concentrazione"<<std::endl;
                        std::cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione;
                        ris=InputDouble(Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione)
                        if(ris==false){
                            std::cout<<"Inserimento non valido."<<std::endl;
                        }

                    }
                }
        break;
        default: std::cout<<"Opzione non valida."<<std::endl;
        break;
    }
    IndiceVuoto++;
    return;
}
