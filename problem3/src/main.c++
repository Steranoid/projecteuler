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

#include "prime_iterator.h++"
using steranoid::prime_iterator;

int main(int, char**) {
	auto constexpr number = 600'851'475'143ull;
	auto largest_prime_factor = 1ull;

	for (auto i = prime_iterator<>(); (*i)*(*i) < number; ++i) {
		if (number % *i == 0) {
			largest_prime_factor = *i;
		}
	}

	cout << "The largest prime factor of " << number << " is " << largest_prime_factor << endl;
	return EXIT_SUCCESS;
}
