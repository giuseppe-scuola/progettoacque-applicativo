void Modifica(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto)
{
    int Scelta, i, batteri;
    Stampa(Array, IndiceVuoto);
    std::cout<<"Quale record vuoi modificare?(inserisci il numero del record) ";
    std::cin>>i;
    PulisciSchermo;
    std::cout<<"Che tipo di modifica vuoi fare?"<<std::endl;
    std::cout<<"1)Del luogo;"<<std::endl;
    std::cout<<"2)Dei Batteri;"<<std::endl;
    std::cin>>Scelta;
    switch(Scelta)
    {
        case 1: PulisciSchermo;
                NomeLuogo(Array, IndiceVuoto);
                std::cout<<"Vuoi modificare anche i dati dei batteri?"
                std::cout<<"1)Si"<<std::endl;
                std::cout<<"2)No"<<std::endl;
                std::cin>>batteri;
                switch(batteri)
                {
                    case 1: for(int j=0; j<SpeciePerRecord; j++){
                                std::cout<<"Inserisci il nome del "<<j+1<<"° batterio: "<<std::endl;
                                std::cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].NomeBatterio;
                                std::cout<<"Inserisci la concentrazione"<<std::endl;
                                std::cin>>Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione;
                                ris=InputDouble(Array[IndiceVuoto].Dati[Array[IndiceVuoto].NumeroSpecie].Concentrazione)
                                if(ris==false){
                                    std::cout<<"Inserimento non valido."<<std::endl;
                                }
                            }
                    break;
                    default: std::cout<<"Inserimento non valido"<<std::endl;
                }
        break;
        case 2: PulisciSchermo;
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
        break;
    }
    return;
}
