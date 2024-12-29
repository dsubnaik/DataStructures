#ifndef Mass_h
#define Mass_h
//class Mass decleration
class Mass
{
//private variables
  private:
    double tonne;
    double kilogram;
    double gram;
//public members
  public:
    Mass();
    Mass(double);
    double getTonne()const;
    double getKilogram()const;
    double getGram()const;
    Mass operator+(Mass &);
    Mass operator+(int);
    Mass operator-(Mass &);
    Mass operator=(Mass &);
    bool operator==(Mass &);
    bool operator>(Mass &);
    bool operator<(Mass &);
    bool operator!=(Mass &);
    Mass operator+=(Mass &);
    Mass operator+=(int);
    void display()const;
};
#endif