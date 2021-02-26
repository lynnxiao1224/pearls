#pragma once
#include <istream>
#include <ostream>
#include <iostream>

namespace operator_overload {
	class Point {
		int x, y, z;

		void operator>>(std::istream& input);

		friend std::istream& operator>>(std::istream& input, Point& p);
		friend std::ostream& operator<<(std::ostream& output, const Point& p);

	};

	void Point::operator>>(std::istream& input)
	{
		input >> x >> y >> z;
	}

	std::istream& operator>>(std::istream& input, Point& p)
	{
		input >> p.x >> p.y >> p.z;
		return input;
	}

	std::ostream& operator<<(std::ostream& output, const Point& p)
	{
		output << p.x << " " << p.y << " " << p.z << " ";
		return output;
	}

	class Rectangle {
		int width, height;

		friend std::istream& operator>>(std::istream& input, Rectangle& r) {
		//std::istream& operator>>(std::istream & input) {
				input >> r.width >> r.height;
			return input;
		}

		friend std::ostream& operator<<(std::ostream& output, const Rectangle& r) {
			output << r.width << " " << r.height << " ";
			return output;
		}
	};

	void testStatic()
	{
		static int i = 1;
		cout << "i=" << i++;
	}


	void testOperator()
	{
		Point p;
		Rectangle r;

		std::cin >> p;
		std::cout << p << std::endl;

		testStatic();
		testStatic();
		testStatic();
		
	}
}