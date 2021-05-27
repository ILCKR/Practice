#include <iostream>

class c_matrix
{
public:
	c_matrix(int a, int b) {
		m = new float[a][b];

	};

private:
	float* m = nullptr;
};



int main() {
	
	return 0;
}