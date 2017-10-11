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
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename T>
bool is_palyndrome(T number) {
	vector<T> digits;
	bool palyndrome = true;
	for (;number != 0;number = number / 10) {
		digits.push_back(number % 10);
	}
	for (auto i = 0ull; i < digits.size()/2 and palyndrome; ++i) {
		palyndrome = (digits[i] == digits[digits.size() - i - 1]);
	}
	return palyndrome;
}

int main(int, char**) {
	auto constexpr max_factor = 999ull;
	auto number = 0ull;

	for (auto i = max_factor; i > 1; --i) {
		for (auto j = max_factor; j > 1 and number < i*j; --j) {
			if (is_palyndrome(i*j)) {
				number = i * j;
			}
		}
	}

	cout << "Palyndrome maximum : " << number << endl;

	return EXIT_SUCCESS;
}
