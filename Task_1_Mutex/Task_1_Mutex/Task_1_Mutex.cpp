// Task_1_Mutex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	Photos object;
	std::thread threadForOutput(&Photos::OutputReadData, &object);
	
	object.ReadDataFromFile();

	if (threadForOutput.joinable())
		threadForOutput.join();
}

