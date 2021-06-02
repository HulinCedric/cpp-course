#ifndef DEF_DUREE
#define DEF_DUREE

class Duree
{
    public:

    Duree(int heures = 0, int minutes = 0, int secondes = 0);
    Duree operator+(const Duree &duree);
    bool operator==(const Duree &duree);
    bool operator<(const Duree &duree);
    Duree operator=(const Duree &duree);

    void afficher(std::ostream &out);

    private:

    int m_heures;
    int m_minutes;
    int m_secondes;
};

#endif
