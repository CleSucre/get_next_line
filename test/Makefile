ifeq ($(OS), Windows_NT)
	DIRSEP	= \\
	CP		= copy
	RM		= del
	EXE		= .exe
else
	DIRSEP	= /
	CP		= cp
	RM		= rm -f
	EXE		= .out
endif

NAME		= get_next_line_test

SRCS		= ..${DIRSEP}get_next_line.c ..${DIRSEP}get_next_line_utils.c

TEST	 	= src${DIRSEP}tester_utils.c \
			  get_next_line_test.c

OBJS_TEST	= ${TEST:.c=.o}

OBJS_BONUS	= ${TEST_BONUS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

test: ${OBJS_TEST}
	${CC} ${CFLAGS} ${SRCS} ${OBJS_TEST} -o ${NAME}

clean:
	${RM} ${OBJS_TEST}

fclean: clean
	${RM} ${NAME}${EXE}

.PHONY: test clean fclean run