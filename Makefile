SUBDIRS = alloc_dinamica array files funzioni input_output liste selezione struct strings

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@
