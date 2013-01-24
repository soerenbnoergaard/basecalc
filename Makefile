all : basecalc

basecalc : basecalc.c
	gcc basecalc.c -lm -o basecalc

install : basecalc
	cp basecalc /usr/local/bin

uninstall : 
	rm -f /usr/local/bin/basecalc
