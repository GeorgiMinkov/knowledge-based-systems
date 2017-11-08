#include "stdafx.h"
#include "Track.h"

void Track::initialize()
{
	for (int index = 0; index < this->matrix.size(); ++index) 
	{
		this->shortPathTreeVisited->at(index) = false;
		
		this->minDistance->at(index) = INFINITE;
	}

	this->parentPath->at(this->from) = -1;
}

int Track::getMinDistanceIndex()
{
	int min = INFINITE, minIndex = -1;

	for (int index = 0; index < this->matrix.size(); ++index) 
	{
		if (!(this->shortPathTreeVisited->at(index)) && this->minDistance->at(index) < min) 
		{
			min = this->minDistance->at(index);
			minIndex = index;
		}
	}

	return minIndex;
}

void Track::utility()
{
	this->minDistance = new container_t(matrix.size());
	this->parentPath = new container_t(matrix.size());
	this->shortPathTreeVisited = new shortestPathTree_t(matrix.size());
}

void Track::pushNumberToMatrix(matrix_t &matrix, std::string &strNumber, const int &vectorRow)
{
	int number = std::stoi(strNumber);

	matrix[vectorRow].push_back(number);

	strNumber = "";
}

Track::Track(const matrix_t &matrix, const int &from, const int &to) : matrix(matrix), from(from - 1), to(to - 1)
{
	this->utility();
}

Track::~Track()
{
	delete this->shortPathTreeVisited;
	delete this->minDistance;
	delete this->parentPath;
}

void Track::find()
{
	if (this->from == -1 || this->to == -1)
	{
		throw "Invalid value for search";
	}

	this->find(this->from, this->to);
}

void Track::find(const int &from, const int &to)
{
	// set value
	this->setFrom(from);
	this->setTo(to);

	this->initialize(); // make initial initializations form shortest path tree and infinite value for algo

	this->minDistance->at(this->from) = 0; // set value from source to source to zero

	bool target = false;

	for (int index = 0; index < this->matrix.size() - 1 && !(target); ++index)
	{
		int minIndex = this->getMinDistanceIndex(); // compute index of minimum distance node from current 

		if (minIndex == this->to)
		{
			target = true;
		}

		this->shortPathTreeVisited->at(minIndex) = true;

		for (int adj = 0; adj < this->matrix.size() && !(target); ++adj)
		{
			if (!(this->shortPathTreeVisited->at(adj)) && this->matrix[adj][minIndex]
				&& this->minDistance->at(minIndex) != INFINITE
				&& this->minDistance->at(minIndex) + this->matrix[adj][minIndex] < this->minDistance->at(adj)) // check condition to add new node to parent path
			{
				this->parentPath->at(adj) = minIndex;
				this->minDistance->at(adj) = this->minDistance->at(minIndex) + this->matrix[adj][minIndex];
			}
		}
	}
}

void Track::print()
{
	std::cout << this->from + 1;
	this->printPath(this->to);
}

void Track::printPath(const int &parent)
{
	if (this->parentPath->at(parent) == -1)
	{
		return ;
	}

	printPath(this->parentPath->at(parent));

	std::cout << ", " << parent + 1;
}

void Track::setFrom(const int &from)
{
	this->from = from - 1;
}

void Track::setTo(const int &to)
{
	this->to = to - 1;
}

void Track::setMatrix(const matrix_t &matrix)
{
	this->matrix = matrix;

	this->minDistance->clear();
	this->parentPath->clear();
	this->shortPathTreeVisited->clear();

	this->minDistance->resize(this->matrix.size(), INFINITE);
	this->parentPath->resize(this->matrix.size());
	this->shortPathTreeVisited->resize(this->matrix.size(), false);
}

matrix_t Track::getMatrix() const
{
	return this->matrix;
}

void Track::readFromFile(const std::string &fileName)
{
	std::ifstream file;

	file.open(fileName.c_str(), std::ios::in);
	
	if (!(file.is_open()))
	{
		throw "File open Error";
	}

	std::string line = "";
	int vectorRow = 0;

	while (getline(file, line))
	{
		if (!vectorRow)
		{
			int numberOfRows = std::count(line.begin(), line.end(), ',') + 1;

			matrix.resize(numberOfRows);
		}

		int strIndex = -1;
		std::string strNumber = "";

		while (line[++strIndex])
		{
			if (line[strIndex] != ',')
			{
				strNumber += line[strIndex];
			}
			else
			{
				pushNumberToMatrix(matrix, strNumber, vectorRow);
			}

			if (line[strIndex + 1] == '\0')
			{
				pushNumberToMatrix(matrix, strNumber, vectorRow);
			}
		}
		++vectorRow;
	}
	file.close();

	this->utility();
}
