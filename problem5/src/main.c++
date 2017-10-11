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
#include <cmath>

using std::cout;
using std::endl;
using std::pow;

#include "prime_iterator.h++"

using steranoid::prime_iterator;

int main(int, char**) {
	auto pi = prime_iterator<>();
	auto i = *pi;
	for (;*pi <= 20; ++pi) {
		for (auto j = 0;(unsigned long long)(pow(*pi,j)) <= 20; ++j) {
			if (i % (unsigned long long)(pow(*pi,j)) != 0) {
				i = i * (*pi);
			}
		}
	}
	cout << "Résultat: " << i << endl;
	return EXIT_SUCCESS;
}
