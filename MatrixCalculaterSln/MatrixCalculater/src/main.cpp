// ��������� v3.3
#include "menu.h"

std::string author = "jj_t";
std::string version = "3.3";

matrix mat_1, mat_2, mat_3, mat_4, mat_t1, mat_t2, mat_t3;



int main()
{
	bool running = true;
	while (running)
	{
		std::cout << "\t\t\t\t\t++++++++++++++" << std::endl
			<< "\t******************" << "\t\t+ ��������� +" << std::endl
			<< "\t*    �����б�    *" << "\t\t* �汾 " << version << "   +" << std::endl
			<< "\t******************" << "\t\t+ ���� " << author << "  +" << std::endl
			<< "\t\t\t\t\t++++++++++++++"
			<< std::endl;
		std::cout << std::endl
			<< "\t[0] " << "�˳�\n"
			<< "\t[1] " << "�������\n"
			<< "\t[2] " << "����ӷ�\n"
			<< "\t[3] " << "����˷�\n"
			<< "\t[4] " << "����ʽ\n"
			<< "\t[5] " << "��\n"
			<< "\t[6] " << "�����Է�����\n"

			<< "\n>>>";

		int menu = -1;
		bool menu_run = true;
		while (true)
		{
			if (std::cin >> menu)
				if (menu >= 0 && menu <= 6) break;
			std::cout << "error" << std::endl;
		}
		// ��ջ�����
		emptybuffer();
		// ���������
		//////////////////////////////////////////////////////////////////// 

		matrix* p1 = nullptr, * p2 = nullptr;
		matrix** pp1 = &p1, ** pp2 = &p2;
		bool to_break = false;
		bool* pbreak = &to_break;
		// ��choose��������
		/////////////////////////////////////////////////////////////////////

		switch (menu)
		{
		case 0:					// �˳�
			running = false;
			break;

		case 1:					// �������
			while (true)
			{
				int menu;
				system("cls");
				std::cout << "\tѡ��༭�ľ���" << std::endl
					<< std::endl
					<< "\t[0] ����\n";

				std::cout << "\t[1] ����1\n";
				mat_1.show();
				std::cout << "\t[2] ����2\n";
				mat_2.show();
				std::cout << "\t[3] ����3\n";
				mat_3.show();
				std::cout << "\t[4] ����4\n";
				mat_4.show();
				std::cout << std::endl << ">>>";

				while (true)
				{
					if (std::cin >> menu)
					{
						if (menu >= 0 && menu <= 4)
						{
							break;
						}
					}
					std::cout << "error" << std::endl;
				}

				switch (menu)
				{

				case 0:
					goto final_end;

				case 1:
					mat_1.get();
					std::cout << "�������Ϊ" << std::endl;
					break;
				case 2:
					mat_2.get();
					std::cout << "�������Ϊ" << std::endl;\
					break;
				case 3:
					mat_3.get();
					std::cout << "�������Ϊ" << std::endl;
					break;
				case 4:
					mat_4.get();
					std::cout << "�������Ϊ" << std::endl;
					break;

				}
			}
			break;					// ����������
		/// ////////////////////////////////////////////////////////

		case 2:						// �ӷ�
			
			choose(pp1, pp2, pbreak);

			if (to_break == true)
			{
				break;
			}

			if (! ((p1->num_i == p2->num_i) && (p1->num_j == p2->num_j)))
			{
				std::cout << "error" << std::endl;
				std::cin.get();
				std::cin.get();
				break;
			}

			mat_t3 = *p1 + *p2;

			system("cls");
			std::cout << "���Ϊ" << std::endl;
			mat_t3.show();
			std::cin.get();
			save();
			break;

		case 3:						// ����˷�
			choose(pp1, pp2, pbreak);

			if (to_break == true)
			{
				break;
			}

			if (!(p1->num_j == p2->num_i))
			{
				std::cout << "error" << std::endl;
				break;
			}
			mat_t3 = *p1 * *p2;

			std::cout << "���Ϊ" << std::endl;
			mat_t3.show();
			std::cin.get();
			std::cin.get();
			break;

		case 4:						// ����ʽ
			choose(pp1, pbreak);

			if (to_break == true)
			{
				break;
			}
			if (p1->num_i != p1->num_j)
			{
				std::cout << "error" << std::endl;
				emptybuffer();

				break;
			}
			p1->cal_determinant();
			std::cout << "\t����ʽΪ>" << p1->determinant;
			std::cin.get();
			break;

		case 5:					// ��
			choose(pp1, pbreak);

			if (to_break == true)
			{
				break;
			}
			p1->cal_rank();
			std::cout << "\t��Ϊ>" << p1->rank;
			emptybuffer();			
			break;

		case 6:
			choose(pp1, pbreak);

			if (to_break) break;

			p1->cal_solution();

			emptybuffer();
			std::cin.get();
		}
		final_end:
		system("cls");
	}
	return 0;
}




