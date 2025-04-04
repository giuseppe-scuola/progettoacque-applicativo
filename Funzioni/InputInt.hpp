bool InputInt(unsigned int &Valore)
{
    //Dichiarazione variabili
    bool Convertibile;
    std::string Temp;

    //Input dalla console
    std::getline(std::cin, Temp);

    //Controllo per caratteri non numerici
    try
    {
        Valore = std::stoul(Temp);
        Convertibile = true;
    }
    catch (...)
    {
        Convertibile = false;
    }

    //Risultato della funzione
    return Convertibile;
}
