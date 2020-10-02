/**
*/

#include "horloge.h"

/**
 * @brief Horloge::Horloge
 * @param _nbModes
 * @param _resolution
 */
Horloge::Horloge(const int _nbModes, const int _resolution) :
    nbModes(_nbModes),
    resolution(_resolution)
{
    leCadran = new Cadran(5, 5);
    leClavier = new Clavier;
    valAvant = time(NULL);
    heures = 0;
    minutes = 0;
    mode = AUCUN_REGLAGE;
}

/**
 * @brief Horloge::~Horloge
 */
Horloge::~Horloge()
{
   delete leCadran;
   delete leClavier;
}

/**
 * @brief Horloge::AvancerMinutes
 * @return
 */
bool Horloge::AvancerMinutes()
{
    bool retour = false;
    minutes++;
    if(minutes >= 60){
        retour = true;
    }
    return retour;
}

/**
 * @brief Horloge::AvancerHeures
 * @return
 */
bool Horloge::AvancerHeures()
{
    bool retour = false;
    heures++;
    switch (resolution) {
        case 12 :
            if(heures > 12){
                retour = true;
                heures = 1;
            }
            break;
        case 24:
            if(heures >= 24){
                retour = true;
                heures = 0;
            }
            break;
    }
    return retour;
}

/**
 * @brief Horloge::ChangerMode
 */
void Horloge::ChangerMode()
{
    mode = (mode + 1)%nbModes; //mode peut prendre les valeurs de 0 à 2
}

/**
 * @brief Horloge::ReculerHeures
 */
void Horloge::ReculerHeures()
{
    heures--;
    switch (resolution) {
        case 12 :
            if(heures == 0){
                heures = 12;
            }
            break;
        case 24:
            if(heures == -1){
                heures = 23;
            }
            break;
    }
}

/**
 * @brief Horloge::ReculerMinutes
 */
void Horloge::ReculerMinutes()
{
    minutes--;
    if(minutes == -1){
        minutes = 59;
    }
}

/**
 * @brief Horloge::Controler
 * @param _numTouche
 * @return
 */
TOUCHES_CLAVIER Horloge::Controler(const TOUCHES_CLAVIER _numTouche)
{
    TOUCHES_CLAVIER touche;
    touche = leClavier->ScruterClavier();
    switch (mode) {
        case AUCUN_REGLAGE:
            ActualiserHeure();
            leCadran->Afficher(heures, 1);
            leCadran->Afficher(minutes, 4);
            if(touche == MODE){
                ChangerMode();
            }
            break;
        case REGLAGE_HEURE:
            if(touche == MODE){
                ChangerMode();
            }
            if(touche == MOINS){
                ReculerHeures();
            }
            if(touche == PLUS){
                AvancerHeures();
            }
            leCadran->Afficher("HH", 1);
            leCadran->Afficher(heures, 4);
            break;
        case 2:
            if(touche == MODE){
                ChangerMode();
            }
            if(touche == MOINS){
                ReculerMinutes();
            }
            if(touche == PLUS){
                AvancerMinutes();
            }
            leCadran->Afficher("MM", 1);
            leCadran->Afficher(minutes, 4);
            break;
    }
    return touche;
}

/**
 * @brief Horloge::ActualiserHeure
 */
void Horloge::ActualiserHeure()
{
    time_t valCourante = time(NULL);
    double seconde = difftime(valCourante, valAvant);
    if (seconde > 1) // à modifier pour aller plus vite pendant le test
    {
        valAvant = valCourante;
        if (AvancerMinutes()){
            AvancerHeures();
        }
    }
}
