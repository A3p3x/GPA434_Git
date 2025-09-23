// En-t�te � r�diger :
//  - contenu de ce fichier :........ � d�finir
//  - contexte : Dans le cadre du cour GPA434
//  - objectifs : Creer un jeux DomeSupremacy
//  - r�alis� par Philippe Le Bourdais
//  - date de cr�ation : 2025-09-21

#include <ezgame>
#include "Arena.h"
#include "Dome.h"
#include "GameEngine.h"

// Point d'entr�e du programme
int WinMain()
{
    ezgame::Application app;    // < instantiation d'objet de la classe ezgame::Application
    app.run<GameEngine>();      // < ex�cution de la fonction run -> d�marre la boucle principale

    return 0;


    //return 0;

}
