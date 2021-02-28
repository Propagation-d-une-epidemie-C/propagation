#ifndef _propagation
#define _propagation
#include <vector>
#include "monde.h"


class propagation {
  private:
  
    // déclaration des données
    double prob_infection;
    unsigned int sain, contamine, inactif;
    double dist_sociale;
    double rayon_contamination;
    position positions;
    monde world;
  
  public:
    //constructeur
    propagation(position new_position, monde new_monde);
    //déclaration des méthodes
    void changer(double rayon_contamination_, double prob_infection_);
    double get_prob_infection() const;
    double get_rayon_contamination() const;
    std::vector<int> comptage(position positions, monde world);
    bool propa(position positions, monde world, std::vector<int> mon_comptage, double rayon_contamination, double prob_infection);
    double R() const;
    void affiche(std::vector<int> mon_comptage);
};

#endif
