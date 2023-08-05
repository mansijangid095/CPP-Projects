#include "../inc/errorHandlingWithInputs.h"

template <class T>
void ErrorHandling<T>::errorHandlingWithUserInput(T &input)
{
    while (true)
    {
        try
        {
            std ::cin >> input;
            if (std ::cin.fail() || std ::cin.peek() != '\n')
            {
                throw invalid_argument("Invalid input Type! Please type correct Input");
            }
            else
            {
                break;
            }
        }
        catch (exception &e)
        {
            std ::cerr << e.what() << std ::endl;
            std ::cin.clear();
            std ::cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (std ::cin.peek() == '\n')
            {
                std ::cin.ignore();
            }
        }
    }
}

template void ErrorHandling<int>::errorHandlingWithUserInput(int &);

