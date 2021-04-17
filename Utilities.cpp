#include "Utilities.h"

static bool compare_with_filter(string value, string filter_value)
{
	return filter_value != "" ? value == filter_value : true;
}

static bool compare_with_filter(int value, int filter_value)
{
	return filter_value != -1 ? value == filter_value : true;
}

static bool validate_by_filter(pc_model model, filter search_filter)
{
	return compare_with_filter(model.processor_type, search_filter.processor_type)
		&& compare_with_filter(model.ram_capacity, search_filter.ram_capacity)
		&& compare_with_filter(model.video_memory_capacity, search_filter.video_memory_capacity)
		&& compare_with_filter(model.hard_drive_capacity, search_filter.hard_drive_capacity);
}

static bool check_field_increase(string op1, string op2, string filter_value)
{
	return filter_value != "" ? op1 <= op2 : true;
}

static bool check_field_increase(int op1, int op2, int filter_value)
{
	return filter_value != -1 ? op1 <= op2 : true;
}

static bool check_increase(pc_model op1, pc_model op2, filter search_filter)
{
	return (check_field_increase(op1.processor_type, op2.processor_type, search_filter.processor_type) +
		check_field_increase(op1.ram_capacity, op2.ram_capacity, search_filter.ram_capacity) +
		check_field_increase(op1.video_memory_capacity, op2.video_memory_capacity, search_filter.video_memory_capacity) +
		check_field_increase(op1.hard_drive_capacity, op2.hard_drive_capacity, search_filter.hard_drive_capacity)) / 4;
}

static bool compare_with_filter_increase(string value, string filter_value)
{
	return filter_value != "" ? filter_value < value : true;
}

static bool compare_with_filter_increase(int value, int filter_value)
{
	return filter_value != -1 ? filter_value < value : true;
}

static bool validate_by_filter_inequality(pc_model model, filter search_filter)
{
	return (compare_with_filter_increase(model.processor_type, search_filter.processor_type) +
		compare_with_filter_increase(model.ram_capacity, search_filter.ram_capacity) +
		compare_with_filter_increase(model.video_memory_capacity, search_filter.video_memory_capacity) +
		compare_with_filter_increase(model.hard_drive_capacity, search_filter.hard_drive_capacity)) / 4;
}
