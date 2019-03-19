#include "../abin.h"
#include "../abin_E-S.h"
#include <cstring>
#include <exception>

typedef struct mathExpr
{
    explicit mathExpr(string s): s_{s}, num_{0}
    {
        if(s_ != '/' && s_ != '+' && s_ != '-' && s != '*')
        {
            throw invalid_argument("Error. Invalid argument.");
            terminate();
        }
    }

    explicit mathExpr(double n): num_{n}, s_{nullptr}
    {}

    string getExpr()
    {
        if(s_ == nullptr) 
            return to_string(num_);
        else
            return s_;     
    }

    private:
        string s_;
        double num_; 
};