/*
 Programme : mastermind
 But :  l'utilisateur doit deviner une chaine de 4 lettre aléatoire decidé par l'ordinateur
 Date de dernière modification : 08/09/2021
 Auteur : T.Lauriou/Q.Robert
 Remarques : Code conforme aux spécification internes données en cours
*/
#include <random>
#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;
int main(void)
{
    //VARIABLE************************************************
    //***********************************************************
    char propJoueur[4]; //tableau du joueur
    char code[4];       //tableau avec le code du mastermind

    bool victoire = false; //lind'icateur si le joueur a gagné ou non
    int tentativeAct;// le tour dans lesquelle le joueur est
    int nbrBienPlace = 0;  //nombre de lettre bien place
    int nbrMalPlace = 0;   //nombre de lettre mal placée
    int nbrA = 0;          //nbr de A dans le code
    int nbrB = 0;          //nbr de B dans le code
    int nbrC = 0;          //nbr de C dans le code
    int nbrD = 0;          //nbr de D dans le code
    int nbrAJ = 0;         //nbr de A dans la proposition du joueur
    int nbrBJ = 0;         //nbr de B dans la proposition du joueur
    int nbrCJ = 0;         //nbr de C dans la proposition du joueur
    int nbrDJ = 0;         //nbr de D dans la proposition du joueur
    int nbrABP = 0;        //nbr de A dans le code bien placé
    int nbrBBP = 0;        //nbr de B dans le code bien placé
    int nbrCBP = 0;        //nbr de C dans le code bien placé
    int nbrDBP = 0;        //nbr de D dans le code bien placé
    //INITIALISATION*******************************************
    //***********************************************************

    //initialisation du code du mastermind
    for (int i = 0; i < 4; i++)
    {
        srand((unsigned int)time(0)); //ici on utilise le temps afin que le random soit différent à chaque fois
        code[i] = 'a' + rand() % 4;   //on affecte une lettre à chaque tour de la boucle
        sleep(1);                     //ce sleep permet de ne pas avoir 4 fois la même lettre à cause de la rapidité d'éxecution du programme
        cout << code[i] << endl;
    }

    //JEU***********************************************************
    //***************************************************************

    //compter combien il y a doccurence de chaque lettre dans le code
    for (int j = 0; j < 4; j++)
    {
        switch (code[j])
        {
        case 'a':
            nbrA = nbrA + 1;
            break;

        case 'b':
            nbrB = nbrB + 1;
            break;

        case 'c':
            nbrC = nbrC + 1;
            break;

        case 'd':
            nbrD = nbrD + 1;
            break;
        }
    }

    //debut du jeu
    for (tentativeAct = 1; tentativeAct < 13; tentativeAct++)
    {
        //reinitialisation des variables  utilisée durant un tour
        nbrAJ = 0;
        nbrBJ = 0;
        nbrCJ = 0;
        nbrDJ = 0;

        nbrBienPlace = 0;
        nbrMalPlace = 0;

        //recupération de la proposition du joueur
        cout <<"tour "<<tentativeAct<<"/12" " veuillez saisir votre proposition lettre par lettre en minuscule : ";
        for (int l = 0; l < 4; l++)
        {
            cin >> propJoueur[l];
            cout << " ";
        }

        //comptage des occurence de chaque lettre dans le proposition du joueur et recherche du nbr de lettre bien placée
        for (int m = 0; m < 4; m++)
        {
            //comptage des occurence de chaque lettre dans le proposition du joueur
            switch (propJoueur[m])
            {
            case 'a':
                nbrAJ = nbrAJ + 1;
                break;

            case 'b':
                nbrBJ = nbrBJ + 1;
                break;

            case 'c':
                nbrCJ = nbrCJ + 1;
                break;

            case 'd':
                nbrDJ = nbrDJ + 1;
                break;
            }

            //recherche du nombre de lettre bien placée

            if (code[m] == propJoueur[m])
            {
                nbrBienPlace = nbrBienPlace + 1;

                //on compte les occurence des lettres bien placées

                switch (code[m])
                {
                case 'a':
                    nbrABP = nbrABP + 1;
                    break;

                case 'b':
                    nbrBBP = nbrBBP + 1;
                    break;

                case 'c':
                    nbrCBP = nbrCBP + 1;
                    break;

                case 'd':
                    nbrDBP = nbrDBP + 1;
                    break;
                }
            }
        }

        //recherche des nombre mal placés
        if (nbrA > nbrAJ)
        {
            nbrMalPlace += nbrA - nbrABP + nbrAJ - nbrA;
        }
        else if (nbrAJ >= nbrA)
        {
            nbrMalPlace += nbrAJ - nbrABP + nbrA - nbrAJ;
        }
        if (nbrB > nbrBJ)
        {
            nbrMalPlace += nbrB - nbrBBP + nbrBJ - nbrB;
        }
        else if (nbrBJ >= nbrB)
        {
            nbrMalPlace += nbrBJ - nbrBBP + nbrB - nbrBJ;
        }
        if (nbrC > nbrCJ)
        {
            nbrMalPlace += nbrC - nbrCBP + nbrCJ - nbrC;
        }
        else if (nbrCJ >= nbrC)
        {
            nbrMalPlace += nbrCJ - nbrCBP + nbrC - nbrCJ;
        }
        if (nbrD > nbrDJ)
        {
            nbrMalPlace += nbrD - nbrDBP + nbrDJ - nbrD;
        }
        else if (nbrDJ >= nbrD)
        {
            nbrMalPlace += nbrDJ - nbrDBP + nbrD - nbrDJ;
        }

        //affichage du nombre de lettre bien et mal place
        cout << nbrBienPlace << " bien place " << nbrMalPlace << " mal place " << endl;

        //si on a les 4 lettres qui sont bien placées on sort de la boucle
        if (nbrBienPlace == 4)
        {
            victoire = true;
            break;
        }
    }

    //FIN DU JEU ET AFFICHAGE

    //affichage du message de victoire ou de défaite
    if(victoire = true)
    {
        cout << "Bravo il t'a fallu " << tentativeAct<< " tentative";
    }
    else
    {
        cout << "dommage tu fera mieux la prochaine fois";
    }
}