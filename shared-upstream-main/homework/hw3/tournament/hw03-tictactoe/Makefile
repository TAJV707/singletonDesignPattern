CXX=g++
CXXFLAGS = -std=c++11 -g
DEP_DIR=/project/grades/Spring-2022/csci3081/dependencies

##### EDIT ME!!! #####################
MAINEXEFILE = tictactoe.cc
CORRECTEXE = tictactoe.correct.cc
MAINTESTFILE = tictactoe_unittest.cc
######################################
LABTESTEXE = tictactoe_unittest
LABEXE = tictactoe

MUTANTS = $(patsubst mutants/mutant%/$(MAINEXEFILE),${LABTESTEXE}_m%,$(wildcard mutants/mutant*/$(MAINEXEFILE)))

all: ${LABTESTEXE}_correct
	
${LABTESTEXE}_correct: 
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include  -Iinclude -L$(DEP_DIR)/lib $(MAINTESTFILE) $(CORRECTEXE) -lgtest_main -lgtest -lgmock -pthread -o $@

test: ${LABTESTEXE}

clean:
	rm -f ${LABEXE}
	rm -f ${LABTESTEXE}
	rm -f ${LABTESTEXE}_*
	rm -rf *.o
