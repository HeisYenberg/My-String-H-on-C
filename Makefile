OS := $(shell uname)

ifeq ($(OS),Darwin)
	CC = -Wall -Werror -Wextra -std=c11
	FLAGS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
	OPEN_CMD = open
	DEFINE = -D MAC
else
	CC = -Wall -Werror -Wextra -std=c11
	FLAGS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
	OPEN_CMD = xdg-open
	DEFINE =
endif

all: clean s21_string.a test gcov_report

s21_string.a:
	gcc $(CC) $(DEFINE) -c s21_*.c
	ar -crs s21_string.a s21_*.o

test:
	gcc $(CC) $(DEFINE) tests/test*.c s21_string.a $(FLAGS) -lgcov -coverage -o test
	./test

gcov_report: clean
	gcc $(CC) $(DEFINE) tests/test*.c s21_*.c $(FLAGS) -o test
	./test
	lcov -t "./test"  -o report.info --no-external -c -d .
	genhtml -o report report.info
	$(OPEN_CMD) ./report/index.html

	rm -rf *.gcno *gcda *.gco

rebuild: clean s21_string.a test

clean:
	rm -rf *.o *.a test
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info

