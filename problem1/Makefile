#This file is part of steranoid_projecteuler.

#steranoid_projecteuler is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.

#steranoid_projecteuler is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.

#You should have received a copy of the GNU General Public License
#along with steranoid_projecteuler.  If not, see <http://www.gnu.org/licenses/>.

CPP=cpp
CPPFLAGS=-Iinc

CC=cc -c
CFLAGS=-Wall -Wextra -pedantic -Wunreachable-code -Wformat-nonliteral -Wformat -Wformat-security -Werror=format-security -Werror=return-type -Winit-self -Wpointer-arith \
	-O2 \
	-g3 \
	-D_FORTIFY_SOURCE=2 \
	--param ssp-buffer-size=1 \
	-fno-strict-overflow -ffunction-sections -fdata-sections -fPIC -fstack-protector -fPIC -fPIE

CXX=c++ -c
CXXFLAGS=-Wall -Wextra -pedantic -Wunreachable-code -Wformat-nonliteral -Wformat -Wformat-security -Werror=format-security -Werror=return-type -Winit-self -Wpointer-arith -Woverloaded-virtual \
	-O2 \
	-g3 \
	-D_FORTIFY_SOURCE=2 \
	--param ssp-buffer-size=1 \
	-fno-strict-overflow -ffunction-sections -fdata-sections -fPIC -fno-rtti -fstack-protector -fPIC -fPIE

LD=g++
LDFLAGS=-Wl,-pie,-z,relro,-z,now,-z,noexecstack,--gc-sections

ifneq ($(MAKECMDGOALS),clean)
include config.mk
-include $(wildcard .dep/*.d)
endif

.PRECIOUS: bin/% obj/%.o .dep/%.d
.SECONDEXPANSION:
.PHONY: clean default

#Édition des liens
bin/%: $$($$*_OBJS) | bin
	$(LD) $(LDFLAGS) $+ -o $@

#Précompilation compilation et assemblage
obj/%.o:src/%.i .dep/%.d | obj
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@
obj/%.o:src/%.c .dep/%.d | obj
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@
obj/%.o:src/%.ii .dep/%.d | obj
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@
obj/%.o:src/%.C .dep/%.d | obj
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@
obj/%.o:src/%.cc .dep/%.d | obj
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@
obj/%.o:src/%.c++ .dep/%.d | obj
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@
obj/%.o:src/%.cpp .dep/%.d | obj
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@

#Dépendances
.dep/%.d:src/%.i | .dep
	$(CPP) -MM $(CPPFLAGS) -MP $< -MQ obj/$*.o -MQ $@ -MF $@
.dep/%.d:src/%.c | .dep
	$(CPP) -MM $(CPPFLAGS) -MP $< -MQ obj/$*.o -MQ $@ -MF $@
.dep/%.d:src/%.ii | .dep
	$(CPP) -MM $(CPPFLAGS) -MP $< -MQ obj/$*.o -MQ $@ -MF $@
.dep/%.d:src/%.C | .dep
	$(CPP) -MM $(CPPFLAGS) -MP $< -MQ obj/$*.o -MQ $@ -MF $@
.dep/%.d:src/%.cc | .dep
	$(CPP) -MM $(CPPFLAGS) -MP $< -MQ obj/$*.o -MQ $@ -MF $@
.dep/%.d:src/%.c++ | .dep
	$(CPP) -MM $(CPPFLAGS) -MP $< -MQ obj/$*.o -MQ $@ -MF $@
.dep/%.d:src/%.cpp | .dep
	$(CPP) -MM $(CPPFLAGS) -MP $< -MQ obj/$*.o -MQ $@ -MF $@

bin obj .dep:
	@mkdir $@

clean:
	rm -rf bin && \
	rm -rf obj && \
	rm -rf .dep
