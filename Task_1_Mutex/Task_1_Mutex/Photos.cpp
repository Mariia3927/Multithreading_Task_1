#include "pch.h"


Photos::Photos() : m_fileName(g_defaultFileName), m_delay(g_defaultDelay)
{
}

Photos::Photos(const std::string & fileName = g_defaultFileName, int delay = g_defaultDelay) : m_fileName(fileName), m_delay(delay)
{
}

Photos::~Photos()
{
}

void Photos::ReadDataFromFile()
{
	std::lock_guard<std::mutex> lk(m_mtx);
	Sleep(m_delay);

	std::fstream fin(m_fileName, std::ios::in);
	if (!fin)
	{
		std::cout << "Error! File didn't open.\n";
		return;
	}

	std::string tmp = "";
	while (fin)
	{
		std::getline(fin, tmp);
		m_names.push_back(tmp);
	}

	fin.close();
}

void Photos::OutputReadData()
{
	while (true)
	{
		if (m_names.size() > 0 && m_mtx.try_lock())
		{
			std::cout << "There are photos' names from the file: \n";
			std::for_each(m_names.begin(), m_names.end(), [](std::string name) { std::cout << name << '\n'; });
			
			m_mtx.unlock();
			return;
		}
		std::cout << "Vector size: " << m_names.size() << '\n';
		Sleep(1000);
	}
}
