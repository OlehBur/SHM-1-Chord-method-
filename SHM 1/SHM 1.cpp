#include <Windows.h>
#include <iostream>
#include <cstdio>


typedef const float& cf;

using namespace std;


float Function(cf x) {
	return pow(x, 3) + 3 * x + 1; 
}

float GetBordOfInterval(cf a, cf b, cf f_a, cf f_b) {
	return  a - 
		(b - a) * f_a 
		/ (f_b - f_a);
}

//метод Хорд
int main(){
	cf precision{ 0.01f };
	float interval[] = { -0.5f, 0.0f },
		c{ 0.0f }, f_a_Result{ 0.0f }, f_b_Result{ 0.0f };

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "\t\t<Метод хорд>\n Pівняння: x^3+3x+1=0\n\n";

	for (int iter = 1; fabs(interval[1] - interval[0]) > precision; iter++) {
		f_a_Result = Function(interval[0]);
		f_b_Result = Function(interval[1]);

		interval[0] = GetBordOfInterval(interval[0], interval[1], f_a_Result, f_b_Result);
		//interval[0]
		//	- (interval[1] - interval[0]) * f_a_Result
		//	/ (f_b_Result - f_a_Result);

		interval[1] = GetBordOfInterval(interval[1], interval[0], f_b_Result, f_a_Result);
			//interval[1] 
			//- (interval[0] - interval[1]) * f_b_Result
			/// (f_a_Result - f_b_Result);

		printf("\t%d. Проміжок: [%g;%g];\n \tf(a)=%g;\n \tf(b)=%g.\n\n", iter, interval[0], interval[1], f_a_Result, f_b_Result);
	}

	//for (int iter = 1; abs(interval[0] - interval[1]) > precision && iter <30; iter++) {
	//	c = (interval[0] - interval[1]) / 2;
	//	(Function(c) < 0) ? 
	//		interval[0] = c :
	//		interval[1] = c;
	//	printf("С%d = %g, F(С%d)=%g, проміжок - [%g;%g].\n", iter, c, iter, Function(c), interval[0], interval[1]);
	//}
	printf("\nМи дійшли до вказаної помилки, корінь рівняння: %g\n.", interval[0]);

}
