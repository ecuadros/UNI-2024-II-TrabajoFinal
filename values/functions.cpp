#include "functions.h"
expo::~expo()
{
    delete input;
}

Complex expo::eval()
{
    return (exp(input->eval()));
}

sine::~sine()
{
    delete input;
}

Complex sine::eval()
{
    return (sin(input->eval()));
}

cosine::~cosine()
{
    delete input;
}

Complex cosine::eval()
{
    return (cos(input->eval()));
}

absolute::~absolute()
{
    delete input;
}

Complex absolute::eval()
{
    return (abs(input->eval()));
}

loga::~loga()
{
    delete input;
}

Complex loga::eval()
{
    return (ln(input->eval()));
}