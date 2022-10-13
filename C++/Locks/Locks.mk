##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Locks
ConfigurationName      :=Debug
WorkspacePath          :=/Users/kiran/Documents/FirstCodelieProj
ProjectPath            :=/Users/kiran/Documents/FirstCodelieProj/Locks
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Kirankumar Srikanta
Date                   :=27/06/2021
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
ObjectsFileList        :="Locks.txt"
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
CXXFLAGS :=  -g -O0 -std=c++17 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/mutex.cpp$(ObjectSuffix) $(IntermediateDirectory)/basic.cpp$(ObjectSuffix) 



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
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/mutex.cpp$(ObjectSuffix): mutex.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mutex.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mutex.cpp$(DependSuffix) -MM mutex.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kiran/Documents/FirstCodelieProj/Locks/mutex.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mutex.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mutex.cpp$(PreprocessSuffix): mutex.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mutex.cpp$(PreprocessSuffix) mutex.cpp

$(IntermediateDirectory)/basic.cpp$(ObjectSuffix): basic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/basic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/basic.cpp$(DependSuffix) -MM basic.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kiran/Documents/FirstCodelieProj/Locks/basic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/basic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/basic.cpp$(PreprocessSuffix): basic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/basic.cpp$(PreprocessSuffix) basic.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


