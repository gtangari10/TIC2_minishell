CFLAGS=-Wall -Wextra -std=gnu99 -ggdb -Wno-unused-parameter

minish: minish.o linea2argv.o wrappers.o ejecutar.o builtin_exit.o builtin_help.o builtin_history.o builtin_status.o builtin_cd.o builtin_dir.o builtin_getenv.o builtin_gid.o builtin_setenv.o builtin_pid.o builtin_uid.o builtin_unsetenv.o externo.o builtin_lookup.o deq-func.o


minish.o: minish.h wrappers.h
linea2argv.o: wrappers.h
wrappers.o: wrappers.h
ejecutar.o: minish.h 
builtin_lookup.o: minish.h
deq-func.o: deq.h
builtin_history.o: minish.h
