/***************************************************************************************************
Ecrivez un programme fondue.cc qui :
1. déclare une constante BASE, initialisée à 4, et qui indique le nombre de personnes pour
laquelle est conçue la recette de base ;
2. déclare une variable fromage, initialisée à 800.0, qui donne la quantité de fromage en
grammes nécessaire pour BASE personnes (du « Vacherin fribourgeois » en
l'occurrence !) ;
3. déclare une variable eau, initialisée à 2.0, qui donne la quantité d'eau en décilitres
nécessaire pour BASE personnes ;
4. déclare une variable ail, initialisée à 2.0, qui donne le nombre de gousses d'ail
nécessaires pour BASE personnes (on choisit le type double car on veut pouvoir utiliser
des moitiés de gousses par exemple) ;
5. déclare une variable pain, initialisée à 400.0, qui donne la quantité de pain en grammes
nécessaire pour BASE personnes ;
6. demande à l'utilisateur d'introduire le nombre de convives pour lequel on veut préparer la
recette ;
7. lit la réponse de l'utilisateur et l'enregistre dans une variable nbConvives de type entier ;
8. adapte les quantités de chaque ingrédient en faisant une règle de trois
(nouvelle_quantite = quantite_de_base * nb_convives / BASE ) ;
9. et affiche la recette pour le nombre de convives voulus selon l'exemple ci-dessous.
Exemple d'exécution du programme
Entrez le nombre de personne(s) conviées à la fondue : 3
Pour faire une fondue fribourgeoise pour 3 personnes, il vous faut :
- 600.0 gr de Vacherin fribourgeois
- 1.5 dl d'eau
- 1.5 gousse(s) d'ail
- 300.0 gr de pain
- du poivre à volonté
***************************************************************************************************/
#include <iostream>
#include <string>
#include <map>

using namespace std;

class RecetteFondue
{
public:
    RecetteFondue(unsigned int nbConvives);
    std::string to_string() const;

private:
    static const int base = 4;
    static const double baseFromage;
    static const double baseEau;
    static const double baseAil;
    static const double basePain;
    unsigned int m_nbConvives;
    double m_ratio;
    double m_fromage;
    double m_eau;
    double m_ail;
    double m_pain;
};

const double RecetteFondue::baseFromage = 800.0;
const double RecetteFondue::baseEau = 2.0;
const double RecetteFondue::baseAil = 2.0;
const double RecetteFondue::basePain = 400.0;

RecetteFondue::RecetteFondue(unsigned int nbConvives) :
    m_nbConvives(nbConvives),
    m_ratio(double(nbConvives) / base),
    m_fromage(baseFromage * m_ratio),
    m_eau(baseEau * m_ratio),
    m_ail(baseAil * m_ratio),
    m_pain(basePain * m_ratio)
{}

string RecetteFondue::to_string() const
{
    return string("Pour faire une fondue fribourgeoise pour ")
        + std::to_string(m_nbConvives) + string(" personnes, il vous faut :\n")
        + std::to_string(m_fromage) + string(" gr de Vacherin fribourgeois\n- ")
        + std::to_string(m_eau) + string(" dl d'eau\n- ")
        + std::to_string(m_ail) + string(" gousse(s) d'ail\n- ")
        + std::to_string(m_pain) + string(" gr de pain\n")
        + string("- du poivre à volonté");
}

ostream& operator<<(ostream& os, const RecetteFondue& recette)
{
    return os << recette.to_string();
}

class RecetteRef
{
public:
    RecetteRef(unsigned int nbConvives, double m_fromage, double m_eau, double m_ail,
        double m_pain);
    RecetteRef(const RecetteRef& recette, unsigned int nbConvives);
    std::string to_string() const;

private:
    double m_ratio; // is this efficient ? code factorisation vs class size ?
    unsigned int m_nbConvives;
    double m_fromage;
    double m_eau;
    double m_ail;
    double m_pain;
};

RecetteRef::RecetteRef(unsigned int nbConvives, double fromage, double eau, double ail,
    double pain) :
    m_ratio(1.0), m_nbConvives(nbConvives), m_fromage(fromage), m_eau(eau), m_ail(ail), m_pain(pain)
{}

RecetteRef::RecetteRef(const RecetteRef& recette, unsigned int nbConvives) :
    m_ratio(static_cast<double>(nbConvives) / recette.m_nbConvives), m_nbConvives(nbConvives),
    m_fromage(recette.m_fromage * m_ratio), m_eau(recette.m_eau * m_ratio),
    m_ail(recette.m_ail * m_ratio), m_pain(recette.m_pain * m_ratio)
{}

string RecetteRef::to_string() const
{
    return string("Pour faire une fondue fribourgeoise pour ")
        + std::to_string(m_nbConvives) + string(" personnes, il vous faut :\n")
        + std::to_string(m_fromage) + string(" gr de Vacherin fribourgeois\n- ")
        + std::to_string(m_eau) + string(" dl d'eau\n- ")
        + std::to_string(m_ail) + string(" gousse(s) d'ail\n- ")
        + std::to_string(m_pain) + string(" gr de pain\n")
        + string("- du poivre à volonté");
}

ostream& operator<<(ostream& os, const RecetteRef& recette)
{
    return os << recette.to_string();
}

class Recette
{
public:
    Recette(const string& name, unsigned int nbConvives, const map<string, double>& ingredients);
    Recette(const Recette& recette, unsigned int nbConvives);
    std::string to_string() const;

private:
    const string m_name;
    const double m_ratio; // is this efficient ? code factorisation vs class size ?
    const unsigned int m_nbConvives;
    map<string, double> m_ingredients;
};

Recette::Recette(const string& name, unsigned int nbConvives, const map<string, double>& ingredients) :
    m_name(name), m_ratio(1.0), m_nbConvives(nbConvives), m_ingredients(ingredients)
{}

Recette::Recette(const Recette& recette, unsigned int nbConvives) :
    m_name(recette.m_name), m_ratio(static_cast<double>(nbConvives) / recette.m_nbConvives),
    m_nbConvives(nbConvives), m_ingredients(recette.m_ingredients)
{
    for (auto ingredient : m_ingredients)
        ingredient.second *= m_ratio;
}

string Recette::to_string() const
{
    string text = string("Pour faire un(e) ") + m_name + string(" pour ")
        + std::to_string(m_nbConvives) + string(" personnes, il vous faut :\n");
    for (auto i : m_ingredients) {
        if (i.second == 0.0) {
            text += string("- ") + string("à volonté de ") + i.first + string("\n");
        } else {
            text += string("- ") + std::to_string(i.second) + string(" de ") + i.first
                + string("\n");
        }
    }
    // remove extra newline
    text.pop_back();

    return text;
}

ostream& operator<<(ostream& os, const Recette& recette)
{
    return os << recette.to_string();
}

int main()
{
    int nbConvives;
    cout << "Entrez le nombre de personne(s) conviées à la fondue : ";
    cin >> nbConvives;
    RecetteFondue recette(nbConvives);
    cout << recette << endl;

    RecetteRef fondue(4, 800.0, 2.0, 2.0, 400.0);
    RecetteRef fonduePour2(fondue, 2);
    cout << fonduePour2 << endl;

    Recette f("fondue fribourgeoise", 4, {{"Vacherin fribourgeois", 800.0},
                                               {"eau", 2.0},
                                               {"ail", 2.0},
                                               {"pain", 400.0},
                                               {"poivre", 0.0}});
    Recette f5(f, 5);
    cout << f5 << endl;
    cout << Recette(f5, 4) << endl;
}
