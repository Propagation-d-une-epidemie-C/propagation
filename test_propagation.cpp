#include "propagation.h"
#include <iostream>

int main(){
	position ma_position;
	monde mon_monde(ma_position);
	propagation ma_propagation(ma_position, mon_monde);
	std::vector<int> mon_comptage = ma_propagation.comptage(ma_position, mon_monde);
	double rayon_contamination = ma_propagation.get_rayon_contamination();
	double prob_infection = ma_propagation.get_prob_infection();
	ma_propagation.propa(ma_position, mon_monde, mon_comptage, rayon_contamination, prob_infection);
	ma_propagation.affiche(mon_comptage);
	return 0;
}
