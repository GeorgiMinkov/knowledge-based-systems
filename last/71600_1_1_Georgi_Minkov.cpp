// Homework 1 - Georgi Minkov
//

#include "Track.h"

void enterFromTestFile()
{
	std::string fileName = "";

	std::cout << "Enter file name: ";
	std::cin >> fileName;

	Track track;
	int from = -1, to = -1;
	track.readFromFile(fileName);

	do
	{
		std::cout << "Enter from: ";
		std::cin >> from;

		std::cout << "Enter to: ";
		std::cin >> to;
	} while ((from < 1 || from > track.getMatrix().size()) || (to < 1 || to > track.getMatrix().size()));

	track.find(from, to);
	track.print();
}

void enterFromMyFile()
{
	std::string fileName = "schedule.csv";

	Track track;
	int from = -1, to = -1;
	track.readFromFile(fileName);

	do
	{
		std::cout << "Enter from: ";
		std::cin >> from;

		std::cout << "Enter to: ";
		std::cin >> to;
	} while ((from < 1 || from > track.getMatrix().size()) || (to < 1 || to > track.getMatrix().size()));

	track.find(from, to);
	track.print();
}

void enterReadyHandled()
{
	std::vector < container_t > matrix1 = {
		{ 0, 32, 54, 23, 14, 27, 22 },
		{ 23, 0, 44, 47, 21, 14, 19 },
		{ 23, 47, 0, 55, 34, 51, 12 },
		{ 32, 44, 27, 0, 22, 37, 53 },
		{ 41, 25, 21, 14, 0, 12, 34 },
		{ 54, 32, 36, 12, 32, 0, 27 },
		{ 32, 21, 45, 23, 37, 11, 0 } };

	std::vector< container_t >  matrix2 = {

		{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
		{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
		{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
		{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
		{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
		{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
		{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
		{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	std::vector < container_t > matrix3 = {
		{ 0, 32, 54, 23, 14, 27, 22 },
		{ 5, 0, 44, 47, 21, 14, 19 },
		{ 23, 47, 0, 55, 34, 51, 12 },
		{ 12, 10, 27, 0, 22, 37, 50 },
		{ 41, 25, 21, 14, 0, 12, 34 },
		{ 64, 32, 36, 3, 32, 0, 27 },
		{ 32, 21, 45, 23, 47, 11, 0 } };

	int choice = -1, from = -1, to = -1;
	do
	{
		std::cout << "Choose inside matrix from 1-3: ";
		std::cin >> choice;
	} while (choice < 1 || choice > 3);

	Track track;

	switch (choice)
	{
	case 1: track.setMatrix(matrix1); break;
	case 2: track.setMatrix(matrix2); break;
	case 3: track.setMatrix(matrix3); break;
	}

	do
	{
		std::cout << "\nEnter from: ";
		std::cin >> from;

		std::cout << "Enter to: ";
		std::cin >> to;
	} while ((from < 1 || from > track.getMatrix().size()) || (to < 1 || to > track.getMatrix().size()));

	track.find(from, to);

	track.print();
}

void menu()
{
	int choice = -1;

	do
	{
		std::cout << "How do you want to execute program:\n1) Enter from custom file tests with name\n2) Enter from already created test files\n3) Start example from condition of task\n\nEnter choice: ";
		std::cin >> choice;
	} while (choice < 1 || choice > 3);

	switch (choice)
	{
	case 1:
	{
		enterFromTestFile();
	} break;
	case 2:
	{
		enterFromMyFile();
	} break;
	case 3:
	{
		enterReadyHandled();
	} break;
	}
}

int main()
{
	menu();
	return 0;
}

