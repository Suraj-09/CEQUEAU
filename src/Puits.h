#include "stdafx.h"

class Puits {
private:
    int idCE;
    int active;
    double distanceRiviere;
    double niveauInitial;
     std::vector<double> debitPompage;

public:
    Puits(int id, int active, double distance, double niveauInitial, std::vector<double> debit);
    
    int getIdCE() const;
    int getActive() const;
    double getDistanceRiviere() const;
    double getNiveauInitial() const;
    const std::vector<double>& getDebitPompage() const;
    double getDebitPompageParIndex(int idxPasDeTemps) const;
};
