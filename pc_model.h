/*5. Модель компьютера характеризуется кодом и названием марки компьютера, типом процессора,
частотой работы процессора, объемом оперативной памяти, объемом жесткого диска, объемом памяти
видеокарты, стоимостью компьютера и кол - вом экземпляров. Поиск по типу процессора,
объему ОЗУ, памяти видеокарты и объему жесткого диска.*/

#pragma once
#include<iostream>
using namespace std;

class pc_model
{

public:
	string code;
	string brand;
	string processor_type;
	int processor_freq;
	int ram_capacity;
	int hard_drive_capacity;
	int video_memory_capacity;
	int cost;
	int count;

	friend istream& operator>> (istream& in, pc_model& op);
	friend ostream& operator<< (ostream& out, const pc_model& op);
};