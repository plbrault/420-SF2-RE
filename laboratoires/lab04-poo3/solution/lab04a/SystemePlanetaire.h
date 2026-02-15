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
    SystemePlanetaire& operator=(const SystemePlanetaire& autreSysteme);

    void ajouterPlanete(Planete planete);
    void afficher(std::ostream& sortie) const;
    void afficher() const;

    std::string getNom() const;
    size_t getNombrePlanetes() const;

    void setNom(std::string nom);

    SystemePlanetaire& operator+=(const Planete& planete);

    const Planete& operator[](size_t indice) const;
    Planete& operator[](size_t indice);

    const Planete& operator[](std::string nom) const;
    Planete& operator[](std::string nom);
};

std::ostream& operator<<(std::ostream& sortie, const SystemePlanetaire& systeme);

#endif //LAB03A_SYSTEMEPLANETAIRE_H