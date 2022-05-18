#ifndef __MATRIX_H__
#define __MATRIX_H__


#include "empty_buffer.h"
#include "fraction.h"
#define lenth 5

class matrix
{
public:
	int num_i, num_j;
	int rank;
	bool gotten;
	frac determinant;
	frac element[lenth][lenth];
	frac trace[lenth];

	// ��ʼ������
	matrix()
	{
		num_i = num_j = rank = -1;
		gotten = false;
		determinant = 0;
		// ��ʼ������
		for (int t_1 = 0; t_1 < lenth; t_1++)
			for (int t_2 = 0; t_2 < lenth; t_2++)
				element[t_1][t_2] = 0;
		for (int t_1 = 0; t_1 < lenth; t_1++)
			trace[t_1] = 0;
	}

	// ��ȡ����
	void get()
	{
		// ��ȡ����
		while (true)
		{
			std::cout << "��������������" << std::endl << ">>>";
			std::cin >> num_i;
			if (num_i >= 1 && num_i <= lenth) break;
			std::cout << "error" << std::endl;
		}
		// ��ȡ����
		while (true)
		{
			std::cout << "��������������" << std::endl << ">>>";
			std::cin >> num_j;
			if (num_j >= 1 && num_j <= lenth) break;
			std::cout << "error" << std::endl;
		}
		// ��ȡԪ��
		std::cout << "����������Ԫ��" << std::endl;
		for (int t_i = 0; t_i < num_i; t_i++)
		{
			for (int t_j = 0; t_j < num_j; t_j++)
			{
				int sign = 1;

				std::cout << "\n���������� ( " << t_i + 1 << ", " << t_j + 1 << " )" << std::endl << ">>>";
				while (!(std::cin >> this->element[t_i][t_j]))
				{
					std::cout << "���������루" << t_i + 1 << ", " << t_j + 1 << " )" << std::endl << ">>>";
				}
			}
		}
		// ��ջ�����
//		std::cout << "����enter����";
//		emptybuffer();
		// ��־�ѻ�ȡ
		gotten = true;
	}
	// ��ʾ����
	void show()
	{
		if (!gotten)
		{
			std::cout << "\t\t[δ����]" << std::endl;
			return;
		}
		std::cout << std::endl << "\t\t------------\n\t\t  (" << num_i << ", " << num_j << ")" << std::endl << std::endl;
		for (int i = 0; i < num_i; i++)
		{
			std::cout << "\t\t[ ";
			for (int j = 0; j < num_j; j++)
			{
				std::cout << element[i][j] << " ";
			}
			std::cout << "]" << std::endl << std::endl;
		}
		std::cout << "\t\t------------" << std::endl;

	}

private:
	// ��˹��Ԫ
	void eliminate()
	{
		// ��ʼ������
		frac cp_element[lenth][lenth] = { 0 };
		for (int t_i = 0; t_i < num_i; t_i++)
			for (int t_j = 0; t_j < num_j; t_j++)
				cp_element[t_i][t_j] = element[t_i][t_j];

		for (int i = 0; i < num_i; i++)
		{
			if (cp_element[i][i] == 0)							// �����һ�е���Ԫ��0
			{
				for (int t_i = i + 1; t_i < num_j; t_i++)		// �ҵ������һ��
				{
					if (cp_element[i][t_i] == 0)
						continue;
					frac tmp = 0;
					for (int place = i; place < num_i; place++)	// �滻
					{
						tmp = cp_element[place][i];
						cp_element[place][i] = cp_element[place][t_i];
						cp_element[place][t_i] = tmp;

					}
				}
			}


			for (int j = i + 1; j < num_j; j++)					// ���ձ������
			{
				frac k = cp_element[i][j] / cp_element[i][i];
				for (int place = i; place < num_i; place++)
				{
					cp_element[place][j] = cp_element[place][j] - k * cp_element[place][i];
				}
			}
		}
		// �ռ��Խ�Ԫ
		for (int t = 0; t < num_i && t < num_j; t++)
		{
			trace[t] = cp_element[t][t];
		}
	}


public:
	// ���أ��ӷ�
	matrix operator+(matrix& mat_2)
	{
		matrix mat;
		mat.gotten = true;
		mat.num_i = this->num_i;
		mat.num_j = this->num_j;
		for (int i = 0; i < this->num_i; i++)
		{
			for (int j = 0; j < this->num_j; j++)
			{
				mat.element[i][j] = this->element[i][j] + mat_2.element[i][j];
			}
		}
		return mat;
	};
	// ���أ�����
	matrix operator*(frac& k)
	{
		matrix mat;
		mat.gotten = true;
		mat.num_i = this->num_i;
		mat.num_j = this->num_j;
		for (int i = 0; i < this->num_i; i++)
		{
			for (int j = 0; j < this->num_j; j++)
			{
				mat.element[i][j] = k * this->element[i][j];
			}
		}
		return mat;
	}

	// ���أ�����˷�
	matrix operator*(matrix& mat_2)
	{
		matrix mat;
		mat.gotten = true;
		mat.num_i = this->num_i;
		mat.num_j = mat_2.num_j;
		for (int i = 0; i < mat.num_i; i++)
		{
			for (int j = 0; j < mat.num_j; j++)
			{
				mat.element[i][j] = 0;
				for (int t = 0; t < this->num_j; t++)
				{
					mat.element[i][j] = this->element[i][t] * mat_2.element[t][j] + mat.element[i][j];
				}
			}
		}
		return mat;
	}
	/*

	int num_i, num_j;
	int order;
	bool gotten;
	double determinant;
	double element[lenth][lenth];
	double trace[lenth];

	*/
	// ���أ��Ⱥ�
	matrix operator=(matrix mat)
	{
		this->gotten = true;
		this->num_i = mat.num_i;
		this->num_j = mat.num_j;
		this->rank = mat.rank;
		this->determinant = mat.determinant;

		for (int i = 0; i < this->num_i; i++)
		{
			for (int j = 0; j < this->num_j; j++)
			{
				this->element[i][j] = mat.element[i][j];
			}
		}
		for (int i = 0; i < this->num_i; i++)
		{
			this->trace[i] = mat.trace[i];
		}
		return *this;
	}
	// ������
	void cal_rank()
	{
		eliminate();
		for (rank = 0; trace[rank] != 0; rank++);
	}
	// ��������ʽ
	void cal_determinant()
	{
		determinant = 1;
		eliminate();
		for (int t = 0; trace[t] != 0; t++)
			determinant = trace[t] * determinant;
	}
	// �����Է����飨�����������
	void cal_solution()
	{
		double det[lenth] = { 0 }, sul[lenth] = { 0 };
		matrix mat_1, mat_2;

		mat_1.num_i = this->num_i;
		mat_1.num_j = this->num_j - 1;
		for (int i = 0; i < mat_1.num_i; i++)
			for (int j = 0; j < mat_1.num_j; j++)
			{
				mat_1.element[i][j] = this->element[i][j];
			}
		mat_1.gotten = true;
		mat_1.cal_rank();

		mat_2 = *this;
		mat_2.cal_rank();

		// std::cout << mat_1.order << "\t" << mat_2.order << std::endl;

		if (mat_1.rank < mat_2.rank)
		{
			std::cout << "�޽�" << std::endl;
			return;
		}
		if (mat_1.rank < mat_1.num_i)
		{
			std::cout << "��������" << std::endl;
		}

		for (int j = 0; j < this->num_j - 1; j++)
		{
			mat_1 = mat_2;
			for (int i = 0; i < this->num_i; i++)
			{
				mat_1.element[i][j] = mat_2.element[i][this->num_j];
			}
			mat_1.cal_determinant();
			det[j] = mat_1.determinant;
		}
		mat_2.cal_determinant();

		for (int t = 0; t < this->num_j; t++)
		{
			sul[t] = det[t] / mat_2.determinant;
		}

		std::cout << "������Ľ�Ϊ\t[ ";
		for (int t = 0; t < this->num_i; t++)
		{
			std::cout << sul[t] << " ";
		}
		std::cout << "] ";

	}
};
//
//matrix operator*(double& k, matrix& mat_2)
//{
//	matrix mat;
//	mat.init();
//	mat.gotten = true;
//	mat.num_i = mat_2.num_i;
//	mat.num_j = mat_2.num_j;
//	for (int i = 0; i < mat_2.num_i; i++)
//	{
//		for (int j = 0; j < mat_2.num_j; j++)
//		{
//			mat.element[i][j] = k * mat_2.element[i][j];
//		}
//	}
//	return mat;
//}


#endif // !__MATRIX_H__

