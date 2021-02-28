#include "propagation.h"
#include <cstdlib>
#include <iostream>

propagation::propagation(position new_position, monde new_monde) : prob_infection(0.3), sain(0), contamine(0), inactif(0), dist_sociale(0), rayon_contamination(2), positions(new_position), world(new_monde) {}



void propagation::changer(double rayon_contamination_, double prob_infection_){
  rayon_contamination = rayon_contamination_;
  prob_infection = prob_infection_;
}

double propagation::get_prob_infection() const{
  return prob_infection;
}

double propagation::get_rayon_contamination() const{
  return rayon_contamination;
}

std::vector<int> propagation::comptage(position positions, monde world){
  int unsigned compteur_sain = 0;
  int unsigned compteur_contamine = 0;
  int unsigned i, j, k;
  std::vector<int> mon_comptage;
  positions.initialise(positions.get_N(), 0);
  for(i = 0; i < positions.get_taille(); i++){
    for(j = 0; j < positions.get_taille(); j++){
      if(world.get_monde()[i][j] == 1){
        compteur_sain++;
        positions.getx().push_back(i);
        positions.gety().push_back(j);
      }
      if(world.get_monde()[i][j] == 2)
        compteur_contamine++; 
    }
  }
  sain = compteur_sain;
  contamine = compteur_contamine;
  inactif = positions.get_N() - (sain + contamine);
  mon_comptage.push_back(sain);
  mon_comptage.push_back(contamine);
  mon_comptage.push_back(inactif);
  return mon_comptage;
}

bool propagation::propa(position positions, monde world, std::vector<int> mon_comptage, double rayon_contamination, double prob_infection){
  unsigned int i, j, k;
  std::vector<int> x = positions.getx();
  std::vector<int> y = positions.gety();

  for (i = 0; i < positions.get_taille(); i++){
    for (j = 0; j < positions.get_taille(); j++){
      if (world.get_monde()[i][j] == 2){
        for(k = 0; k < x.size(); k++){
          if(((i - x[k])*(i - x[k]) + (j - y[k])*(j - y[k]) <= rayon_contamination*rayon_contamination) && rand() <= prob_infection)
            world.get_monde()[x[k]][y[k]] = 2;
          if(mon_comptage[1] == 0)
            return true;
        }
      }
    }
  }
}
  

void propagation::affiche(std::vector<int> mon_comptage){
  for(unsigned int i; i < mon_comptage.size(); i++)
    std::cout<<mon_comptage[i]<<std::endl;
}
   
