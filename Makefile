CFLAGS=-Wall -Wextra -std=gnu99 -ggdb

minish: minish.o linea2argv.o wrappers.o ejectuar.o
#builtin_exit.o builtin_help.o builtin_history.o builtin_status.o builtin_cd.o builtin_dir.o builtin_getenv.o builtin_gid.o builtin_setenv.o builtin_pid.o builtin_uid.o builtin_unsetenv.o ejecutar.o externo.o

minish.o: minish.h wrappers.h
linea2argv.o: linea2argv.h wrappers.h
wrappers.o: wrappers.h
ejecutar.o: minish.h