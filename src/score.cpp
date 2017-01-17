#include <iostream>
#include <fstream>
#include <vector>

#include "score.hpp"

using namespace std;

/**
 *
 * \fun void sauveLevel(int score, std::string namelevel)
 * \brief fonction qui va sauvegarder les scores dans le fichier
 *        allScores.txt avec tous les autres scores
 * \param score le score du level courant
 * \param namelevel le nom du level courant
 */
void saveLevel(int score, std::string namelevel) {
	std::string name = to_string(score) + namelevel;

	ofstream fichier("res/allScores.ceg", ios::out | ios::app);  // ouverture en écriture avec effacement du fichier ouvert
	if (fichier) {
		fichier << name << "\n";
		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
}


void saveAllScore(std::vector<int> vect_score) {
	ofstream fichier("res/allScores.ceg", ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
	if (fichier) {
		for (int i = 0; i < vect_score.size(); i++)
		{
			fichier << to_string(vect_score[i]) << "\n";
		}
		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
}



/**
 *
 * \fun std::vector<sct_score> getAllScore()
 *
 * \brief fonction qui recupere tous les scores du fichier allScores.txt
 * \return un vector de structure sur les scores.
 */
std::vector<sct_score> getAllScore() {
	std::vector<sct_score> vect_score;
	ifstream fichier("res/allScores.ceg", ios::in);  // ouverture en écriture avec effacement du fichier ouvert
	if (fichier) {
		std::string ligne;
		//printf("Tous les scores: \n");
		while (getline(fichier, ligne)) {
			char str[40];
			int i;

			sscanf(ligne.c_str(), "%d%s", &i, str);
			sct_score sct_s;
			sct_s.score = i;
			sct_s.namelevel = str;

			vect_score.push_back(sct_s);
		}

		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;

	return vect_score;
}

std::vector<int> getAllScoreWithoutName() {
	std::vector<int> vect_score;
	ifstream fichier("res/allScores.ceg", ios::in);  // ouverture en écriture avec effacement du fichier ouvert
	if (fichier) {
		std::string ligne;
		//printf("Tous les scores: \n");
		while (getline(fichier, ligne)) {
			char str[40];
			int i;
			
			sscanf(ligne.c_str(), "%d", &i);

			vect_score.push_back(i);
		}

		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier !" << endl;

	return vect_score;
}

/**
 *
 * \fun bool isFistTuto()
 *
 * \brief fonction qui va creer un fichier si c'est un premier
 *        passage dans cette fonction.
 * \return retourne true si c'est le premier pasage dans la fonction
 *         (si le fichier n'existe pas) et retourne false sinon.
 */
bool isFistTuto(){
    ifstream lecturefichier("firstTuto.ceg", ios::in);
    if(lecturefichier){
        lecturefichier.close();
        return false;
    }
    else{
        ofstream ecriturefichier("firstTuto.ceg", ios::out);
        lecturefichier.close();
        ecriturefichier.close();
        return true;
    }
}
