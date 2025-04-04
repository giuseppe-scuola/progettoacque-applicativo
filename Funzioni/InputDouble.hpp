bool InputDouble(double &Valore)
{
    //Dichiarazione variabili
    bool Convertibile;
    std::string Temp;

    //Input dalla console
    std::getline(std::cin, Temp);

    //Controllo per caratteri non numerici
    try
    {
        Valore = std::stod(Temp);
        Convertibile = true;
    }
    catch (...)
    {
        Convertibile = false;
    }

    //Risultato della funzione
    return Convertibile;
}
