void NomeLuogo(record Vector[LunghezzaDatabase], unsigned int Indice)
{
    int Scelta;
    std::cout<<"1)Campana"<<std::endl;
    std::cout<<"2)Grotte Di Stiffe"<<std::endl;
    std::cout<<"3)Vetoio"<<std::endl;
    std::cout<<"4)Barete"<<std::endl;
    std::cout<<"5)Stazione dell’Aquila"<<std::endl;
    std::cout<<"6)Sassa"<<std::endl;
    std::cout<<"7)Pizzoli"<<std::endl;
    std::cin>>Scelta;

    switch(Scelta){
        case 1: Vector[Indice].Luogo="Campana";
                Vector[Indice].Latitudine="42° 14' 48.829'' N";
                Vector[Indice].Longitudine="13° 34' 4.494'' E";
        break;
        case 2: Vector[Indice].Luogo="Grotte Di Stiffe";
                Vector[Indice].Latitudine="42° 15' 15.012'' N";
                Vector[Indice].Longitudine="13° 32' 28.183'' E";
        break;
        case 3: Vector[Indice].Luogo="Vetoio";
                Vector[Indice].Latitudine="42° 21′ 09.4'' N";
                Vector[Indice].Longitudine="13° 22′ 40.36'' E";
        break;
        case 4: Vector[Indice].Luogo="Barete";
                Vector[Indice].Latitudine="42° 26' 57.156'' N ";
                Vector[Indice].Longitudine="13° 16' 50.102'' E ";
        break;
        case 5: Vector[Indice].Luogo="Stazione dell’Aquila";
                Vector[Indice].Latitudine="42° 21' 3.924'' N";
                Vector[Indice].Longitudine="13° 23' 5.69'' E ";
        break;
        case 6: Vector[Indice].Luogo="Sassa";
                Vector[Indice].Latitudine="42° 21′ 07.44'' N";
                Vector[Indice].Longitudine="13° 17′ 57.42'' E";
        break;
        case 7: Vector[Indice].Luogo="Pizzoli";
                Vector[Indice].Latitudine="42° 26' 9.762'' N";
                Vector[Indice].Longitudine="13° 18' 4.378'' E ";
        break;
    }
}
