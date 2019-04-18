//
// Created by Alex Sofin on 2019-02-08.
//

#include <cmath>
#include <iostream>
#include "Trapezium.h"

using namespace std;

struct Trapezium : ITrapezium
{
    double Base1;
    double Base2;
    double Side1;
    double Side2;

    static bool SimilarFigures(Trapezium tr1, Trapezium tr2)
    {
        int isSimilar = 0;
        double coeficient = 0;
        coeficient = tr1.Base1 / tr2.Base1;
        if (tr1.Base2 / tr2.Base2 == coeficient) isSimilar++;
        if (tr1.Side1 / tr2.Side1 == coeficient) isSimilar++;
        if (tr1.Side2 / tr2.Side2 == coeficient) isSimilar++;
        if(isSimilar == 3) return true;
        isSimilar = 0;
        coeficient = tr1.Base1 / tr2.Base2;
        if (tr1.Base2 / tr2.Base1 == coeficient) isSimilar++;
        if (tr1.Side1 / tr2.Side2 == coeficient) isSimilar++;
        if (tr1.Side2 / tr2.Side1 == coeficient) isSimilar++;
        if(isSimilar == 3) return true;
        return false;
    }

    void Resize(int coeficient) override
    {
        Base1/=coeficient;
        Base2/=coeficient;
        Side1/=coeficient;
        Side2/=coeficient;
    }

    double GetPerimetr() override
    {
        double res = Base1 + Base2 + Side1 + Side2;
        cout << "Perimetr: " << res << endl;
        return res;
    }

    double GetArea() override
    {
        double res = (Base1 + Base2) * GetHeight() / 2;
        cout << "Area: " << res << endl;
        return res;
    }

    double GetMiddleLine() override
    {
        double res = (Base1 + Base2) / 2;
        cout << "MiddleLine: " << res << endl;
        return res;
    }

    double GetHeight() override
    {
        double a = pow(Side1, 2);
        double b = pow(Base2 - Base1, 2);
        double c = pow(Side1, 2);
        double d = pow(Side2, 2);
        double e = 2 * (Base2 - Base1);
        double res = sqrt(a-pow(((b+c-d)/e), 2));
        cout << "Height: " << res << endl;
        return res;
    }

    void GetInfo()
    {
        GetPerimetr();
        GetArea();
        GetMiddleLine();
        GetHeight();
    }
};
