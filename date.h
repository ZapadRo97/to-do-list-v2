#ifndef DATE_H
#define DATE_H


class Date
{
    public:
        Date();
        ~Date();
        void SetDate(int, int); //the same day
        void SetDate(int, int, int); //other day
        void ShowDate();

    protected:
        int day, month, year;
        int hour, minute;

    private:
};

#endif // DATE_H
