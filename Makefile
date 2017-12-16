#############################################################################
# StreamingActivity
#

OBJS=StreamingActivity.o Video.o Stream.o Account.o RunTime.o
TOBJS=Video_t.o Stream_t.o Account_t.o
EXE=StreamingActivity Video_t Stream_t Account_t

GCC= g++
CFLAGS=-Wall -std=c++11

.PHONY : all
all : $(EXE) test

# StreamingActivity
.PHONY : run
run : StreamingActivity
	@./StreamingActivity

StreamingActivity : $(OBJS)
	$(GCC) $^ -o $@

StreamingActivity.o: StreamingActivity.cpp Video.hpp Stream.hpp Account.hpp RunTime.hpp
	$(GCC) $(CFLAGS) -c $<

# Video
Video.o: Video.cpp Video.hpp RunTime.hpp
	$(GCC) $(CFLAGS) -c $<

Video_t : Video_t.o Video.o RunTime.o
	$(GCC) $^ -o $@

Video_t.o: Video_t.cpp Video.hpp catch.hpp
	$(GCC) $(CFLAGS) -c $<

# Stream
Stream.o: Stream.cpp Stream.hpp Video.hpp
	$(GCC) $(CFLAGS) -c $<

Stream_t : Stream_t.o Stream.o Video.o RunTime.o
	$(GCC) $^ -o $@

Stream_t.o: Stream_t.cpp Stream.hpp catch.hpp
	$(GCC) $(CFLAGS) -c $<

# Account
Account.o: Account.cpp Account.hpp Video.hpp Stream.hpp
	$(GCC) $(CFLAGS) -c $<

Account_t : Account_t.o Account.o Stream.o Video.o RunTime.o
	$(GCC) $^ -o $@

Account_t.o: Account_t.cpp Account.hpp catch.hpp
	$(GCC) $(CFLAGS) -c $<

# RunTime
RunTime.o: RunTime.cpp RunTime.hpp
	$(GCC) $(CFLAGS) -c $<	
	
# Note: is not part of clean
catch.hpp :
	curl -L -O https://github.com/catchorg/Catch2/releases/download/v2.0.1/catch.hpp

# clean
.PHONY : clean
clean : cleanobjects
	rm -f $(EXE)

.PHONY : cleanobjects
cleanobjects :
	rm -f $(OBJS) $(TOBJS)

# unit testing
.PHONY : test
test : Video_t Stream_t Account_t
	./Video_t
	./Stream_t
	./Account_t
