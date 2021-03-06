
#----------------------------------------------------------------------------------------
# To build parser and scanner:
#
# dos2unix edl_parser.y
# dos2unix edl_scanner.l
# bison -d edl_parser.y -o EdlParser.cpp  // creates EdlParser.cpp and EdlParser.hpp
# flex -f -oEdlScanner.cpp edl_scanner.l  // creates EdlScanner.cpp (EdlScanner.h already exists)
#
# search for "FlexLexer.h" in EdlScanner.cpp - replace:
#   #include <FlexLexer.h>
# with
#   #include "./platform/FlexLexer.h"
#----------------------------------------------------------------------------------------

include ../makedefs

LIB = $(OPENEAAGLES_LIB_DIR)/liboebase.a

OBJS =  \
	distributions/Exponential.o \
	distributions/Lognormal.o \
	distributions/Pareto.o \
	distributions/Uniform.o \
	functors/Function.o \
	functors/Functions.o \
	functors/Table.o \
	functors/Tables.o \
	nethandlers/PosixHandler.o \
	nethandlers/TcpClient.o \
	nethandlers/TcpHandler.o \
	nethandlers/TcpServerMultiple.o \
	nethandlers/TcpServerSingle.o \
	nethandlers/UdpBroadcastHandler.o \
	nethandlers/UdpMulticastHandler.o \
	nethandlers/UdpUnicastHandler.o \
	osg/Math.o \
	osg/Matrixd.o \
	osg/MatrixDecomposition.o \
	osg/Matrixf.o \
	osg/Quat.o \
	platform/Thread_linux.o \
	ubf/Action.o \
	ubf/Agent.o \
	ubf/Arbiter.o \
	ubf/Behavior.o \
	ubf/State.o \
	units/Angles.o \
	units/AngularVelocity.o \
	units/Areas.o \
	units/Density.o \
	units/Distances.o \
	units/Energies.o \
	units/FlowRate.o \
	units/Forces.o \
	units/Frequencies.o \
	units/LinearVelocity.o \
	units/Masses.o \
	units/Powers.o \
	units/Times.o \
	units/Volumes.o \
	util/platform/system_linux.o \
	util/lfi.o \
	util/math_utils.o \
	util/osg_utils.o \
	util/str_utils.o \
	util/system.o \
	Boolean.o \
	Cie.o \
	Cmy.o \
	Color.o \
	Complex.o \
	Component.o \
	Decibel.o \
	EarthModel.o \
	EdlParser.o \
	EdlScanner.o \
	factory.o \
	FileReader.o \
	Float.o \
	Hls.o \
	Hsva.o \
	Hsv.o \
	Identifier.o \
	Integer.o \
	IoAdapter.o \
	IoData.o \
	IoDevice.o \
	IoHandler.o \
	LatLon.o \
	List.o \
	Locus.o \
	Logger.o \
	Matrix.o \
	MonitorMetrics.o \
	Nav.o \
	NavDR.o \
	NetHandler.o \
	Number.o \
	Object.o \
	Operators.o \
	Pair.o \
	PairStream.o \
	Rgba.o \
	Rgb.o \
	Rng.o \
	SlotTable.o \
	Stack.o \
	Statistic.o \
	StateMachine.o \
	String.o \
	Terrain.o \
	Thread.o \
	ThreadPool.o \
	Timers.o \
	Transforms.o \
	Vectors.o \
	Yiq.o

.PHONY: all clean

all: $(LIB)

$(LIB) : $(OBJS)
	ar rs $@ $(OBJS)

clean:
	-rm -f distributions/*.o
	-rm -f functors/*.o
	-rm -f nethandlers/*.o
	-rm -f osg/*.o
	-rm -f platform/*.o
	-rm -f ubf/*.o
	-rm -f units/*.o
	-rm -f util/platform/*.o
	-rm -f util/*.o
	-rm -f *.o
	-rm -f $(LIB)
