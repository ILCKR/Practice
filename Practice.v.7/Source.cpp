#include <iostream>

class c_matrix
{
public:
    c_matrix(int a, int b)
    {
        a_size = a;
        b_size = b;

        m = new float* [a];

        for (int i = 0; i < a; i++)
            m[i] = new float[b];
    };


    void fill(float val)
    {
        for (int i = 0; i < a_size; i++)
        {
            for (int j = 0; j < b_size; j++)
            {
                m[i][j] = val;
            }
        }
    };


    void print()
    {
        for (int i = 0; i < a_size; i++)
        {
            for (int j = 0; j < b_size; j++)
            {
                std::cout << m[i][j] << " ";
            }

            std::cout << std::endl;
        }
    };


    float get_determinant()
    {
        if (a_size == 2 && b_size == 3)
        {
            std::cout << "got 2 order matrix" << std::endl;
        }
        else if (a_size == 3 && b_size == 3)
        {
            std::cout << "got 3 order matrix" << std::endl;
        }

        return -1;
    };

private:
    int a_size;
    int b_size;
    float** m;
};

int main()
{
    c_matrix m{ 5, 5 };

    m.fill(15);

    m.print();

    std::cin.get();
    return EXIT_SUCCESS;
}