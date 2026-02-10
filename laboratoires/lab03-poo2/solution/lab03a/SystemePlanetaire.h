#ifndef LAB03A_SYSTEMEPLANETAIRE_H
#define LAB03A_SYSTEMEPLANETAIRE_H

#include "Planete.h"

class SystemePlanetaire {
private:
    std::string _nom;
    Planete* _planetes;
    size_t _nombrePlanetes;
    size_t _capacitePlanetes;
public:
    SystemePlanetaire();
    SystemePlanetaire(std::string nom);
    SystemePlanetaire(const SystemePlanetaire& autreSysteme);
    ~SystemePlanetaire();

    void ajouterPlanete(Planete planete);
    void afficher(std::ostream& sortie) const;
    void afficher() const;

    std::string getNom() const;
    size_t getNombrePlanetes() const;
    Planete* getPlanete(size_t indice) const;
    Planete* getPlanete(std::string nom) const;

    void setNom(std::string nom);
};

#endif //LAB03A_SYSTEMEPLANETAIRE_H