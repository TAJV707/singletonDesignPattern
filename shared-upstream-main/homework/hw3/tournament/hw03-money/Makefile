CXX=g++
CXXFLAGS = -std=c++11 -g
DEP_DIR=/project/grades/Spring-2022/csci3081/dependencies

##### EDIT ME!!! #####################
MAINEXEFILE = money.cc
CORRECTEXE = money.correct.cc
MAINTESTFILE = money_unittest.cc
######################################
LABTESTEXE = money_unittest
LABEXE = money

MUTANTS = $(patsubst mutants/mutant%/$(MAINEXEFILE),${LABTESTEXE}_m%,$(wildcard mutants/mutant*/$(MAINEXEFILE)))

all: ${LABEXE} ${LABTESTEXE}_correct

	
${LABEXE}:
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include  -Iinclude -L$(DEP_DIR)/lib main.cc $(CORRECTEXE) -lgtest_main -lgtest -lgmock -pthread -o $@

${LABTESTEXE}_correct: $(MAINTESTFILE)
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include  -Iinclude -L$(DEP_DIR)/lib $(MAINTESTFILE) $(CORRECTEXE) -lgtest_main -lgtest -lgmock -pthread -o $@

clean:
	rm -f ${LABEXE}
	rm -f ${LABTESTEXE}
	rm -f ${LABTESTEXE}_*
	rm -rf *.o
