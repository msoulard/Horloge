#ifndef CLAVIER_H
#define CLAVIER_H

#include <termios.h>
#include <unistd.h>

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
