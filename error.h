#ifndef ERROR_H
#define ERROR_H


class Error
{
    public:
        Error(int);
        ~Error();
        void Tratare();

    protected:

    private:
        int tip;
};

#endif // ERROR_H
