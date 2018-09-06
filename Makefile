targets = \
	1_two_sum.exec\
    2_add_two_numbers.exec\
	3_longest_substring_without_repeating_characters.exec\
	4_median_of_two_sorted_arrays.exec\
	5_longest_palindromic_substring.exec\
	6_zigzag_conversion.exec\
	7_reverse_interger.exec\
	8_string_to_interger.exec\
	9_palindrome_number.exec\
	10_regular_expression_matching.exec\
	11_container_with_most_water.exec\
	12_integer_to_roman.exec\
	13_roman_to_integer.exec\
	14_longest_common_prefix.exec\
	15_3_sum.exec\
	16_3sum_closest.exec\
	17_letter_ombinations_of_a_phone_number.exec\
	502_ipo.exec\


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
