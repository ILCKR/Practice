#include <iostream>

class c_matrix
{
public:
    c_matrix(int a)
    {
        size = a;

        m = new float* [a];

        for (int i = 0; i < a; i++)
            m[i] = new float[a];
    };

    /* /void print()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << m[i][j] << " ";
            }

            std::cout << std::endl;
        }
    }; */

    c_matrix transponier()
    {
        c_matrix res(size);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                res.m[i][j] = m[i][j];
            }
        }

        float tmp;
        for (int k = 0; k < size - 1; k++) {
            for (int i = k + 1; i < size; i++) {
                tmp = -res.m[i][k] / res.m[k][k];
                for (int j = 0; j < size; j++) {
                    res.m[i][j] += res.m[k][j] * tmp;
                }
            }
        }

        return res;
    }

    float get_determinant()
    {
        c_matrix nn = transponier();

       // nn.print();

        float sum = 1;
        for (int i = 0; i < size; i++)
        {
            if (nn.m[i][i] != nn.m[i][i]) {
                sum = 0;
                break;
            }

            sum *= nn.m[i][i];
        }

        return sum;
    };

private:
    int size;
public:
    float** m;
};

int main()
{
    setlocale(LC_ALL, "RU");
    int size = 0;

    std::cout << "Введите размер матрицы: ";
    std::cin >> size;
    if (size <= 0)
    {
        std::cout << "Вы ввели некорректный размер матрицы." << std::endl;
        system("pause");
        return EXIT_FAILURE;
    }

    c_matrix m(size);

    std::cout << "Введите матрицу:" << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            float in;
            std::cin >> in;

            if (std::cin.fail()) {
                std::cout << "Вы ввели некорректное значение." << std::endl;

                system("pause");
                return EXIT_FAILURE;
            }
            else {
                m.m[i][j] = in;
            }
        }
    }

    std::cout << "Определитель матрицы: " << m.get_determinant() << "." << std::endl;

    system("pause");
    return EXIT_SUCCESS;
}