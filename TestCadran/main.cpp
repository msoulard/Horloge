#include <iostream>
#include "cadran.h"
#include <unistd.h>

using namespace std;

int main()
{
    Cadran leCadran;
    Cadran unAutreCadran(10, 10, 2, 20, 34, 45);
    char touche;

    for(int i = 10 ; i >= 0 ; i--){
        leCadran.Afficher(i, 3, 2);
        unAutreCadran.Afficher(i, 5, 1);
        sleep(1);
    }
    leCadran.Afficher("Fin ", 1, 0);
    unAutreCadran.Effacer();
    unAutreCadran.Afficher("Fin ", 1, 0);
    cin >> touche;

    return 0;
}
