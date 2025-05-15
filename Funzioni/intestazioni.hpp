void Azzera(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto);

void ApriFile(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto, ifstream &FileInput);

unsigned long Menu();
bool InputLong(unsigned long &Valore);

void Inserimento(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto);
void InserimentoSingolo(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto);
void InserimentoMassivo(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto);
record SceltaLuogo(record Array[LunghezzaDatabase], unsigned long IndiceVuoto);
record LuogoCustom(record Base);

void StampaArray(record Array[LunghezzaDatabase], unsigned long IndiceVuoto);
void StampaRecord(record Array[LunghezzaDatabase], unsigned long IndiceDaStampare);

void Modifica(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto);
void ModificaBatteri(record &DaModificare);

void CancellaPrompt(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto);
void Cancella(record Array[LunghezzaDatabase], unsigned long &IndiceVuoto, unsigned long DaRimuovere);

void RicercaPrompt(record Array[LunghezzaDatabase], unsigned long IndiceVuoto);
void RicercaLuogo(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, string Localita);
void RicercaBatterio(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, string BatterioRicerca);
void ConcentrazioneMinore(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, unsigned long Valore);
void ConcentrazioneMaggiore(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, unsigned long Valore);
void ConcentrazioneCompresa(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, unsigned long Valore1, unsigned long Valore2);
void RicercaTipo(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, string Tipo);



void Grafico(record Array[LunghezzaDatabase], unsigned long IndiceVuoto);

void SalvaSuFilePrompt(record Array[LunghezzaDatabase], unsigned long IndiceVuoto);
void SalvaSuFile(record Array[LunghezzaDatabase], unsigned long IndiceVuoto, ofstream &FileOutput);


#include "Azzera.hpp"
#include "ApriFile.hpp"
#include "Menu.hpp"
#include "InputLong.hpp"
#include "Inserimento.hpp"
#include "Stampa.hpp"
#include "Modifica.hpp"
#include "Cancella.hpp"
#include "Ricerca.hpp"
#include "Grafico.hpp"
#include "SceltaLuogo.hpp"
#include "SalvaSuFile.hpp"