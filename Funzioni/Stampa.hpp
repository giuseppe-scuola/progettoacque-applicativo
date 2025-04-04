void Stampa(record Array[LunghezzaDatabase], unsigned int IndiceVuoto)
{
    unsigned int conta=0;
    while(conta<=IndiceVuoto)
    {
        cout<<Array[IndiceVuoto].Latitudine<<"|"<<Array[IndiceVuoto].Longitudine<<"|"<<Array[IndiceVuoto].NumeroSpecie<<'\t';
        for(int k=0; k<8; k++)
        {
            cout<<Array[IndiceVuoto].Dati[k].NomeBatterio;
            cout<<Array[IndiceVuoto].Dati[k].Concentrazione;
        }
        conta++;
        cout<<endl;
    }
}
