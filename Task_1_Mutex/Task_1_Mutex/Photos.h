#pragma once
#include "pch.h"


class Photos
{
public:
	Photos();
	Photos(const std::string& fileName, int delay);
	Photos(const Photos& obj) = delete;
	Photos& operator=(const Photos& obj) = delete;
	~Photos();

	void ReadDataFromFile();
	void OutputReadData();

private:
	std::string m_fileName;
	int m_delay;
	std::vector<std::string> m_names {};
	std::mutex m_mtx;
};

