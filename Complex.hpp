//@author eylony1403@gmail.com

class Complex
{
    public:
    Complex(double, double);
    bool operator==(const Complex &) const;


    private:
        double _re;
        double _im;
};