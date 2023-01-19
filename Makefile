.DEFAULT_GOAL := all

CC=gcc
CXX_FLAGS += $(NAME)/$(NAME).c -o $(FNAME)/$(FNAME)
LD_FLAGS += -lc -ldl
FNAME="Arturium Browser"
NAME=arturium-browser

RM = rm -f
DIR = ../$(NAME)

release32: CXX_FLAGS += -m32
release32: LD_FLAGS += -m32
release: library
release32: release
all: release

library: $(FNAME)

$(FNAME):
	mkdir -p ./$(FNAME)/resources
	cp $(NAME)/* $(FNAME)
	cp build_info.json $(FNAME)/resources
	cp $(NAME)/plugin.py $(FNAME)/resources
	$(CC) $(CXX_FLAGS) $(LD_FLAGS)
	strip $(FNAME)/$(FNAME)
	rm -f $(FNAME)/$(NAME).c $(FNAME)/plugin.py
	
install:
	mkdir -p /opt/$(FNAME)/resources
	cp -r $(FNAME)/* /opt/$(FNAME)
	cp $(FNAME)/$(NAME).desktop /usr/share/applications
	cp $(FNAME)/$(NAME).png /usr/share/icons/hicolor/256x256/apps

clean:
	$(RM) $(FNAME)
