/*5. Модель компьютера характеризуется кодом и названием марки компьютера, типом процессора,
частотой работы процессора, объемом оперативной памяти, объемом жесткого диска, объемом памяти
видеокарты, стоимостью компьютера и кол - вом экземпляров. Поиск по типу процессора,
объему ОЗУ, памяти видеокарты и объему жесткого диска.*/

#pragma once
#include<iostream>
using std::string;
using std::cout;
using std::endl;

class pc_model //ИНКАПСУЛИРОВАТЬ ХОТЯ БЫ ЧТО НИБУДЬ; IF - маленьки код, return, большой код
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


	//Компараторы на больше с параметрами

	/*static bool comp_all(pc_model op1, pc_model op2) //Соответствие по всем 4 параметрам поиска
	{
		return op1.processor_type == op2.processor_type &&
			op1.ram_capacity == op2.ram_capacity &&
			op1.video_memory_capacity == op2.video_memory_capacity &&
			op1.hard_drive_capacity == op2.hard_drive_capacity;
	}

	static bool comp_all_less(pc_model op1, pc_model op2) //Соответствие по всем 4 параметрам поиска
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
	cout << "Введите код" << endl;
	in >> op.code;
	cout << "Введите марку компьютера" << endl;
	in >> op.brand;
	cout << "Введите тип процессора" << endl;
	in >> op.processor_type;
	cout << "Введите частоту работы процессора" << endl;
	in >> op.processor_freq;
	cout << "Введите объем оперативной памяти" << endl;
	in >> op.ram_capacity;
	cout << "Введите объем жесткого диска" << endl;
	in >> op.hard_drive_capacity;
	cout << "Введите объем памяти видеокарты" << endl;
	in >> op.video_memory_capacity;
	cout << "Введите стоимость" << endl;
	in >> op.cost;
	cout << "Введите кол-во экземпляров" << endl;
	in >> op.count;
	return in;
}

std::ostream& operator<< (std::ostream& out, const pc_model& op)
{
	out << "Код - " << op.code << endl << "Марка - " << op.brand << endl << "Тип процессора - " << op.processor_type << endl
		<< "Частота работы процессора - " << op.processor_freq << endl << "Объем оперативной памяти - " << op.ram_capacity << endl
		<< "Объем жесткого диска - " << op.hard_drive_capacity << endl << "Объем памяти видеокарты - " << op.video_memory_capacity << endl
		<< "Стоимость - " << op.cost << endl << "Кол-во экземпляров - " << op.count << endl;
	return out;
}