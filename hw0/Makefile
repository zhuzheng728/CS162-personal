run_wc: test.txt
	wc test.txt

run_wcc: wc test.txt
	./wc test.txt
wc: wc.c
	gcc -g wc.c -o wc

run_test: test
	./test
test: test.c
	gcc -g test.c -o test

clean:
	rm -rf wc test
