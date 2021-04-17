#pragma once

#include <iostream>
using namespace std;

class filter
{
public:
	string processor_type;
	int ram_capacity;
	int hard_drive_capacity;
	int video_memory_capacity;

	filter()
	{
		processor_type = "";
		ram_capacity = -1;	
		hard_drive_capacity = -1;
		video_memory_capacity = -1;
	}
};