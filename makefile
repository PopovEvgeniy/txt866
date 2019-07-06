install:
	@echo Installation in progress. Please wait
	@gcc txt866.c -g0 -O0 -o txt866
	@chmod ugo+rx txt866
	@cp -f -p txt866 /bin/
	@echo Installation was successfuly complete
uninstall:
	@rm -f /bin/txt866
	@echo Uninstallation was successfuly complete