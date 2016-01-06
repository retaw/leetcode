targets = \
	1_two_sum.exec\
    2_add_two_numbers.exec\


CC = g++
cc = g++

cc_flags = -std=c++11 -ggdb -Wall


.PHONY:
all: $(targets)


$(targets): %.exec: %.cpp
	$(cc) $(cc_flags) $< -o $@


.PHONY: clean distclean
clean:
	rm -f *.o *.d *.d.* *.exec

distclean: clean
