targets = \
	1_two_sum.exec\
    2_add_two_numbers.exec\
	3_longest_substring_without_repeating_characters.exec\
	4_median_of_two_sorted_arrays.exec\
	5_longest_palindromic_substring.exec\
	6_zigzag_conversion.exec\


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
