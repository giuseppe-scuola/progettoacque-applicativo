void Inserimento(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    int Scelta;

    //scelta tra inserimento massivo o singolo
    std::cout<<"Che tipo di inserimento vuoi fare?"<<std::endl;
    std::cout<<"1)Singolo"<<std::endl;
    std::cout<<"2)Massivo"<<std::endl;
    std::cin>>Scelta;

    switch(Scelta){

        case 1: PulisciSchermo;
                std::cout<<"Hai scelto l'inserimento singolo"<<std::endl;
                std::cout<<std::endl;

                std::cout<<"Qual è il nome del luogo?"<<std::endl;
                NomeLuogo(Array, IndiceVuoto);

                PulisciSchermo;
                std::cout<<"Inserisci il numero della specie: ";
                std::cin>>Array[IndiceVuoto].NumeroSpecie;
                std::cout<<std::endl;

                for(int k=0, k<SpeciePerRecord, k++){
                    std::cout<<"Inserisci il nome del "<<k+1<<"° batterio: "<<std::endl;
                    std::cin>>Array[IndiceVuoto].NomeBatterio;
                    std::cout<<"Inserisci la concentrazione"<<std::endl;
                    std::cin>>Array[IndiceVuoto].Concentrazione;
                }

        break;
        case 2: PulisciSchermo;
                int Num_Massivi;
                std::cout<<"Hai scelto l'inserimento massivo"<<std::endl;
                std::cout<<std::endl;

                std::cout<<"Quanti dati vuoi inserire? ";
                std::cin>>Num_Massivi;
                for(int i=0; i<Num_Massivi; i++)
                {
                    std::cout<<"Qual è il nome del "<<i+1"° luogo?"<<std::endl;
                    NomeLuogo(Array, IndiceVuoto);
                    PulisciSchermo;
                    std::cout<<"Inserisci il numero della specie: ";
                    InputDouble(Array[IndiceVuoto].NumeroSpecie);
                    std::cout<<std::endl;
                    for(int j=0; j<SpeciePerRecord; j++){
                        std::cout<<"Inserisci il nome del "<<j+1<<"° batterio: "<<std::endl;
                        std::cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio;
                        std::cout<<"Inserisci la concentrazione"<<std::endl;
                        std::cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione;
                    }
                }
        break;
        default: std::cout<<"Opzione non valida."<<std::endl;
        break;
    }
    IndiceVuoto++;
    return;
}
