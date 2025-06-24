#
# macOS makefile, tested with Monterey X64, Monterey ARM-M2, Ventura ARM-M2
#
OS         :=macOS
CXXFLAGS   := -O3 -fPIC -pedantic -std=c++11

Platform               :=$(OS)
ConfigurationName      :=Release
IntermediateDirectory  :=../temp/$(OS)
OutDir                 := $(IntermediateDirectory)
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
LibExt                 :=dylib 
OutputFile             :=../bin/$(Platform)/libsnapmb.$(LibExt)
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="filelist.txt"
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -O3
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)../../src/sys $(IncludeSwitch)../../src/core $(IncludeSwitch)../../src/lib 
Libs                   := $(LibrarySwitch)pthread
LibPath                := $(LibraryPathSwitch). 
LibInstall             := /usr/local/lib

##
## Common variables (CXXFLAGS varies across platforms)
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CFLAGS   := 

##
## User defined environment variables
##
Objects0=$(IntermediateDirectory)/snap_msgsock.o \
	$(IntermediateDirectory)/snap_sersock.o \
	$(IntermediateDirectory)/snap_sysutils.o \
	$(IntermediateDirectory)/snap_evtqueue.o \
	$(IntermediateDirectory)/snap_tcpsrvr.o \
	$(IntermediateDirectory)/snap_threads.o \
	$(IntermediateDirectory)/mb_broker.o \
	$(IntermediateDirectory)/mb_netclient.o \
	$(IntermediateDirectory)/mb_fieldcontroller.o \
	$(IntermediateDirectory)/mb_serbroker.o \
	$(IntermediateDirectory)/mb_sercontroller.o \
	$(IntermediateDirectory)/mb_serclient.o \
	$(IntermediateDirectory)/mb_serchannels.o \
	$(IntermediateDirectory)/mb_device.o \
	$(IntermediateDirectory)/mb_sthdevice.o \
	$(IntermediateDirectory)/mb_tcpdevice.o \
	$(IntermediateDirectory)/mb_udpdevice.o \
	$(IntermediateDirectory)/mb_serdevice.o \
	$(IntermediateDirectory)/mb_utils.o \
	$(IntermediateDirectory)/mb_text.o \
	$(IntermediateDirectory)/mb_libinterface.o \
	$(IntermediateDirectory)/snapmb_libmain.o 

Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean install PreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@$(MakeDirCommand) $(IntermediateDirectory)
	@echo $(Objects0)  > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	$(RM) $(ObjectsFileList)

$(IntermediateDirectory)/.d:
	@test -d ../temp/$(OS) || $(MakeDirCommand) ../temp/$(OS)

PreBuild:

PostBuild:

##
## Objects
##
$(IntermediateDirectory)/snap_msgsock.o: 
	$(CXX) $(SourceSwitch) "../../src/sys/snap_msgsock.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/snap_msgsock.o $(IncludePath)

$(IntermediateDirectory)/snap_sersock.o: 
	$(CXX) $(SourceSwitch) "../../src/sys/snap_sersock.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/snap_sersock.o $(IncludePath)

$(IntermediateDirectory)/snap_sysutils.o:
	$(CXX) $(SourceSwitch) "../../src/sys/snap_sysutils.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/snap_sysutils.o $(IncludePath)

$(IntermediateDirectory)/snap_evtqueue.o: 
	$(CXX) $(SourceSwitch) "../../src/sys/snap_evtqueue.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/snap_evtqueue.o $(IncludePath)

$(IntermediateDirectory)/snap_tcpsrvr.o:
	$(CXX) $(SourceSwitch) "../../src/sys/snap_tcpsrvr.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/snap_tcpsrvr.o $(IncludePath)

$(IntermediateDirectory)/snap_threads.o:
	$(CXX) $(SourceSwitch) "../../src/sys/snap_threads.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/snap_threads.o $(IncludePath)

$(IntermediateDirectory)/mb_broker.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_broker.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_broker.o $(IncludePath)

$(IntermediateDirectory)/mb_netclient.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_netclient.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_netclient.o $(IncludePath)

$(IntermediateDirectory)/mb_fieldcontroller.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_fieldcontroller.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_fieldcontroller.o $(IncludePath)

$(IntermediateDirectory)/mb_serbroker.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_serbroker.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_serbroker.o $(IncludePath)

$(IntermediateDirectory)/mb_sercontroller.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_sercontroller.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_sercontroller.o $(IncludePath)

$(IntermediateDirectory)/mb_serclient.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_serclient.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_serclient.o $(IncludePath)

$(IntermediateDirectory)/mb_serchannels.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_serchannels.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_serchannels.o $(IncludePath)

$(IntermediateDirectory)/mb_device.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_device.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_device.o $(IncludePath)

$(IntermediateDirectory)/mb_sthdevice.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_sthdevice.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_sthdevice.o $(IncludePath)

$(IntermediateDirectory)/mb_tcpdevice.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_tcpdevice.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_tcpdevice.o $(IncludePath)

$(IntermediateDirectory)/mb_udpdevice.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_udpdevice.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_udpdevice.o $(IncludePath)

$(IntermediateDirectory)/mb_serdevice.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_serdevice.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_serdevice.o $(IncludePath)

$(IntermediateDirectory)/mb_utils.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_utils.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_utils.o $(IncludePath)

$(IntermediateDirectory)/mb_text.o:
	$(CXX) $(SourceSwitch) "../../src/core/mb_text.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_text.o $(IncludePath)

$(IntermediateDirectory)/mb_libinterface.o:
	$(CXX) $(SourceSwitch) "../../src/lib/mb_libinterface.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/mb_libinterface.o $(IncludePath)

$(IntermediateDirectory)/snapmb_libmain.o:
	$(CXX) $(SourceSwitch) "../../src/lib/snapmb_libmain.cpp" $(CXXFLAGS) -o $(IntermediateDirectory)/snapmb_libmain.o $(IncludePath)

##
## Clean / Install
##
clean:
	$(RM) $(IntermediateDirectory)/*.o
	$(RM) $(OutputFile)

install: all
	$(MakeDirCommand) $(LibInstall)
	cp -f $(OutputFile) $(LibInstall)

