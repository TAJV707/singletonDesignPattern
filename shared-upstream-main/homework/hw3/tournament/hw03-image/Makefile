# rwildcard recursively searches through directory for files matching wildcard
# code taken from https://stackoverflow.com/a/18258352/13403845
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

CXX=g++
CXXFLAGS = -std=c++11
ROOT_DIR := ./
DEP_DIR=/project/grades/Spring-2022/csci3081/dependencies

INCLUDE_DIR := ./include/
SRC_DIR := ./src_correct
OBJ_DIR := ./build

MAINFILE := main.cc
MAINTESTFILE := image_processing_unittest.cc

LABTESTEXE = image_processing_unittest
LABEXE = image_processing

# SRCFILES is every .cc file recursively 
SRCFILES := $(call rwildcard,$(SRC_DIR)/,*.cc)
OBJFILES := $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRCFILES))

# looks at directory structure for finding mutant numbers
MUTANTS = $(patsubst mutants/mutant%,${LABTESTEXE}_m%,$(wildcard mutants/mutant*))

all: ${LABEXE} ${LABTESTEXE}_correct $(MUTANTS)

${LABTESTEXE}_correct: $(OBJFILES) $(MAINTESTFILE)
	mkdir -p out
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -I$(INCLUDE_DIR) -L$(DEP_DIR)/lib  $(MAINTESTFILE) -lgtest_main -lgtest -lgmock -pthread $(OBJFILES) -o out/$@

# Application Target
${LABEXE}: $(OBJFILES) $(MAINFILE)
	mkdir -p out
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(MAINFILE) $(OBJFILES) -o out/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@ 

${LABTESTEXE}_m%: mutants/mutant%/*.cc $(OBJFILES) $(MAINTESTFILE)
	mkdir -p out
	$(CXX) $(CXXFLAGS) -I$(DEP_DIR)/include -I$(INCLUDE_DIR) -L$(DEP_DIR)/lib  $(MAINTESTFILE) $< -lgtest_main -lgtest -lgmock -pthread $(filter-out $(OBJ_DIR)/$(patsubst %.cc,%.o, $(notdir $<)) $(OBJ_DIR)/filters/$(patsubst %.cc,%.o, $(notdir $<)), $(OBJFILES)) -o out/$@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf out/
	rm -f ${LABEXE} *.exe
	rm -f ${LABTESTEXE}
	rm -f ${LABTESTEXE}_*

