OBJECTS := obj/ifc.o

ifc: lib
	$(CC) $(CFLAGS) $(OBJECTS) src/main.c -o ifc

lib: $(OBJECTS)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $^ -o $@
