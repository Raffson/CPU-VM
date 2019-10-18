# set the source
SET( pref ${CMAKE_CURRENT_SOURCE_DIR}/Components )
SET( src	${pref}/Machine.cpp
			${pref}/Program.cpp
			${pref}/Register.cpp
			${pref}/Instruction.cpp
			${pref}/UnaryInstruction.cpp
			${pref}/BinaryInstruction.cpp
			${pref}/Instructions/IMov.cpp
			${pref}/Instructions/IAdd.cpp
			${pref}/Instructions/ISub.cpp
			${pref}/Instructions/IInc.cpp
			${pref}/Instructions/IDec.cpp
			${pref}/Instructions/ICMP.cpp
			${pref}/Instructions/IJump.cpp
)

# generate the executable
ADD_EXECUTABLE( CPU-VM	main.cpp	${src} )
INSTALL( TARGETS CPU-VM RUNTIME DESTINATION ${BIN_INSTALL_LOCATION} )
