#ifndef CLAVIER_H
#define CLAVIER_H

/**
  @file clavier.h
  @brief Déclaration de la classe Clavier
  @author Maëva Soulard
  @date 02/10/2020
  */
#include <termios.h>
#include <unistd.h>

/**
 * @brief The TOUCHES_CLAVIER enum
 * @details Enumération des touches du clavier
 */
enum TOUCHES_CLAVIER{
    AUCUNE,
    FIN,
    MODE,
    PLUS,
    MOINS
};

class Clavier {
public:
    Clavier();
    ~Clavier();
    TOUCHES_CLAVIER ScruterClavier();

private:
    struct termios etatInitial ;

};

#endif // CLAVIER_H
