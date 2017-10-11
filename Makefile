SUBDIRS=helloworld/. $(wildcard problem*/.)
TOPTARGETS=default clean

$(TOPTARGETS):$(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)
