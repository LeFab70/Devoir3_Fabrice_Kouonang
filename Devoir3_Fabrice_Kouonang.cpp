/*
     Programmer: Fabrice Kouonang
     Date:      08/11/2024
     But:       Le programme presente un menu d'operations au choix a l'user
                et recupere les informations sur chaque categorie de son choix
                puis calcule et affiche une visulisation des resultats finaux

*/

#include <iostream>
#include<iomanip>

using namespace std;


/*
==================================================
 |       Prototypes des fonctions                 |
 |                                                |
==================================================
*/
void afficherMessageAccuiel(int ordreMenu);
void afficherMenu(void);
bool validationEntree(double minInterval, double maxInterval, int valAcomparer, string msg);
double evaluationTotalFacture(int qteElement, string msg1, string msg2);
void visualiserTotaux(int nbreCanne, int nbreCourone, double prixTotalCanne, double prixTotalCourone);


/*
==================================================
 |       Definitions des constantes               |
 |                                                |
==================================================
*/

//Prix standard des couronnes en $ 
const double PRIX_COURON_MIN     = 10.0;
const double PRIX_COURON_MIN_INF = 15.0;
const double PRIX_COURON_MIN_SUP = 25.0;
const double PRIX_COURON_MAX     = 40.0;

//Prix standard des cannes en $
const double PRIX_CANNE_MIN     = 6.0;
const double PRIX_CANNE_MIN_INF = 8.0;
const double PRIX_CANNE_MIN_SUP = 10.0;
const double PRIX_CANNE_MAX     = 15.0;

//Autres constantes
const double TAUX_TAXE          = (double) 13/100;



int main()
{
    //Liste des inputs
    unsigned short choixMenu         = 0;
    unsigned short nbreCourone       = 0;
    unsigned short nbreCanne         = 0;

    // liste des outputs
    double   prixTotalCourone        = 0.0;
    double   prixTotalCanne          = 0.0;
  
    cout << setprecision(2) << fixed;
 
    do
    {
        system("cls");
        afficherMessageAccuiel(0);
        afficherMenu();
        cin >> choixMenu;

        //Validation des donnees utilisateurs
        validationEntree(1, 4,choixMenu, " Choix incorrect, entrez votre choix : ");
       
        //Donnees valides ==suite du programme
        if (choixMenu != 4)
        {
            system("cls");

            switch (choixMenu)
            {
            case 1:
                // Couronne

                afficherMessageAccuiel(choixMenu);
                cin >> nbreCourone;
                //validation entree user
                validationEntree(1, 3, nbreCourone, " Choix incorrect, entrez le nombre de couronne <1 a 3> : ");
                //saisie valide
                //Traitement
                prixTotalCourone=evaluationTotalFacture(nbreCourone,"Pour la couronne # "," Entrez le nombre de banches de pin: ");
                break;
            
            case 2:

                // Canne
                afficherMessageAccuiel(choixMenu);
                cin >> nbreCanne;
                //validation donnees
                validationEntree(1,5,nbreCanne, " Choix incorrect, entrez le nombre de canne <1 a 5> : ");
                //Donnees valides
                prixTotalCanne = evaluationTotalFacture(nbreCanne, "Pour la canne # ", " Entrez la quantite de ruban en pied :  ");
                break;

           case 3: 

               afficherMessageAccuiel(choixMenu);
               visualiserTotaux(nbreCanne, nbreCourone, prixTotalCanne, prixTotalCourone);
               break;
            }
               
            cout << endl << "Appuyer sur une touche pour retourner au menu principal" << endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            }
     
    } while (choixMenu!=4 );

    //Sortie definitif du programme
    cout << endl << endl
        << " Merci d'avoir utilise notre programme.\n";
    cin.get();
    return 0;
}



/*
==================================================
 |       Definitions des fonctions                |
 |                                                |
==================================================
*/


void visualiserTotaux(int nbreCanne, int nbreCourone, double prixTotalCanne,double prixTotalCourone)
{
    double  totalTaxe = 0.0;
    // tester si les donnees ont ete saisies
    if (nbreCanne == 0 && nbreCourone == 0)
        cout << " Aucunes donnees saisies";
    else
    {
        totalTaxe = (prixTotalCanne + prixTotalCourone) * TAUX_TAXE;
        cout << "Nombre de couronnes :\t "
            << nbreCourone
            << endl
            << "Prix des couronnes:  \t"
            << prixTotalCourone << " $"
            << endl
            << "Nombre de cannes:    \t"
            << nbreCanne
            << endl
            << "Prix cannes:          \t"
            << prixTotalCanne << " $"
            << endl
            << "Prix total:            \t"
            << prixTotalCanne + prixTotalCourone << " $"
            << endl
            << "Prix de la taxe :      \t"
            << totalTaxe << " $"
            << endl
            << "Prix total:           \t"
            << totalTaxe + (prixTotalCanne + prixTotalCourone) << " $";
    }
}

void afficherMessageAccuiel(int ordreMenu)
{
    switch (ordreMenu)
    {
    case 0://menu principal
        cout << "    *" << endl
            << "   /.\\" << "\t\tCOMPAGNIE" << endl
            << "  /..'\\" << "\t\tNOEL" << endl
            << "  /'.'\\" << "\t\tFABRICE" << endl
            << " /.''.'\\" << "\tKOUONANG" << endl
            << " /.'.'.\\" << "\tINC." << endl
            << "/'.''.'.\\" << endl
            << "^^^[_]^^^" << endl << endl;
        break;
    case 1:
        cout << "      ,....," << endl
            << "   ,;;:o;;;o;;," << endl
            << " ,;;o;'''''';;;;," << endl
            << ",;:;;        ;;o;," << endl
            << ";o;;          ;;;;" << endl
            << ";;o;          ;;o;" << endl
            << "';;;,  _  _  ,;;;'" << endl
            << " ';o;;/_\\/_#\\;;o;'" << endl
            << "   ';;\\_\\/_/;;'" << endl
            << "      '//\\\\'" << endl
            << "      //  \\\\" << endl
            << "     |/    \\|" << endl << endl;
        cout << endl
            << "Entrez le nombre de couronnes <1 a 3> : ";
        break;
    case 2:
        cout << "    .----." << endl
            << "  .'`.  .'`." << endl
            << " /-._:--:_.-\\" << endl
            << "|-._/    \\ _.|" << endl
            << "|._ |    |' _|" << endl
            << "`---'    |-' |" << endl
            << "         |.-'|" << endl
            << "         |' _|" << endl
            << "         |-' |" << endl
            << "         |.-'|" << endl
            << "         |' _|" << endl
            << "         |-' |" << endl
            << "         `---'" << endl << endl;
        cout << endl
            << " Entrez le nombre de cannes <1 a 5> : ";

        break;

    case 3:
        cout << "     *    .      .     VISUALISER" << endl
            << "        . | .          L'INFORMATION" << endl
            << "*        \\|/" << endl
            << "       -->*<--   ." << endl
            << "         /|\\" << endl
            << ".       ' | '       *" << endl
            << "          |" << endl
            << "    .     |    ." << endl
            << "          '" << endl << endl;

        break;
    }
        
}

void afficherMenu(void)
{
    cout << endl
        << "1. Entrez l'information des couronnes"
        << endl
        << "2. Entrez l'information des cannes"
        << endl
        << "3. Visualiser l'information"
        << endl
        << "4. Sortir du programme"
        << endl << endl
        << "Entrez votre choix : ";
}

bool validationEntree(double minInterval, double maxInterval, int valAcomparer,string msg)
{
    while (!cin || !(valAcomparer >= minInterval && valAcomparer <= maxInterval))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl <<msg;
        cin >> valAcomparer;
    }
    return true;
}

double evaluationTotalFacture(int qteElement,string msg1, string msg2)
{
    double qtePourConception = 0.0;
    double  puApplicable = 0.0;
    double  prixTotalElement= 0.0;

    for (int i = 1; i <= qteElement; i++)
    {
        cout << endl
            << msg1 << i << " : "
            << endl
            << msg2;
        cin >> qtePourConception;

        // recherche prix unitaire
        if (qtePourConception < 11)
            puApplicable = PRIX_COURON_MIN;
        else if (qtePourConception < 16)
            puApplicable = PRIX_COURON_MIN_INF;
        else if (qtePourConception < 21)
            puApplicable = PRIX_COURON_MIN_SUP;
        else
            puApplicable = PRIX_COURON_MAX;

        // calcul montant couronne
        prixTotalElement += puApplicable;

    }
    return prixTotalElement;
}
