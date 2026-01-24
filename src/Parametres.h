//****************************************************************************
// Fichier: Parametres.h
//
// Date creation: 2012-10-01
// Auteur:
//                Rio Tinto Alcan
//                Energie electrique
//                1954 Davis, Saguenay arr. Jonquiere,
//                G7S 4R7, QC, Canada
//
//****************************************************************************
#pragma once

#include "DateChrono.h"

//! Classe de donnees des parametres relatifs reservoirs SOL, NAPPE et MARAIS.
class ParamSol
{
public:
  //! Coefficient d'infiltration dans le réservoir NAPPE.
  // CIN
  std::vector<float> coeffInfiltrationNappe;
  //! Coefficient de vidange du réservoir LACS et MARAIS.
  // CVMAR
  float coeffVidangeLacsMarais;
  //! Coefficient de vidange basse du réservoir NAPPE.
  // CVNB
  std::vector<float> coeffVidangeBasseNappe;
  //! Coefficient de vidange haute du réservoir NAPPE.
  // CVNH
  std::vector<float> coeffVidangeHauteNappe;
  //! Coefficient de vidange basse du réservoir SOL.
  // CVSB
  float coeffVidangeBasseSol;
  //! Coefficient de vidange intermédiaire du réservoir SOL.
  // CVSI
  std::vector<float> coeffVidangeIntermediaireSol;
  //! Infiltration maximale (mm/jour).
  // XINFMA
  float infiltrationMax;

  //! Seuil d'infiltration du réservoir SOL vers le réservoir NAPPE (mm).
  // HINF
  std::vector<float> seuilInfiltrationSolVersNappe;
  //! Seuil de vidange intermédiaire du réservoir SOL (mm).
  // HINT
  std::vector<float> seuilVidangeIntermediaireSol;
  //! Seuil de vidange du réservoir LACS et MARAIS (mm).
  // HMAR
  float seuilVidangeLacsMarais;
  //! Seuil de vidange supérieure du réservoir NAPPE (mm).
  // HNAP
  std::vector<float> seuilVidangeHauteNappe;
  //! Seuil de prélévement de l'eau à taux potentiel, par évapotranspiration (mm).
  // HPOT
  std::vector<float> seuilPrelevementEauTauxPotentiel;
  //! Hauteur du réservoir SOL (mm).
  // HSOL
  std::vector<float> hauteurReservoirSol;
  //! Lame d'eau nécessaire pour que débute le ruissellement sur les surfaces impermeables (mm).
  // HRIMP
  std::vector<float> lameEauDebutRuisellement;

  //! Coefficient de correction des précipitations annuelles en fonction de l'altitude (mm/mètre/an).
  // COEP
  float coeffCorrectionPluieAnAltitude;
  //! Fraction de l'évapotranspiration prise dans le réservoir NAPPE (de 0.0 a 1.0);
  // EVNAP

  //float fractionEvapoNappe;
  //! Fraction de surface imperméable des carreaux entiers (de 0.0 à 1.0).
  // TRI
  std::vector<float> fractionImpermeableCE;
  //! Latitude moyenne du bassin versant en degrés et minutes sexagésimales
  //! (ex.: XLA = 4245 pour une latitude de 42o45').
  // XLA
  float latitudeMoyenneBV;
  //! Correction des températures en fonction de l'altitude (degC/1 000 m).
  // COET
  float correctionTempAltitude;

};

//! Classe de donnees pour les valeurs initiales des reservoirs.
class ParamSolInitial
{
public:
  //! Niveau d'eau initial dans le réservoir SOL (mm).
  // HSINI
  float niveauInitialSol;
  //! Niveau d'eau initial dans le réservoir NAPPE (mm).
  // HNINI
  float niveauInitialNappe;
  //! Niveau d'eau initial dans le réservoir LACS et MARAIS (mm).
  // HMINI
  float niveauInitialLacsMarais;
  //! Debit initial à l'exutoire du bassin versant (m3/s).
  // QO
  float debitInitialExutoire;
};

//! Classe de donnees pour les parametres optionnels.
class ParamOption
{
public:
  //! Module de fonte a utiliser
  int moduleFonte;
  //! Module d'evapotranspiration a utiliser
  int moduleEvapo;
  //! Execution de la qualite?
  bool calculQualite;
  //! Module DLI %%%%%
  int moduleDLI;
  // TODO: Releves neige
  bool logNeigeAjustee;
    //! Utilisation du module d'ombrage
  int moduleOmbrage;
  //! Utilisation du module de pompage
  int modulePompage;
 };

//! Classe de donnees pour les parametres relatifs a la fonction de transfert.
class ParamTransfert
{
public:
  //! Parametre de calcul des coefficients de transfert des carreaux partiels, pour
  //! le pas de temps de la simulation.
  // EXXKT
  float paramCalculCoeffTransfertCP;
  //! Temps de concentration du bassin versant (en pas de temps).
  // ZN
  float tempsConcentrationBV;
 };

// TODO: Releves neige
enum TypeAjustementNeige {AUCUN, ZONE, STATIONS_3};
/*! valeur specifique d'un parametre pour la zone définie par
    iMin, iMax, jMin et jMax
*/
class ValeurZone
{
public:
  int iMin;
  int iMax;
  int jMin;
  int jMax;
  float valeur;
};

//! Classe de donnees pour les parametres facultatifs.
class ParamFacultatifs
{
public:
  //! Corrections des superficies des carreaux partiels.
  std::map<int, float> superficieCPAmontCorriges;
  //! Coefficients de transfert particuliers
  std::map<int, double> coeffTxParticuliers;
  /*!
    Permettent de tenir compte, pour le calcul des coefficients de transfert,
    des lacs chevauchant plusieurs carreaux partiels, ou encore d'exclure du carreau
    partiel les lacs non situes sur le reseau d'écoulement
  */
  std::map<int, int> lacs;
  //! Liste fraction de surface impermeable de carreau entier
  std::map<int, float> surfacesImper;

  //! Liste de l'appartenance des carreaux entiers a une zone de lac exutoire (precipitations directes)
  std::vector<int> lacExutoire;

  // TODO: Releves neige
  //! Releves de neige remplacant les stocks de neige calcules aux dates donnees.
  std::multimap<DateChrono, ValeurZone> relevesNeige;
  TypeAjustementNeige typeAjustementNeige;
 };

class ParamPompage {
public:
    int delai;
    double coeffPompage;
    std::vector<float> conductiviteHydraulique;
    std::vector<float> coeffEmmagasinement;  // coefficient d'emmagasinement
};

// TODO: Releves neige
typedef std::multimap<DateChrono, ValeurZone>::const_iterator RelevesNeigeIter;

//! Classe des parametres de la simulation
class Parametres
{
public:
   Parametres();
   Parametres(DateChrono dateDebut, DateChrono dateFin);
   ~Parametres();

   //! Getter Date de debut de la simulation
   const DateChrono& dateDebut() const;
   //! Getter Date de fin de la simulation
   const DateChrono& dateFin() const;
   //! Getter Duree en heure d'un pas de simulation: 1,2,3,4,6,8,12,24 heures
   int dureeHeuresPasSimulation() const;
   //! Getter nombre jours de simulation
   int nbJoursSimulation() const;
   //! Getter nombre pas de simulation
   int nbPasSimulation() const;
   //! Getter nombre pas pas jour de simulation
   int nbPasParJourSimulation() const;
   //! Getter selection des carreaux entiers qu'on desire en sortie
   const std::vector<bool>& resultatsIdCE() const;
   //! Getter selection des carreaux partiels qu'on desire en sortie
   const std::vector<bool>& resultatsIdCP() const;
   //! Getter param sol
   const ParamSol& sol() const;
   //! Getter param solInitial
   const ParamSolInitial& solInitial() const;
   //! Getter param option
   const ParamOption& option() const;
   //! Getter param transfert
   const ParamTransfert& transfert() const;
   //! Getter param facultatifs
   const ParamFacultatifs& facultatifs() const;
      //! Getter param pompage
   const ParamPompage& pompage() const;

   //! Initialisation des parametres a partir de fichiers d'intrants Matlab
   void initialiserFichier(std::string nomFichierParamExec, std::string nomFichierParamSimul, int nbCE, int nbCP);
   //! Initialisation des parametres a partir de variables Matlab (mxArray)
   void initialiser(const mxArray* paramExec, const mxArray* paramSimul, int nbCE, int nbCP);

private:
   DateChrono dateDebut_;
   DateChrono dateFin_;
   // 1,2,3,4,6,8,12,24 heures
   int dureeHeuresPasSimulation_;
   // Selection des carreaux entiers qu'on desire en sortie
   std::vector<bool> resultatsIdCE_;
   // Selection des carreaux partiels qu'on desire en sortie
   std::vector<bool> resultatsIdCP_;
   ParamSol   sol_;
   ParamSolInitial solInitial_;
   ParamOption option_;
   ParamTransfert transfert_;
   ParamFacultatifs facultatifs_;
   ParamPompage pompage_;

   //! Validation du nombre de valeurs d'un parametre spatialisable.
   bool validerNombreValeurs(const std::string& nomChamp, int nbValeur, int nbValeursOK);
};

//! Parametres spatialisables.
/*!
  Parametres obligatoires dont la valeur peut etre modifiee
  pour chaque carreau entier a l'aide de vecteurs facultatifs.
*/
class ParamCE {
public:
  ParamCE();
  // NEIGE
  //! Seuil de transformation pluie-neige (degC).
  // STRNE
  float seuilTranformationPluieNeige;
  //! Taux potentiel de fonte en forêt (mm/degC/jour).
  // TFC
  float tauxPotentielFonteForet;
  //! Taux potentiel de fonte en clairière (mm/degC/jour).
  // TFD
  float tauxPotentielFonteClairiere;
  //! Seuil de température de fonte en foret (degC).
  // TSC
  float seuilTempFonteForet;
  //! Seuil de température de fonte en clairiere (degC).
  // TSD
  float seuilTempFonteClairiere;
  //! Temperature du murissement du stock de neige (degC).
  // TTS
  float tempMurissementNeige;
  // SOL
  //! Coefficient d'infiltration dans le réservoir NAPPE.
  // CIN
  float coeffInfiltrationNappe;
  //! Coefficient de vidange basse du réservoir NAPPE.
  // CVNB
  float coeffVidangeBasseNappe;
  //! Coefficient de vidange haute du réservoir NAPPE.
  // CVNH
  float coeffVidangeHauteNappe;
  //! Coefficient de vidange intermédiaire du réservoir SOL.
  // CVSI
  float coeffVidangeIntermediaireSol;
  //! Seuil d'infiltration du réservoir SOL vers le réservoir NAPPE (mm).
  // HINF
  float seuilInfiltrationSolVersNappe;
  //! Seuil de vidange intermédiaire du réservoir SOL (mm).
  // HINT
  float seuilVidangeIntermediaireSol;
  //! Seuil de vidange supérieure du réservoir NAPPE (mm).
  // HNAP
  float seuilVidangeHauteNappe;
  //! Seuil de prélévement de l'eau à taux potentiel, par évapotranspiration (mm).
  // HPOT
  float seuilPrelevementEauTauxPotentiel;
  //! Hauteur du réservoir SOL (mm).
  // HSOL
  float hauteurReservoirSol;
  //! Lame d'eau nécessaire pour que débute le ruissellement sur les surfaces impermeables (mm).
  // HRIMP
  float lameEauDebutRuisellement;
  //! Fraction de surface imperméable des carreaux entiers (de 0.0 à 1.0).
  // TRI
  float fractionImpermeableCE;
  // conductivite hydraulique
  float conductiviteHydraulique;
  // coefficient d'emmagasinnement : C'est la quantité d'eau libéré sous une variation unitaire de la charge hydraulique
  float coeffEmmagasinement;
};
