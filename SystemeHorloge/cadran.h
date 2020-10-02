#ifndef CADRAN_H
#define CADRAN_H

/**
  @file cadran.h
  @brief Déclaration de la classe Cadran
  @author Maëva Soulard
  @date 01/10/2020
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Cadran{
public:
    Cadran(const int _posX=1, const int _posY=1, const int _hauteur=1, const int _largeur=7, const int _texte=33, const int _fond=42);
    ~Cadran();
    void Afficher(const string _texte, const int _positionY=0, int _positionX=0);
    void Afficher(const int _valeur, const int _positionY=0, int _positionX=0);
    void Effacer();
private:
    void PositionnerCurseur(const int _posx, const int _posy);
    int posX;   /// coordonnée en X du premier caractère dans le cadran
    int posY;   /// coordonnée en Y du premier caractère dans le cadran
    int hauteur;    /// nombre de lignes du cadran
    int largeur;    /// nombre de caractères par ligne
    int texte; ///couleur du texte
    int fond; ///couleur du fond
};

#endif // CADRAN_H
