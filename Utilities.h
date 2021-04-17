#pragma once

#include "pc_model.h"
#include "Filter.h"


//Компараторы для проверки на равенство полей объекта и полей фильтра + общая функция проверки
static bool compare_with_filter(string value, string filter_value);
static bool compare_with_filter(int value, int filter_value);
static bool validate_by_filter(pc_model model, filter search_filter);

//Компараторы для проверки (op1 <= op2) двух объектов в соответсвии с фильтром (для сортировки контейнера)
static bool check_field_increase(string op1, string op2, string filter_value);
static bool check_field_increase(int op1, int op2, int filter_value);
static bool check_increase(pc_model op1, pc_model op2, filter search_filter);

//Компараторы для проверки на неравенство(search_filter < model) полей объекта и полей фильтра (для бинарного поиска)
static bool compare_with_filter_increase(string value, string filter_value);
static bool compare_with_filter_increase(int value, int filter_value);
static bool validate_by_filter_inequality(pc_model model, filter search_filter);
