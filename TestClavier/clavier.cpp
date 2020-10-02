/**
*/

#include <cstdio>
#include "clavier.h"

/**
  @brief Clavier::Clavier
 */
Clavier::Clavier() {
    struct termios etatCourant;

    tcgetattr(STDIN_FILENO, &etatInitial);
    etatCourant = etatInitial;
    etatCourant.c_lflag &= ~ICANON;
    etatCourant.c_lflag &= ~ECHO;
    etatCourant.c_lflag &= ~ISIG;
    etatCourant.c_oflag &= ~NL0;
    etatCourant.c_oflag &= ~CR0;
    etatCourant.c_oflag &= ~TAB0;
    etatCourant.c_oflag &= ~BS0;
    etatCourant.c_cc[VMIN] = 0;
    etatCourant.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &etatCourant);
    //read(STDIN_FILENO, &toucheAvant, 1);
    //touche = toucheAvant;
}

/**
 * @brief Clavier::~Clavier
 */
Clavier::~Clavier() {
    tcsetattr(STDIN_FILENO, TCSANOW, &etatInitial);
}

/**
 * @brief Clavier::ScruterClavier
 * @return
 */
TOUCHES_CLAVIER Clavier::ScruterClavier()
{

    TOUCHES_CLAVIER retour = AUCUNE;
    char touche = 0;
    int test = read(STDIN_FILENO, &touche, 1);

    if (test != -1) {
        switch (touche) {
        case '+' : //touche PLUS enfoncée
            retour = PLUS;
            break;
        case '-' : //touche MOINS enfoncée
            retour = MOINS;
            break;
        case '\n': //touche Entrée enfoncée pour FIN
        case '\r':
            retour = FIN;
            break;
        case ' ': //touche Espace enfoncée pour MODE
            retour = MODE;
            break;
        default: //pas de touche enfoncée donc AUCUNE
            retour = AUCUNE;
            break;
        }
    }
    return retour;
}
