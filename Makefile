copy_files: copy_files.out
	./copy_files.out

copy_files.out: main.o libcopy_files.a
	gcc main.o -L. -lcopy_files -o copy_files.out

libcopy_files.a: copy_files.o
	ar cr libcopy_files.a copy_files.o

main.o: main.c
	gcc -c main.c

clean:
	rm *.o *.a output_file.txt copy_files.out

