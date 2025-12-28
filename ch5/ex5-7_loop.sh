gunzip ex5-7_test_input.txt.gz
time for i in $(seq 1 1000); do ./ex5-7_sort < ex5-7_test_input.txt > /dev/null; done
