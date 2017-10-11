//This file is part of steranoid_projecteuler.

//steranoid_projecteuler is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//steranoid_projecteuler is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with steranoid_projecteuler.  If not, see <http://www.gnu.org/licenses/>.

#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int main(int, char**) {
	auto sum = 0ull;

	for (auto i = 1ull; i * 3ull < 1000ull; i++) {
		if (i % 5ull != 0ull) {
			sum += i*3ull;
		}
	}
	for (auto j = 1ull; j * 5ull < 1000ull; j++) {
		sum += j*5ull;
	}

	cout << "Sum:" << sum << endl;
	return EXIT_SUCCESS;
}
