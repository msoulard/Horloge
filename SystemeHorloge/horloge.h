#ifndef HORLOGE_H
#define HORLOGE_H

/**
   @file horloge.h
   @brief Déclaration de la classe Horloge
   @author Maëva Soulard
   @date 02/10/2020
*/
#include "clavier.h"
#include "cadran.h"
#include <time.h>

/**
 * @brief The MODES_HORLOGE enum
 * @details Enumération des modes de l'horloge
 */
enum MODES_HORLOGE{
    AUCUN_REGLAGE,
    REGLAGE_HEURE,
    REGLAGE_MINUTE
};

class Horloge
{
public:
    Horloge(const int _nbModes=3, const int _resolution=24);
    ~Horloge();
    bool AvancerMinutes();
    bool AvancerHeures();
    void ChangerMode();
    void ReculerHeures();
    void ReculerMinutes();
    TOUCHES_CLAVIER Controler(const TOUCHES_CLAVIER _numTouche=AUCUNE);
    void ActualiserHeure();
private:
    int heures;
    int minutes;
    const int nbModes;
    const int resolution;
    int mode;
    time_t valAvant;
    Cadran *leCadran;
    Clavier *leClavier;
};

#endif // HORLOGE_H
