SUBDIRS=$(wildcard */.)

default: all

all:$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: all default $(SUBDIRS)
