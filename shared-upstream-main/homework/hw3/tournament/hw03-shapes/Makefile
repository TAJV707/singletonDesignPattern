CXX=g++
CXXFLAGS = -std=c++11 -g
DEP_DIR=/project/grades/Spring-2022/csci3081/dependencies

##### EDIT ME!!! #####################
CORRECTEXE = shapes.correct.cc
MAINTESTFILE = shapes_unittest.cc
######################################
LABTESTEXE = shapes_unittest
LABEXE = shapes


all: ${LABEXE} ${LABTESTEXE} ${LABTESTEXE}_correct

${LABEXE}:
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include  -Iinclude -L$(DEP_DIR)/lib main.cc $(CORRECTEXE) -lgtest_main -lgtest -lgmock -pthread -o $@

${LABTESTEXE}: 
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include  -Iinclude -L$(DEP_DIR)/lib $(MAINTESTFILE) $(CORRECTEXE) -lgtest_main -lgtest -lgmock -pthread -o $@

#${LABEXE}: ${LABTESTEXE}
#	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include  -Iinclude -L$(DEP_DIR)/lib -L$(BUILD_DIR)/lib main.cc $(MAINEXEFILE) -lgtest_main -lgtest -lgmock -pthread -o $@

# mutant 10 adds a member variable to Queue class to increase its sizeof
# ${LABTESTEXE}_m10: mutants/mutant10/queue.cc
# 	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include  -Imutants/mutant10 -L$(DEP_DIR)/lib $(MAINTESTFILE) $< -lgtest_main -lgtest -lgmock -pthread -o $@

test: ${LABTESTEXE}

clean:
	rm -f ${LABEXE}
	rm -f ${LABTESTEXE}
	rm -f ${LABTESTEXE}_*
	rm -rf *.o
