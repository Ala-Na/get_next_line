HEADER_PATH = ..
GNL = ../get_next_line.c ../get_next_line_utils.c
TEST = ./test.c
TEST_STDIN = ./test_stdin.c
TEST_BONUS = ./bonus_test.c
BONUS_GNL = ../get_next_line_bonus.c ../get_next_line_utils_bonus.c

all :	
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 $(GNL) $(TEST) -I $(HEADER_PATH) -o test1
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=2 $(GNL) $(TEST) -I $(HEADER_PATH) -o test2
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 $(GNL) $(TEST) -I $(HEADER_PATH) -o test42
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=9999 $(GNL) $(TEST) -I $(HEADER_PATH) -o test9999
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10000000 $(GNL) $(TEST) -I $(HEADER_PATH) -o test10000000
	@./test1
	@./test2
	@./test42
	@./test9999
	@./test10000000

bonus :	
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 $(BONUS_GNL) $(TEST_BONUS) -I $(HEADER_PATH) -o test1_bonus
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=2 $(BONUS_GNL) $(TEST_BONUS) -I $(HEADER_PATH) -o test2_bonus
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 $(BONUS_GNL) $(TEST_BONUS) -I $(HEADER_PATH) -o test42_bonus
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=9999 $(BONUS_GNL) $(TEST_BONUS) -I $(HEADER_PATH) -o test9999_bonus
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10000000 $(BONUS_GNL) $(TEST_BONUS) -I $(HEADER_PATH) -o test10000000_bonus
	@./test1_bonus
	@./test2_bonus
	@./test42_bonus
	@./test9999_bonus
	@./test10000000_bonus

stdin_1 :
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 $(GNL) $(TEST_STDIN) -I $(HEADER_PATH) -o test_stdin
	@./test_stdin

stdin_2 :
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=2 $(GNL) $(TEST_STDIN) -I $(HEADER_PATH) -o test_stdin
	@./test_stdin

stdin_42 :
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 $(GNL) $(TEST_STDIN) -I $(HEADER_PATH) -o test_stdin
	@./test_stdin

stdin_9999 :
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=9999 $(GNL) $(TEST_STDIN) -I $(HEADER_PATH) -o test_stdin
	@./test_stdin

fclean :
	rm -f test1 test2 test42 test9999 test10000000 test_stdin test1_bonus test2_bonus test42_bonus test9999_bonus test10000000_bonus

.PHONY: all fclean

