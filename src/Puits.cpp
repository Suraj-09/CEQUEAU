#include "Puits.h"

Puits::Puits(int id, int active, double distance, double h0, std::vector<double> debit)
    : idCE(id),
      active(active),
      distanceRiviere(distance),
      debitPompage(debit),
      niveauInitial(h0) {}

int Puits::getIdCE() const { 
    return idCE; 
}

int Puits::getActive() const { 
    return active; 
}

double Puits::getDistanceRiviere() const { 
    return distanceRiviere; 
}

double Puits::getNiveauInitial() const { 
  return niveauInitial;
}

const std::vector<double>& Puits::getDebitPompage() const {
  return debitPompage;
}

double Puits::getDebitPompageParIndex(int idxPasDeTemps) const {
  if (idxPasDeTemps < 0) 
    return 0;

  return debitPompage[idxPasDeTemps];
}
