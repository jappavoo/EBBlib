CFLAGS := -O4 
#CFLAGS := -g -O2
SRCS := EBBMgrPrim.c CObjEBBRootShared.c CObjEBB.c \
	sys/defFT.c EBBMemMgrPrim.c EBBCtrPrim.c ebbtest.c \
	sys/arch/amd64/defFT.S
OBJS := $(patsubst %.c, %.o, $(filter %.c, $(SRCS)))
OBJS += $(patsubst %.S, %.o, $(filter %.S, $(SRCS)))
DEPS := $(patsubst %.c, %.d, $(filter %.c, $(SRCS)))
DEPS := $(patsubst %.S, %.d, $(filter %.S, $(SRCS)))

all: ebbtest

ebbtest: $(OBJS) ebbtest.mk
	gcc $(CFLAGS) $(OBJS) -lpthread -o $@

objctest: objctest.m clrBTB.o $(OBJS) sys/arch/amd64/defFT.o
	gcc-mp-4.4 -fgnu-runtime $(CFLAGS) objctest.m clrBTB.o $(OBJS) -lobjc sys/arch/amd64/defFT.o -o $@ 

clrBTB.o: jmps.S clrBTB.S
	gcc -c clrBTB.S

clrBTB.S: jmps.S
	touch clrBTB.S

jmps.S:
	./mkjmps 1024 > jmps.S

-include $(DEPS)

%.o : %.c ebbtest.mk
	gcc $(CFLAGS) -MMD -MP -c $< -o $@

%.o: %.S ebbtest.mk
	gcc $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	-rm $(wildcard $(OBJS) $(DEPS) ebbtest)