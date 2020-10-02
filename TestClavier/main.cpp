#include <iostream>
#include "clavier.h"

using namespace std;

int main()
{
    TOUCHES_CLAVIER touche;
    Clavier leClavier;
    do{
        touche = leClavier.ScruterClavier();
        if(touche != AUCUNE){
            cout << "La touche appuyée est " << touche << endl;
        }
    }while(touche != FIN);

    return 0;
}
