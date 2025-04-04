void ApriFile(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto, std::ifstream &FileInput);

int Menu();
bool InputInt(unsigned int &Valore);

void Inserimento(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto);
bool InputDouble(double &Valore);

void Stampa(record Array[LunghezzaDatabase], unsigned int IndiceVuoto);

void Modifica(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto);

void CancellaPrompt(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto);
void Cancella(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto, unsigned int DaRimuovere);

void Ricerca(record Array[LunghezzaDatabase], unsigned int IndiceVuoto);

void Grafico(record Array[LunghezzaDatabase], unsigned int IndiceVuoto);

void Nome_Luogo(record Vector[LunghezzaDatabase], unsigned int Indice)

void SalvaSuFilePrompt(record Array[LunghezzaDatabase], unsigned int IndiceVuoto);
void SalvaSuFile(record Array[LunghezzaDatabase], unsigned int IndiceVuoto, std::ofstream &FileOutput);

#include "ApriFile.hpp"
#include "Menu.hpp"
#include "InputInt.hpp"
#include "Inserimento.hpp"
#include "InputDouble.hpp"
#include "Stampa.hpp"
#include "Modifica.hpp"
#include "Cancella.hpp"
#include "Ricerca.hpp"
#include "Grafico.hpp"
#include "NomeLuogo.hpp"
#include "SalvaSuFile.hpp"
