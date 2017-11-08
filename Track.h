#pragma once

#include "Sources.h"

typedef std::vector < std::vector <int> > matrix_t;
typedef std::vector < bool > shortestPathTree_t;
typedef std::vector < int > container_t;

const int INFINITE = INT_MAX;

class Track {
	matrix_t matrix;
	shortestPathTree_t *shortPathTreeVisited;
	container_t *minDistance;
	container_t *parentPath;

	int from;
	int to;

	void initialize();

	int getMinDistanceIndex();

	void utility();
	void pushNumberToMatrix(matrix_t &, std::string &, const int &);
public:
	Track(const matrix_t & matrix = matrix_t(), const int &from = -1, const int &to = -1);
	~Track();

	// setters
	void setFrom(const int &);
	void setTo(const int &);
	void setMatrix(const matrix_t &);

	// getters
	matrix_t getMatrix() const;
	// read from file
	void readFromFile(const std::string &);

	// function for finding element
	void find();
	void find(const int &, const int &);

	// output function
	void print();
	void printPath(const int &);
};