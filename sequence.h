/*Результатом должна быть консольная программа с текстовым меню. Программа должна содержать
шаблонный класс для управления данными согласно заданию. Для хранения данных необходимо выбрать оптимальный
с точки зрения задания контейнер.

5. Модель компьютера характеризуется кодом и названием марки компьютера, типом процессора,
частотой работы процессора, объемом оперативной памяти, объемом жесткого диска, объемом памяти
видеокарты, стоимостью компьютера и кол-вом экземпляров. Поиск по типу процессора,
объему ОЗУ, памяти видеокарты и объему жесткого диска.*/

#pragma once
#include <vector>
#include <algorithm>
#include <iterator> 
#include <fstream>
#include <string>

using namespace std;


typedef bool(*filter)(const pc_model, const pc_model);

template <class T, template<typename ELEM = T, typename ALLOC = allocator<ELEM> > class cont = vector>
class sequence
{
	cont<T> container;

public:
	//1. Предусмотреть операции добавления, изменения и удаления элемента
	//контейнера.
	void add(T elem) //Могут ли повторяться или нет, если нет то множество
	{
		container.push_back(elem);
	}

	void change(T condition, bool comp(const T, const T), T new_elem) //Заменяет все элементы по заданному критерию
	{
		//for (T elem : container) //ЗДЕСЬ ВОСПОЛЬЗОВАТЬСЯ АЛГОРИТМАМИ
		//{
		//	if (elem == elem_to_change)
		//	{
		//		elem = new_elem;
		//	}
		//}

		for_each(container.begin(), container.end(), [&](T i){ //TRANSFORM???
			if (comp(i, condition))
			{
				i = new_elem;
			}
		});

		//replace_if????
	}

	void delete_elem(T condition, bool comp(const T, const T))
	{
		auto res = remove_if(container.begin(), container.end(), [](T i) { //&
			if (comp(i, condition))
			{
				return i;
			}
		});

		container.erase(res, container.end());
	}

	/*3. Реализовать операции поиска по заданным критериям и выборки подмножества
		элементов по заданным критериям.Реализовать поиск в двух вариантах : линейный
		поиск и двоичный поиск на отсортированном контейнере.*/

	/*T find_linear(T condition, bool comp(const T, const T))
	{
		for_each(container.begin(), container.end(), [&](T i){
			if (comp(i, condition))
			{
				cout << i << endl;
				return i;
			}
		});
		
		throw runtime_error("Элемент не был найден\n");
	}*/

	/*T*/void find_linear(T condition, vector<filter> filters)
	{
		for_each(container.begin(), container.end(), [&](T i) {
			bool res = true;;

			for (filter comp : filters)
			{
				if (!comp(i, condition))
				{
					res = false;
					break;
				}
			}
			if (res)
			{
				cout << i << endl;
			}
			});

		//throw runtime_error("Элемент не был найден\n");
	}

	void sort_container(bool comp(const T, const T))  //НУЖНО ЛИ ВЕЗДЕ В ФУНКЦИЯХ & //Сортирувать нужно другой контейнер
	{
		sort(container.begin(), container.end(), [&](T a, T b) {
			return comp(a, b);
		});
	}

	T find_binary(T condition, bool comp_equal(const T, const T), bool comp_less(const T, const T))
	{
		sort_container(comp_less);
		typename cont<T>::iterator left = container.begin();
		typename cont<T>::iterator right = container.end();
		typename cont<T>::iterator mid = container.begin(); 
		advance(mid, distance(left,right)/2);

		for (; !comp_equal(*mid,condition);)
		{
			if (left > right)          // если границы сомкнулись 
			{
				throw runtime_error("Элемент не был найден\n");
			}

			if (comp_less(condition, *mid)) //condition < mid
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
			advance(mid, distance(left, right) / 2);
		}

		return *mid;
	}

	cont<T> find_all(T condition, bool comp(const T, const T))
	{
		cont<T> res;
		for_each(container.begin(), container.end(), [&](T i) {
			if (comp(i, condition))
			{
				res.push_back(i);
			}
		});

		if (res.size() == 0)
		{
			throw runtime_error("Элементы не были найдены\n");
		}

		return res;
	}

	//2. Реализовать ввод и вывод элементов контейнера с использованием потоковых
	//итераторов на экран и в файл.

	//4. Предусмотреть вывод подмножества выборки на экран и в файл.
	void print_file(string file_name)
	{
		ofstream fout(file_name);
		copy(container.begin(), container.end(), ostream_iterator<T>(fout, "\n"));
		fout.close();
	}

	void init_from_file(string file_name)
	{
		ifstream fin(file_name);
		istream_iterator<string> in(fin);

		string code, brand, processor_type;
		int processor_freq, ram_capacity, hard_drive_capacity, video_memory_capacity;
		long cost, count;

		while (!fin.eof())
		{
			processor_type =*in;
			in++;
			code = *in;
			in++;
			brand = *in;
			in++;
			processor_type = stoi(*in);
			in++;
			processor_freq = stoi(*in);
			in++;
			ram_capacity = stoi(*in);
			in++;
			hard_drive_capacity = stoi(*in);
			in++;
			video_memory_capacity = stoi(*in);
			in++;
			cost = stol(*in);
			in++;
			count = stol(*in);
			in++;
			
			pc_model temp = pc_model(code, brand, processor_type, processor_freq, ram_capacity,
				hard_drive_capacity, video_memory_capacity, cost, count);
			add(temp);
			in++;
		}

	}

	void print_console(cont<T> container)
	{
		copy(container.begin(), container.end(), ostream_iterator<T>(cout,"\n"));
	}
};