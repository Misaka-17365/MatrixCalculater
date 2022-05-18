//#include "matrix.h"
//#include "empty_buffer.h"
//#include <string>
//
//using namespace std;
//extern matrix mat_1, mat_2, mat_3, mat_4, mat_t1, mat_t2, mat_t3;
//
//
//void calculate()
//{
//	string str_1;
//	matrix* p_mat_1 = nullptr, * p_mat_2 = nullptr;
//	matrix* p_a_mat[10];
//	void* p1 = nullptr, * p2 = nullptr;
//	double scalar_1 = 1, scalar_2;
//
//	cin >> str_1;
//	int position;
//	for(position = 0; position )
//	void cal_multiply();
//
//	
//}
//// 处理乘法部分
//void cal_multiply()
//{
//	bool is_matrix_1, is_matrix_2;
//	int position = -1;
//
//	size_t t;
//	t = str_1.find("*");
//	if (t == string::npos) return;
//	position = t;
//
//	for (int i = position - 1; i >= 0; i--)
//	{
//		if (str_1[i] == ']')
//		{
//			if (str_1[i - 1] >= '1' && str_1[i - 1] <= '4')
//			{
//				switch (str_1[i - 1])
//				{
//				case 1:
//					p1 = (matrix*)&mat_1;
//					break;
//
//				case 2:
//					p1 = (matrix*)&mat_2;
//					break;
//
//				case 3:
//					p1 = (matrix*)&mat_3;
//					break;
//
//				case 4:
//					p1 = (matrix*)&mat_4;
//					break;
//				}
//				is_matrix_1 = true;
//				goto finish;
//			}
//			else
//			{
//				goto input_error;
//			}
//		}
//
//		if (str_1[i] >= '0' && str_1[i] <= '9')
//		{
//			int mul_1 = str_1[i] - '0';
//			int mul_10 = 0, mul_100 = 0, mul_1000 = 0;
//			if (str_1[i - 1] >= '0' && str_1[i - 1] <= '9')
//			{
//				mul_10 = str_1[i - 1] - '0';
//				if (str_1[i - 2] >= '0' && str_1[i - 2] <= '9')
//				{
//					mul_100 = str_1[i - 2] - '0';
//					if (str_1[i - 3] >= '0' && str_1[i - 3] <= '9')
//					{
//						mul_1000 = str_1[i - 3] - '0';
//					}
//				}
//			}
//
//			scalar_1 = mul_1 + mul_10 * 10 + mul_100 * 100 + mul_1000 * 1000;
//			p1 = (double*)&scalar_1;
//			is_matrix_1 = false;
//			goto finish;
//		}
//		goto input_error;
//
//	}
//
//
//	for (int i = position + 1; i <= (int)str_1.length(); i++)
//	{
//		if (str_1[i] == '[')
//		{
//			if (str_1[i + 1] >= '1' && str_1[i + 1] <= '4')
//			{
//				switch (str_1[i + 1])
//				{
//				case 1:
//					p2 = (matrix*)&mat_1;
//					break;
//
//				case 2:
//					p2 = (matrix*)&mat_2;
//					break;
//
//				case 3:
//					p2 = (matrix*)&mat_3;
//					break;
//
//				case 4:
//					p2 = (matrix*)&mat_4;
//					break;
//				}
//				is_matrix_2 = true;
//				goto finish;
//			}
//			else
//			{
//				goto input_error;
//			}
//		}
//
//		if (str_1[i] >= '0' && str_1[i] <= '9')
//		{
//			int mul_1 = str_1[i] - '0';
//			int mul_10 = 0, mul_100 = 0, mul_1000 = 0;
//
//			if (str_1[i + 1] >= '0' && str_1[i + 1] <= '9')
//			{
//				mul_10 = mul_1;
//				mul_1 = str_1[i + 1];
//				if (str_1[i + 2] >= '0' && str_1[i + 2] <= '9')
//				{
//					mul_100 = mul_10;
//					mul_10 = mul_1;
//					mul_1 = str_1[i + 2];
//					if (str_1[i + 3] >= '0' && str_1[i + 3] <= '9')
//					{
//						mul_1000 = mul_100;
//						mul_100 = mul_10;
//						mul_10 = mul_1;
//						mul_1 = str_1[i + 3];
//					}
//				}
//			}
//			scalar_2 = mul_1 + mul_10 * 10 + mul_100 * 100 + mul_1000 * 1000;
//			p2 = (double*)&scalar_2;
//			is_matrix_2 = false;
//			goto finish;
//		}
//
//		goto input_error;
//	}
//}
//finish:
//p_mat_1 = (matrix*)malloc(sizeof(matrix));
//
//if (is_matrix_1 == false && is_matrix_2 == true)
//{
//	*p_mat_1 = *(matrix*)p2 * *(double*)p1;
//}
//if (is_matrix_1 == true && is_matrix_2 == false)
//{
//	*p_mat_1 = *(matrix*)p1 * *(double*)p2;
//}
//if (is_matrix_1 == true && is_matrix_2 == true)
//{
//	*p_mat_1 = *(matrix*)p1 * *(matrix*)p2;
//}
//
//
//return;
//
//input_error:
//cout << "输入有误" << endl;
//return;
//}