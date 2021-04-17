/*Результатом должна быть консольная программа с текстовым меню. Программа должна содержать 
шаблонный класс для управления данными согласно заданию. Для хранения данных необходимо выбрать оптимальный 
с точки зрения задания контейнер.

5. Модель компьютера характеризуется кодом и названием марки компьютера, типом процессора,
частотой работы процессора, объемом оперативной памяти, объемом жесткого диска, объемом памяти
видеокарты, стоимостью компьютера и кол-вом экземпляров. Поиск по типу процессора,
объему ОЗУ, памяти видеокарты и объему жесткого диска.*/ //Либо по одному либо по двум либо по трем

#include "sequence.h"
#include <iostream>

int input_int()
{
    for (;;)
    {
        int val;
        cin >> val;

        if (!cin.fail())
        {
            return val;
        }
        cout << "Введено некорректное значение. Повторите ввод" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
    }
}

int bounded_input(int low, int high)
{
    for (;;)
    {
        int value = input_int();
        if ((value >= low) && (value <= high))
        {
            return value;
        }

        std::cout << "Введенное значение выходит за допустимый диапазон. Повторите ввод" << std::endl;
    }
}

pc_model get_model()
{
    pc_model model;
    cout << "Введите код" << endl;
    model.code = input_int();
    cout << "Введите марку компьютера" << endl;
    cin >> model.brand;
    cout << "Введите тип процессора" << endl;
    cin >> model.processor_type;
    cout << "Введите частоту работы процессора" << endl;
    model.processor_freq = input_int();
    cout << "Введите объем оперативной памяти" << endl;
    model.ram_capacity = input_int();
    cout << "Введите объем жесткого диска" << endl;
    model.hard_drive_capacity = input_int();
    cout << "Введите объем памяти видеокарты" << endl;
    model.video_memory_capacity = input_int();
    cout << "Введите стоимость в тыс" << endl;
    model.cost = input_int();
    cout << "Введите кол-во экземпляров в тыс" << endl;
    model.count = input_int();
    return model;
}

filter get_filter()
{
    filter search_filter;
    string type;
    int capacity;

    int answer;
    cout << "Добавить фильтр по типу процессора? 1 - да" << endl;
    answer = input_int();
    if (answer == 1)
    {
        cout << "Введите тип процессора" << endl;
        cin >> type;
        search_filter.processor_type = type;
    }

    cout << "Добавить фильтр по объему ОЗУ? 1 - да" << endl;
    answer = input_int();
    if (answer == 1)
    {
        cout << "Введите объем ОЗУ" << endl;
        capacity = input_int();
        search_filter.ram_capacity = capacity;
    }
    cout << "Добавить фильтр по объему памяти видеокарты? 1 - да" << endl;
    answer = input_int();
    if (answer == 1)
    {
        cout << "Введите объем памяти видеокарты" << endl;
        capacity = input_int();
        search_filter.video_memory_capacity = capacity;
    }
    cout << "Добавить фильтр по объему жесткого диска? 1 - да" << endl;
    answer = input_int();
    if (answer == 1)
    {
        cout << "Введите объем жесткого диска" << endl;
        capacity = input_int();
        search_filter.hard_drive_capacity = capacity;
    }

    return search_filter;
}

istream& operator>> (istream& in, pc_model& op)
{
    in >> op.code;
    in >> op.brand;
    in >> op.processor_type;
    in >> op.processor_freq;
    in >> op.ram_capacity;
    in >> op.hard_drive_capacity;
    in >> op.video_memory_capacity;
    in >> op.cost;
    in >> op.count;
    return in;
}

ostream& operator<< (ostream& out, const pc_model& op)
{
    out << op.code << endl << op.brand << endl << op.processor_type << endl << op.processor_freq << endl << op.ram_capacity << endl
        << op.hard_drive_capacity << endl << op.video_memory_capacity << endl
        << op.cost << endl << op.count << endl;
    return out;
}

void print_selection(vector<pc_model> seq)
{
    cout << "Вывод результата: " << endl;
    cout << "1 - в файл" << endl;
    cout << "2 - на экран" << endl;

    string file_name;
    int answer = bounded_input(1, 2);

    switch (answer)
    {
    case 1:
        cout << "Введите имя файла" << endl;
        cin >> file_name;
        sequence<pc_model>::print_file(seq, file_name);
        break;
    case 2:
        sequence<pc_model>::print_console(seq);
        break;
    }
}

void show_find_menu()
{
    cout << "ПОИСК:" << endl;
    cout << "   1 - линейный" << endl;
    cout << "   2 - двоичный" << endl;
    cout << "   3 - выборка всех вариантов" << endl;
    cout << "   4 - назад" << endl;
}

void find_menu(sequence<pc_model>& seq)
{
    show_find_menu();

    int answer = bounded_input(1, 4);
    pc_model object_to_find;
    filter search_filter = get_filter();
    vector<pc_model> res;
    try
    {
        switch (answer)
        {
        case 1:
            cout << seq.find_linear(search_filter) << endl;
            break;
        case 2:
            cout << seq.find_binary(search_filter) << endl;
            break;
        case 3:
            res = seq.find_all(search_filter);
            print_selection(res);
            break;
        case 4:
            return;
            break;
        }
    }
    catch (runtime_error err)
    {
       cout << err.what() << endl;
    }
}

void show_change_menu()
{
    cout << "РАБОТА С КОНТЕЙНЕРОМ:" << endl;
    cout << "   1 - добавить элемент" << endl;
    cout << "   2 - изменить элемент" << endl;
    cout << "   3 - удалить элемент" << endl;
    cout << "   4 - назад" << endl;
}

void change_menu(sequence<pc_model>& seq)
{
    show_change_menu();
    int answer = bounded_input(1, 4);
    pc_model new_model;
    filter search_filter;

    switch (answer)
    {
    case 1:
        new_model = get_model();
        seq.add(new_model);
        break;
    case 2:
        search_filter = get_filter();
        new_model = get_model();
        seq.change(search_filter, new_model);
        break;
    case 3:
        search_filter = get_filter();
        seq.delete_elem(search_filter);
        break;
    case 4:
        return;
        break;
    }
}

void show_menu()
{
    cout << "Меню" << endl;
    cout << "1 - поиск" << endl;
    cout << "2 - работа с контейнером" << endl;
    cout << "Вывод результата: " << endl;
    cout << "3 - в файл" << endl;
    cout << "4 - на экран" << endl << endl;
    cout << "5 - выход" << endl;
}

bool seq_menu(sequence<pc_model>& seq)
{
    show_menu();

    string file_name;
    int answer = bounded_input(1, 5);

    switch (answer)
    {
    case 1:
        find_menu(seq);
        break;
    case 2:
        change_menu(seq);
        break;
    case 3:
        cout << "Введите имя файла" << endl;
        cin >> file_name;
        seq.print_file(file_name);
        break;
    case 4:
        seq.print_console();
        break;
    case 5:
        return false;
        break;
    }
    return true;
}

void menu()
{
    cout << "Выберите способ заполнения контейнера" << endl;
    cout << "   1 - с клавиатуры" << endl;
    cout << "   2 - из файла" << endl;
    int answer = bounded_input(1, 2);
    sequence<pc_model> seq;
    string file_name;
    int n;

    try
    {
        switch (answer)
        {
        case 1:
            cout << "Введите колличество элементов в контейнере - ";
            n = input_int();
            seq.generate_n(n);
            break;
        case 2:
            cout << "Введите имя файла" << endl;
            cin >> file_name;
            seq.init_from_file(file_name);
            break;
        }

        for (; seq_menu(seq););
    }
    catch (runtime_error err)
    {
        cout << err.what() << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
	menu();
}
