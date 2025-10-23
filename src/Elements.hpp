#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <string>
#include <Materiaux.hpp>
#include <vector>

class Elements
{
    private:
        /* data */
        std::string nom;
        int priorite;
        int couche;
        bool structural;
        Materiaux materiau;
        /* dimensions */
        double largeur;
        double hauteur;
        double profondeur;
        std::vector<std::pair<double, double>> Base_points;

    public:
        Elements(/* args */);
        ~Elements();
};

#endif // ELEMENTS_HPP