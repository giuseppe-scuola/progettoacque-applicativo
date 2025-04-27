void Azzera(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto);

void ApriFile(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto, ifstream &FileInput);

unsigned int Menu();
bool InputInt(unsigned int &Valore);

void Inserimento(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto);
void InserimentoSingolo(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto);
void InserimentoMassivo(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto);
record SceltaLuogo(record Array[LunghezzaDatabase], unsigned int IndiceVuoto);
bool InputDouble(double &Valore);

void StampaArray(record Array[LunghezzaDatabase], unsigned int IndiceVuoto);
void StampaRecord(record Array[LunghezzaDatabase], unsigned int IndiceDaStampare);

void Modifica(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto);
void ModificaBatteri(record &DaModificare);

void CancellaPrompt(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto);
void Cancella(record Array[LunghezzaDatabase], unsigned int &IndiceVuoto, unsigned int DaRimuovere);

void RicercaPrompt(record Array[LunghezzaDatabase], unsigned int IndiceVuoto);
void RicercaLuogo(record Array[LunghezzaDatabase], unsigned int IndiceVuoto, string Localita);
void RicercaBatterio(record Array[LunghezzaDatabase], unsigned int IndiceVuoto, string BatterioRicerca);
void ConcentrazioneMinore(record Array[LunghezzaDatabase], unsigned int IndiceVuoto, unsigned int Valore);
void ConcentrazioneMaggiore(record Array[LunghezzaDatabase], unsigned int IndiceVuoto, unsigned int Valore);
void ConcentrazioneMaggiore(record Array[LunghezzaDatabase], unsigned int IndiceVuoto, unsigned int Valore);


void Grafico(record Array[LunghezzaDatabase], unsigned int IndiceVuoto);

void SalvaSuFilePrompt(record Array[LunghezzaDatabase], unsigned int IndiceVuoto);
void SalvaSuFile(record Array[LunghezzaDatabase], unsigned int IndiceVuoto, ofstream &FileOutput);


#include "Azzera.hpp"
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
#include "SceltaLuogo.hpp"
#include "SalvaSuFile.hpp"
