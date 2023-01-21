.DEFAULT_GOAL := all

CC=gcc
CCX_FLAGS += -fPIC $(NAME)/$(NAME).c -o $(FNAME)/$(FNAME)
LD_FLAGS += -pie -lc -ldl
FNAME="Arturium Browser"
NAME=arturium-browser

RM = rm -f

all: release
release: library
release32: release
release32: CCX_FLAGS += -m32
release32: LD_FLAGS += -m32

library: $(FNAME)

$(FNAME):
	mkdir -p ./$(FNAME)/resources
	cp $(NAME)/* $(FNAME)
	cp build_info.json $(FNAME)/resources
	cp $(NAME)/plugin.py $(FNAME)/resources
	$(CC) $(CCX_FLAGS) $(LD_FLAGS)
	strip $(FNAME)/$(FNAME)
	rm -f $(FNAME)/$(NAME).c $(FNAME)/plugin.py
	
install:
	mkdir -p /opt/$(NAME)/resources
	cp -r $(FNAME)/* /opt/$(FNAME)
	cp $(FNAME)/$(NAME).desktop /usr/share/applications
	cp $(FNAME)/$(NAME).png /usr/share/icons/hicolor/256x256/apps

clean:
	$(RM) $(FNAME)
