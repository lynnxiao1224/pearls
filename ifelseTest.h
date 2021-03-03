#pragma once

#include <iostream>

namespace xl_210303 {

	/* if / else woulb be made pair from inside...
	*/

	class ifelseTest {
	public:
		void test() {

			int a = 1, b = 2, c = 3, x = 0;
			if (a > b)
				if (c > a) x = a;
				else x = c;
			std::cout << "x = " <<x<< std::endl;    // x = 0
		}
	};

}
