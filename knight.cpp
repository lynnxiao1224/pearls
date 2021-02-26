
#include <iostream>
#include <vector>
using std::cout;//using declarations
using std::cin;
using std::endl;


std::vector<int> xlist(100, 0);
std::vector<int> ylist(100, 0);

std::vector<std::vector<int>> grid(9, std::vector<int>(9, -1));

int fx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int fy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int steps = 0;

bool isValid(int x, int y)
{
	if (x < 1 || x > 8 || y < 1 || y > 8) {
		return false;
	}

	if (xlist[x * 9 + y] > 0) {
		return false;
	}

	return true;
}

bool route(int x, int y, int dstX, int dstY)
{
	if (x == dstX && y == dstY) {
		cout << "(" << x << "," << y << ")" << endl;
		return true;
	}

	for (int i = 0; i < 8; i++) {
		int nx = x + fx[i];
		int ny = y + fy[i];

		if (!isValid(nx, ny)) {
			continue;
		}

		xlist[nx * 9 + ny] = steps++;
		if (route(nx, ny, dstX, dstY)) {
			cout << "(" << x << "," << y << ")" << endl;
			return true;
		}
		xlist[nx * 9 + ny] = 0;
	}


	return false;
}

void knight()
{
	int srcX = 1;//the begin of x
	int srcY = 3;//the begin of y
	int dstX = 1;//the end of x
	int dstY = 8;//the end of y

	xlist[srcX * 9 + srcY] = steps++;

	if (route(srcX, srcY, dstX, dstY)) {
		for (int i = 1; i < 9; i++) {
			for (int j = 1; j < 9; j++) {
				cout << xlist[i * 9 + j] << "   ";
			}
			cout << endl;
		}
	}
}