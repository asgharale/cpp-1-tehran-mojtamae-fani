double SUM_OF_NUMBERS(double a, double b)
{
    return a + b;
}

double MULTIPLIE_OF_NUMS(double a, double b)
{
    return a * b;
}

double SUBTRACTION_OF_NUMS(double a, double b)
{
    return a - b;
}

double TAGHSIM_OF_NUMS(double a, double b)
{
    return a / b;
}

double OPERATION_FACTORY(double a, double b, char operation)
{
    double res;

    if (operation == '+')
    {
        res = SUM_OF_NUMBERS(a, b);
    }
    else if (operation == '*')
    {
        res = MULTIPLIE_OF_NUMS(a, b);
    }
    else if (operation == '/')
    {
        res = SUBTRACTION_OF_NUMS(a, b);
    }
    else if (operation == '-')
    {
        res = TAGHSIM_OF_NUMS(a, b);
    }

    return res;
}
