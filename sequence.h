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
#include "Utilities.cpp"

using namespace std;

template <class T, template<typename ELEM = T, typename ALLOC = allocator<ELEM> > class cont = vector>
class sequence
{
	cont<T> container;

public:
	//1. Предусмотреть операции добавления, изменения и удаления элемента
	//контейнера.
	void add(T elem)
	{
		container.push_back(elem);
	}

	void change(filter search_filter, T new_elem) //Заменяет элемент по фильтру
	{
		typename cont<T>::iterator found_elem_it = find_if(container.begin(), container.end(), [=](T model) {
			return validate_by_filter(model, search_filter);
			});
		*found_elem_it = new_elem;
	}

	void delete_elem(filter search_filter) //Удаляет элемент по фильтру
	{
		typename cont<T>::iterator found_elem_it = find_if(container.begin(), container.end(), [=](T model) {
			return validate_by_filter(model, search_filter);
			});
		container.erase(found_elem_it);
	}

	/*3. Реализовать операции поиска по заданным критериям и выборки подмножества
		элементов по заданным критериям.Реализовать поиск в двух вариантах : линейный
		поиск и двоичный поиск на отсортированном контейнере.*/	

	T find_linear(filter search_filter)
	{
		T res;
		bool found = false;
		for_each(container.begin(), container.end(), [&](T model) {

			bool fits = validate_by_filter(model, search_filter);
			if (fits)
			{
				found = true;
				res = model;
				return;
			}
		});
		
		if (!found)
		{
			throw runtime_error("Элемент не был найден\n");
		}
		return res;
	}

	void sort_container_by_filter(filter search_filter)
	{
		sort(container.begin(), container.end(), [&](T a, T b) {
			return check_increase(a,b, search_filter);
			});
	}

	T find_binary(filter search_filter)
	{
		sort_container_by_filter(search_filter);

		typename cont<T>::iterator left = container.begin();
		typename cont<T>::iterator right = container.end()-1;
		typename cont<T>::iterator mid = container.begin();
		advance(mid, distance(left, right) / 2);

		for (; !validate_by_filter(*mid, search_filter);)
		{
			if (left == right)          // если границы сомкнулись 
			{
				throw runtime_error("Элемент не был найден\n");
			}

			//mid > filter_value
			validate_by_filter_inequality(*mid, search_filter) ? right = mid - 1 : left = mid + 1;

			mid = left + distance(left, right) / 2;
		}
		return *mid;
	}

	cont<T> find_all(filter search_filter)
	{
		cont<T> res;
		for_each(container.begin(), container.end(), [&](T model) {
			bool fits = validate_by_filter(model, search_filter);
			if (fits)
			{
				res.push_back(model);
			}
		});

		if (res.size() == 0)
		{
			throw runtime_error("Элементы не были найдены\n");
		}

		return res;
	}

	//4. Предусмотреть вывод подмножества выборки на экран и в файл.
	static void print_console(cont<T> container)
	{
		copy(container.begin(), container.end(), ostream_iterator<T>(cout, "\n"));
	}

	static void print_file(cont<T> container, string file_name)
	{
		ofstream fout(file_name);
		copy(container.begin(), container.end(), ostream_iterator<T>(fout, "\n"));
		fout.close();
	}

	//2. Реализовать ввод и вывод элементов контейнера с использованием потоковых
	//итераторов на экран и в файл.

	void print_file(string file_name)
	{
		print_file(container, file_name);
	}

	void print_console()
	{
		print_console(container);
	}

	void init_from_file(string file_name)
	{
		ifstream fin(file_name);

		if (fin.fail())
		{
			throw runtime_error("Произошла ошибка при открытии файла\n");
		}
		istream_iterator<T> begin(fin);
		istream_iterator<T> end;
		copy(begin, end, back_inserter(container));
	}

	void generate_n(int n)
	{
		for (int i = 0; i < n; i++)
		{
			T elem;
			cin >> elem;
			add(elem);
		}
	}
};