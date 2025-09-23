// En-tête à rédiger :
//  - contenu de ce fichier :........ à définir
//  - contexte : Dans le cadre du cour GPA434
//  - objectifs : Creer un jeux DomeSupremacy
//  - réalisé par Philippe Le Bourdais
//  - date de création : 2025-09-21

#include <ezgame>
#include "Arena.h"
#include "Dome.h"
#include "GameEngine.h"

// Point d'entrée du programme
int WinMain()
{
    ezgame::Application app;    // < instantiation d'objet de la classe ezgame::Application
    app.run<GameEngine>();      // < exécution de la fonction run -> démarre la boucle principale

    return 0;


    //return 0;

}
