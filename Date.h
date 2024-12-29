#ifndef Date_h
#define Date_h
//Date class desclaration
class Date
{
//private member
  private:
    int month;
    int date;
    int year;
//public members
  public:
    Date();
    Date(int,int,int);
    void setDate(int,int,int);
    void addDays(int);
    void subtractDays(int);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void printDate() const;    
};
#endif
