install:
	@echo Installation in progress. Please wait
	@gcc txt866.c -g0 -O0 -o /bin/txt866
	@chmod ugo+rx /bin/txt866
	@echo Installation was successfuly complete
uninstall:
	@rm -f /bin/txt866
	@echo Uninstallation was successfuly complete