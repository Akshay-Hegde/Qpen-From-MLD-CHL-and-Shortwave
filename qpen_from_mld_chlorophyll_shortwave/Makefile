CC      = gcc
CFLAGS  = -g
RM      = rm -f
BIN     = /bin
EXE     = qpen_from_mld_chl_shortwave
SRC     = qpen_from_mld_chl_shortwave.c
 
default: all

all: $(EXE)

clean veryclean:
	@$(RM) $(EXE)
$(EXE) : 
	@$(CC) $(CFLAGS) -o $(EXE) $(SRC) -lm

install:$(EXE)
	@install $(EXE) $(BIN)
	@$(RM) $(EXE)
	@echo "Installation successfull"

