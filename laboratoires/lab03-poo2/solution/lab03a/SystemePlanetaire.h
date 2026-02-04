#ifndef LAB03A_SYSTEMEPLANETAIRE_H
#define LAB03A_SYSTEMEPLANETAIRE_H

#include "Planete.h"

class SystemePlanetaire {
private:
    Planete* _planetes;
    size_t _nombrePlanetes;
    size_t _capacitePlanetes;
public:
    SystemePlanetaire();
    SystemePlanetaire(const SystemePlanetaire& autreSysteme);
    ~SystemePlanetaire();

    void ajouterPlanete();

    void afficher()const;

    Planete getPlanete(size_t i) const;
    Planete getPlanete(std::string nom) const;
};

#endif //LAB03A_SYSTEMEPLANETAIRE_H