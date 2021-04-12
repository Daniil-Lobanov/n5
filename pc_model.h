/*5. ������ ���������� ��������������� ����� � ��������� ����� ����������, ����� ����������,
�������� ������ ����������, ������� ����������� ������, ������� �������� �����, ������� ������
����������, ���������� ���������� � ��� - ��� �����������. ����� �� ���� ����������,
������ ���, ������ ���������� � ������ �������� �����.*/

#pragma once
#include<iostream>
using std::string;
using std::cout;
using std::endl;

class pc_model //��������������� ���� �� ��� ������; IF - �������� ���, return, ������� ���
{
	string code;
	string brand;
	string processor_type;
	int processor_freq;
	int ram_capacity;
	int hard_drive_capacity;
	int video_memory_capacity;
	long cost;
	long count;

public: 
	pc_model()
	{}

	pc_model(string code, string brand, string processor_type, int processor_freq, int ram_capacity,
		int hard_drive_capacity, int video_memory_capacity, long cost, long count)
	{
		this->code = code;
		this->brand = brand;
		this->processor_type = processor_type;
		this->processor_freq = processor_freq;
		this->ram_capacity = ram_capacity;
		this->hard_drive_capacity = hard_drive_capacity;
		this->video_memory_capacity = video_memory_capacity;
		this->cost = cost;
		this->count = count;
	}

	void set_processor(string processor_type)
	{
		this->processor_type = processor_type;
	}

	void set_ram(int ram_capacity)
	{
		this->ram_capacity = ram_capacity;
	}

	void set_video(int video_memory_capacity)
	{
		this->video_memory_capacity = video_memory_capacity;
	}

	void set_hard_drive(int hard_drive_capacity)
	{
		this->hard_drive_capacity = hard_drive_capacity;
	}
	
	/*bool operator == (const pc_model& op) //??????
	{
		return (processor_type == op.processor_type) && (ram_capacity == op.ram_capacity) && (video_memory_capacity == op.video_memory_capacity) && 
			(hard_drive_capacity == op.hard_drive_capacity);
	}*/


	//����������� �� ������ � �����������

	/*static bool comp_all(pc_model op1, pc_model op2) //������������ �� ���� 4 ���������� ������
	{
		return op1.processor_type == op2.processor_type &&
			op1.ram_capacity == op2.ram_capacity &&
			op1.video_memory_capacity == op2.video_memory_capacity &&
			op1.hard_drive_capacity == op2.hard_drive_capacity;
	}

	static bool comp_all_less(pc_model op1, pc_model op2) //������������ �� ���� 4 ���������� ������
	{
		return op1.processor_type < op2.processor_type &&
			op1.ram_capacity < op2.ram_capacity &&
			op1.video_memory_capacity < op2.video_memory_capacity &&
			op1.hard_drive_capacity < op2.hard_drive_capacity;
	}

	/*static bool comp_type_less(pc_model op1, pc_model op2)
	{
		return op1.processor_type < op2.processor_type;
	}

	static bool comp_ram_less(pc_model op1, pc_model op2)
	{
		return op1.ram_capacity < op2.ram_capacity;
	}

	static bool comp_video_less(pc_model op1, pc_model op2)
	{
		return op1.video_memory_capacity < op2.video_memory_capacity;
	}

	static bool comp_hard_drive_less(pc_model op1, pc_model op2)
	{
		return op1.hard_drive_capacity < op2.hard_drive_capacity;
	}*/
	//////////////////////////////////////////////////

	static bool comp_type(pc_model op1, pc_model op2)
	{
		return op1.processor_type == op2.processor_type;
	}

	static bool comp_ram(pc_model op1, pc_model op2)
	{
		return op1.ram_capacity == op2.ram_capacity;
	}

	static bool comp_video(pc_model op1, pc_model op2)
	{
		return op1.video_memory_capacity == op2.video_memory_capacity;
	}

	static bool comp_hard_drive(pc_model op1, pc_model op2)
	{
		return op1.hard_drive_capacity == op2.hard_drive_capacity;
	}


	/*static bool comp_type(pc_model pc, string search_type)
	{
		return pc.processor_type == search_type;
	}

	static bool comp_ram(pc_model pc, int ram_capacity)
	{
		return pc.ram_capacity == ram_capacity;
	}

	static bool comp_video_memory(pc_model pc, int video_memory_capacity)
	{
		return pc.video_memory_capacity == video_memory_capacity;
	}

	static bool comp_hard_drive(pc_model pc, int hard_drive_capacity)
	{
		return pc.hard_drive_capacity == hard_drive_capacity;
	}*/

	friend std::istream& operator>> (std::istream& in, pc_model& op);
	friend std::ostream& operator<< (std::ostream& out, const pc_model& op);
};

std::istream& operator>> (std::istream& in, pc_model& op)
{
	cout << "������� ���" << endl;
	in >> op.code;
	cout << "������� ����� ����������" << endl;
	in >> op.brand;
	cout << "������� ��� ����������" << endl;
	in >> op.processor_type;
	cout << "������� ������� ������ ����������" << endl;
	in >> op.processor_freq;
	cout << "������� ����� ����������� ������" << endl;
	in >> op.ram_capacity;
	cout << "������� ����� �������� �����" << endl;
	in >> op.hard_drive_capacity;
	cout << "������� ����� ������ ����������" << endl;
	in >> op.video_memory_capacity;
	cout << "������� ���������" << endl;
	in >> op.cost;
	cout << "������� ���-�� �����������" << endl;
	in >> op.count;
	return in;
}

std::ostream& operator<< (std::ostream& out, const pc_model& op)
{
	out << "��� - " << op.code << endl << "����� - " << op.brand << endl << "��� ���������� - " << op.processor_type << endl
		<< "������� ������ ���������� - " << op.processor_freq << endl << "����� ����������� ������ - " << op.ram_capacity << endl
		<< "����� �������� ����� - " << op.hard_drive_capacity << endl << "����� ������ ���������� - " << op.video_memory_capacity << endl
		<< "��������� - " << op.cost << endl << "���-�� ����������� - " << op.count << endl;
	return out;
}