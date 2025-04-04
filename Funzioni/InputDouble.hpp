bool InputDouble(double &Valore)
{
    //Dichiarazione variabili
    bool Convertibile;
    string Temp;

    //Input dalla console
    getline(cin, Temp);

    //Controllo per caratteri non numerici
    try
    {
        Valore = stod(Temp);
        Convertibile = true;
    }
    catch (...)
    {
        Convertibile = false;
    }

    //Risultato della funzione
    return Convertibile;
}
