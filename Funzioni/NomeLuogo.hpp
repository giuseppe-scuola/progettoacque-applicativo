void NomeLuogo(record Vector[LunghezzaDatabase], unsigned int Indice)
{
    int Scelta;
    cout<<"1)Raio"<<endl;
    cout<<"2)Pizzoli"<<endl;
    cout<<"3)Vera Sorgente"<<endl;
    cout<<"4)Fiume Vera"<<endl;
    cout<<"5)Aterno prima delle Grotte"<<endl;
    cout<<"6)Grotte in profondita'"<<endl;
    cout<<"7)Ingresso Grotte"<<endl;
    cout<<"8)Aterno"<<endl;
    cout<<"9)Valle San Giuliano"<<endl;
    cin>>Scelta;

    switch(Scelta){
        case 1: Vector[Indice].Luogo="Raio";
                Vector[Indice].Latitudine="42° 21' 30.5'' N";
                Vector[Indice].Longitudine="13° 19' 32.8'' E";
        break;
        case 2: Vector[Indice].Luogo="Pizzoli";
                Vector[Indice].Latitudine="42° 26' 9.762'' N";
                Vector[Indice].Longitudine="13° 18' 4.378'' E ";
        break;
        case 3: Vector[Indice].Luogo="Vera Sorgente";
                Vector[Indice].Latitudine="42° 22' 03.2'' N";
                Vector[Indice].Longitudine="13° 27' 32.1'' E";
        break;
        case 4: Vector[Indice].Luogo="Fiume Vera";
                Vector[Indice].Latitudine="42° 22' 06.0'' N";
                Vector[Indice].Longitudine="13° 27' 31.4'' E";
        break;
        case 5: Vector[Indice].Luogo="Aterno prima delle Grotte";
                Vector[Indice].Latitudine="//";
                Vector[Indice].Longitudine="//";
        break;
        case 6: Vector[Indice].Luogo="Grotte in profondita'";
                Vector[Indice].Latitudine="//";
                Vector[Indice].Longitudine="//";
        break;
        case 7: Vector[Indice].Luogo="Ingresso Grotte";
                Vector[Indice].Latitudine="//";
                Vector[Indice].Longitudine="//";
        break;
        case 8: Vector[Indice].Luogo="Aterno";
                Vector[Indice].Latitudine="//";
                Vector[Indice].Longitudine="//";
        break;
        case 9: Vector[Indice].Luogo="Valle San Giuliano";
                Vector[Indice].Latitudine="//";
                Vector[Indice].Longitudine="//";
        break;
    }
}