void Stampa(record Array[LunghezzaDatabase], unsigned int IndiceVuoto)
{
    unsigned int conta=0;
    while(conta<=IndiceVuoto)
    {
        std::cout<<Array[IndiceVuoto].Latitudine<<"|"<<Array[IndiceVuoto].Longitudine<<"|"<<Array[IndiceVuoto].NumeroSpecie<<'\t';
        for(int k=0; k<8; k++)
        {
            std::cout<<Array[IndiceVuoto].Dati[k].NomeBatterio;
            std::cout<<Array[IndiceVuoto].Dati[k].Concentrazione;
        }
        conta++;
        std::cout<<std::endl;
    }
}
