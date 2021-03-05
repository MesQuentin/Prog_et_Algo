#include <iostream>

using namespace std;


//Structures - Définition

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
    Noeud* dernier;
    int nbNoeud;

};

struct DynaTableau{
    int* donnees;
    int nbDonnees;
    int gdMax;
};




//Listes Chainées - Fonctions

void initialise(Liste* liste)
{
    liste->premier = NULL;
    liste->dernier = NULL;
    liste->nbNoeud = 0;
}

bool est_vide(const Liste* liste)
{
    if (liste->nbNoeud == 0) {
        return true;
    }

    else {
        return false;
    }
}

void ajoute(Liste* liste, int valeur)
{
    Noeud* Last_man_standing = new Noeud;
    Last_man_standing->donnee = valeur;
    Last_man_standing->suivant = NULL;

    if (liste->premier==NULL) {
        liste->dernier=Last_man_standing;
        liste->premier=Last_man_standing;
    }
    else {
        liste->dernier->suivant=Last_man_standing;
        liste->dernier=Last_man_standing;
    }

    liste->nbNoeud=liste->nbNoeud+1;
}

void affiche(const Liste* liste)
{
    cout << "Voici votre liste, tres cher.e :" <<endl;
    cout<<endl;

    int i = 0;
    Noeud * passeur = liste->premier;

    while (passeur!=liste->dernier->suivant) {
        cout << i << "e valeure : " << passeur->donnee << endl;
        passeur=passeur->suivant;
        i++;
    }
}

int recupere(const Liste* liste, int n)
{
    if (n==0 || n>liste->nbNoeud) {
        return -1;
    }

    Noeud* passeur = liste->premier;
    while (n!=0) {
        passeur=passeur->suivant;
        n--;
    }
    return passeur->donnee;
}

int cherche(const Liste* liste, int valeur)
{
    int i = liste->nbNoeud;
    Noeud* passeur = liste->premier;
    while (i!=0) {
        if (passeur->donnee==valeur) {
            return liste->nbNoeud-i;
        }
        else {
            passeur=passeur->suivant;
            i--;
        }
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{

    if (n>liste->nbNoeud || n<=0) {
        cout << " Mauvaise valeur de n ! N'ayez pas trop la n ! " << endl;
    }

    Noeud* passeur = liste->premier;

    while (n>1) {
        passeur=passeur->suivant;
        n--;
    }
    passeur->donnee=valeur;
}




//Tableaux Dynamiques - Fonctions

void ajoute(DynaTableau* tableau, int valeur)
{
    if (tableau->gdMax==tableau->nbDonnees) {
        tableau->donnees[tableau->nbDonnees]=valeur;
    }

    else {
        int* agrandissement = new int[tableau->gdMax +1];

        for(int i=0; i<tableau->gdMax; i++) {
            agrandissement[i] = tableau->donnees[i];
        }
        agrandissement[tableau->gdMax] = valeur;

        tableau->donnees = agrandissement;
        tableau->gdMax = tableau->gdMax + 1;
    }

    tableau->nbDonnees=tableau->nbDonnees+1;
}


void initialise(DynaTableau* tableau, int capacite)
{
    tableau->gdMax = capacite;
    tableau->donnees = new int[capacite];
    tableau->nbDonnees = 0;
}

bool est_vide(const DynaTableau* tableau)
{
    if(tableau->nbDonnees == 0){
        return true;
    }

    else{
        return false;
    }
}

void affiche(const DynaTableau* tableau)
{
    cout << "Tres cher.e, voici votre tableau :" << endl;
    cout << endl;
    for(int i=0; i<tableau->nbDonnees; i++) {
        cout << i << "e valeur : " << tableau->donnees[i] << endl;
    }
}

int recupere(const DynaTableau* tableau, int n)
{
    if (n>=0 && n <tableau->nbDonnees) {
        return tableau->donnees[n];
    }
    else {
        cout << "Ce n ne convient pas ! Courage, tout n est pas encore perdu, après tout, ils possèdent un bon sens de l'orientation ! " << endl;
        return -1;
    }
}

int cherche(const DynaTableau* tableau, int valeur)
{
    int i = 0;

    while (i<tableau->nbDonnees) {
        if (tableau->donnees[i]==valeur) {
            return i;
        }

        else {
            i++;
        }
    }

    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    if (n>=0 && n <tableau->nbDonnees) {
         tableau->donnees[n] = valeur;
    }

    else {
        cout << "Decidement, ce n ne me plais pas ! Changez-moi ce malanadrin ! " << endl;
    }
}



//Piles et Files, ou comment changer une structure qui marchait deja très bien

void pousse_file(Liste* liste, int valeur)
{
    //Fonction déjà créée, autant pour les listes que pour les tableaux dynamiques
    ajoute(liste, valeur);
}


int retire_file(Liste* liste)
{
    int i = 1;
    Noeud* passeur = liste->premier;

    while (i<liste->nbNoeud-1) {
        passeur=passeur->suivant;
        i++;
    }

    i = passeur->suivant->donnee;
    passeur->suivant=NULL;
    liste->dernier=passeur;
    liste->nbNoeud=liste->nbNoeud-1;

    return i;
}


void pousse_pile(Liste* liste, int valeur)
{
    Noeud* passeur = new Noeud;
    passeur->donnee=valeur;
    passeur->suivant=liste->premier;

    liste->premier=passeur;
    liste->nbNoeud=liste->nbNoeud+1;
}


int retire_pile(Liste* liste)
{
    int i = liste->premier->donnee;
    liste->premier=liste->premier->suivant;
    liste->nbNoeud=liste->nbNoeud-1;

    return i;
}




//Main, ou le truc soi-disant important

int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&liste) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
