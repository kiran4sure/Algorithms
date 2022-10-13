##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=telephone
ConfigurationName      :=Debug
WorkspacePath          :=/Users/kiran/Projects/C++/state_machine
ProjectPath            :=/Users/kiran/Projects/C++/state_machine/telephone
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Kirankumar Srikanta
Date                   :=19/03/2020
CodeLitePath           :="/Users/kiran/Library/Application Support/CodeLite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="telephone.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/state_ringing.cpp$(ObjectSuffix) $(IntermediateDirectory)/idle.cpp$(ObjectSuffix) $(IntermediateDirectory)/on_call.cpp$(ObjectSuffix) $(IntermediateDirectory)/state_handler.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kiran/Projects/C++/state_machine/telephone/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/state_ringing.cpp$(ObjectSuffix): state_ringing.cpp $(IntermediateDirectory)/state_ringing.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kiran/Projects/C++/state_machine/telephone/state_ringing.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/state_ringing.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/state_ringing.cpp$(DependSuffix): state_ringing.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/state_ringing.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/state_ringing.cpp$(DependSuffix) -MM state_ringing.cpp

$(IntermediateDirectory)/state_ringing.cpp$(PreprocessSuffix): state_ringing.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/state_ringing.cpp$(PreprocessSuffix) state_ringing.cpp

$(IntermediateDirectory)/idle.cpp$(ObjectSuffix): idle.cpp $(IntermediateDirectory)/idle.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kiran/Projects/C++/state_machine/telephone/idle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/idle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/idle.cpp$(DependSuffix): idle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/idle.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/idle.cpp$(DependSuffix) -MM idle.cpp

$(IntermediateDirectory)/idle.cpp$(PreprocessSuffix): idle.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/idle.cpp$(PreprocessSuffix) idle.cpp

$(IntermediateDirectory)/on_call.cpp$(ObjectSuffix): on_call.cpp $(IntermediateDirectory)/on_call.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kiran/Projects/C++/state_machine/telephone/on_call.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/on_call.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/on_call.cpp$(DependSuffix): on_call.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/on_call.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/on_call.cpp$(DependSuffix) -MM on_call.cpp

$(IntermediateDirectory)/on_call.cpp$(PreprocessSuffix): on_call.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/on_call.cpp$(PreprocessSuffix) on_call.cpp

$(IntermediateDirectory)/state_handler.cpp$(ObjectSuffix): state_handler.cpp $(IntermediateDirectory)/state_handler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kiran/Projects/C++/state_machine/telephone/state_handler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/state_handler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/state_handler.cpp$(DependSuffix): state_handler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/state_handler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/state_handler.cpp$(DependSuffix) -MM state_handler.cpp

$(IntermediateDirectory)/state_handler.cpp$(PreprocessSuffix): state_handler.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/state_handler.cpp$(PreprocessSuffix) state_handler.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


