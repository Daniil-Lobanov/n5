/*����������� ������ ���� ���������� ��������� � ��������� ����. ��������� ������ ���������
��������� ����� ��� ���������� ������� �������� �������. ��� �������� ������ ���������� ������� �����������
� ����� ������ ������� ���������.

5. ������ ���������� ��������������� ����� � ��������� ����� ����������, ����� ����������,
�������� ������ ����������, ������� ����������� ������, ������� �������� �����, ������� ������
����������, ���������� ���������� � ���-��� �����������. ����� �� ���� ����������,
������ ���, ������ ���������� � ������ �������� �����.*/

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
	//1. ������������� �������� ����������, ��������� � �������� ��������
	//����������.
	void add(T elem) //����� �� ����������� ��� ���, ���� ��� �� ���������
	{
		container.push_back(elem);
	}

	void change(T condition, bool comp(const T, const T), T new_elem) //�������� ��� �������� �� ��������� ��������
	{
		//for (T elem : container) //����� ��������������� �����������
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

	/*3. ����������� �������� ������ �� �������� ��������� � ������� ������������
		��������� �� �������� ���������.����������� ����� � ���� ��������� : ��������
		����� � �������� ����� �� ��������������� ����������.*/

	/*T find_linear(T condition, bool comp(const T, const T))
	{
		for_each(container.begin(), container.end(), [&](T i){
			if (comp(i, condition))
			{
				cout << i << endl;
				return i;
			}
		});
		
		throw runtime_error("������� �� ��� ������\n");
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

		//throw runtime_error("������� �� ��� ������\n");
	}

	void sort_container(bool comp(const T, const T))  //����� �� ����� � �������� & //����������� ����� ������ ���������
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
			if (left > right)          // ���� ������� ���������� 
			{
				throw runtime_error("������� �� ��� ������\n");
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
			throw runtime_error("�������� �� ���� �������\n");
		}

		return res;
	}

	//2. ����������� ���� � ����� ��������� ���������� � �������������� ���������
	//���������� �� ����� � � ����.

	//4. ������������� ����� ������������ ������� �� ����� � � ����.
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