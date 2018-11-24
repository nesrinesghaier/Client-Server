#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/DAO/ClientDAO.o \
	${OBJECTDIR}/DAO/TCPClientDAO.o \
	${OBJECTDIR}/Presentation/Controller.o \
	${OBJECTDIR}/Presentation/Model.o \
	${OBJECTDIR}/Presentation/View.o \
	${OBJECTDIR}/Service/ClientService.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/client

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/client: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/client ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/DAO/ClientDAO.o: DAO/ClientDAO.cpp
	${MKDIR} -p ${OBJECTDIR}/DAO
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DAO/ClientDAO.o DAO/ClientDAO.cpp

${OBJECTDIR}/DAO/TCPClientDAO.o: DAO/TCPClientDAO.cpp
	${MKDIR} -p ${OBJECTDIR}/DAO
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DAO/TCPClientDAO.o DAO/TCPClientDAO.cpp

${OBJECTDIR}/Presentation/Controller.o: Presentation/Controller.cpp
	${MKDIR} -p ${OBJECTDIR}/Presentation
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Presentation/Controller.o Presentation/Controller.cpp

${OBJECTDIR}/Presentation/Model.o: Presentation/Model.cpp
	${MKDIR} -p ${OBJECTDIR}/Presentation
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Presentation/Model.o Presentation/Model.cpp

${OBJECTDIR}/Presentation/View.o: Presentation/View.cpp
	${MKDIR} -p ${OBJECTDIR}/Presentation
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Presentation/View.o Presentation/View.cpp

${OBJECTDIR}/Service/ClientService.o: Service/ClientService.cpp
	${MKDIR} -p ${OBJECTDIR}/Service
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Service/ClientService.o Service/ClientService.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
