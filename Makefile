CXX = clang++
CXXFLAGS = -Wall -Werror
VERSION=1.0.2.3

TARGET_PIMPL = pimpl
OBJS_PIMPL = pimpl.o
PIMPL_BIN = ${TARGET_PIMPL}-${VERSION}

TARGET_INHERIT = inherit
OBJS_INHERIT = inherit.o
INHERIT_BIN = ${TARGET_INHERIT}-${VERSION}

TBNAME=examples-${VERSION}

.PHONY: clean tarball

all: ${TARGET_PIMPL} ${TARGET_INHERIT}

${TARGET_PIMPL}: ${OBJS_PIMPL}
	${CXX} -o ${PIMPL_BIN} $<

${TARGET_INHERIT}: ${OBJS_INHERIT}
	${CXX} -o ${INHERIT_BIN} $<

%.cpp.o:
	${CXX} ${CXXFLAGS} -c -o $? $@

clean:
	rm -f ${PIMPL_BIN} ${INHERIT_BIN}
	rm -f ${OBJS_PIMPL} ${OBJS_INHERIT}
	rm -f ${TBNAME}.tar.gz

tarball:
	@mkdir ${TBNAME}
	@cp *.cpp *.hpp ${TBNAME}
	@cp Makefile ${TBNAME}
	@tar czf ${TBNAME}.tar.gz ${TBNAME}
	@rm -fr ${TBNAME}
	@tar tzvvf ${TBNAME}.tar.gz
