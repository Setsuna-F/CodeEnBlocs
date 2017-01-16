#ifndef SCORE_HPP
#define SCORE_HPP

#include <sstream>

class vector;


/**
 *
 * \brief sct_score la structure qui garde le score et le nom du level
 *
 */
struct sct_score{
    int score;
    std::string namelevel;
};


/**
 *
 * \fun void sauveLevel(int score, std::string namelevel)
 * \brief fonction qui va sauvegarder les scores dans le fichier
 *        allScores.txt avec tous les autres scores
 * \param score le score du level courant
 * \param namelevel le nom du level courant
 */
void saveLevel(int score, std::string namelevel);


void saveAllScore(std::vector<int>);


/**
 *
 * \fun std::vector<sct_score> getAllScore()
 *
 * \brief fonction qui recupere tous les scores du fichier allScores.txt
 * \return un vector de structure sur les scores.
 */
std::vector<sct_score> getAllScore();


std::vector<int> getAllScoreWithoutName();


/**
 *
 * \fun bool isFistTuto()
 *
 * \brief fonction qui va creer un fichier si c'est un premier
 *        passage dans cette fonction.
 * \return retourne true si c'est le premier pasage dans la fonction
 *         (si le fichier n'existe pas) et retourne false sinon.
 */
bool isFistTuto();


#endif
