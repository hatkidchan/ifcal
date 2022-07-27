OBJECTS := obj/ifc.o

clean:
	$(RM) $(OBJECTS) ifcal

ifcal: lib
	$(CC) $(CFLAGS) $(OBJECTS) src/main.c -o ifcal

lib: $(OBJECTS)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $^ -o $@
