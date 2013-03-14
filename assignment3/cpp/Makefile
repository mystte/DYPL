##
## Makefile for  Assignment3 -- DYPL
## 
## Made by stephane ROSE
## Login   stro0335
## 
##

## Project name
NAME_SH			= assignment3

## Sources
SRCS			= main.cpp		\
			  Parser.cpp		\
			  Dictionary.cpp	\
			  rules.cpp

## Objets
OBJS			= $(SRCS:.cpp=.o)

## Binary
CXX			= g++
RM			= rm -f
ECHO			= echo


## Flags
CPPFLAGS		= -W -Wall -Wextra -pedantic
## Rules
$(NAME_SH)		: $(OBJS)
		  	@$(CXX) -o $(NAME_SH) $(OBJS) $(CPPFLAGS)

all			: $(NAME_SH)

clean			:
			@$(RM) $(OBJS)
			@$(RM) *~
			@$(RM) \#*\#
	  		@$(RM) *.core


fclean			: clean
		  	-@$(RM) $(NAME_SH)


re			: fclean $(NAME_SH)