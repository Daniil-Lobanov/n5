/*Результатом должна быть консольная программа с текстовым меню. Программа должна содержать 
шаблонный класс для управления данными согласно заданию. Для хранения данных необходимо выбрать оптимальный 
с точки зрения задания контейнер.

5. Модель компьютера характеризуется кодом и названием марки компьютера, типом процессора,
частотой работы процессора, объемом оперативной памяти, объемом жесткого диска, объемом памяти
видеокарты, стоимостью компьютера и кол-вом экземпляров. Поиск по типу процессора,
объему ОЗУ, памяти видеокарты и объему жесткого диска.*/ //Либо по одному либо по двум либо по трем


#include "pc_model.h"
#include "sequence.h"
#include <iostream>

using std::cout;
using std::cin;


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

//pc_model make_object_to_find(string processor_type = "", int ram_capacity = 0, int hard_drive_capacity = 0,
//    int video_memory_capacity = 0)
//{
//    pc_model object_to_find;
//    object_to_find.set_processor(processor_type);
//    object_to_find.set_ram(ram_capacity);
//    object_to_find.set_hard_drive(hard_drive_capacity);
//    object_to_find.set_video(video_memory_capacity);
//
//    return object_to_find;
//}

std::vector<filter> get_filters(pc_model& object_to_find)
{
    std::vector<filter> filters;
    string type;
    int capacity;

    int answer;
    cout << "Добавить фильтр по типу процессора? 1 - да" << endl;
    answer = input_int();
    if (answer == 1)
    {
        filters.push_back(pc_model::comp_type);
        cout << "Введите тип процессора" << endl;
        cin >> type;
        object_to_find.set_processor(type);
    }

    cout << "Добавить фильтр по объему ОЗУ? 1 - да" << endl;
    answer = input_int();
    if (answer == 1)
    {
        filters.push_back(pc_model::comp_ram);
        cout << "Введите объем ОЗУ" << endl;
        capacity = input_int();
        object_to_find.set_ram(capacity);
    }
    cout << "Добавить фильтр по объему памяти видеокарты? 1 - да" << endl;
    answer = input_int();
    if (answer == 1)
    {
        filters.push_back(pc_model::comp_video);
        cout << "Введите объем ОЗУ" << endl;
        capacity = input_int();
        object_to_find.set_video(capacity);
    }
    cout << "Добавить фильтр по объему жесткого диска? 1 - да" << endl;
    answer = input_int();
    if (answer == 1)
    {
        filters.push_back(pc_model::comp_hard_drive);
        cout << "Введите объем ОЗУ" << endl;
        capacity = input_int();
        object_to_find.set_hard_drive(capacity);
    }
    
    return filters;
}

void show_find_menu()
{
    cout << "ПОИСК:" << endl;
    cout << "   1 - линейный" << endl;
    cout << "   2 - двоичный" << endl;
    cout << "   3 - выборка всех вариантов:" << endl;
}

void find_menu(sequence<pc_model>& seq)
{
    show_find_menu();
        
    /*string processor_type;
    int ram_capacity, hard_drive_capacity, video_memory_capacity;
    std::vector<pc_model> temp;*/


    int answer = bounded_input(1, 3);
    pc_model object_to_find;
    std::vector<filter> filters = get_filters(object_to_find);

    switch (answer)
    {
    case 1:
        /*cout << "Введите тип процессора" << endl;
        cin >> processor_type;
        cout << "Введите объем ОЗУ" << endl;
        ram_capacity = input_int();
        cout << "Введите объем памяти видеокарты" << endl;
        video_memory_capacity = input_int();
        cout << "Введите объем жесткого диска" << endl;
        hard_drive_capacity = input_int();

        object_to_find = make_object_to_find(processor_type, ram_capacity, hard_drive_capacity,
            video_memory_capacity);
        seq.find_linear(object_to_find, pc_model::comp_all);*/
        /*cout << */seq.find_linear(object_to_find, filters);
        break;
    case 2:
        /*cout << "Введите тип процессора" << endl;
        cin >> processor_type;
        cout << "Введите объем ОЗУ" << endl;
        ram_capacity = input_int();
        cout << "Введите объем памяти видеокарты" << endl;
        video_memory_capacity = input_int();
        cout << "Введите объем жесткого диска" << endl;
        hard_drive_capacity = input_int();

        object_to_find = make_object_to_find(processor_type, ram_capacity, hard_drive_capacity,
            video_memory_capacity);
        seq.find_binary(object_to_find, pc_model::comp_all, pc_model::comp_all_less);*/

        break;
    case 3:
        /*cout << "Введите тип процессора" << endl;
        cin >> processor_type;
        object_to_find = make_object_to_find(processor_type);
        temp = seq.find_all(object_to_find, pc_model::comp_type);*/

        break;
    /*case 4:
        /*cout << "Введите объем ОЗУ" << endl;
        ram_capacity = input_int();
        object_to_find.set_ram(ram_capacity);
        temp = seq.find_all(object_to_find, pc_model::comp_ram);
        break;
    case 5:
        /*cout << "Введите объем памяти видеокарты" << endl;
        video_memory_capacity = input_int();
        object_to_find.set_ram(video_memory_capacity);
        temp = seq.find_all(object_to_find, pc_model::comp_video);
        break;
    case 6:
        /*cout << "Введите объем жесткого диска" << endl;
        hard_drive_capacity = input_int();
        object_to_find.set_ram(hard_drive_capacity);
        temp = seq.find_all(object_to_find, pc_model::comp_hard_drive);
        break;*/
    }
}

void show_menu()
{
    cout << "Меню" << endl;
    cout << "1 - поиск" << endl;
    cout << "Вывод результата: " << endl;
    cout << "2 - в файл" << endl;
    cout << "3 - на экран" << endl << endl;
    cout << "4 - выход" << endl;
}

bool seq_menu(sequence<pc_model>& seq)
{
    show_menu();

    string file_name;
    int answer = bounded_input(1, 4);

    switch (answer)
    {
    case 1:
        find_menu(seq);         //СДЕЛАТЬ ЧТО-ТО С ПОВТОРЯЮЩИМИСЯ КУСКАМИ КОДА!!!
                                //УНИВЕРСАЛЬНУЮ ПРОЦЕДУРУ ДЛЯ СОЗДАНИЯ ОБЪЕКТА КЛАССА С ЗАДАННЫМ ПАРАМЕТОМ
                                //ДЛЯ МУЛЬТИПОИСКА МОЖНО РЕАЛИЗОВАТЬ СПИСОК ИЗ КОМПАРАТОРОВ!!!!
        break;
    case 2:
        cout << "Введите имя файла" << endl;
        cin >> file_name;
        seq.print_file(file_name);
        break;
    case 3:
        //seq.print_console();
        break;
    case 4:
        return false;
        break;
    }
    return true;
}

sequence<pc_model> generate_n(int n)
{
    sequence<pc_model> seq;//СДЕЛАТЬ ПРОВЕРКУ НА ПЕРЕПОЛНЕНИЕ
    for (int i = 0; i < n; i++)
    {
        pc_model elem;
        cin >> elem;
        seq.add(elem);
    }
    return seq;
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

    switch (answer)
    {
    case 1:
        cout << "Введите колличество элементов в контейнере - ";
        n = input_int();
        seq = generate_n(n);
        break;
    case 2:
        cout << "Введите имя файла" << endl;
        cin >> file_name;
        seq.init_from_file(file_name);
        break;
    }

    for (; seq_menu(seq););
}



int main()
{
    setlocale(LC_ALL, "Russian");
	menu();
}
