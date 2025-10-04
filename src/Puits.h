#include "stdafx.h"

class Puits {
private:
    int idCE;
    int active;
    double distanceRiviere;
    double niveauInitial;
    std::vector<double> debitPompage;
    std::vector<double> poidsCE;

public:
    Puits(int id, int active, double distance, double niveauInitial, std::vector<double> debit);
    Puits(int id, int active, double distance, double niveauInitial, std::vector<double> debit, std::vector<double> poids);
    
    int getIdCE() const;
    int getActive() const;
    double getDistanceRiviere() const;
    double getNiveauInitial() const;
    const std::vector<double>& getDebitPompage() const;
    const std::vector<double>& getPoidsCE() const;

    double getDebitPompageParIndex(int idxPasDeTemps) const;
    double getPoidsParIdCE(int idCE) const;
};
